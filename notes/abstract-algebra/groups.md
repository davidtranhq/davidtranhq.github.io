---
layout: default
toc: true
order: 1
---

# Groups

## Groups

**Definition**: A binary operation on a set $S$ is a function $*: S \times S \to S$

**Example**: Let $S = \lbrace x \in \mathbb R \mid x \geq -1 \rbrace$. $+$ on $S$ is not a binary operation since $-1 + -1 = -2 \not\in S$. 

**Example**: $\times$ is not a binary option on $M_{m \times n}(\mathbb R)$ when $m \neq n$

**Definition**: A binary operation $*$ on $S$ is
1. **associative** if for all $a, b, c \in S$, $(a * b) * c = a * (b * c)$
2. **commutative** if for all $a, b \in S$, $a * b = b * a$

**Example**: $+$ is both associative and commutative on $\mathbb Z, \mathbb Q, \mathbb R, \mathbb C$.

**Definition**: Let $S$ be a set with a binary operation $*$. Then $*$ has an **identity element** if there is $e \in S$ such that for any $a \in S$, $a * e = a = e * a$.

**Example**: $(\mathbb Z, +)$ has identity element $0$, since $a + 0 = a = 0 + a$.

**Example**: $\operatorname{Bij(X)}$ has identity element $\operatorname{id}_X: X \to X$.

**Non-Example**: Let $P = \lbrace x \in \mathbb R \mid x \geq 2 \rbrace = [2, \infty)$. $+: P \times P \to P$ is a binary operation that doesn't have an identity element, since for any $a, b \in P$, $a + b \gt a, b$.

**Proposition**: If a binary operation $\star$ on $S$ has an identity element, then it is nuique.

*Proof*: Suppose $e, e' \in S$ are both identity elements. Then $e = e * e' = e'$. $\blacksquare$

**Definition**: Let $S$ be a set with a binary operation $*$ and identity elemnet $e$. The **inverse** of an element $a \in S$ is an element $b \in S$ such that $a * b = e = b * a$.

**Example**: $(\mathbb Z, +)$, the inverse of $n$ is $-n$.

**Example**: $(\mathbb Z, \cdot)$, the inverse of 1 is 1, the inverse of -1 is -1, the inverse of 2 does not exist.

**Proposition**: Let $*$ be an associative binary operation on $S$ with identity element $e$. Then if an element $a \in S$ has an inverse, then it is unique.

*Proof*: Suppose $b, b' \in S$ are both inverses of $a$. So $a * b = e = b * a$ and $a * b' = e = b' * a$. We have $b = b * e = b * (a * b') = (b * a) * b' = e * b' = b'$. $\blacksquare$

**Notation**: We write $a^{-1}$ for the inverse of $a$.

**Definition**: A **group** is a set $G$ with a binary operation $*$ that is associative, has an identity element, and every element has an inverse.

**Example**: $(\mathbb Z, +)$, $(\mathbb R, +)$

**Definition**: The set of all permutations of a set $S$ is denoted by $\operatorname{Sym}(S)$. The set of all permutations of the set $\lbrace 1, 2, \dots, n \rbrace$ is denoted by $S_n$. The group $\operatorname{Sym}(S)$ is called the **symmetric group** on $S$, and $S_n$ is called the **symmetric group of degree $n$**.

**Proposition (Cancellation Property for Groups)**: Let $G$ be a group, and let $a, b, c \in G$.
* if $ab = ac$, then $b = c$
* if $ac = bc$, then $a = b$

**Proposition**: If $G$ is a group if and only if for all $a, b \in G$, then each of the equations $ax = b$ and $xa = b$ has a unique solution.

**Definition**: A group $G$ is said to be **abelian** if $ab = ba$ for all $a, b \in G$.

**Definition**: The set of all invertible $n \times n$ matrices with entries in $\mathbb R$ is called the **general linear group of degree $n$ over the real numbers** and is denoted by $\text{GL}_n(\mathbb R)$

## Subgroups

**Definition**: Let $G$ be a group with identity $e$ and $H \subseteq G$. Then $H$ is a **subgroup** of $G$ if
1. $ab \in H$ for all $a, b \in H$
2. $e \in H$
3. $a^{-1} \in H$ for all $a \in H$

**Remark**: A subgroup of a group is itself a group.

**Example**: The set of all $n \times n$ matrices over $\mathbb R$ with determinant 1 is the **special linear group over $\mathbb R$** $\text{SL}_n(\mathbb R)$, which is a subgroup of $\text{GL}_n(\mathbb R)$.

**Lemma**: Let $G$ be a group and let $H \subseteq G$. Then $H$ is a subgroup of $G$ if and only if $H$ is non-empty and $ab^{-1} \in H$ for all $a, b \in H$.

*Proof*: TODO.

**Lemma**: Let $G$ be a group, and let $H$ be a finite, non-empty subset of $G$. Then $H$ is a subgroup of $G$ if and only if $ab \in H$ for all $a, b \in H$.

*Proof (Sketch)*: $(\leftarrow)$ Since $ab \in H$, $a, a^2, a^3, \dots \in H$, and since $H$ is finite, eventually $a^i = a^j$ for some $i \lt j$ Then $a^{j - i} = e$ and $a^{j - i - 1}$ is the inverse of $a$.



## Homomorphisms

**Definition**: Let $(G_1, *_1)$ and $(G_2, *_2)$ be groups. A function $f: G_1 \to G_2$ is a **group homomorphism**, if for all $a, b \in G_1$, $f(a *_1 b) = f(a) *_2 f(b)$.

**Example**: $\det: GL_n(\mathbb R) \to \mathbb R^*$ is a group homomorphism since $\det(AB) = \det A \det B$.

**Example**: $\exp: \mathbb R \to \mathbb R^\times$ is a group homorphism since $\exp(x + y) = \exp x \exp y$.

**Lemma**: Let $(G_1, *_1)$ and $(G_2, *_2)$ be groups and $f: G_1 \to G_2$ be a homomorphism. Then:

1. $f(e_1) = e_2$
2. $f(a^{-1}) = f(a)^{-1}$ for all $a \in G$
3. $f(a^n) = (f(a))^n$ for all $a \in G$, $n \in \mathbb N$

*Proof*: 

(1) $e_2 *_2 f(e_1) = f(e_1) = f(e_1 *_1 e_1) = f(e_1) * f(e_1)$, so $e_2 = f(e_1)$, by the cancellation law.

(2) TODO.

(3) By induction.

$\blacksquare$

**Proposition**: Let $f: G_1 \to G_2$ be a group homomorphism.

1. If $H_1 \subseteq G_1$ is a subgroup, then $f(H_1)$ is a subgroup of $G_2$.
2. If $H_2 \subseteq G_2$ is a subgruop, then $f^{-1}(H_2)$ is a subgroup of $G_1$.

*Proof*:

(1) TODO.

(2) TODO.

**Definition**: The **kernel** of a group homomorphism $f: G_1 \to G_2$ is $\operatorname{Ker}(f) = \lbrace x \in G_1 \mid f(x) = e_2 \rbrace$.

**Remark**: $\operatorname{Ker}(f) = f^{-1}(\lbrace e_2 \rbrace)$.

**Corollary**: For any group homomorphism $f: G_1 \to G_2$, $\operatorname{Ker}(f)$ is a subgroup of $G_1$.

**Proposition**: A group homomorphism $f: G_1 \to G_2$ is injective if and only if $\operatorname{Ker}(f) = \lbrace e_1 \rbrace$.

*Proof*: $(\rightarrow)$ Suppose $a \in \operatorname{Ker}(f)$. Then $f(a) = e_2 = f(e_1)$. By injectivity of $f$, $a = e_1$. $(\leftarrow)$

**Definition**: A group homomorphism $f: G_1 \to G_2$ is a **group isomorphism** if there is any group homomorphism $g: G_2 \to G_1$ such that $g \circ f = \operatorname{id}_{G_1}$ and $f \circ g = \operatorname{id}_{G_2}$.

**Proposition**: A group homormophism $f: G_1 \to G_2$ is an isomorphism if and only if it is a bijection.

*Proof*: $(\rightarrow)$ By definition.

$(\leftarrow)$ Let $g: G_2 \to G_1$ such that $g \circ f = \operatorname{id}_{G_1}$ and $f \circ g = \operatorname{id}_{G_2}$. Choose $y, y' \in G_2$. Then

$$
\begin{align*}
    g(y_1 *_2 y_2) &= g(f(x_1) *_2 f(x_2)) \\
    &= g(f(x_1 *_1 x_2)) \\
    &= (g \circ f)(x_1 *_1 x_2) \\
    &= x_1 *_1 x_2 \\
    &= g(y_1) *_1 g(y_2)
\end{align*}
$$
$\blacksquare$

**Corollary**: 
1. The inverse of a group isomorphism is a group isomorphism.
2. The composite of a group isomorphism is a group isomorphism.

**Notation**: $G_1 \cong G_2$ if there is a group ismorphism $f: G_1 \to G_2$.

**Example**: $\mathbb Z \not \cong \mathbb Z_2$ since the orders differ.

**Definition**: Let $G_1$ and $G_2$ be groups. The product of $G_1$ and $G_2$ is the group $(G_1 \times G_2)$ with the operation defined elementwise.

**Example**: Show that $\mathbb Z_6 \cong \mathbb Z_2 \times \mathbb Z_3$ with the isomorphism given by $f(k) = (k \mod 2, k \mod 3)$

*Proof*: TODO.

## Cyclic Groups

**Definition**: Let $a \in G$ for some group $G$. If $\exists n \in \mathbb N^+$ such that $a^n = e$, then $a$ has **finite order**, and the smallest such $n$ is the **order** of $a$, denoted $o(a)$. If there does not exist such $n$, then $a$ has **infinite order**.

**Definition**: Let $G$ be a group and let $a \in G$. The set $\langle a \rangle = \lbrace x \in G \mid x = a^n, n \in \mathbb Z \rbrace$ is called the **cyclical subgroup generated by $a$**.
* the group $G$ is called a **cyclic group** if there exists an element $a \in G$ such that $G = \langle a \rangle$. Then $a$ is called a **generator** of $G$.

**Lemma**: Let $G$ be a group and $a \in G$.

1. If the order of $a$ is finite, then $a^k = a^l$ if and only if $k = l$.
2. If the order of $a$ is $n$, then $a^k = a^l$ if and only if $n \mid k - l$.

*Proof*: TODO.

**Corollary**: Let $a \in G$. If $o(a) = k$ and $a^n = e$, then $k \mid n$.

*Proof*: TODO.

**Proposition**: Let $G$ be a group and let $a \in G$.
* The set $\langle a \rangle$ is a subgroup of $G$.
* If $K$ is any subgroup of $G$ such that $a \in K$, then $\langle a \rangle \subseteq K$

*Proof*: TODO.

**Proposition**: Every subgroup of a cyclic group is cyclic.

*Proof*: TODO.

**Theorem**: Let $G$ be a cyclic group.

1. If the order of $G$ is infinite, then $G \cong \mathbb Z$.
2. If the order of $G$ is $n$, then $G \cong \mathbb Z_n$.