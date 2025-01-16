---
layout: post
toc: true
title: Motivations of constexpr, constinit, and consteval
---

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
    static constinit int x = plusOne(1);
    
    // Valid: plusTwo(2) is a constant expression evaluated
    // at compile-time because it is required in a constant
    // expression context, namely, the initialization of y
    static constinit int y = plusTwo(2); 

    // INVALID: note that constinit variables are not constant expressions! 
    static constinit int y2 = plusTwo(x);

    // INVALID: plusThree(3) is not a constant expression
    static constinit int y2 = plusThree(3);
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

```c++
consteval int numCoinCombinations(std::vector<int> coins, int target)
{
    std::vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 0; i <= target; ++i) {
        for (int c : coins) {
            if (i - c >= 0)
                dp[i] = dp[i] + dp[i - c];
        }
    }
    return dp[target];
}

int main()
{
    // All at compile-time :)
    std::printf("{}", numCoinCombinations({1, 1500, 1000}, 2000));
}
```
