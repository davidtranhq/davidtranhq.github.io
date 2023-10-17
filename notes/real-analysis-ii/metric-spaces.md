---
layout: default
order: 3
toc: true
---

# Metric Spaces

**Definition**: A **metric space** is a non-empty space $X$ with a function $d: X \times X \to \mathbb R$ such that
* $d(x, y) \geq 0, \forall x, y \in X$
* $d(x, y) = 0$ if and only if $x = y$
* $d(x, y) = d(y, x), \forall x, y \in X$
* $d(x, y) \leq d(x, z) + d(z, y), \forall x, y, z, \in X$

We call the elements of $X$ **points**, $d$ the **metric** or **distance function**, $(X, d)$ the **metric space**, and $d(x, y)$ the **distance between $x$ and $y$**.

**Definition**: Let $(X, d)$ be a metric space. A sequence of points $(x_n) \subseteq X$ **converges to** $x \in X$ if $\forall \epsilon \gt 0, \exists n_0$ such that $d(x_n, x) \lt \epsilon$ for all $n \gt n_0$.

Equivalently, $x_n \to x$ if $d(x_n, x) \to 0$.

If there is no such $x \in X$, the sequence $(x_n)$ is divergent.

**Example**: Let $X = \mathbb R$ and $d_\text{discrete}(x, y) = 
\begin{cases}
1, & x \neq y \\
0, & x = y
\end{cases}$. Let $(x_n)$ be a sequence, $x_n \to x$ if $\exists n_0$ such that $x_n = x$ for all $n \geq n_0$.

**Definition**: A sequence $(x_n) \subseteq X$ is **Cauchy** if $\forall \epsilon \gt 0, \exists n_0$ such that $d(x_n, x_m) \lt \epsilon$ for all $n, m \gt n_0$.

**Proposition**: Let $(x_n)$ be a covergent sequence in $(X, d)$. Then it is Cauchy.

*Proof*: Suppose $x_n \to x \in X$. Let $\epsilon \gt 0$. Then, $\exists n_0$ such that $d(x_n, x) \lt \epsilon/2$ for all $n \gt n_0$. Similarily, for all $n, m \gt n_0$, $d(x_n, x) \lt \epsilon/2$ and $d(x_m, x) \lt \epsilon/2$. So $d(x_n, x_m) \leq d(x_n, x) + d(x_m, x) = \epsilon/2 + \epsilon/2 = \epsilon$. Hence $(x_n)$ is Cauchy. $\blacksquare$

**Definition**: A metric space $(X, d)$ in which every Cauchy sequence converges is called **complete**.

**Example**: Some complete metric spaces:
* $(\mathbb R^n, d_{\text{standard}})$
* $(\mathbb R^n, d_\text{discrete})$
* *$(C[0, 1], \sup_\text{metric})$

$(f_n)$ is Cauchy, but $\not\exists f \in X$ such that $f_n \to f$. TODO.

**Example**: $X = [0, 1], d_\text{st}(x, y) = \vert x - y \vert$. $Y = \mathbb Q \cap [0, 1]$. Restrict $d_\text{st}$ to $Y$. Let $x_n$ be a sequence in $Y$ that converges in $X$ to $x = \frac{1}{\sqrt 2}$. Then $(x_n)$ is Cauchy in $Y$ but it does not converge in $Y$. 

*Proof*: TODO.

**Proposition**: Let $(x_n)$ be a Cauchy sequence in a metric space $(X, d)$. If $(x_n)$ has a convergent subsequence $x_{n_k} \to x \in X$, then $x_n \to x$.

*Proof*: Let $\epsilon \gt 0$. Since $(x_n)$ is Cauchy, it follows that $\exists n_0$ such that $d(x_n, x_m) \lt \epsilon$ for all $m, n \gt n_0$. Since $x_{n_k} \to x$, it also follows that $\exists k_0$ such that $d(x_{n_k}, x) \lt \epsilon$ for all $k \gt k_0$. For all $n \gt n_0$, choosing $k \geq k_0$ such that $n_k \gt n_0$, we have 

$$
d(x_n, x) \leq d(x_n, x_{n_k}) + d(x_{n_k}, x) \lt \epsilon + \epsilon = 2\epsilon.
$$

Hence $x_n \to x$. $\blacksquare$



**Definition**: Let $(X, d)$ be a metric space with $Y \subseteq X$ a non-empty subset. Then, restricting $d$ to $Y \times Y \to Y$ yields a **subspace metric** on $Y$.

**Definition**: A **ball** with center $x$ of radius $r$ in a metric space $(X, d)$ is the set $B(x_0; r) = \lbrace x \in X \mid d(x, x_0) \lt r \rbrace$.

**Example**: $B(0; 1) = \lbrace 0 \rbrace$ in $(\mathbb R^2, d_\text{discrete})$

**Definition**: A set $S \subseteq X$ in $(X, d)$ is **open** if $\forall x \in S, \exists \epsilon \gt 0$ such that $B(x; \epsilon) \subseteq S$.

**Example**: $\emptyset$ is open vacuously.

**Proposition**: The union of an arbitrary family of open sets is open.

**Proposition**: The intersection of finitely many open sets is open.

**Proposition**: Let $S = B(x; r)$ be a ball in $(X, d)$. Then $S$ is open.

*Proof*: Let $x_0 \in B(x; r)$. Choose $\delta = \frac{r - d(x, x_0)}{2}$. Then $\forall y \in B(x_0; \delta)$, 

$$
d(y, x) \leq d(y, x_0) + d(x_0, x) \lt \delta + d(x_0, x) = r
$$

So $B(x_0; \delta) \subseteq B(x, r)$. $\blacksquare$

**Proposition**: If $x_n \to x$ in $(X, d)$, then the limit is unique.

*Proof*: Suppose $x_n \to x$ and $x_n \to x'$ with $x \neq x'$. Then $r = d(x, x') \gt 0$ and $\exists n_0$ such that $x_n \in B(x, r/2)$ and $x_n \in B(y; r/2)$ for all $n \gt n_0$. But $B(x; r/2) \cap B(y; r/2) = \emptyset$; a contradiction. We show the balls are disjoint by assuming that $\exists p$ in both. Then, $d(p, x) \lt r/2$ and $d(p, y) \lt r/2$. So $r = d(x, y) \leq d(x, p) + d(p, y) \lt r/2 + r/2 = r$; a contradiction. $\blacksquare$

**Definition**: Let $(X, d_X), (Y, d_Y)$ be metric spaces. The function $f: X \to Y$ is **continuous** at $x_0 \in X$ if $\forall \epsilon \gt 0 \exists \delta \gt 0$ such that if $d_X(x, x_0) \lt \delta$ then $d_Y(f(x), f(x_0)) \lt \epsilon$. 
* $f$ is **continuous** if it is continuous at every $x \in X$.

**Proposition**: Let $(X, d_X), (Y, d_Y)$ be metric spaces. $f: X \to Y$ is **continuous** if for every open set $S$ in $Y$, $f^{-1}(S)$ is open in $X$.

*Proof*: $(\rightarrow)$ Suppose $f$ is continuous. Let $S \subseteq Y$ be open. If $S = \emptyset$, then $f^{-1}(\emptyset) = \emptyset$ is open. If $S \neq \emptyset$, let $y_0 = f(x_0) \in S$. Since $S$ is open, $\exists \epsilon \gt 0$ such that $B(y_0; \epsilon) \subseteq S$. Since $f$ is continuous at $x_0$, $\exists \delta \gt 0$ such that for all $x \in B(x_0; \delta)$, $d(f(x_0), f(x)) \lt \epsilon$. Hence, $B(x_0; \delta) \subseteq f^{-1}(S)$. So $f^{-1}(S)$ is open.

$(\leftarrow)$ Suppose for all open $S$, $f^{-1}(S)$ is open. Let $x_0 \in X$. Let $\epsilon \gt 0$. Since $B(f(x_0); \epsilon)$ is open in $Y$, $f^{-1}(B(f(x_0)); \epsilon)$ is open in $X$. Since $x_0 \in f^{-1}(B(f(x_0); \epsilon))$, $\exists \delta \gt 0$ such that $B(x_0; \delta) \subseteq f^{-1}(B(f(x_0); \epsilon))$. So $f$ is continuous at $x_0$, and $f$ is continuous. $\blacksquare$

**Proposition**: Let $(X, d_X), (Y, d_Y)$ be metric spaces. $f: X \to Y$ is **continuous** if for every convergent sequence $(x_n) \subseteq X$ the sequence $f(x_n)$ converges in $Y$.

*Proof*: $(\rightarrow)$ Suppose $f$ is continuous. Let $(x_n)$ be a convergent sequence in $X$, say $x_n \to x'$. Let $\epsilon \gt 0$. Since $f$ is continuous at $x'$, $\exists \delta \gt 0$ such that $d(f(x), f(x')) \lt \epsilon$ for all $x \in B(x'; \delta)$. Since $x_n \to x'$, $\exists n_0$ such that $x_n \in B(x'; \delta)$ for all $n \gt n_0$.

$(\leftarrow)$ Suppose $f$ is not continuous. Then $\exists x_0$ and $\exists \epsilon \gt 0$ such that for every $\delta \gt 0$, $\exists x \in B(x_0; \delta)$ such that $d_Y(f(x), f(x_0)) \geq \epsilon$. Set $\delta = 1, \frac{1}{2}, \frac{1}{3}, \dots$ and denote these $x$ by $x_1, x_2, x_3, \dots$. Then the sequence $(x_n)$ converges in $X$ to $x_0$ and $d_Y(f(x_n), f(x_0)) \geq \epsilon$ for all $n$, so $f(x_n) \not \to f(x_0)$. $\blacksquare$

**Fact**: On $(X, d)$, $d'(x, y) = \frac{d(x, y)}{1 + d(x, y)}$ is the **bounded metric**.

Note the triangle inequality holds in $d'$ since

$$
\begin{align*}
d'(x, y) + d'(y, z) &= \frac{d(x, y)}{1 + d(x, y)} + \frac{d(y, z)}{1 + d(y, z)} \\
&\geq \frac{d(x, y) + d(y, z)}{1 + d(x, y) + d(y, z)} \\
&= \frac{1}{1 + \frac{1}{d(x, z) + d(z, y)}} \\
&= \frac{d(x, y)}{1 + d(x, y)} \\
&= d'(x, z)
\end{align*}
$$

## Interior, Limit Points, Open and Closed Sets

**Definition**: Let $(X, d)$ be a metric space and let $S \subseteq X$.
* A point $x_0 \in S$ is called an **interior point** of $S$ if $\exists \epsilon \gt 0$ such that $B(x_0, \epsilon) \subseteq S$.
* The set of all interior points of $S$ is called the **interior of $S$**, and is denoted by $\operatorname{Int}(S)$ or $\mathring S$.
* A point $x_0 \in X$ is called a **limit point of $S$** if for all $\epsilon \gt 0$, $B(x_0, \epsilon)$ contains a point of $S$ which is not $x_0$ (that is, at least one point of $S$).
* $S$ is **closed** if all limit points of $S$ are in $S$.
* The **closure of $S$** is the union of $S$ with all of its limit points, denoted $\overline S$.
* The **boundary of $S$** is $\partial S = \overline S - \mathring S$
* The set $S$ is **dense in $X$** if $\overline S = X$.

**Proposition**: For subsets $S, W$ of $(X, d)$,
* $\operatorname{Int}(S)$ is open.
* $S$ is open if and only if $\operatorname{Int}(S) = S$.
* $\operatorname{Int}(\operatorname{Int}(S)) = \operatorname{Int}(S)$
* $\operatorname{Int}(S)$ is the union of all open sets contained in $S$.

*Proof*: $(\subseteq)$ Let $x \in \operatorname{Int}(S)$. Then $x$ is in an open ball around $x$ contained in $S$, which is an open set contained in $S$. $(\supseteq)$ Let $x$ be in some open set $T \subseteq S$. Then there is an open ball around $x$ contained in $T$ which is contained in $S$, so $x \in \operatorname{Int}(S)$. $\blacksquare$

* If $S \subseteq W$, then $\operatorname{Int}(S) \subseteq \operatorname{Int}(W)$

*Proof*: If $\operatorname{Int}(S) = \emptyset$, then $\operatorname{Int} S \subseteq \operatorname{Int} W$. So assume $\operatorname{Int} S = \emptyset$. Let $x_0 \in \operatorname{Int} S$. Then $\exists \epsilon \gt 0$ such that $B(x_0; \epsilon) \subseteq S$. Since $S \subseteq W$, it follows that $x_0 \in W$ and $B(x_0; \epsilon) \subseteq W$. Then $x_0 \in \operatorname{Int} W$. So $\operatorname{Int} S \subseteq \operatorname{Int} W$. $\blacksquare$

* $\operatorname{Int}(S \cap W) = \operatorname{Int} S \cap \operatorname{Int} W$

*Proof*: $(\subseteq)$ By the above, $\operatorname{Int}(S \cap W) \subseteq \operatorname{Int} S$ and $\operatorname{Int}(S \cap W) \subseteq \operatorname{Int} W$. So $\operatorname{Int}(S \cap W) \subseteq \operatorname{Int} S \cap \operatorname{Int} W$.

$(\supseteq)$ Now suppose $x_0 \in \operatorname{Int} S \cap \operatorname{Int} W$. Then $\exists \epsilon_1 \gt 0$ such that $B(x_0; \epsilon_1) \subseteq S$ and $\exists \epsilon_2$ such that $B(x_0; \epsilon_2) \subseteq W$. Then $B(x_0; \min \lbrace \epsilon_1, \epsilon_2 \rbrace) \subseteq S \cap W$. So $x_0 \in \operatorname{Int}(S \cap W)$ and $\operatorname{Int} S \cap \operatorname{Int} W \subseteq \operatorname{Int}(S \cap W)$. $\blacksquare$

* $\operatorname{Int}(S \cup W) \supseteq \operatorname{Int} S \cup \operatorname{Int} W$
* If $x_0$ is a limit point of $S$, then all open balls around $x_0$ contain infinitely many points of $S$.

*Proof*: By contrapositive, choose an $\epsilon$-ball $B_\epsilon$ around $x_0$ that contains only finitely many points of $S$, call the set of these points $P$. Define $\epsilon' = \frac{1}{2} \operatorname{min}\lbrace d(x_0, p) \mid p \in P \rbrace$. Then $B_{\epsilon'}$ contains no points of $S$, so $x_0$ is not a limit point. $\blacksquare$

* $x_0$ is a limit point of $S$ if and only if there is a sequence of distinct points $(x_n) \subseteq S$ such that $x_n \to x_0$.

*Proof*: $(\rightarrow)$ Suppose $x$ is a limit point. Then there is an open ball $B_0(x, \epsilon_0)$ with $\epsilon_0 \gt 0$ containing at least one point in $S$. Choose a point $x_0 \in B_0$. Let $\epsilon_1 = d(x, x_0)/2$. Then $B_1(x, e_1)$ is also an open ball containing at least one point in $S$, which is distinct from $x_1$. Continue this process to form a sequence $(x_n)$, which converges to $x_0$ since $d(x, x_n) \to 0$ as $n \to \infty$.

$(\leftarrow)$ Suppose there is a sequence of distinct points $(x_n) \subseteq S$ convergent to $x$. Let $\epsilon \gt 0$. Since $(x_n)$ converges to $x$, there is at least one $x_n$ with $d(x, x_n) \lt \epsilon$. So $x_n \in B(x, \epsilon)$. $\blacksquare$ 

* The closure of a set is a closed set.
* $S$ is closed if and only if it is equal to its closure.
* $\overline{\overline S} = \overline S$
* $\overline{S}$ is the intersection of all closed sets containing $S$.

*Proof*: $(\subseteq)$ Let $x \in \overline{S}$. Let $T$ be a closed set containing $S$. If $x$ is not a limit point of $S$, then $x \in S \subseteq T$. If it is, then for all $\epsilon \gt 0$, $B(x, \epsilon)$ contains some point $x_0$ in $S$. Since $S \subseteq T$, $x_0 \in T$, so $B(x, \epsilon)$ contains at least one point in $T$. So $x$ is a limit point of $T$. Since $T$ is closed, $x \in T$. Since $T$ was arbitrary, $x$ is in all closed sets containing $S$.

$(\supseteq)$ Let $x$ be in the intersection of all closed sets containing $S$. Since $\overline S$ is a closed set containing $S$, then $x \in \overline S$. $\blacksquare$

* The intersection of an arbitirary family of closed sets is closed.
* The finite union of closed subsets $S_1, \dots, S_m \subseteq X$ is closed.

*Proof*: $\bigcup_{k = 1}^m S_k = \bigcup_{k = 1}^m (X \setminus (X \setminus S_k)) = X \setminus \bigcap_{k = 1}^m (X - \setminus S_k)$. Note that $X \setminus S_k$ is open, and since the intersection of finitely many open sets is open, $\bigcap_{k = 1}^m (X \setminus S_k)$ is open. So $X \setminus \bigcap_{k = 1}^m (X \setminus S_k)$ is closed. $\blacksquare$

* $\emptyset, X$ are closed.
* If $S \subseteq W$, then $\overline S \subseteq \overline W$.
* $\overline {S \cup W} = \overline S \cup \overline W$
* $\overline{S \cap W} \subseteq \overline S \cap \overline W$
* $x_0 \in \overline S$ if and only if $\forall \epsilon \gt 0$, $B(x_0, \epsilon) \cap S \neq \emptyset$
* $x \in \overline S$ if and only if there exists a sequence $(x_n) \subseteq S$ such that $x_n \to x_0$.
* $\forall x_0 \in X$ and $\epsilon \gt 0$, the closed ball $\overline{B(x_0, \epsilon)} = \lbrace x \in X \mid d(x, x_0) \leq \epsilon \rbrace$ is closed.
* $S$ is closed if and only if $X \setminus S$ is open.

*Proof*: If $S = \emptyset$, then $X \setminus S = X$. If $S = X, then $X \setminus S = \emptyset$. In both cases, the statement holds. So suppose $S \neq \emptyset$ and $S \neq X$.

$(\rightarrow)$ Assume $S$ is closed. Let $x_0 \in X \setminus S$. Then, $x_0$ is not a limit point of $S$. So $\exists \epsilon \gt 0$ such that $B(x_0; \epsilon) \subseteq X \setminus S$. Hence, $X \setminus S$ is open.

$(\leftarrow)$ Suppose $X \setminus S$ is open and assume for the sake of contradiction that $S$ is not closed. Then there is a limit point $x_0$ of $S$ such that $x_0 \not\in S$. Then $x_0 \in X \setminus S$. Since $X \setminus S$ is open, it follows that $\exists \epsilon \gt 0$ such that $B(x_0; \epsilon) \subseteq X \setminus S$. This contradicts that $x_0$ is a limit point. $\blacksquare$

* $\partial S$ is a closed set.
* $\partial S = \partial(X \setminus S)$
* $S$ is closed if and only if $\partial S \subseteq S$.

**Proposition**: Let $(X, d_X), (Y, d_Y)$ be metric spaces. Then $f: X \to Y$ is continuous if and only if for every $S$ closed in $Y$, $f^{-1}(S)$ is closed in $X$.

*Proof*: Recall that $f$ is continuous if and only if $\forall S$ open in $Y$, $f^{-1}(S)$ is open in $X$. We have $f^{-1}(Y \setminus S) = X \setminus f^{-1}(S)$. $\blacksquare$

## Completion of Metric Spaces

**Definition**: An **isometry** is a function $f: X_1 \to X_2$ such that $d_2(f(x_1), f(y_1)) = d_1(x_1, y_1)$ for all $(x_1, y_1) \in X_1$. That is, an isometry is a distance preserving map. Also caled an **isometric embedding**.

**Example**:
* In $(\mathbb R^2, d_\text{st})$, translations and rotations are isometries.
* In $(\mathbb R^2, d_1)$, rotation is not an isometry but translation is.

**Example**: $f: [0, \infty) \to [0, \infty), x \mapsto x + 10$ is an isometry.

**Proposition**: Isometries preserve convergence of seqeuences.

**Proposition**: Isometries preserve Cauchyness.

**Proposition**: Isometries are one-to-one.

**Definition**: A subset $Y \subseteq X$ is **dense** if every $x \in X$ is the limit of a sequence in $Y$.

**Definition**: A completion of a metric space $(X, d)$ is a metric space $(X^*, d^*)$ together with an isometric embedding $i: X \to X^*$ such that
1. $X^*$ is complete
2. $X$ is dense in $X^*$.

**Example**:
* $[0, 1]$ is the completion of $[0, 1)$
* $\mathbb R$ is the completion of $\mathbb Q$

### Existence and Uniqueness of Completions

**Notation**: Let $(x_n), (y_n)$ be sequences in a metric space. Write $(x_n) \sim (y_n)$ to mean $\lim_{n \to \infty} d(x_n, y_n) = 0$.

**Lemma**:
1. If $x_n \to a$ and $y_n \to a$, then $x_n \sim y_n$.
2. If $x_n \sim y_n$ and $x_n \to a$, then $y_n \to a$.

*Proof*: TODO.

**Theorem 1.53**: If $(X, d)$ is a metric space, then $X$ has a unique completion. That is, if $i: X \to A$ and $j: X \to B$ are two completions, then there is a unique bijective isometry $\phi: A \to B$ so that $\phi \circ i = j$.

*Proof*: Let $\mathscr C$ be the set of Cauchy sequences in $X$. Define an equivalence relation $\sim$ on $\mathscr C$ by $\lbrace x_n \rbrace \sim \lbrace y_n \rbrace$ if $d(x_n, y_n) \to 0$. Define $X^* = \mathscr C / \sim$ as the equivalence classes of $\mathscr C$, and $d^* = X^* \times X^* \to [0, \infty)$ such that $d^*([x_n], [y_n]) = \lim_{n \to \infty} d(x_n, y_n)$. (TODO: Check that the limit exists and that $d^*$ is well-defined).

**Theorem (Urysohn's Lemma)**: Let $A, B$ be disjoint closed sets in a metric space $(X, d)$. Then, there exists a continuous function $f: X \to \mathbb R$ such that
* $f(x) = 0$ for all $x \in A$
* $f(x) = 1$ for all $x \in B$
* $0 \leq f(x) \leq 1$ for all $x \in X$.

*Proof*: Consider the function $h(x) = d(x, A) = $\operatorname{Int}_{y \in A} \lbrace d(x, y) \rbrace$.