---
layout: post
toc: true
title: What is Perfect Forwarding?
---

Perfect forwarding is a technique in C++ that allows you to pass arguments to a wrapped function while preserving their value category (lvalue or rvalue). Consider the following:

```c++
void inner(std::string& s);
void inner(std::string&& s);

void wrapper(std::string& s) { inner(s); }
void wrapper(std::string&& s) { inner(std::move(s)); }
void universalWrapper(/* what to declare here? */ s);

int main()
{
    std::string s = "Hello";
    wrapper(s); // Calls save(std::string&)
    wrapper(std::move(s)); // Calls save(std::string&&)
}
```

In the above, `inner` is overloaded to do different things based on whether the argument is an lvalue or rvalue. Since the argument to `inner` is passed through another function `wrapper`, we need to overload `wrapper` as well to ensure that the correct version of `inner` is called. Worse still, if there are multiple arguments, we would need to overload `wrapper` for each combination of lvalue and rvalue references.

To avoid this, we can use a `universal reference`:

```c++
template <typename T>
void wrapper(T&& s) { /* ... */ }
```

Now, if `wrapper` is passed an rvalue (lvalue), `s` will be an rvalue (lvalue) reference. This works because of template deduction rules and reference collapsing:

```c++
// The template matches the argument std::string {"rvalue"} to
// the parameter T&& s, from which T is deduced to be a std::string.
wrapper(std::string {"rvalue"});

// The template matches the argument lvalue to
// the paramter T&& s, from which T is deduced to be a std::string&.
// If T were deduced to be a std::string or std::string&&, then T&&
// would be an rvalue reference, which can't bind to the lvalue argument.
std::string lvalue = "lvalue";
wrapper(lvalue);
```

It may seem strange that `T&&` can be both an lvalue and rvalue reference, but this is a consequence of reference collapsing rules in C++. Specifically, a "reference to a reference" doesn't make sense, so C++ collapses double/multiple references into a single reference type by the following rule: **a multiple reference type is an rvalue reference if and only if every reference in the type is an rvalue reference. Otherwise it is an lvalue reference.** So `T&&` can match an lvalue by deducing `T` as an lvalue reference type, since an lvalue reference and an rvalue reference collapse to an lvalue reference.

Note that the above rule is why the template parameter must be declared as `T&&` instead of `T&`. If it were `T&`, then the template would only match lvalues, since there is no way to deduce `T` such that the reference collapses to an rvalue reference. (If it were `T`, then the template wouldn't deduce a reference type at all, and the argument would be passed by value!)

Thus, universal references allow us to write a single function that can accept both lvalues and rvalues by reference. However, we still need to be careful about how we use the parameter inside the function. The value category of an object is not the same as its type. The type of `s` is either "rvalue reference to `T`" or "lvalue reference to `T`", but the value category of `s`, being a named expression, is always an lvalue. So, passing `s` to `inner` would always pass an lvalue reference, regardless of the type of `s`. To preserve the value category, we need to use `std::forward`:

```c++
template <typename T>
void wrapper(T&& s)
{
    inner(std::forward<T>(s)); // Preserves the value category of s
}
```

`std::forward` is a utility function that conditionally casts `s` to an rvalue reference if `T` is an rvalue reference type, or leaves it as an lvalue reference if `T` is an lvalue reference type. This way, we can ensure that the correct version of `inner` is called based on the value category of the argument passed to `wrapper`.
