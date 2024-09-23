---
layout: post
title: Why Does Perfect Forwarding Use Rvalue References?
---

Perfect forwarding is a technique in C++ used to preserve the reference type of a value when passed to a function through another function. For example,

```
foo(
```

||`T`|`T&`|`T&&`|
|---|---|---|---|
|`T = U`|`U`|`U&`|`U&&`|
|`T = U&`|`U&`|`U&`|`U&`|
|`T = U&&`|`U&&`|`U&`|`U&&`|
