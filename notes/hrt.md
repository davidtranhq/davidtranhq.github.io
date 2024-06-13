---
layout: default
toc: true
---

# Trading Firm Interview Prep

## Operating Systems

### Virtualization

#### Limited Direct Execution (How System Calls work)
* trap instruction jumps into kernel code
* on boot, trap table is set-up in the kernel, which details exactly where the trap instruction can jump to (depending on the trap number), and thus the code that is run on trap
* system call is finished with a return-from-trap instruction: returning to the process that called the trap instruction
* on trap, process pushes its state to its kernel stack, on return-from-trap, kernel pops state from its kernel stack and pushes it to the process's stack (using the PCB)

#### Process
* process control block stored in the kernel's process list: contains everything needed to run a program:
  * thread-specific: registers, address space (page table information), process state (running, ready, waiting) for multiprogramming, kernel stack, etc.
* `fork()` copies the PCB, creates a new (duplicate) process
* `exec()` replaces the PCB of the running process with a new one to run a different program, overwrites the code segment of the old process and re-initailizes heap and stack
  

#### Scheduling

* FIFO achieves best turnaround time but worse response time
* SJF achieves best response time but worst turnaround time
* MLFQ achieves Pareto frontier between the two
  * feedback: once a scheduled task uses its "allotment" priority is decreased
  * every so often return all processes to the highest priority
  * run queues in priority order with round-robin
* scheduling uses a large amount of CPU time
* Linux uses Completely Fair Scheduling (CFS): divides a pre-determined latency equally among all jobs
  * running jobs are kept in a RB tree to determine which job has run the least (and thus should be run next)
  * time allocation can also be weighted with a configurable "niceness" property (nicer processes get less share)

#### Memory API
* `brk()` or `sbrk()`: change the (virtual) end marker of the heap for this process (in essence, allocate more virtual memory to the heap)
* `mmap()`: allocate virtual memory backed either
  * anonymously: swap space with physical pages allocated on demand or immediately
  * by a file: file is read/written to on demand: doesn't require the entire file to be read into memory
    * advantage over `read()`: faster for random-access
    * writes are guaranteed to be persisted only after a call to `msync(2)`

### Concurrency

#### Threads
* multiple threads can be in one process: each with their own program state but using the same address space, stored in a thread-control block

#### Mutex
* implemented in Linux with futexes (fast user-space mutex): comprised of an integer and a queue of sleeping threads stored in physical memory
* `futex_wait(mutex, v)` puts the thread to sleep and adds it to the queue
* `futex_wake(mutex)` wakes a sleeping thread in the queue 
```
void lock(int *mutex) {
    if (atomic_bit_test_set(mutex, 31) == 0) return;
    atomic_increment(mutex);
    while true {
        if (atomic_bit_test_set(mutex, 31) == 0) {
            atomic_decrement(mutex);
            return;
        }
        int v = *mutex;
        if (v >= 0) continue;
        futex_wait(mutex, v);
    }
}
```

#### Condition Variable

From https://stackoverflow.com/a/4742791/6327671 :
> A common implementation approach for a mutex is to use a flag and a queue. The flag indicates whether the mutex is held by anyone (a single-count semaphore would work too), and the queue tracks which threads are in line waiting to acquire the mutex exclusively.
> 
> A condition variable is then implemented as another queue bolted onto that mutex. Threads that got in line to wait to acquire the mutex can—usually once they have acquired it—volunteer to get out of the front of the line and get into the condition queue instead. At this point, you have two separate sets of waiters:
> 
> * Those waiting to acquire the mutex exclusively
> * Those waiting for the condition variable to be signaled
> 
> When a thread holding the mutex exclusively signals the condition variable, for which we'll assume for now that it's a singular signal (unleashing no more than one waiting thread) and not a broadcast (unleashing all the waiting threads), the first thread in the condition variable queue gets shunted back over into the front (usually) of the mutex queue. Once the thread currently holding the mutex—usually the thread that signaled the condition variable—relinquishes the mutex, the next thread in the mutex queue can acquire it. That next thread in line will have been the one that was at the head of the condition variable queue.
>
> There are many complicated details that come into play, but this sketch should give you a feel for the structures and operations in play.


#### Semaphores
* implemented with value, condition variable and mutex
* `wait` (decrementing) acquires a mutex and waits on a condition variable if the value is not positive
* `post` (incrementing) acquires a mutex, increments the value, signals the condition variables, and releases the mutex

```
struct semaphore {
    int value;
    mutex m;
    condition_variable cv;
};

void init(semaphore *s, int value) {
    s->value = value;
    init mutex s->m;
    init condition variable s->cv;
}

// only decrement when positive
void wait(semaphore *s) {
    acquire mutex
    while value <= 0:
        cv wait
    decrement value
    release mutex
}

void post(semaphore *s) {
    acquire mutex
    increment value
    signal cv
    release mutex
}
```

#### Single Buffer Producer/Consumer Problem
* key: use two condition variables, one to signal consumers and one to signal producers

```
condition_variable empty, fill;
mutex m;
size = 0

void consume() {
    lock mutex
    while size == 0:
        wait(fill)
    get element from buffer
    size -= 1
    signal(empty)
    unlock mutex
}

void produce() {
    lock mutex
    while size == FULL:
        wait(empty)
    put element in buffer
    size += 1
    signal(fill)
    unlock mutex
}
```

#### Common Concurrency Problems
* atomicity violation: operations (usually memory acccesses) are assumed to be atomic when they are not: fix with mutexes
* order violation: operations are assumed to be in a particular order when they are non-deterministic: fix with condition variables to signal ordering

##### Deadlock
* necessary conditions for deadlock to occur:
  * mutual exclusion
  * hold-and-wait
    * prevent by using an additional mutex to grab all locks at once: but this decreases concurrency and becomes less feasible with more encapsulation (we don't know which locks are needed in advance)
  * no preemption
    * fix by including preemption: using `trylock()`: if we fail to acquire the lock then don't sleep but return early (and presumably release the locks we were holding)
  * circular wait
    * can be prevented by acquiring locks in order of their address: this solves the Dining Philosopher's problem

### Persistence

#### Files
* files are opened with the system call `open()`, which:
  * stores a `FILE *` in the process' file table (located in the PCB), returning a file descriptor (the index into this file table)
  * `FILE *` points to a file struct, which contains, among others, read/write flags, position in the file, and a pointer to the inode
  * the file struct is stored in an open file table in the kernel

### Important Linux System Calls (how are each implemented)

* `fork()`
  * duplicates the process' PCB
* `execve()`
  * reuses process' PCB: rewrites code section, reinitializes heap/stack
* `exit()`
  * first performs cleanup, calls functions registered with `atexit()`
  * calls `exit()` system call which makes the kernel clean up resources and set the exit status in the PCB
* `wait()` 
  * set the process' status in its PCB to wait
  * OS periodically checks its child processes for terminated processes, which will wake the parent PCB (and give it the exit code of the child)
* `open()`
  * OS searches for the inode with the given name, creates a new entry (`struct file`) in the kernel-level open-file table, adds an entry to the per-process file table `struct file *`, and returns a file descriptor (the index into this per-process table)
* `close()`
  * deallocates the file descriptor in the process and, if it was the last reference to the file, from the kernel-level open file table
* `read()`
  * reads data from the file pointed to by the descriptor into the provided buffer, and updates the position recorded in the file struct
* `write()`
  * reverse of `read()`
* `pipe()`
  * kernel reserves a buffer of memory, returns file descriptors for the read and write ends of the pipe
* `dup()`
  * duplicate a file descriptor in the process' file descriptor table, assigning it to the first open file descriptor
* `dup2()`
  * copy a file descriptor into an existing one: this is how input/output redirection is achieved (the STDOUT file descriptor is overwritten with the file descriptor of the desired output)
* `stat()` and `fstat()`
  * read metadata from the associated file's inode
* `mmap()` and `munmap()`
  * maps (and unmaps) parts of the process' virtual address space. can be
    * anonymous: 
* `brk()`
  * sets the end of the data segment of the calling process to a specified value, changing the size of the process' heap
  * new physical pages aren't necessarily mapped here immediately: rather, demand-paging or copy-on-write is used
* `sbrk()`
  * same as `brk()`, but increments the current end rather than setting it to a specified value
* `ioctl()`
  * provides a generic mechanism for performing device-specific or implementation-specific control operations on file descriptors
* `socket()`
  * return a file descriptor to a buffer for sending and recieving packets. usually there are two buffers: a user-space buffer and a kernel-space buffer, to seperate the application layer from the lower layers of the network stack
* `bind()`
  * associates a given name (IP address and port number) for a given socket (through its file descriptor) in the kernel's socket table, inside a networking subsystem of the kernel
* `listen()`
  * sets the specified socket to the listening state (e.g. in the socket table), and initializes a buffer for an internal queue for incoming connection requests.
  * if processes were waiting for the socket to transition into the listening state, they are notified
* `accept()`
  * blocks the process if there are no pending connections, otherwise dequeues the pending connection from the queue and returns a file descriptor to the newly created socket for exclusive communciation with the incoming client
* `connect()`
  * attempt to connect with a server, using the provided socket if a connection is established
* `select()`
  * blocks the thread until one of the specified sockets (specfied with file descriptors) is ready, after which `select()` returns a value indicating a socket is ready, or none are ready. the ready sockets can then be idenfitied by a structure passed into `select()` (which told `select()` which sockets we wanted to listen to)
* `poll()`
  * less portable version of `select()` but easier to use: can monitor an unlimited number of sockets
* `epoll()`
  * more scalable version of `poll()` that uses events, waits for incoming events rather than scanning all watched socket fds
* `kill()`
  * kernel checks if the process that sent the signal has permissions, and then goes to the recieving PCB, updates flags, checks if there is an associated signal handler in the PCB (if there is, runs it, otherwise, runs default action)
* `signal()`
  * registers a signal handler in the process' PCB
* `sigaction()`
  * same as `signal()`, but provides more controls and options

### Inter-process Communication

#### Pipe
* pipe at command-line: `A | B`: process is created, a pipe is opened and forked into `A` and `A'`: before `A'` is `exec()`'d into `B`, we close the STDOUT of `A` and the STDIN of `B` and replace them respectively with the write and read ends of the pipe

#### 

## C++

### Compilation Process
* headers + sources -> preprocessor processes macros/includes/directives -> translation units -> compiler compiles/generates code/instantiates tempaltes/evaluates constexpr -> assembly -> assembler assembles into -> object files -> linker links into executable
* object files contain executable code and symbol table, sections (static data, text)
* one-definition-rule: each object must be defined only once unless:
  * declared inline (all definitions all still need to be the same)

### `constexpr`/`consteval`
* marks function as evaluatable at compile-time (although it still can be evaluated at runtime)
* variables marked constexpr can be used in places where constexpr variables are expected
* `consteval` forces a function to be evaluated at compile time
* `constexpr` implies inline, but not necessarily const

### Memory Layout
* members in struct/classes are guaranteed to be layed-out in memory in declaration-order within their access specifier (until C++20), and even outside access specifier (C++23)
* some architectures may require byte-boundary alignment 

### stl data structures

#### hashmap/hashset

```
struct hashtable {
    list<payload> list;
    array<payload> table;
}
```
* elements are added to the list: `table[hash]` points to the node indicating the start of its bucket

#### map/set

* implemented as red-black tree

#### deque

* vector of pointers to fixed-size arrays
* once limit is reached, vector size is doubled and moved to the "middle" of the allocated memory region
* O(1) amortized push_front, push_back

#### string
* small-string optimization: string is stored in the struct itself for small strings: no dynamic allocation

#### span
* wrapper pointing to a contiguous sequence of elements
* dynamic span: size is stored in the wrapper
* static span: size is known at compile time: only a pointer is stored