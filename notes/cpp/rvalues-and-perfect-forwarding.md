---
layout: post
toc: true
---

# Rvalues and Perfect Forwarding

## Rvalues

An lvalue is an object that has a persistent location in memory that can be referred to.
An rvalue is an object that does not have a persistent location in memory that can be referred to.

For example:

```c++
int bar()
{
  return 5; // 5 is an rvalue
}

void foo() // lvalue, stored at &foo
{
  int x = 5; // lvalue, stored at &x
  int y = bar(); // y is an lvalue, but bar() is an rvalue, we can't refer to it directly
}
```

Where are rvalues stored then? If the value is small enough, it might be stored in a register, or even evaluated by the compiler entirely and not stored anywhere (e.g. in the case of `5 + 1` above, and `foo()` with return-value optimization). But if it's larger, like a `struct` that can't fit in a register:

```c++
struct BigType
{
  uint64_t a, b, c, d, e, f;
};

BigType bar()
{
  return {1, 2, 3, 4, 5, 6};
}

void foo()
{
  BigType x = bar();
}
```

it might be stored somewhere in memory. The distinction is that we can't refer to it. For example, here `bar()` is would be stored somewhere in memory (ignoring compiler optimizations), the only thing distinguishing it from an lvalue is the fact that we can't refer to it: until we bind `x` to it. So `x` is an lvalue but the struct returned by `bar()` is an rvalue.

## Perfect Forwarding

Consider the following:

```c++
void takesRValue(int&& rValue)
{
  // rValue is (internally) a pointer, which is an lvalue!
}

void foo()
{
  int x = 2;
  takesRValue(x); // does not compile, x is an lvalue
  takesRValue(1); // compiles, 1 is an rvalue
```

`rValue` only binds to rvalues, so the first call doesn't compile but the second call does. But, inside the `takesRValue` function, `rValue` is an **lvalue**: the object that it refers to is an rvalue. One way to think of this is: the rvalue-ness or lvalue-ness of a variable represemts the type of of the object that the variable refers to, not the variable itself.

To preserve the rvalue-ness or lvalue-ness, we use a templated rvalue parameter with `std::forward<T>`:

```c++
template<typename T>
void bar(T&& x)
{
  return std::forward<T>(x);
}
```

Here, `x` in the function is an lvalue reference if it is passed an lvalue, and a plain (non-reference) value type if passed an rvalue.

If `std::forward` is passed an lvalue, it does nothing and just returns its argument. If it is passed a plain (non-reference) type, it is the same as `static_cast<T&&>(x)`, that is, essentially `std::move(x)`.

