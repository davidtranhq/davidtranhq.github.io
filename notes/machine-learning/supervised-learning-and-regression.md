---
layout: default
order: 1
toc: true
---

# Supervised Learning and Regression

**model**: function relating $x$ to $y$, optionally parameterized by parameters $\bm \theta$

## Loss Functions

**residuals**: error of the model (can have positive or negative residual)

**least absolute deviation**: the $L_1$-norm of the magnitudes of residuals

$$
    L(\theta) 
    = \sum_{i = 1}^n \vert y_i - \hat y_i \vert 
    = \sum_{i = 1}^n \vert r_i \vert
    = \vert \vert \bm r \vert \vert_1
$$

**ordinary least squares**: the sum of squared residuals: the squared $L_2$-norm

$$
    L(\theta) = \sum_{i = 1}^n (y_i - \hat y_i)^2 = \sum_{i = 1}^n r^2_i = \vert \vert \bm r \vert \vert _2^2
$$

* OLS is more commonly used because errors are usually normally distributed, and big errors are weighted more heavily than small errors


