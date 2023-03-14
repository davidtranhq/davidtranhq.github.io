# Limits and Continuity

**Definition**: A set $U \subseteq \mathbb R$ is **open** when 

$$
\begin{align*}
    \forall a \in U, \exists r > 0, (a - r, a + r) \subseteq U
\end{align*}
$$

**Proposition**:
1. $\mathbb R$ and $\emptyset$ are open.
2. For any $\lbrace U_\iota \rbrace_{\iota \in I}$ family of open sets, $\bigcup_{\iota \in I} U_\iota$ is open.
3. If $U_1, \dots, U_k$ are open, then $U_1 \cap \dots \cap U_k$ is open.

*Proof*: 
1. $\emptyset$ is open because the definition holds vacuously. $\blacksquare$
2. Let $\mathcal U := \lbrace U_\iota \rbrace_{\iota \in I}$ be a family of open sets and $a \in \bigcup \mathcal U$. Let $\iota_u \in I$ be such that $a \in U_{\iota_u}$. By the openness of $U_{\iota_u}$, we can choose $r \gt 0$ such that $(a - r, a + r) \subseteq \bigcup \mathcal U$. $\blacksquare$.
3. Given $U_1, \dots, U_k$ open sets and $a \in U_1 \cap \dots \cap U_k$ there are $r_1, \dots, r_k > 0$ such that $(a - r_j, a + r_j) \subseteq U_j$ for $j = 1\dots k$. Set $r = \min \lbrace r_1, \dots, r_k \rbrace$. Then, $(a - r, a + r) \subseteq (a - r_j, a + r_j) \subseteq U_j, \forall j$. So $(a - r, a + r) \subseteq U_1 \cap \dots \cap U_k$.

**Example**: The infinite intersection of open sets is not open. Consider $U_n = (-1/n, 1/n)$ for $n \in \mathbb Z_+$. Then $U_n$ is open, $\forall n \geq 1$, but $\bigcap_{n = 1}^\infty U_n = \lbrace 0 \rbrace$, which is **not** open.

**Proposition**: Any open interval in $\mathbb R$ is an open set.

*Proof*: If $I = (-\infty, \infty)$, then $I = \mathbb R$, which is open. So suppose otherwise. Let $a, b \in \mathbb R$ and WLOG, suppose $a \lt b$. Let $c \in (a, b)$. Choose $r = \min \lbrace c - a, b - c \rbrace$. Let $x \in (c - r, c + r)$. Then $a \leq c - r \lt x \lt c + r \leq b$, so $x \in (a, b)$. So $(c - r, c + r) \subseteq (a, b)$, so $(a, b)$ is open. 

If $(a, \infty)$, choose $r = c - a$, and if $(-\infty, b)$, choose $r = b - c$.

**Definition**: A set $F \subseteq \mathbb R$ is **closed**, when $\mathbb R \setminus F$ is open.

**Proposition**:
1. $\mathbb R$ and $\emptyset$ are closed.
2. If $\lbrace F_\iota \rbrace_{\iota \in I}$ are closed sets, then $\bigcap_{\iota \in I} F_\iota$ is closed.
3. If $F_1, \dots, F_k$ are closed, then $F_1 \cup \dots \cup F_k$ is closed.

*Proof*: TODO.

**Definition**: A point $a \in \mathbb R$ is a **limit point** of a set $A \subseteq \mathbb R$ when $\exists (x_n)_{n = 1}^\infty \subseteq A \setminus \lbrace a \rbrace$ such that $\lim_{n \to \infty} x_n = a$.

**Theorem 1**: A set $X$ is closed if and only if

$$
[\forall x_0 \in \mathbb R, \exists (x_n)_{n = 1}^\infty, \lim_{n \to \infty} x_n = x_0] \implies x_0 \in X
$$

That is, a set is closed if and only if it contains all its limit points.

*Proof*: ($\rightarrow$) Assume $X \subseteq \mathbb R$ is closed, and let $x_0 \in \mathbb R$ and $(x_n)_{n = 1}^\infty \subseteq X$ be such that $\lim_{n \to \infty} x_n = x_0$. Suppose $x_0 \not\in X$. Then $x_0 \in \mathbb R \setminus X$, which is open. Choose $\epsilon > 0$ such that $(x_0 - \epsilon, x_0 + \epsilon) \subseteq \mathbb R \setminus X$. Then, $\forall n \in \mathbb Z_+$, $\vert x_n - x_0 \vert \geq \epsilon$, contradicting the assumption that $\lim x_n = x_0$.

($\leftarrow$) Assume for every $x_0 \in \mathbb R$ such that $\exists (x_n)_{n = 1}^\infty \subseteq X$ with $\lim_{n \to \infty} x_n = x_0, x_0 \in X$. Suppose $X$ is not closed. Then $\mathbb R \setminus X$ is not open. Choose $x_0 \in \mathbb R \setminus X$ such that $\forall n \in \mathbb Z_+, \exists x_n \in X$ such that $x_n \in (x_0 - 1/n_1, x_0 + 1/n)$.

**Definition**: A set $K \subseteq \mathbb R$ is **compact**, when $\forall (x_n)_n \subseteq K$, $\exists (x_{n_k})_k \subseteq (x_n)_n$ convergent to an element of $K$.

**Proposition**: Every closed interval is a compact set.

*Proof*: Let $I = [a, b]$, with $a \lt b$ since if $a = b$ then $I$ is a singleton and there is nothing to show. Let $(x_n)_n \subseteq [a, b]$. By Bolzano-Weistress, we can choose a subsequence $(x_{n_k})_k \subseteq (x_n)_n$ such that $\lim_{k \to \infty} x_{n_k} = x_0 \in \mathbb R$. By the above theorem and since $I = \bar I$, it follows that $x_0 \in I$. $\blacksquare$

**Theorem (Heine-Borel)**: A set $K \subseteq \mathbb R$ is compact iff $K$ is closed and bounded. 

*Proof*: ($\leftarrow$) Assume $K$ is closed and bounded. Let $S = (x_n)_n \subseteq K$ be an arbitrary sequence. Since $K$ is bounded, $S$ is bounded, and by Bolzano-Weistress, we can choose a convergent subsequence $S' = (x_{n_k})_k \subseteq S$. Let $x_0 = \lim_{k \to \infty} x_{n_k}$. By Theorem 1, $x_0 \in K$.

($\rightarrow$) Assume for the sake of contradiction that $K$ is not bounded above. Then, $\forall n \in \mathbb Z_+$, $\exists x_n \in K$ such that $x_n \geq n$. We claim that $(x_n)_n$ contains no convergent subsequence. Suppose otherwise that there is $(x_{n_k})_k \subseteq (x_n)_n$ convergent to $x_0 \in \mathbb R$> Choose $N_0 \in \mathbb N$ such that $N_0 \geq x_0 + 1$. Then, $\forall n \geq N_0$, $\vert x_n - x_0 \vert \geq 1$. In particular, if $K_0$ is such that $n_{k_0} \geq N_0$, then $\forall k \geq K_0, \vert x_{n_k} - x_0 \vert \geq 1$. (TODO: show contradiction). The claim contradicts the compactness of $K$. Thus, $K$ is bounded. It remains to show that $K$ is closed. Let $x_0 \in \mathbb R, (x_n)_n \subseteq K$ be such that $\lim_{n \to \infty} x_n = x_0$. By assumption of the compcatness of $K$, we can choose a subsequence $(x_{n_k})_k$ convergent to $z_0 \in K$. Since $\lim x_n$ exists, then $x_0 = z_0 \subseteq K$. So $K$ is closed by Theorem 1. $\blacksquare$

**Example**: The ternary Cantor set is a compact set.

**Definition**: A set $U \subseteq \mathbb R$ is called an (open) **neighborhood** of a point $a \in \mathbb R$ when $U$ is open and $a \in U$. 

**Definition**: Given a function $f: A \to \mathbb R, A \subseteq \mathbb R$, and a limit point of $A$, $a \in \mathbb R$, we say that the **limit of $f$ at $a$ exists and equals $L$,** and we write $\lim_{x \to a} f(x) = L$ when 

$$
\begin{align*}
    \forall \epsilon \gt 0, \exists \delta \gt 0, \forall x \in A, 0 \lt \vert x - a \vert \lt \delta \implies \vert f(x) - L \vert \lt \epsilon
\end{align*}
$$

**Example**: Show that $\lim_{x \to 1} \frac{1}{x} = 1$. 

*Note*: Let $a = 1, f(x) = \frac{1}{x}, A = \mathbb R \setminus \lbrace 0 \rbrace$. We have 

$$
\begin{align*}
    \vert 1/x - 1 \vert = \vert \frac{1 - x}{x} \vert = \frac{1}{\vert x \vert} \cdot \vert x - 1 \vert
\end{align*}
$$

Since we can make $\vert x - 1 \vert$ arbitrarily small, it remains to show that $\frac{1}{\vert x \vert}$ is bounded by some $m$ for all $0 \lt \vert x - 1 \vert \lt \delta$. Assuming that $\delta \leq \frac{1}{2}$, we have $(1 - 1/2 \lt x \lt 1 + 1/2)$. Then, $x \gt \frac{1}{2} \implies \frac{1}{x} \lt 2 \implies \frac{1}{\vert x \vert} \lt 2$, since $x \gt 0$. 

*Proof*: Let $\epsilon \gt 0$ be arbitrary. Choose $\delta = \min\lbrace \frac{1}{2}, \frac{\epsilon}{2} \rbrace$. Then, for all $x \in \mathbb R$ such that $0 \lt \vert x - 1 \vert \lt \delta$, we have $\frac{1}{\vert x \vert} \lt 2$ and so $\left\vert \frac{1}{x} - 1 \right\vert = \frac{1}{\vert x \vert} \cdot \vert x - 1 \vert \lt 2 \delta \leq \epsilon$.

