---
layout: default
order: 1
toc: true
---

# Groups

**Definition**: A **semigroup** is an ordered pair $(S, *)$ where $S \neq 0$ and $*$ is an associative binary operation on $S$. 

**Example**:
* $(\mathbb Z, +), (\mathbb Z, \cdot), (\mathbb Q, +)$, etc. are commutative semigroups.
* $(\mathbb R^3, \times)$ is **not** a semigroup, where $\times$ is the cross product, since the cross product is not associative.
* $(\mathbb Z, -)$ is not a semigroup either, since $(1 - 1) - 1 \neq 1 - (1 - 1)$.

**Definition**: A **group** is a semigroup $(G, *)$ with the additional following properties:
1. There is an identity element $e \in G$, that is, $ae = a = ea$ for all $a \in G$. 
2. Every element $a \in G$ has an inverse $b \in G$, that is, $ab = e = ba$.

**Remark**: Note that $ab = e$ doesn't necessarily imply $ba = e$ since commutativity is not a group axiom, so the inverse axiom requires both $ab = ba = e$.

**Proposition**: The identity element of a group is unique.

**Proposition**: The inverse element of an element $a$ in a group is unique.

**Notation**: Since the inverse of $a$ is uniquely determined by $a$, we denote its inverse as $a^{-1}$.

**Definition**: An **Abelian** group is a commutative group.

**Notation**: $S^\times = \lbrace a \in S \mid a^{-1} \in S\rbrace$

**Example**:
* $\mathbb Z, \mathbb Q, \mathbb R, \mathbb C$ are all Abelian groups under $+$ with $e = 0$ and $-a$ the inverse of $a$.
* $\mathbb R^{\times} = \lbrace a \in \mathbb R \mid 1/a \in \mathbb R\rbrace = \mathbb R - \lbrace 0 \rbrace$ is an Abelian group.
* $\mathbb Q^\times = \mathbb Q - \lbrace 0 \rbrace$ and $\mathbb C^\times = \mathbb C - \lbrace 0 \rbrace$ are also Abelian groups.
* $\mathbb Z - \lbrace 0 \rbrace$ is a commutative subgroup but not a group, since only $1$ and $-1$ have inverses.
  * Note that $\mathbb Z - \lbrace 0 \rbrace \neq \mathbb Z^\times$.
* If $V$ is a vector space, then it is an Abelian group under $+$, where $e = \vec 0$.

---

*The Integers Modulo $n$*

**Notation**: Let $n \in \mathbb Z^+$. Then $\bar a = \lbrace a + nk \mid k \in \mathbb Z \rbrace = a + n\mathbb Z$. The integers moodulo $n$ is denoted

$$
\mathbb Z/n\mathbb Z = \lbrace \overline a \mid a \in \mathbb Z \rbrace = \lbrace \overline 0, \overline 1, \dots, \overline{n - 1} \rbrace
$$

Notice that $\overline a = \overline b \iff n \mid (a - b) \iff a \equiv b \pmod n$. We define binary operations on $\mathbb Z/n\mathbb Z$ by

$$
\overline a + \overline b := \overline{a + b} \\
\overline a \cdot \overline b := \overline{ab}
$$

**Theorem**: The operations $+$ and $\cdot$ are well-defined on $\mathbb Z/n\mathbb Z$, that is, they are independent of the choices of representatives of the conjugacy classes.

*Proof*: Take $\overline a_1 = \overline a_2$ and $\overline b_1 = \overline b_2$ and write $a_1 = a_2 + kn$ and $b_1 = b_2 + ln$ for $k, l \in \mathbb Z$ to show that $a_1 + b_1 = a_2 + b_2 + (k + l)n$, so $\overline{a_1 + b_1} = \overline{a_2 + b_2}$. Similarily for multiplication. $\blacksquare$

**Example**: In $(\mathbb Z/n\mathbb Z, \cdot), \overline 0$ has no multiplicative inverse unless $n = 1$. So $(\mathbb Z/n\mathbb Z)$ is **not** a group, unless $n = 1$, so $\overline 0 = \overline 1$.

---

**Notation**: $(a, n) := \gcd(a, n)$

**Proposition**: $a \in (\mathbb Z/n\mathbb Z)^\times$ if and only if $(a, n) = 1$.

*Proof*: $(\rightarrow)$ If $a \in (\mathbb Z/n\mathbb Z)^\times$ then so is $a^{-1}$, and $aa^{-1} = 1 \equiv aa^{-1} + nx = \overline 1$, so $(a, n) = 1$.    

$(\leftarrow)$ By Bezout's identity, $ax + ny = 1$, for some $x, y \in \mathbb Z$ so $\overline a \overline x = \overline{ax} = \overline 1$. So $\overline x = \overline a^{-1}$. $\blacksquare$

**Theorem**: $((\mathbb Z/n\mathbb Z)^\times, \cdot)$ is a finite Abelian group with cardinality

$$
\phi(n) = \vert (\mathbb Z/n\mathbb Z)^\times \vert
$$

where $\phi$ is the Euler-phi (or totient) function of $n$.