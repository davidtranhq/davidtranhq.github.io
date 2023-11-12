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

**Definition**: A **field** is a commutative ring with unity $1 \neq 0$ such that every nonzero element is a unit.

**Remark**: Every field is an integral domain.

**Example**:
* $\mathbb Z$ is not a field, since $2$ is not a unit.
* $\mathbb Q$ is a field as for $a/b \in \mathbb Q$ where $a,b \in \mathbb Z$, $b \neq 0$, if $a/b \neq 0$, then $a \neq 0$, so $b/a \cdot a/b = 1$.
* $\mathbb R, \mathbb C$
* $\mathbb Z_p$

**Theorem (Cancellation Law)**: Let $R$ be an integral domain and $a \in R$ a nonzero element. If $ab = ac$, then $b = c$ where $b, c \in R$.

*Proof*: TODO.

**Theorem**: If $D$ is a finite integral domain, then $D$ is a field.

*Proof*: Let $D = \lbrace a_1, \dots, a_n \rbrace$. For $b \in D$ nonzero, consider the list $ba, \dots, ba_n$. All elements are distinct by the Cancellation Law. In particular, $1 = ba_i$ for some $i$. So $a_i$ is the multiplicative inverse of $b$, making it a unit. $\blacksquare$

**Example**: $\mathbb Z[x]$ is an integral domain but ont a field, since $x \in \mathbb Z[x]$ is not a unit. Similarily, $\mathbb R[x], \mathbb Q[x], \mathbb C[x], \mathbb Z_p[x]$ are integral domains but not fields.

**Definition**: Let $R, S$ be rings. A **ring homomorphism** $f: R \to S$ is a function such that $f(r + r') = f(r) + f(r')$ and $f(rr') = f(r)f(r')$ for all $r, r' \in R$.

**Example**: 
* $q_n: \mathbb Z \to \mathbb Z_n$ given by $q_n(k) = k \bmod n$.
* $\operatorname{id}_R: R \to R$ for any ring $R$.
* $\operatorname{ev}_1: \mathbb Z[x] \to \mathbb Z$ given by $\operatorname{ev}_1(f(x)) = f(1)$
* $i: \mathbb Z \to \mathbb Z[x]$ given by $i(k) = k$.
* $d: \mathbb Z \to \mathbb Z$ given by $d(k) = 2k$ is NOT a ring homomorphism since $d(1 \cdot 1) = d(1) = 2 \neq d(1)d(1) = 4$.

**Definition**: A ring homomorphism $f: R \to S$ is a **ring isomorphism** if there is a $g: S \to R$ a ring homomorphism such that $g \circ f = \operatorname{id}_R$ and $f \circ g = \operatorname{id}_S$.

**Proposition**: A ring homomorphism $f: R \to S$ is a ring isomorphism if and only if it is bijective.

*Proof*: $(\rightarrow)$ This follows from the analogous theorem for groups as $f$ is in part a group homomorphism.

$(\leftarrow)$ As $f$ is bijective and a group homomorphism, there is a group homomorphism $g: S \to R$ such that $g \circ f = \operatorname{id}_R$ and $f \circ g = \operatorname{id}_S$. It remains to show that $f$ is a ring homomorphism, that is, $g(ss') = g(s)g(s')$. As $f$ and $g$ are inverses, there are $r, r' \in R$ such that $f(r) = s, g(s) = r, g(s') = r'$, and $f(r') = s'$. Then

$$
g(ss') = g(f(r)f(r')) = (g \circ f)(rr') = r \circ r' = g(s)g(s')
$$

$\blacksquare$

**Definition**: The **kernel** of a ring homomorphism $f: R \to S$ is the set $\operatorname{Ker}(f) = \lbrace r \in R \mid f(r) = 0 \rbrace$.

**Lemma**: A ring homomorphism $f: R \to S$ is injective if and only if $\operatorname{Ker}(f) = \lbrace 0 \rbrace$.

*Proof*: This follows from the analagous fact from groups. $\blacksquare$

**Recall**: For a group $G$ and a normal subgroup $H$, we form $G/H = \lbrace aH \mid a \in H \rbrace$. This is a gruop with a binary operation given by $(aH)(bH) = (ab)H$.

For a ring $R$ and a subring $A$ we can form $R/A$, which is an abelian group with $(r + A) = (s + A) = (r + s) + A$, where $R/A = \lbrace r + A \mid r \in R \rbrace$, since $(R, +)$ is abelian, so it is normal. Note that in general, it is **not** a ring.

**Definition**: An **ideal** in a ring $R$ is a subset $I \subseteq R$ such that
1. $I$ is a subgroup of $(R, +)$.
2. For any $a \in I$ or $r \in R$, $ar, ra \in I$.

**Example**: Examples of ideals:
* $2 \mathbb Z, 3 \mathbb Z, n \mathbb Z \subseteq \mathbb Z$, for all $n \geq 0$
* For any ring $R$, $\lbrace 0 \rbrace$ and $R$ are ideals.

**Example**: Subrings that are not ideals:
* $\mathbb Z \subseteq \mathbb Q$

**Example**: Find a ring $R$ and subsets $I$ and $J$ such that $I \subseteq J \subseteq R$ and $I \subseteq J$ is an ideal, $J \subseteq R$ is an ideal, but $I \subseteq R$ is not an ideal.

TODO.

**Example**: Consider $\mathbb Z[x]$. Define $I = \lbrace a_nx^n + \dots + a_1 x \mid a_i \in \mathbb Z \rbrace \cup \lbrace 0 \rbrace$, that is, polynomials with constant term 0. Then $I$ is an ideal of $\mathbb Z[x]$.

**Definition**: For a subset $A \subseteq R$ of a ring $R$, let $\langle A \rangle$ be the smallest ideal containing $A$. It is called the **ideal generated by $A$**.

**Notation**: For $A \subseteq R$ with $R$ a ring, write

$$
AR = \lbrace a_1r_1 + \dots + a_nr_n \mid a_i \in A, r_i \in R \rbrace \\
RA = \lbrace r_1a_1 + \dots + r_na_n \mid a_i \in A, r_i \in R \rbrace
$$

**Remark**: If $R$ is commutative, then $AR = RA$.

**Proposition**: If $R$ is commutative, then $\langle A \rangle = AR$.

*Proof*: First, observe that $AR \subseteq \langle A \rangle$, as $ar \in \langle A \rangle$ for all $a \in A, r \in R$ since $\langle A \rangle$ is an ideal, and $\langle A \rangle$ is closed under addition. It remains to show that $AR$ is an ideal, since then because $\langle A \rangle$ is the smallest ideal, $\langle A \rangle \subseteq AR$. $AR$ is an ideal since $AR$ is an additive subgroup, and for $a_1 r_1 + \dots + a_n r_n \in AR$ and $r \in R$, we have $(a_1r_1 + \dots + a_nr_n)r = a_1(r_1)r + \dots + a_n(r_nr) \in AR$. $\blacksquare$

**Definition**: An ideal $I$ of a ring $R$ is **principal** if $I = \langle a \rangle$, that is, it is generated by a single element $a \in R$.

**Example**:
* $\lbrace 0 \rbrace$ is principal of any ring $R$.
* $n \mathbb Z = \langle n \rangle$ in $\mathbb Z$ is principal.
* $\langle x \rangle \subseteq \mathbb Z[x]$ is the principal ideal of polynomials with constant term 0.

**Example**: If $R$ ring with unity 1, then $R$ is a principal ideal of $R$ as $R = \langle 1 \rangle$, since for $r \in R$, we must have $r = r \cdot 1 \in \langle 1 \rangle$.

**Corollary**: If $1 \in I$, then $I = R$. 

**Proposition**: For any ring homomorphism $f: R \to S$, $\operatorname{Ker}(f)$ is an ideal.

*Proof*: Let $a \in \operatorname{Ker}(f)$ and $r \in R$. Then $f(ar) = f(a)f(r) = 0 \cdot f(r) = 0$. Moreover, $\operatorname{Ker}(f)$ is an additive subgroup. $\blacksquare$

**Example**: In $\mathbb Z[x]$, we have $\langle x \rangle, \langle 2 \rangle$, but we also have $\langle 2, x \rangle =$ polynomials with even coefficients or constant term = 0.

**Construction**: Given an ideal $I$ in a ring $R$, define multiplication on $R/I$ as 

$$
(r + I)(s + I) = rs + I
$$

**Lemma**: This is a well-defined binary operation.

*Proof*: Suppose $r + I = r' + I$ and $s + I = s' + I$. Then $r' = r + a$ and $s' = s + b$. for some $a, b \in I$. Then 

$$
\begin{align*}
(r' + I)(s' + I) 
&= r's' + I \\
&= (r + a)(s + b) + I
&= rs + rb + as + ab + i \\
&= rs + I
\end{align*}
$$
$\blacksquare$

**Theorem**: For a ring $R$ and an ideal $I$, the set $R/I$ is again a ring with $(r + I) = (s + I) = (r + s) + I$ and $(r + I)(s + I) = rs + I$.

*Proof*: The first four ring axioms follows form the analagous theorem for groups. For associativity of multiplication, we have

$$
\begin{align*}
(r + I)((s + I)(t + I))
&= (r + I)(st + I)
\\ &= r(st) + I
\\ &= (rs)t + I
\\&= (rs + I)(t + I)
\\&= ((r+I)(s+I))(t + I).
\end{align*}
$$

Distributivity follows similarily. $\blacksquare$

**Corollary**: Let $R$ be a ring and $I$ an ideal. Then
1. If $R$ is commutative, then so is $R/I$.
2. If $R$ has unity 1, then $R/I$ has unity $1 + I$.

*Proof*: TODO (as above). $\blacksquare$

**Theorem (First Isomorphism Theorem for Rings)**: Let $f: R \to S$ be a surjective ring homomorphism. Then there exists a nuique ring isomorphism $\overline f: R/\operatorname{Ker}(f) \to S$ such that $f\ circ q = f$ where $q: R \to R/\operatorname{Ker}(f)$ is the canonical quotient map $q(r) = r + \operatorname{Ker}(f)$.

*Proof*: This follows from the analagous theorem for groups, except we need to check that $\overline f$ preserves multiplication. (TODO) $\blacksquare$

**Definition**: A proper ideal $I \subseteq R$ is
1. **prime** if for any $a, b \in R$, if $ab \in I$, then $a \in I$ or $b \in I$.
2. **maximal** if for any ideal $J$ such that $I \subseteq J \subseteq R$, we have $J = I$ or $J = R$.

**Example**: In $\mathbb Z$: prime ideals: $2 \mathbb Z$, $p \mathbb Z$ for $p$ prime. $\lbrace 0 \rbrace$ is a prime. maximal ideals: $p\mathbb Z$ for $p$ prime. For example, $2 \mathbb Z$ is maximal since if $J \supset 2\mathbb Z$, there is $2n + 1 \in J$, then $(2n + 1) - 2n = 1 \in J$. So $J = \mathbb Z$.

In $\mathbb Z_6$, $\langle 2 \rangle, \langle 3 \rangle$ are prime and maximal. $\langle 0 \rangle$ is not prime, since $2 \cdot 3 = 0$.

In $\mathbb Z_{30}$, the maximal/prime ideals are $\langle 2 \rangle, \langle 3 \rangle, \langle 5 \rangle$.

$\mathbb Z_2$ has only one maximal ideal: $\lbrace 0 \rbrace$.

**Theorem**: Let $R$ be a commutative ring with unity $1 \neq 0$. An ideal $I$ of $R$ is prime if and only if $R/I$ is an integral domain.

*Proof*: $(\rightarrow)$ Suppose that $I$ is prime and let $(a + I)(b + I) = I$ in $R/I$. Then $ab + I = (a + I)(b + I) = I$. So $ab \in I$. Since $I$ is prime, $a \in I$, so $a + I = I$, or $b \in I$, so $b + I = I$.

$(\leftarrow)$ Suppose that $R/I$ is an integral domain.  Let $a, b \in R$ such that $ab \in I$. Then $ab + I = I$. Then $(a + I)(b + I) = ab + I = I$. As $R/I$ is an integral domain, either $a + I = I$, so $a \in I$, or $b + I = I$, so $b \in I$. $\blacksquare$

**Theorem**: Let $R$ be a commutative ring with unity $1 \neq 0$. An ideal $I$ of $R$ is maximal if and only if $R/I$ is a field.

*Proof*: $(\rightarrow)$ Suppose that $I$ is maximal. Let $r \in R$ such that $r \not\in I$, so $r + I \neq I$. We need to find a multiplicative inverse of $r + I$ in $R/I$. Define $J = \lbrace rr' + a \mid r' \in R, a \in I \rbrace$. We claim that $J$ is an ideal (TODO). We know that $J \supseteq I$ as $a \in I$ is of the form $a = r \cdot 0 + a$. $J = I$ is impossible since $r \in J$ but $r \not\in I$, so $J = R$ and $1 \in J$. So there are $r' \in R$ and $a \in I$ such that $rr' + a = 1$. Then $1 + I = (rr' + a) + I = (r + I)(r' + I) + a + I = (r + I)(r' + I)$. Thus $r' + I$ is the inverse of $r + I$.

$(\leftarrow)$ Suppose that $R/I$ is a field and let $J$ be an ideal such that $I \subseteq J \subseteq R$. If $J = I$ we are done, so suppose otherwise. Then there is $a \in J$ such that $a \not\in I$. Then there is $b \in R$ such that $(a + I)(b + I) = 1 + I$ since $R/I$ is a field. So $1 - ab \in I$. Then $1 = 1 - ab + ab$, and since $1 - ab \in I \subseteq J$ and $ab \subseteq J$ (since $a \in J$), so $1 \in J$. So $J$ is an ideal containing 1, so $J = R$.

$\blacksquare$

**Corollary**: Every maximal ideal is prime in commutative rings with unity $1 \neq 0$.