---
layout: default
order: 2
toc: true
---

# Integrals

**Definition**: A **partition** of an interval $[a, b]$ is a subset $X = \lbrace x_0, x_1, \dots, x_n \rbrace$, $n \geq 1$ such that $a = x_0 \lt \dots \lt x_n = b$. 

Let $f: [a, b] \to \mathbb R$ be a bounded function. For each $k \in \lbrace 0, 1, \dots, n \rbrace$,

$$
    m_k = \inf_{x_{k - 1} \leq x \leq x_k} f(x) \\
    M_k = \sup_{x_{k - 1}, \leq x \leq x_k} f(x)
$$

**Lower sum**: $L_X(f) = \sum_{k = 1}^n m_k(x_k - x_{k - 1})$

**Upper sum**: $U_X(f) = \sum_{k = 1}^n M_k(x_k - x_{k - 1})$

If $X'$ is another partition such that $X \subseteq X'$, then $X'$ is called a **refinement** of $X$.

**Observation**: In the notations above,

$$
    L_X(f) \leq L_{X'}(f) \\
    U_{X'} \leq U_X(f)
$$

Also for any two partiitons, $X, Y$, $L_X(f) \leq U_Y(f)$.

**Definition:** Let $f: [a, b] \to \mathbb R$ be a bounded function. $f$ is **integrable** on $[a, b]$ if

$$
    \sup_X L_X(f) = \inf_X U_X(f)
$$

If so, this number is called the **definite integral** of $f$ over $[a, b]$ and we denote it by $\int_a^b f(x)$.

**Example**: 

$$
f(x) = \begin{cases}
    1, x \in \mathbb Q \\
    0, x \not\in \mathbb Q
\end{cases}
$$
is not integrable on $[0, 1]$.

*Proof*: Let $X$ be a partition of $[0, 1]$. For each $k \in \lbrace 0, 1, \dots, n \rbrace$, $m_k = 0$ and $M_k = 1$. So $L_X(f) = 0$ and $U_X(f) = 1$, the length of the total interval. So $\sup_X L_X(f) = \sup_X 0 = 0$, and $\inf_X U_X(f) = \inf_X 1 = 1$. So the function is not integrable. $\blacksquare$

**Theorem**: A bounded function $f: [a, b] \to \mathbb R$ is integrable if and only if $\forall \epsilon \gt 0$, there exists a partition $X$ such that $U_X(f) - L_X(f) \lt \epsilon$.

*Proof*: ($\rightarrow$) Suppose $f$ is integrable. Let $\epsilon \gt 0$. Choose a partition $X'$ such that $U_{X'}(f) \lt \int_a^{\underline b} f(x) dx + \epsilon / 2$. Also, choose a partition $Y$ such that $L_Y(f) \gt \int_{\underline a}^b f(x) dx - \epsilon / 2$. Let $X = X' \cup Y$. Therefore, $U_X(f) - L_X(f) \leq U_{X'}(f) - L_Y(f) \lt \epsilon/2 + \epsilon/2 = \epsilon$.

($\leftarrow$) Let $\epsilon \gt 0$. Suppose there exists a partition $X$ such that $U_X(f) - L_X(f) \lt \epsilon$. Then,

$$
    I = \int_{\underline a}^b f(x) dx - \int_a^{\underline b} f(x) dx \leq U_X(f) - L(X)(f) \lt \epsilon
$$

for each pair $X, \epsilon$. Note that $I$ is fixed and non-negative, since $L_X(f) \leq U_Y(f)$ for any two partitions $X, Y$. Since $I \lt \epsilon$ for any $\epsilon$, $I = 0$. So $f$ is integrable. $\blacksquare$

**Theorem**: Let $f: [a. b] \to \mathbb R$ be bounded, and suppose $X_n, n = 1, 2, \dots$ are partitions such that $\lim_{n \to \infty} U_{X_n}(f) = \lim_{n \to \infty} L_{X_n}(f) = c$. Then $f$ is integrable and $\int_a^b f(x) dx = c$. 

*Proof*: For each $n \in \mathbb N$,

$$
L_{X_n}(f) \leq \int_{\underline a}^b f(x) dx \leq \int_a^{\underline b} f(x)dx \leq U_{X_n}(f)
$$

By Squeeze Theorem, $\int_{\underline a}^b f(x) dx = \int_a^{\underline b}$. So the statement follows. $\blacksquare$