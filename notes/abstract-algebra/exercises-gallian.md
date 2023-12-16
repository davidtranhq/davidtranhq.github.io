---
order: 2000
layout: default
toc: true
---

# Exercises (Gallian)

## Chapter 9

### 24

Let $H = \langle(2, 2)\rangle = \lbrace (0, 0), (2, 2), (0, 4), (2, 6), (0, 8), (2, 10) \rbrace$.
$(0, 1) + H$ is of order 4, so the factor group is not $\mathbb Z_2 \times \mathbb Z_2 \times \mathbb Z_2$.
There are no elements of order 8. So it is $\mathbb Z_4 \times \mathbb Z_2$.

## Chapter 12

### 3
$\left\langle \begin{bmatrix}1 & 1 \\ 0 & 1\end{bmatrix}\right\rangle$ generates an additive subgroup of real 2x2 matrices, but $\begin{bmatrix}1 & 1 \\ 0 & 1\end{bmatrix}^2 = \begin{bmatrix}1 & 2 \\ 0 & 1\end{bmatrix} \not\in \left\langle \begin{bmatrix}1 & 1 \\ 0 & 1\end{bmatrix}\right\rangle$.

### 5
We use the fact that the subring properties hold if subtraction and multlipliation is closed.

(a) is a subring since the difference and product of even integers are even.

(b) is equivalent to the polynomials whose coefficient of $x$ is 0.
This is a subring since it is closed under subtraction and multiplication.
To see closure under multiplication, note that an $x$ term generate from a product requires
multiplication of 2 terms with degree less than 1, which doesn't exist.

(c) is not since it is not closed under multiplication: $x$ is in the subset but $x^2$ is not.

### 7

(a) In $\mathbb Z_p$ every element but $0$ has a multiplicative inverse.
If $a = 0$ we are done. Otherwise $a^2 = a \implies a = 1$
(left multipying by $a^{-1}$).

(b) If $a \neq 0$ then $ab = 0 \implies b = 0$ by left-multiplication of $a^{-1}$.
Likewise for $b \neq 0$.

(c) Left multiplication by $a^{-1}$.

### 13
$k\mathbb Z \subseteq \mathbb Z$ for $k \in \mathbb Z$ is a subring, since it is closed under
subtraction and multiplication. To see this, let $ka. kb \in k\mathbb Z$.
Then $ka - kb = k(a - b) \in k\mathbb Z$, and $(ka)(kb) = k(kab) \in k\mathbb Z$.

### 28

$4 \mid 2$ since $4 \cdot 2 = 8 \bmod 6 \equiv 2$.

$3 \mid 7$ since $3 \cdot 5 = 15 \bmod 8 \equiv 7$.

$9 \mid 12$ since $9 \cdot 3 = 27 \bmod 15 \equiv 12$.

### 30

The multiplicative inverse of $(1 - a)$ is $(1 + a + \dots + a^{n - 1})$, since
$(1 - a)(1 + a + \dots + a^{n - 1}) = 1 + a^n = 1$.

### 32
Let $m \gt 0$ and suppose $a^m = 0$ for some $a$. If $m = n$ we are done.
Suppose $m \lt n$. Then $n = qm + r$. So $a^n = a = a^{qm}a^r = 0$.
If instead $n \lt m$ then choose $k$ such that $m \lt n^k$. Since $a^n = a$,
$a^{n^2} = (a^n)^n = a^n = a$, and so on for $a^{n^k}$. So apply the $m \lt n$ case to $m \lt n^k$.

### 54
Since $a$ is a unit, $a = bc \implies 1 = a^{-1}bc$, so $c^{-1} = a^{-1}b$.
Similarily, $b^{-1} = ca^{-1}$.

### 56
Note that $a + a = 0$ since $a + a = (a + a)^2 = a^2 + a^2 + a^2 + a^2 = a + a + a + a$.
So $x + y = (x + y)^2 = x^2 + xy + yx + y^2 = x + y + xy + yx$, so $xy + yx = 0$.
Thus $xy + xy + yx = xy$, but since $xy + xy = 0$, $yx = xy$.

## Chapter 13

### 3
Let $R$ be a commutative ring such that for $a, b, c \in R$ and $a \neq 0$,
$ab = ac$ implies $b = c$. Then there are no zero-divisors. For if there were one, say $d$, with
non-zero $x \in R$ such that $dx = 0$,

## Chapter 18

###