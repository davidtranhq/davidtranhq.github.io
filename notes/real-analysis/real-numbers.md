---
layout: default
order: 4
toc: true
---
# Real Numbers

## Fields

**Definition**: A **field** is a triple $(\mathbb F, +, \cdot)$ where $\mathbb F$ is a nonempty set, $+: \mathbb F \times \mathbb F \to \mathbb F$, and $\cdot: \mathbb F \times \mathbb F \to \mathbb F$ are functions, called **addition** and **multiplication**, satisfying the following axioms:
* addition is closed ($\forall x, y \in \mathbb F, x + y \in \mathbb F$)
* addition is commutative
* addition is associative
* there exists an additive identity $0$ for any $x \in \mathbb F$
* there exists an additive inverse $-x$ for any $x \in \mathbb F$
* multiplication is closed
* multiplication is commutative
* multiplication is associative
* there exists a multiplictaive identity $1$
* there exists a multiplicative inverse $y = x^{-1}$ for any $x \in \mathbb F$
* distributivity $\forall x,y,z \in \mathbb F, x \cdot (y + z) = x \cdot y + x \cdot z$

**Theorem**: Let $(\mathbb F, +, \cdot)$ be a field. Then,
1. The additive and multiplicative identities are unique.
2. $\forall x \in \mathbb{F}, -x$ is unique.
3. $\forall x \in \mathbb{F} \setminus \lbrace 0 \rbrace, x^{-1}$ is unique.
4. $\forall x, y \in \mathbb{F} (x + z = y + z) \implies (x + y)$ (cancellation law)
5. $\forall x \in \mathbb{F} x \cdot 0 = 0$
6. $\forall x \in \mathbb F (-1) \cdot x = -x$
7. $\forall x,y \in \mathbb F, x \cdot y = 0 \implies (x = 0 \lor y = 0)$
8. $\forall x, y \in \mathbb F \exists ! z \in \mathbb F, x = y + z$ (subtraction)
9. $\forall x \in \mathbb F, \forall y \in \mathbb F \setminus \lbrace 0 \rbrace, \exists ! x \in \mathbb F, x = y \cdot z$ (division)

*Proof*: TODO.

**Definition**: The **characteristic** of a field $\mathbb F$ is defined as the smallest number of times needed to sum the multiplicative identity of $\mathbb F$ to obtain 0. That is,

$$
\begin{align*}
    \operatorname{char}(\mathbb F) = \begin{cases}
        p & p = \operatorname{min}\lbrace k \in \mathbb N : 1_1 + \dots + 1_k = 0\rbrace \\
        0 & \text{if $p$ doesn't exist} 
    \end{cases}
\end{align*}
$$

**Example**:
1. $\mathbb Q = \lbrace p/q : p \in \mathbb Z, q \in \mathbb N_+ \rbrace$ is the smallest field of characteristic $0$.
2. $\mathbb R, \mathbb C$ are other fields of characteristic 0.
3. Let $p \in \mathbb N$ be prime. Define $\mathbb{Z}_p = \lbrace \bar 0, \bar 1, \dots, \bar{p - 1} \rbrace$ with addition and multiplication included from $\mathbb Z \mod p$. Then, $\mathbb Z_p$ is a field and $\operatorname{char} (\mathbb Z_p) = p$.

### Ordered Fields

**Definition**: An **ordered field** is a field equipped with a linear order relation compatible with the field addition and multiplicatinon. That is, $(\mathbb F, +, \cdot)$ is an ordered field when there is a relation $<$ on $\mathbb F$ satisfying the following axioms (OF):
1.  $\forall x, y \in \mathbb F$, one of $x \lt y$,  $x = y$, $y \lt x$ is true (trichotomy)
2. $\forall x, y, z \in \mathbb F, x < y \land y < z \implies x < z$ (transitivity)
3. $\forall x, y, z \in \mathbb F, x \lt y \implies x + z \lt y + z$
4. $\forall x, y, z \in \mathbb F, x \lt y \land 0 < z \implies x \cdot z \lt y \cdot z$

*Notation*: We write $x \leq y$ when $x \lt y \lor x = y$.

**Example**: $\mathbb Q, \mathbb R$ with $\lt$. But, $\mathbb C$ and $\mathbb Z_p$ are NOT ordered fields! ($\mathbb Z_p$ does not satisfy (3)). Show that no relation $\lt$ can exist for $\mathbb C$ that complies with the order axioms.

*Proof*: Suppose for the sake of contradiction that an ordereding exists. Then, either $0 \lt i$ or $0 \gt i$. Suppose $0 \lt i$. Then by Axiom 4, $0i \lt i^2 \implies 0 \lt -1 \implies 0 \lt (-1)^2 = 1$. Then, by Axiom 3, $0 \lt -1 \implies 0 + 1 \lt -1 + 1 \implies 1 \lt 0$. We have $0 \lt 1$ and $1 \lt 0$, contradicting Axiom 1. A symmetric argument can be made for the case when $i \lt 0$. $\blacksquare$

**Definition**: Let $(\mathbb F, \lt)$ be an ordered field. We say $a \in \mathbb F$ is **positive** if $0 \lt a$ and **negative** if $a \lt 0$ (and **non-negative** if $0 \leq a$).

**Theorem**: Let $(\mathbb F, \lt)$ be an ordered field with $x, y, z, w \in \mathbb F$. Then,
1. $(x \lt y \land z \lt w) \implies x + z \lt y + w$
2. $x \lt y \implies -y \lt -x$
3. $x \lt y \land z \lt 0 \implies xz > yz$
4. $0 \lt 1$
5. $x \gt 0 \implies \frac{1}{x} \gt 0$
6. $0 \lt x \lt y \implies \frac{1}{x} \gt \frac{1}{y}$

*Proof*:
1. Suppose $x \lt y \land z \lt w$. Then, by (OF3), $x + z \lt y + z = z + y \lt w + y = y + w$. $\blacksquare$
2. Suppose $x \lt y$. Then $-y = -y + 0 = -y + (x + (-x)) = x + (-y + (-x)) \lt y + (-y + (-x)) = -x$. $\blacksquare$
3. TODO.
4. By definition $0 \neq 1$. Suppose for the sake contradiction that $1 \lt 0$. Then, by (3), $1 \cdot 1 = 1 \gt 1 \cdot 0 = 0$. This contradicts that $1 \lt 0$. So $1 \gt 0$.
5. Suppose $x > 0$. Then $\frac{1}{x} \neq 0$, otherwise $1 = x \cdot \frac{1}{x} = 0$. By (OF1), either $\frac{1}{x} < 0$ or $\frac{1}{x} > 0$. Suppose $\frac{1}{x} \lt 0$. Then by (3), $0 \cdot \frac{1}{x} = 0 \gt x \cdot \frac{1}{x} = 1$, contradicting (4). So, $\frac{1}{x} > 0$. $\blacksquare$
6. Suppose $0 \lt x \lt y$. Then, $\frac{1}{x} \neq \frac{1}{y}$, otherwise $1 = x \cdot \frac{1}{x} = x \cdot \frac{1}{y} \lt y \cdot \frac{1}{y} = 1$. So by (OF1), either $\frac{1}{x} \lt \frac{1}{y}$ or $\frac{1}{x} \gt \frac{1}{y}$. Suppose $\frac{1}{x} \lt \frac{1}{y}$. Then, $1 = \frac{1}{x} \cdot x < \frac{1}{y} \cdot x < \frac{1}{y} \cdot y = 1$, a contradiction. So, $\frac{1}{x} > \frac{1}{y}$. $\blacksquare$.

**Theorem**: Let $(\mathbb F, \lt)$ be an ordered field. Then, there exists an injection $\psi: \mathbb N \hookrightarrow \mathbb F$ such that the elements of $\psi(\mathbb N_+)$ are positive and $\operatorname{char}(\mathbb F) = 0$.

*Proof*: Define $\psi: \mathbb N \to \mathbb F$: recurisvely as 

$$
\begin{align*}
    \psi(0_{\mathbb N}) &= 0_{\mathbb F} \\
    \psi(n + 1_{\mathbb N}) &= \psi(n_{\mathbb N}) + 1
\end{align*}
$$

for all $n \in \mathbb N$. Then, $\forall n \in \mathbb N, \psi(n) = 0 + \psi(n) < 1 + \psi(n) = \psi(n + 1) = 0 + \psi(n + 1) \lt 1 + \psi(n + 1) = \psi(n + 2) \dots$. By induction, it can be shown that $\forall k \in \mathbb N_+, \psi(n) < \psi(n + k)$, thus $\psi$ is injective. So, there is no $n \in \mathbb N_+$ with $\psi(n) = 0$, so $\operatorname{char}(\mathbb F) = 0$, by definition. (TODO: why?) $\blacksquare$

**Corollary**: Every ordered field $\mathbb F$ contains the field of rational numbers $\mathbb Q$.

*Proof*: TODO.

**Corollary**: Let $(\mathbb F, \lt)$ be an ordered field, $x, y \in \mathbb F$. If $\forall \epsilon \gt 0, x \leq y + \epsilon$, then $x \leq y$.

*Proof*: TODO.

**Definition**: Let $(\mathbb F, \lt)$ be an ordered field. The **absolute value function** on $\mathbb F$ is 

$$
\begin{align*}
    \lvert x \rvert = \begin{cases}
        x & 0 \leq x \\
        -x & x < 0
    \end{cases}
\end{align*}
$$

**Theorem**: Let $(\mathbb F, \lt)$ be an ordered field, $x, y \in \mathbb F$, $a \in \mathbb F$, $a \geq 0$. Then,
1. $\lvert x \rvert \geq 0$
2. $\lvert x \rvert \leq a \iff -a \leq x \leq a$
3. $\lvert xy \rvert = \lvert x \rvert \lvert y \rvert$
4. $\lvert x + y \rvert \leq \lvert x \rvert + \lvert y \rvert$ (triangle inequality)

*Proof*: TODO.

**Definition (Interval)**: Let $(X, \lt)$ be a non-empty set with a linear order relation $<$. A subset $I \subseteq X$ is called an **interval** in $X$ when 

$$
\begin{align*}
    \forall x,y,z \in X, (x \in I \land y \in I \land x < z \land z < y) \implies z \in I 
\end{align*}
$$

## Completeness Axiom

**Definition**: Let $(X, \lt)$ be a nonempty set with linear ordering $\lt$. Let $S \subseteq X$.
1. $a \in X$ is a **lower bound** for $S$ when $\forall s \in S, a \leq s$.
2. If $S$ has a lower bound, we say $S$ is **bounded below**.
3. $a \in X$ is an **upper bound** for $S$ when $\forall s \in S, s \leq s$.
4. If $S$ has an upper bound, we say $S$ is **bounded above**.
5. $a \in X$ is called the **minimal element** of $S$ (or **minimum** of S), when $a \in S \land (\forall s \in S, a \leq s)$.
6. $a \in X$ is called the **maximal element** of $S$ (or **maximum** of $S$) when $a \in S \land (\forall s \in S, s \leq a)$.

**Definition**: Let $(X, \lt)$ be a non-empty set with a linear order $\lt$, let $S \subseteq X, S \neq \emptyset$ be bounded.
1. $\alpha \in X$ is called the **infimum** (or **greatest lower bound**) of $S$ when $(\forall s \in S, \alpha \leq s) \land (\forall \beta \in X, \alpha \lt \beta \implies (\exists s \in S, s \lt \beta))$
2. $\alpha \in X$ is called the **supremum** (or **least upper bound**) of $S$ when $(\forall s \in S, s \leq \alpha) \land (\beta \in X, \beta \lt \alpha \implies (\exists s \in S, \beta < s))$

**Example**:
1. $\lbrace \frac{1}{n} : n \in \mathbb N_+ \rbrace$
2. $[0, \sqrt 2] \cap \mathbb Q$ with $X = \mathbb Q$
3. $[0, \sqrt 2)$ with $X = \mathbb R$

Note: if $\max S$ exists, then $\operatorname{sup} S = \max S$!

**Definition**: We say that a non-empty linearly ordered set $(X, \lt)$ satisfies the **Completeness Axiom**, when every non-empty bounded above subset of $X$ has a least upper bound.

**Definition**: The field $\mathbb R$ of real numbers is defined as the smallest (with respect to inclusion) ordered field satisfying the completness axiom.

## Archimedian Property of $\mathbb R$

**Theorem**: The set $\mathbb N$ is not bounded above in $\mathbb R$.

*Proof*: Suppose otherwise and let $\alpha = \sup \mathbb N$ Then, $\alpha - 1$ is not an upper bound for $\mathbb N$, so $\exists n_0 \in \mathbb N, \alpha - 1 < n_0$. But then $\alpha < n_0 + 1$. $\blacksquare$.

**Theorem**: The following conditions are equivalent.
1. $\mathbb N$ is not bounded above.
2. $\forall x \in \mathbb R, \exists n \in \mathbb N, x \lt n$.
3. $\forall x, y \in \mathbb R, x \gt 0 \implies \exists n \in \mathbb N, nx \gt y$.
4. $\forall x \in \mathbb R, x \gt 0 \implies \exists n \in \mathbb N, 0 \lt \frac{1}{n} \lt x$.

*Proof*: 

($1 \to 2$) by definition.

($2 \to 3$) Let $x \in \mathbb R_+, y \in \mathbb R$. By (2), $\exists n_0 \in \mathbb N, \frac{y}{x} \lt n_0$. Then, as $x \gt 0$, $\frac{y}{x} \cdot x = y \lt n_0 x$.

($3 \to 4$). Let $x \in \mathbb R$. By (2), $\exists n_0 \in \mathbb N_+, n_0x \gt 1$. Then, $n_0 \gt 0 \implies \frac{1}{n_0} \gt 0 \implies n_0 \cdot x \cdot \frac{1}{n_0} \gt 1 \cdot \frac{1}{n_0}$, that is, $x \gt \frac{1}{n_0}$.

($4 \to 1$). Suppose $\alpha \in \mathbb R$ such that $\alpha \geq n, \forall n \in \mathbb N$. Then, $\alpha \geq 1 \gt 0$, and $\forall n \in \mathbb N, \frac{1}{n} \leq \frac{1}{\alpha}$, contradicting (4). $\blacksquare$

**Theorem**: For every $s \in \mathbb R, s \gt 0 \implies \exists x \in \mathbb R, x^2 = s$.

*Proof*: Given $s \in \mathbb R_+$, let $S = \lbrace x \in \mathbb R : x \geq 0 \land x^2 \lt s  \rbrace$. Then, $S \neq \emptyset$ as $0 \in \mathbb S$ and $S$ is bounded above (indeed, $s \gt 0 \implies s + 1 \gt 1 \implies (s + 1)^2 \gt s + 1 \implies s + 1 \not\in S$). Let $\alpha = \sup S$. We claim that $\alpha^2 = s$.
1. Suppose $\alpha^2 \lt s$. Then, $s - \alpha^2 > 0$, so $\exists n_1 \in \mathbb N, s - \alpha^2 \gt \frac{1}{n_1}$, that is, $\alpha^2 + \frac{1}{n_1} \lt s$. It remains to find $n_2 \in \mathbb N$ such that $(\alpha + \frac{1}{n_2})^2 \leq \alpha^2 + \frac{1}{n_1}$, because then $\alpha + \frac{1}{n_2} \in S$, contradicting the definition of $\alpha$. TODO.
2. Suppose then that $s \leq \alpha^2$. Then, $\exists n_1 \in \mathbb N_+$ such that $\alpha^2 -s \gt \frac{1}{n_1}$, that is, $\alpha^2 - \frac{1}{n} \gt s$. Again, it suffices to find an $n_2 \in \mathbb N_2$ such that $(\alpha - \frac{1}{n_2})^2 \geq \alpha^2 - \frac{1}{n_1}$. TODO. $\blacksquare$.

**Corollary**: For every prime number $p$, there exists $x_p \in \mathbb R$ such that $x_p^2 = p$. Hence, $\mathbb Q \subseteq \mathbb R$.

## Density of $\mathbb Q$ in $\mathbb R$.

**Theorem**: If $x, y \in \mathbb R, x \lt y$, then there is $q \in \mathbb Q$ such that $x \lt q \lt y$.

*Proof*: By the Archimedean Principle, $y \gt x \implies y - x \gt 0 \implies \exists n \in \mathbb N$ such that $\frac{1}{n} \lt \frac{y - x}{2}$. TODO.

**Theorem**: If $x, y \in \mathbb R, x \lt y$, then there is $s \in \mathbb R \setminus \mathbb Q$ such that $x \lt s \lt y$. 

*Proof*: TODO.

**Theorem (Nested Interval Principle)**: Let $I_1 \supseteq I_2 \supseteq \dots$ be a nested sequence of closed intervals in $\mathbb R$. Then, $\bigcap_{k \geq 1}I_k \neq \emptyset$.

*Proof*: TODO.