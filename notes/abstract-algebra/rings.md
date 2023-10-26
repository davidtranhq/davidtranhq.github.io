---
layout: default
order: 2
toc: true
---

# Rings

**Definition**: A **ring** is a set $R$ with two binary operations: addition, written $+$, and multiplication, written $\cdot$, subject to 6 axioms:
1. $(a + b) + c = a + (b + c)$ for all $a, b, c \in R$
2. There is an element $0 \in R$ such that for every $a \in R$, $a + 0 = a = 0 + a$
3. For any $a \in R$, there is $-a \in R$ such that $a + (-a) = 0 = (-a + a)$
4. $a + b = b + a$ for all $a, b \in R$
5. $(ab)c = a(bc)$ for all $a, b, c \in R$
6. $a(b + c) = ab + ac$ and $(a + b)c = ac + bc$ for all $a, b, c \in R$ (**distributivity**)

**Remark**: 
* $(R, +)$ is an abelian group (by (1)-(4)).
* $0$ and additive inverses are unique.

**Definition**: A ring $R$:
* has **unity** if there is $1 \in R$ such that $1 \cdot a = a = a \cdot 1$ for all $a \in R$
* is **commutative** if $a \cdot b = b \cdot a$ for all $a, b \in R$

**Remark**: The identity of a unitary ring is unique.

**Example**:
* $\mathbb Z$ with $+$ and $\cdot$ forms a ring and is commutative with unity.
* $\mathbb Q, \mathbb R, \mathbb C$ with $+$ and $\cdot$ are all rings with commutative and unity.
* $\mathbb Z[x] =$ set of polynomials with integer coefficients is a commutative ring with unity given by constant polynomial 1.
* Similarily, $\mathbb Q[x], \mathbb R[x], \mathbb C[x]$ are commutative iwth unity 1.
* $\mathbb Z_n$ with $+_n$ and $\cdot_n$, commutative with unity 1
* $M_{n \times n}(\mathbb R)$ with addition and multiplication of matrices is not commutative with unity $I_n = \begin{bmatrix} 1 & 0 \\ 0 & 1\end{bmatrix}$.
* $M_{n \times n}(R)$ is a ring for any ring $R$ (has unity if and only if $R$ has unity)
* $R[x]$ is a ring for any ring $R$.
* $2 \mathbb Z$ is a commutative ring without unity

**Definition**: The **product** of rings $R_1, R_2$ is the ring $R_1 \times R_2 = \lbrace (r_1, r_2) \mid r_1 \in R_1, r_2 \in R_2 \rbrace$ with

$$
\begin{align*}
(r_1, r_2) + (r_1', r_2') &= (r_1 + r_1', r_2 + r_2') \\
(r_1, r_2) \cdot (r_1', r_2') &= (r_1r_1' + r_2r_2')
\end{align*}
$$

**Proposition**: Let $R$ be a ring. Then,
1. $a \cdot 0 = 0 = 0 \cdot a$ for all $a \in R$
2. $(-a) \cdot b = - a\cdot b = a \cdot (-b)$
3. $(-a) \cdot (-b) = a \cdot b$

*Proof*: (1) For $a \in R$, $a \cdot 0 = a \cdot (0 + 0) = a \cdot 0 + a \cdot 0$, and since $a \cdot 0 = a \cdot 0 + 0$, by Cancellation in the abelian group $(R, +)$, $a \cdot 0 = 0$.

(2) For $a, b \in R$, we have $ab + (-a)b = (a + (-a))b = 0 \cdot b = 0 = ab + (-ab)$, so by Cancellation in the abelian group $(R, +)$, $(-a)b = -ab$.

(3) TODO.

**Definition**: Let $R$ be a ring with unity 1. An element $a \in R$ is a **unit** if there is an element $b \in R$ such that $ab = ba = 1$.

**Example**:
* In $\mathbb Z: 1, -1$
* In $\mathbb Z_3: 1, 2$
* In $\mathbb Z_4: 1, 3$
* In $\mathbb Z_{10}: 1, 3, 7, 9$
* In $\mathbb Z_n$: all $k$ with $\gcd(k, n) = 1$
* In $\mathbb Q$: all non-zero elements
* In $\mathbb R$: all non-zero elements
* In $\mathbb C$: all non-zero elements
* In $M_{n \times n}(\mathbb R)$: invertible matrices ($\det \neq 0$)
* In $\mathbb R[x]$: non-zero constant polynomials

**Definition**: Let $R$ be a ring. A subset $S \subseteq R$ is a **subring** if
1. $a + b \in S$ for all $a, b \in S$
2. $0 \in S$
3. $-a \in S$ for all $a \in S$
4. $a \cdot b \in S$ for all $a, b \in S$

**Example**:
* $\mathbb Z[x]$ is a subring of $\mathbb Q[x]$.
* $2 \mathbb Z$ is a subring of $\mathbb Z$.

**Remark**: Units and multiplicative identities do not necessarily hold in the subring.

**Definition**: Let $R$ be a ring. A non-zero element $a \in R$ is a **zero divisor** if there is a non-zero element $b \in R$ such that $ab = ba = 0$.

**Example**:
* $\mathbb Z$: nothing
* $\mathbb Q, \mathbb R, \mathbb C$: nothing
* $\mathbb Z_4: 2$
* $\mathbb Z_{10}: 2, 4, 5, 6, 8$
* $\mathbb Z_n$: all $k \neq 0$ with $\gcd(k, n) \gt 1$

**Definition**: An **integral domain** is a commutative ring with unity $1 \neq 0$ without zero divisors.

**Example**: $\mathbb Z, \mathbb Q, \mathbb R, \mathbb C, \mathbb Z_p$, $\mathbb R[x], \mathbb Q[x], \mathbb C[x], \mathbb Z[x]$, not $\mathbb Z_n$.