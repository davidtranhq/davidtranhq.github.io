# Parallel Integer Polynomial Multiplication

## TODO
1. Make serial C/C++ implementation of the algorithm
2. Move to CUDA C++

Yuzhen Xie, SuperTech Group, CSAIL MIT (think of reaching out to apply)

Balanced Dense Polynomial Multiplication on Multicores

Using coefficients:
* easy to determine the degree of ht epolynomial, hard to multiply

Moving to FFT:
* easy to multiply, hard to determine degree

Now: multivariate polynomials:
* Kronecker substitution: reduce a multivariate polynomial to a univariate polynomial
  * transformation has pros and cons:
    * cons: requires padding, e.g. if we transform multivariate polynomials to univariate, and then multiply them, to retrieve product as multivariate oplynomial, for that to work, we need more computations than if we stayed in the multivariate world (need to do padding)
    * pros: we can treat multivariate as univariate, e.g., if we have some extremely fast treatment of univariate polynomials

* transforming to univariate brings more problems on multicore architectures (not necessarily Kronecker substitution), the problem is that the multivariate polynomial becomes a very big univariate polynomial, causes practical problems with cache misses, etc.

* for large enough polynomials, we see linear speedup with respect to the number of cores for bivariate interpolation (when the degree of both variables are the same)
  * performance degrades as the dimensions (degree of the variable) differs

Why?

Comparison of polynomials with dimensions that have the same product:
* With 8 variables of very small degree, there is lots of branch misprediction (e.g. iterating over the degree of each variable)

Both theory and experimentation show that on multicore architecture, equal dimensional bivariate polynomials are fastest (compared to unbalanced), and when the dimensions are larger

do speculative operations take place on GPU? problems related to cache misses occur, nonetheless

"Pragmatic approach"
1. Draft Implementation
2. Measure experimentally, what is the effective memory bandwidth

input and output has GMP computation, but the intermediaries use machine word operations 

