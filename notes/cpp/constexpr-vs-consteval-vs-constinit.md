---
layout: post
toc: true
---

# Motivations of `constexpr` vs `constinit` vs `consteval`

The confusion between these three qualifiers usually comes from misunderstanding the guarantees of `constexpr`. `constexpr` does NOT guarantee evaluation at compile-time, nor does it guarantee that a variable has no runtime storage.

For example,

```c++
constexpr int plusOne(int x) { return x + 1; }

int main()
{
    // y *may* be initialized dynamically on the stack
    // plusOne *may* be executed at runtime
    constexpr int y = plusOne(1);
    return y;
}
```

The main usage of `constexpr` is to allow an expression to be used in contexts that require a *constant expression*. The distinction is worth repeating: the `constexpr` keyword does not make an expression a constant expression, it only allows it to be used in contexts that require one. The confusion here is because *constant expression* is not a colloquial term to mean "evaluated at compile-time with no runtime storage", but rather an abstract term in the C++ standard with a formal definition.


Only when a `constexpr` variable is used or `constexpr` function evaluated in a context requiring a constant expression, is it evaluted at compile-time. For example:

```c++
constexpr int plusOne(int x) { return x + 1; }

int main()
{
    constexpr int y = plusOne(1);
    constexpr int z = plusOne(2);
    static_assert(y == 2); // Because of this line, y is guaranteed to be evaluated at compile time.

    std::array<int, z> arr; // Because of this line, z is guaranteed to be evaluated at compile time.
    return y;
}
```

Note though that there are still no guarantees about zero runtime storage overhead. For an example on why this is not possible, consider the following:

```c++
int main()
{
    constexpr int x = 5;
    static_assert(x == 5);
    return &x; // x needs to have runtime storage for this to make sense
}
```

## Guaranteed compile-time evaluation

`consteval` and `constinit` are used to fill this missing guarantee from 
`constexpr`. 

`consteval` can only be applied to functions, and forces the function to be evaluated at compile-time whenever it is called. If this is not possible, it is a compile-time error. If the function were marked `constexpr` and called in a context where compile-time evaluation were not possible, it would "silently" be evaluated at runtime.

```c++
consteval int plusOne(int x) { return 1; }
constexpr int plusTwo(int x) { return 2; }

int main()
{
    int x = plusOne(1); // x is guaranteed to be evaluated at compile-time, despite not being used in a constant expression
    int y = plusTwo(x); // plusTwo may evaluate at runtime, since x is not a constant expression

    int y2 = plusOne(x); // compilation-error because plusOne is consteval but x is not a constant expression
}
```

`constinit` can only be applied to variables and forces their *constant initalization*; another C++ standard term which essentially means "initialized at compile-time". As a natural consequence, `constinit` can only be applied to variables with static or thread-local storage duration. The initialization must be done with a *constant expression*.

```c++
consteval int plusOne(int x) { return x + 1; }
constexpr int plusTwo(int x) { return x + 2; }
int plusThree(int x) { return x + 3; }

int main()
{
    // Valid: plusOne(1) is a constant expression
    constinit int x = plusOne(1);
    
    // Valid: plusTwo(2) is a constant expression evaluated
    // at compile-time because it is required in a constant
    // expression context, namely, the initialization of y
    constinit int y = plusTwo(2); 

    // INVALID: note that constinit variables are not constant expressions! 
    constinit int y2 = plusTwo(x);

    // INVALID: plusThree(3) is not a constant expression
    constinit int y2 = plusThree(3);
}
```

## `constinit` does not imply `const`

`constexpr` implies `const`, but `constinit` does NOT imply `const`: this may seem counter-intuitive, but it makes sense when considering that the initialization of an object is different from the usage of it. From this perspective, `constinit` is the converse of `const`:

* `const`: initialized at run-time, immutable access
* `constinit`: initialized at compile-time, mutable access
* `const constinit`: initialized at compile-time, immutable access

## When to use what

* Use `consteval` to force a function to be evaluated at compile-time. For example: a very expensive function used to pre-compute values that you never want called at run-time.

```c++
consteval int calculateNthPrime(int n);
```

* Use `constinit` to force a variable to be evaluated at compile-time. This is especially useful for avoiding the [*static initialization order fiasco*](https://en.cppreference.com/w/cpp/language/siof) (i.e., ambiguous ordering of initialization of variables with static storage duration)

`main.cpp`
```c++
extern int x;
extern constinit y;

int main()
{
    std::print("{}", x); // undefined behaviour
    std::print("{}", y); // well-defined, y is guaranteed to be 20
}
```

`definitions.cpp`

```c++
int x = 10;
constinit int y = 20;
```


* Use `constexpr` on a variable to allow it to be used in a constant expression.

* Use `constexpr` on a functions when it makes sense for it to be evaluated both at compile-time and at run-time. For example, the constructors for `std::vector` are `constexpr`, allowing for algorithms that require auxilary space to be computed all at compile-time:

<iframe width="800px" height="550px" src="https://godbolt.org/e#g:!((g:!((g:!((h:codeEditor,i:(filename:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,selection:(endColumn:1,endLineNumber:23,positionColumn:1,positionLineNumber:23,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:'%23include+%3Cvector%3E%0A%23include+%3Calgorithm%3E%0A%23include+%3Cformat%3E%0A%0Aconsteval+int+numCoinCombinations(std::vector%3Cint%3E+coins,+int+target)%0A%7B%0A++++std::vector%3Cint%3E+dp(target+%2B+1)%3B%0A++++dp%5B0%5D+%3D+1%3B%0A++++for+(int+i+%3D+0%3B+i+%3C%3D+target%3B+%2B%2Bi)+%7B%0A++++++++for+(int+c+:+coins)+%7B%0A++++++++++++if+(i+-+c+%3E%3D+0)%0A++++++++++++++++dp%5Bi%5D+%3D+dp%5Bi%5D+%2B+dp%5Bi+-+c%5D%3B%0A++++++++%7D%0A++++%7D%0A++++return+dp%5Btarget%5D%3B%0A%7D%0A%0Aint+main()%0A%7B%0A++++//+All+at+compile-time+:)%0A++++std::printf(%22%7B%7D%22,+numCoinCombinations(%7B1,+1500,+1000%7D,+2000))%3B%0A%7D%0A'),l:'5',n:'0',o:'C%2B%2B+source+%231',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0'),(g:!((h:compiler,i:(compiler:g142,filters:(b:'0',binary:'1',binaryObject:'1',commentOnly:'0',debugCalls:'1',demangle:'0',directives:'0',execute:'1',intel:'0',libraryCode:'0',trim:'1',verboseDemangling:'0'),flagsViewOpen:'1',fontScale:14,fontUsePx:'0',j:1,lang:c%2B%2B,libs:!(),options:'-std%3Dc%2B%2B20',overrides:!(),selection:(endColumn:1,endLineNumber:1,positionColumn:1,positionLineNumber:1,selectionStartColumn:1,selectionStartLineNumber:1,startColumn:1,startLineNumber:1),source:1),l:'5',n:'0',o:'+x86-64+gcc+14.2+(Editor+%231)',t:'0')),k:50,l:'4',n:'0',o:'',s:0,t:'0')),l:'2',n:'0',o:'',t:'0')),version:4"></iframe>