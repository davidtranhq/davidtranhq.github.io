---
layout: default
order: 7
---

# Point Estimation

---
Recall:
* a **parameter** is a descriptive measure of an unknown probability distribution.
* a **statistic** is a descriptive measure of a sample

---

**Definition**: A **point estimate** of a parameter $\theta$ is a single number that can be regarded as a sensible value for $\theta$.

**Definition**: A **point estimator** is a selected statistic from given sample data used to generate a point estimate.

**Example**: Suppose we have some random sample $X$ from a (suspected) symmetric normal distribution with unknown mean $\mu$. $\bar X, \tilde X, \bar X_e$, and $\bar X_{tr(1)}$ are all estimators for $\mu$, which generate point estimates $\bar x, \tilde x, \bar x_e, \bar x_{tr(10)}$, respectively.

Note: The exact value of a parameter can only be determined from the entire population. Any statistic derived from some sample of the population is only a parameter estimate.

**Definition**: The bias of an estimator $\hat \theta$ is $\mathbb E(\hat \theta) - \theta$.

**Definition**: The **mean squared error** of an estimator $\hat \theta$ is

$$
    MSE_{\hat \theta} = \mathbb E[(\hat \theta - \theta)^2]
$$

**Theorem**: For any estimator $\hat \theta$, $MSE_{\hat \theta} = V(\hat \theta) + [\mathbb E(\hat \theta) - \theta]^2$, that is, the variance of $\hat \theta$ plus the bias squared.

*Proof*: TODO. $\blacksquare$

**Example**: Let $\hat p = \frac{X + \sqrt{\frac{n}{4}}}{n + \sqrt n}$ be an estimator for the population proportion of successes, where successes are indepedent for some sample $X$ of size $n$. Determine it's MSE.

We have

$$
\mathbb E[\hat p] = \frac{np + \sqrt{\frac{n}{4}}}{n + \sqrt n}
$$ 

and 

$$
V(\hat p) = \frac{V(X) + 0}{(n + \sqrt n)^2} = \frac{np(1 - p)}{(n + \sqrt n)^2}
$$

(recall $V(aX) = a^2V(X)$) since $X$ is binomially-distributed with variance $np(1 - p)$ and expectation $np$. So

$$
\begin{align*}
    MSE_{\hat p} = V(\hat p) + \mathbb E[\hat p - p]^2 = \frac{1}{4(\sqrt n + 1)^2}
\end{align*}
$$

Compared to the usual estimator $\hat p_0 = \frac{X}{n}$ (the sample proportion),

$$
\begin{align*}
    MSE_{\hat p_0} = \frac{p(1 - p)}{n} + \mathbb E[p - p] = \frac{p(1 - p)}{n}
\end{align*}
$$

we see that for certain values of $p$, $\hat p$ performs better or worse:

<!-- #region drawnote -->
<svg id="svg" xmlns="http://www.w3.org/2000/svg" viewbox="127.86000061035156,23.56999969482422,219.99998474121094,177.1400146484375" style="height:177.1400146484375; display:block; margin:auto"><line x1="160" y1="60" x2="160" y2="180" fill="none" stroke="lightyellow" stroke-width="2" d="M 160 60 L 160 180"></line><line x1="160" y1="180" x2="300" y2="180" fill="none" stroke="lightyellow" stroke-width="2" d="M 160 180 L 300 180"></line><line x1="140" y1="140" x2="320" y2="140" fill="none" stroke="lightgreen" stroke-width="2" d="M 140 140 L 320 140"></line><path d="M 331.9,135.71 L 331.67,136.43 L 331.67,137.38 L 331.67,138.33 L 331.67,140.24 L 331.67,140.71 L 331.67,141.67 L 332.14,145 L 332.14,145.95 L 332.62,146.9 L 332.62,147.38 L 332.62,147.86 L 332.62,148.81 L 332.62,149.76 L 332.62,150.71 L 332.62,151.19 L 333.1,152.14 L 332.62,151.67 L 332.62,148.81 L 332.14,146.9 L 332.14,145 L 332.14,143.1 L 332.14,139.76 L 332.14,137.86 L 332.14,136.9 L 332.14,136.43 L 332.14,135.95 L 332.14,135.48 L 332.14,135 L 332.62,135 L 333.1,135 L 334.05,135 L 334.52,135.48 L 335.48,136.43 L 335.95,136.9 L 336.43,137.38 L 336.43,137.86 L 336.9,137.86 L 336.9,138.33 L 337.38,138.81 L 337.38,139.29 L 337.38,139.76 L 337.38,140.24 L 337.38,140.71 L 337.38,141.19 L 337.38,141.67 L 337.38,142.14 L 336.9,142.62 L 336.43,143.1 L 335.95,143.57 L 335.48,143.57 L 335,144.05 L 334.52,144.52 L 334.05,144.52" fill="none" stroke="lightgreen" stroke-width="2"></path><path d="M 330.95,127.62 L 330.71,125.95 L 330.71,125.48 L 331.19,125.48 L 331.19,125 L 331.19,124.05 L 331.67,124.05 L 332.14,123.57 L 332.62,123.57 L 333.57,124.05 L 334.05,124.52 L 334.52,125 L 334.52,125.48 L 335,126.9 L 335.48,126.9 L 335.48,127.38 L 335.95,127.38 L 336.43,127.86 L 336.9,128.81 L 337.38,128.81 L 337.86,129.76" fill="none" stroke="lightgreen" stroke-width="2"></path><path d="M 160.95,180 L 161.19,178.81 L 161.67,178.33 L 161.67,176.43 L 162.62,174.52 L 163.57,173.1 L 165,169.29 L 165,168.81 L 165.48,165.48 L 165.95,164.52 L 166.43,163.57 L 166.43,162.62 L 166.9,161.67 L 166.9,161.19 L 167.86,158.81 L 168.33,157.86 L 170.24,155.95 L 170.71,155 L 171.67,153.57 L 171.67,153.1 L 172.14,152.14 L 173.1,150.24 L 173.57,149.29 L 175,147.38 L 175.48,146.43 L 175.95,145.48 L 176.43,145 L 177.86,144.05 L 177.86,143.57 L 178.33,143.1 L 178.33,142.62 L 178.81,141.67 L 179.76,140.71 L 180.24,139.76 L 180.71,139.29 L 181.19,138.33 L 181.67,137.38 L 182.62,136.9 L 183.57,135.48 L 186.43,133.57 L 186.9,133.1 L 188.33,131.67 L 189.29,131.67 L 189.29,131.19 L 190.24,130.71 L 190.71,130.24 L 191.67,128.81 L 192.14,128.81 L 192.62,128.33 L 193.57,127.86 L 195.48,126.43 L 196.43,125.95 L 196.9,125.48 L 197.38,125.48 L 197.86,125 L 198.33,125 L 200.24,124.05 L 200.71,124.05 L 201.19,124.05 L 201.67,124.05 L 202.14,124.05 L 203.57,123.1 L 204.52,123.1 L 206.9,122.62 L 207.38,122.14 L 207.86,122.14 L 208.33,121.67 L 208.81,121.19 L 211.19,120.71 L 212.14,120.71 L 215,120.71 L 216.9,120.71 L 218.33,120.24 L 218.81,120.24 L 219.29,120.24 L 219.76,120.24 L 220.71,120.24 L 222.14,120.24 L 223.1,120.24 L 224.05,120.24 L 224.52,120.24 L 225.95,120.24 L 226.43,120.24 L 226.9,120.24 L 227.86,120.24 L 228.33,120.24 L 229.76,120.24 L 231.19,120.24 L 232.14,120.24 L 233.1,120.24 L 234.52,120.24 L 235.48,120.24 L 235.95,120.24 L 236.43,120.24 L 238.33,120.24 L 238.81,120.71 L 240.71,121.67 L 243.1,122.14 L 244.05,122.14 L 244.52,122.62 L 245,122.62 L 245.48,123.1 L 246.9,123.57 L 247.86,124.05 L 249.76,125 L 250.24,125 L 251.67,125.48 L 252.14,125.95 L 252.62,126.43 L 255,128.33 L 255.95,128.81 L 259.29,130.71 L 260.71,131.67 L 261.67,132.62 L 262.14,133.1 L 262.62,133.57 L 263.57,134.05 L 263.57,134.52 L 264.52,135.48 L 265.48,136.43 L 266.43,137.38 L 266.9,137.86 L 267.86,138.33 L 268.33,139.29 L 269.76,140.71 L 271.67,142.62 L 272.62,143.57 L 275.48,146.43 L 275.95,146.9 L 276.43,147.38 L 277.86,147.86 L 278.81,149.29 L 279.76,150.24 L 280.71,150.71 L 281.19,151.67 L 281.67,152.14 L 282.62,152.62 L 282.62,153.57 L 283.57,154.52 L 284.52,155.48 L 285.48,156.43 L 285.95,156.43 L 287.38,157.86 L 288.33,158.81 L 288.81,158.81 L 288.81,159.29 L 289.76,160.24 L 290.24,160.71 L 291.19,162.62 L 291.19,163.1 L 292.62,164.05 L 293.1,165.48 L 294.52,167.38 L 295,167.86 L 295.95,169.76 L 296.43,170.24 L 296.43,170.71 L 296.9,171.19 L 296.9,171.67 L 297.38,172.14 L 297.86,172.62 L 298.33,174.05 L 298.81,174.52 L 298.81,175 L 299.29,176.9 L 299.76,176.9 L 299.76,177.38 L 300.71,178.81" fill="none" stroke="lightblue" stroke-width="2"></path><path d="M 264.76,106.67 L 264.52,107.86 L 264.52,108.33 L 265,109.76 L 266.43,112.62 L 267.86,117.86 L 267.86,118.81 L 268.33,122.14 L 268.33,123.1 L 268.81,125.48 L 268.81,125.95 L 268.81,126.43 L 268.81,124.52 L 268.33,122.62 L 267.86,119.29 L 267.38,117.38 L 266.9,113.57 L 266.9,112.62 L 266.9,112.14 L 266.43,110.71 L 265.95,110.24 L 265.95,109.76 L 265.95,108.81 L 265.95,108.33 L 265.95,107.86 L 266.43,107.38 L 266.9,107.38 L 267.38,106.43 L 267.86,106.43 L 268.33,106.43 L 268.81,106.43 L 269.29,106.43 L 270.24,106.43 L 271.19,106.9 L 271.67,107.38 L 272.14,107.86 L 272.14,108.33 L 272.62,108.81 L 273.1,109.29 L 273.1,109.76 L 273.57,110.71 L 273.57,111.19 L 273.57,111.67 L 273.57,112.14 L 273.57,113.1 L 273.57,113.57 L 273.57,114.05 L 273.1,114.52 L 273.1,115 L 272.62,115.48 L 272.14,115.48 L 271.67,115.48 L 270.71,115.48 L 270.24,115.48 L 269.29,115.95" fill="none" stroke="lightblue" stroke-width="2"></path><path d="M 265.71,99.52 L 265.48,98.81 L 265.48,98.33 L 265.48,97.86 L 265.48,97.38 L 265.48,96.9 L 265.48,95.95 L 265.48,95.48 L 265.48,95 L 265.95,94.05 L 266.43,93.57 L 266.9,93.57 L 267.86,95.48 L 268.81,95.95 L 269.76,98.33 L 270.24,98.81 L 271.19,99.76 L 271.19,100.24 L 271.67,100.71 L 271.67,101.19 L 271.67,102.14 L 271.67,103.1" fill="none" stroke="lightblue" stroke-width="2"></path><path d="M 281.9,117.14 L 281.67,116.43 L 280.71,116.43 L 280.24,116.9 L 280.24,117.38 L 279.76,117.38 L 279.76,117.86 L 279.29,118.33 L 279.29,118.81 L 279.29,119.29 L 279.29,119.76 L 279.29,120.24 L 279.29,120.71 L 279.29,121.67 L 279.29,122.14 L 279.29,122.62 L 279.76,122.62 L 280.24,122.62 L 281.67,122.62 L 282.14,122.62 L 282.62,122.62 L 283.1,122.62 L 284.05,122.14 L 284.05,121.67 L 284.05,121.19 L 284.52,121.19 L 284.52,120.71 L 284.52,119.76 L 284.52,119.29 L 285,119.29 L 285,118.81 L 285,117.86 L 284.52,117.38 L 284.52,116.9 L 284.05,116.9 L 283.57,116.43 L 283.1,116.43 L 282.62,116.43 L 282.14,116.43 L 281.67,116.43" fill="none" stroke="lightblue" stroke-width="2"></path><path d="M 319.05,176.19 L 318.81,176.9 L 318.81,177.86 L 318.81,178.33 L 318.81,178.81 L 318.81,179.76 L 318.81,180.71 L 318.81,181.67 L 318.81,182.62 L 318.81,184.05 L 318.81,184.52 L 318.81,186.43 L 318.81,187.38 L 318.81,187.86 L 318.81,188.33 L 318.81,188.81 L 318.81,189.76 L 318.81,190.24 L 318.81,190.71 L 318.81,189.76 L 318.33,188.81 L 318.33,186.43 L 318.33,183.57 L 318.33,182.62 L 317.86,181.67 L 317.86,181.19 L 317.86,180.71 L 317.86,179.76 L 317.86,179.29 L 317.86,178.81 L 317.86,177.86 L 318.33,177.38 L 318.81,177.38 L 319.29,176.9 L 319.76,176.9 L 320.24,176.9 L 320.71,176.9 L 321.19,176.9 L 321.67,176.9 L 322.14,176.9 L 323.1,176.9 L 323.57,176.9 L 324.05,176.9 L 324.52,177.38 L 324.52,177.86 L 325,177.86 L 325.48,178.33 L 325.95,178.81 L 326.43,179.29 L 326.43,179.76 L 326.43,180.71 L 326.43,181.19 L 326.43,181.67 L 326.43,182.62 L 326.43,183.57 L 326.43,184.05 L 325.95,184.52 L 325.48,185 L 325,185 L 324.05,185.48 L 323.57,185.95 L 323.1,185.95 L 322.62,185.95 L 322.14,185.95 L 321.67,185.95 L 321.19,185.95 L 320.24,185.95 L 319.76,185.95 L 319.29,185.95 L 319.29,186.43" fill="none" stroke="lightyellow" stroke-width="2"></path><path d="M 140.48,54.29 L 139.76,54.05 L 139.29,52.14 L 139.29,50.71 L 139.29,47.86 L 139.29,45 L 138.81,40.24 L 138.33,38.33 L 137.86,36.43 L 137.86,35.48 L 137.86,35 L 138.33,35 L 138.81,35.95 L 140.71,37.86 L 141.67,39.76 L 142.62,40.71 L 143.1,41.19 L 143.57,41.67 L 144.05,42.14 L 144.52,42.62 L 144.52,43.57 L 145.48,44.05 L 145.48,42.62 L 145.48,39.29 L 145.48,38.33 L 145.95,37.38 L 146.43,36.43 L 147.38,35 L 147.86,34.52 L 148.33,34.52 L 148.33,35 L 148.81,35.95 L 149.29,38.81 L 149.76,40.24 L 150.24,42.14 L 151.19,44.52 L 151.19,45 L 151.67,46.9 L 152.62,47.86 L 152.62,48.33 L 152.62,49.29 L 152.62,49.76 L 153.1,50.71 L 153.1,51.67 L 153.1,52.62 L 153.1,53.1" fill="none" stroke="lightyellow" stroke-width="2"></path><path d="M 165.71,35.24 L 165.71,34.76 L 165,34.05 L 165,33.57 L 164.52,33.57 L 163.57,33.57 L 162.62,33.57 L 161.19,33.57 L 160.71,33.57 L 159.76,33.57 L 158.81,33.57 L 157.86,34.05 L 157.38,34.05 L 157.38,34.52 L 157.38,35 L 157.38,35.95 L 157.38,36.43 L 157.38,37.38 L 157.38,37.86 L 157.38,38.33 L 157.86,38.81 L 158.33,39.76 L 158.81,40.24 L 159.29,40.24 L 160.71,41.19 L 161.19,41.19 L 162.62,42.14 L 163.1,42.62 L 163.57,42.62 L 163.57,43.1 L 164.52,44.05 L 164.52,44.52 L 165,45.48 L 165.48,45.95 L 165.48,46.9 L 165.48,47.38 L 165.48,47.86 L 165.48,48.33 L 165,49.29 L 164.52,49.29 L 164.05,49.76 L 163.57,49.76 L 162.62,49.76 L 162.14,50.24 L 161.67,50.24 L 161.19,50.24 L 160.24,50.24 L 159.76,50.24 L 159.29,50.24 L 158.81,50.24 L 158.33,50.24" fill="none" stroke="lightyellow" stroke-width="2"></path><path d="M 181.43,35.24 L 180.71,35 L 180.24,35 L 179.76,35 L 179.29,35 L 178.81,35 L 177.86,35 L 175.95,35 L 174.52,35 L 174.05,35 L 173.57,35.48 L 173.57,35.95 L 173.57,36.9 L 173.57,39.29 L 173.57,39.76 L 173.57,44.05 L 174.05,46.9 L 174.52,50.24 L 174.52,50.71 L 174.52,51.19 L 175,53.1 L 175,53.57 L 175.95,54.52 L 176.43,55 L 179.76,55 L 181.67,55 L 182.62,55 L 183.1,55 L 183.57,55 L 184.05,55 L 184.05,54.52" fill="none" stroke="lightyellow" stroke-width="2"></path><path d="M 174.29,46.19 L 175.95,45.95 L 177.38,45.95 L 178.33,46.43 L 180.24,46.43" fill="none" stroke="lightyellow" stroke-width="2"></path></svg>  
<!-- #endregion -->

**Definition**: A point estimator $\hat \theta$ is an **unbiased estimator** of $\theta$ if its bias is 0.

**Proposition**: When $X$ is a binomial random variable with parameters $n, p$, the sample proportion $\hat p = \frac{X}{n}$ is an unbiased estimator of $p$.

*Proof*: $\mathbb E[\hat p] - p = \frac{np}{n} - p = 0$. $\blacksquare$.

**Example**: The sample standard deviation $S^2 = \frac{\sum_i (X_i - \bar X)^2}{n - 1}$ is unbiased.

*Proof*: TODO. $\blacksquare$

**Proposition**: If $X_1, X_2, \dots, X_n$ is a random sample from a distirbution with mean $\mu$, then
1. $\bar X$ is an unbiased estimator of $\mu$.
1. If the distribution is also continuous and symmetric, then $\tilde X$ and any trimmed mean are also unbiased estimators of $\mu$. 

*Proof*:
1. $\mathbb E[\bar X] = \mathbb E[ \frac{\sum_i X_i}{n}] = \frac{1}{n}\mathbb E [\sum_i \mu] = \frac{1}{n} n\mu = \mu$, so $\mathbb E[\bar X] - \mu = 0$.

2. TODO. $\blacksquare$

**Example**: Let $X_1, \dots X_n$ be $n$ independent samples from a distirbution with mean $\mu$. Each sample has mean $\mu$ (unbiased sample) and variance $\sigma^2$.

Show that $\bar X^2$ is a biased estimate for $\mu^2$.

*Proof*: We have $\mathbb E[\bar X^2] = V(\bar X) + \mathbb E[\bar X]^2 = \frac{\sigma^2}{n} + \mu^2 \neq \mu^2$, so $\bar X^2$ is biased. $\blacksquare$

For what value of $k$ is the estimator $\bar X^2 - kS^2$ unbiased for $\mu^2$?

*Solution*:

$$
\begin{align*}
    \mathbb E[\bar X^2 - kS^2] &= \frac{\sigma^2}{n} + \mu^2 - k\sigma^2 \\
    &= \sigma^2 (\frac{1}{n} - k) + \mu^2 \\
    &= \mu^2 
\end{align*}
$$

when $k = \frac{1}{n}$. $\blacksquare$

**Definition (Principle of Minimum Variance Unbiased Estimation)**: Choose the estimator $\hat \theta$ with the minimum variance among all unbiased estimators: the **minimum variance unbiased estimator (MVUE)**. Since $MSE = V(\hat \theta) + \operatorname{bias}^2$, this minimizes the mean squared error.

**Theorem**: Let $X_1, \dots, X_n$ be a random sample from a normal distribution with parameters $\mu$ and $\sigma$. Then the estimator $\hat \mu = \bar X$ is the MVUE for $\mu$.

*Proof*: TODO. $\blacksquare$.

Note that this is true only for the normal distribution: the MVUE is different (or may not exist) for different distributions.

**Definition**: The **standard error** of an estimator $\hat \theta$ is its standard deviation $\sigma_{\hat \theta} = \sqrt{V(\hat \theta)}$.

Note: the standard error can itself be unknown, yielding a standard error estimator $\hat \sigma_{\hat \theta}$.

**Example**: Consider random samples $X_1, \dots, X_m$ and $Y_1, \dots, Y_n$ from distributions with means $\mu_1, \mu_2$ and standard deviations $\sigma_1, \sigma_2$, respectively. 

Show that $\bar X - \bar Y$ is an unbiased estimator of $\mu_1 - \mu_2$.

*Proof*: $\mathbb E[\bar X - \bar Y] = \mathbb E[\bar X] - \mathbb E[\bar Y] = \mu_1 - \mu_2$. $\blacksquare$

Find the variance and standard deviation of $\bar X - \bar Y$.

*Solution*: $V(\bar X - \bar Y) = V(\bar X) + V(\bar Y) = \frac{\sigma_1^2}{m} + \frac{\sigma_2^2}{n}$. So $\sigma_{\bar X - \bar Y} = \sqrt{V(\bar X - \bar Y)}$. $\blacksquare$.

## Bootstrap

The **bootstrap** is a method for numerically computing $\sigma_{\hat \theta}$ for some estimator $\hat \theta$.

### Parametric Bootstrap

Suppose the population pdf is $f(x; \theta)$.
1. Compute a point estimate $\hat \theta$ from the data $x_1, \dots, x_n$.
1. Sample $B$ bootstrap samples from $f(x; \hat \theta)$.
1. Calculate bootstrap estimates $\hat \theta_1^*, \dots, \hat \theta_B^*$ for each bootstrap sample.
1. Compute the sample mean of the boostrap estimates $\bar \theta^* = \sum \frac{\hat \theta_i^*}{B}$

The **boostrap estimate** of $\sigma_{\hat \theta}$ is then

$$
    S_{\hat \theta} = \sqrt{\frac{1}{B - 1}\sum (\hat \theta^*_i - {\bar \theta^*})^2}
$$

### Non-Parametric Bootstrap

The non-parametric bootstrap is the same as the parametric bootstrap, except bootstrap samples are sampled randomly from the original data $x_1, \dots, x_n$. 

## The Method of Moments

**Definition**: Let $X_1, \dots, X_n$ be a random sample from $f(x)$.
* $\mathbb E[X^k]$ is the **kth population moment** (**kth moment of the distribution $f(x)$**)
* $\frac{1}{n}\sum_{i =1}^n X_i^k$ is the **kth sample moment**

**Definition**: Let $X_1, \dots, X_n$ be a random sample from a distribution with unknown parameters $f(x; \theta_1, \dots, \theta_m)$. The **moment estimators** $\hat \theta_1, \dots, \hat \theta_m$ are obtained by equating the first $m$ population moments with the first $m$ sample moments.

**Example**: Let $X_1, \dots, X_n$ be a random sample from an exponential distribution with parameter $\lambda$. Find the moment estimator $\hat \lambda$.

*Solution*: The first population moment is $\mathbb E[X] = \frac{1}{\lambda}$. The first sample moment is $\bar X$. Setting them to be equal, we have $\frac{1}{\lambda} = \bar X \implies \lambda = \frac{1}{\bar X}$. So, the moment estimator $\hat \lambda = \frac{1}{\bar X}$. $\blacksquare$.

**Example**: Let $X_1, \dots, X_n$ be a random sample from a gamma distribution with parameters $\alpha, \beta$. Find the moment estimators $\hat \alpha, \hat \beta$.

*Solution*: The first and second population moments are $\mathbb E[X] = \alpha\beta$ and $\mathbb E[X^2] = V(X) + \mathbb E[X]^2 = \alpha\beta^2 + \alpha^2\beta^2$. The first and second sample moments are $\bar X$ and $\frac{1}{n} \sum X_i^2 = TODO.$
