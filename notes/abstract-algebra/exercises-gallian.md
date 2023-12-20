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

## Chapter 17

### 2
$f(x)$ factored in $D$ factors into units in $F$.

### 3
Suppose it wasn't primitive. Then Then its content is greater than 1, so it is not a unit in $\mathbb Z$, and can be factored out.

### 4

Since $r = p/q$ is a root, then

$$
\frac{p^n}{q^n} + a_{n - 1}\frac{p^{n - 1}}{q^{n - 1}} + \dots + a_0 = 0
$$

Multiplying both sides by $q^n$ we have

$$
p^n + a_{n - 1}qp^{n - 1} + \dots + q_na_0 = 0
$$

So $q \mid p^n$. Since $\gcd(p, q) = 1$, $\gcd(p^n, q) = 1$, so $q = 1$.

### 5

(a) If $f(x) = g(x)h(x)$, then $af(x) = ag(x)h(x)$, with $g(x), h(x)$ non-units. $\blacksquare$

(b) If $f(ax)$ is irreducible, then $f(ax) = g(ax)h(ax)$, where either $g$ or $h$ is a unit polynomial (constant). Then for $f(x) = g(x)h(x)$, either $g$ or $h$ is a unit polynomial. $\blacksquare$

(c) Same proof as above. $\blacksquare$

(d) Since $f(x + 1) = 8x^3 + 24x^2 + 18x + 3$, by Eisenstein's Criterion with $p = 3$, $f(x + 1)$ is irreducible. So $f(x)$ is irreducible. $\blacksquare$

### 11

By the theorem that states $\mathbb Z_p[x] / \langle f(x) \rangle$ is a field with $p^n$ elements. where $f(x)$ is a polynomial of degree $n$, $\mathbb Z_5[x]/\langle x^2 + 1 \rangle$ is a field with 25 elements.

### 12

Similar to 11, $\mathbb Z_3[x]/\langle x^3 - 2 \rangle$.

### 14

(a) Irreducible by Eisenstein's with $p = 3$.

(b) By Theorem 17.3 it suffices to check that this polynomial is irreducible over $\mathbb Z_2[x]$. $f(x) \neq 0 \pmod 2$ for $x = 0, 1$ so there are no linear factors. So both factors of $f(x)$ would have to be quadratic. But, none of the 4 quadratic polynomials in $\mathbb Z_2[x]$ factor $f(x)$ (by polynomial long division), so it is irreducible in $\mathbb Z_2[x]$.

(c) Irreducible by Eistestein's with $p = 3$.

(d) Again, it suffices to check $x^5 + x^2 + 1 \in \mathbb Z_2[x]$ is irreducible.

(e) Multiply by 14 for $35x^5 + 63x^4 + 210 x^3 + 6x^2 + 84x + 3$, which is irreducible by Eisenstein's with $p = 3$. Since $af(x)$ is irreducible, $f(x)$ is irreducible.

### 21

Done in class: use Eisenstein's Criterion on $f(x + 1)$.

### 23

$f(1) = 0$ so $(x - 1)$ is a factor. Then by polynomial long division, $f(x) = (x - 1)(x^2 + x + 1)$. To verify,

$$
(x - 1)(x^2 + x + 1) = x^3 + x^2 + x - x^2 - x - 1 = x^3 - 1 = x^3 + 6
$$
