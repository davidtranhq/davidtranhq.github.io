---
layout: default
toc: true
order: 7
---

# Sequences and Series of Functions

**Definition**: Let $A \subseteq \mathbb R$ be non-empty, $\mathcal F = \lbrace f: A \to \mathbb R \rbrace$ be a set of functions. A **sequence of functions on A** is a function 

$$
\begin{align*}
    n \in \mathbb N \mapsto f_n \in \mathcal F
\end{align*}
$$

and we write $(f_n)_{n = 0}^\infty$

**Definition**: Given a sequence of functions on $A$, $(f_n)_n$ and a function $f: A \to \mathbb R$, we say that $(f_n)$ **converges to $f$ pointwise** when 

$$
\begin{align*}
    \forall a \in A, \forall \epsilon \gt 0, \exists N_a \in \mathbb N, \forall n \geq N_a, \vert f_n(a) - f(a) \vert \lt \epsilon
\end{align*}
$$

We say $(f_n)$ **converges uniformly** on $A$ to $f$, when 

$$
\begin{align*}
    \forall \epsilon \gt 0, \exists N \in \mathbb N, \forall n \geq N, \forall x \in A, \vert f_n(x) - f(x) \vert \lt \epsilon
\end{align*}
$$

and we write $f_n \rightrightarrows_A f$.

**Remark**: If $f_n \rightrightarrows_A f$, then $f_n(x) \to_{n \to \infty} f(x), \forall x \in A$, that is, $f_n \to_{n \to \infty} f$. That is, uniform convergence implies pointwise convergence.

**Remark**: If $f_n \to_{n \to \infty} f$, then $f_n \rightrightarrows g \implies g = f$.

**Example**: $f_n(x) = x^n, x \in [0, 1]$

Claim 1: $f_n \to f$, where 

$$
\begin{align*}
    f(x) = \begin{cases}
        0 & x \in [0, 1) \\
        1 & x = 1
    \end{cases}
\end{align*}
$$

*Proof*: For any $x \in [0, 1)$, we have $\lim_{n \to \infty} x^n = 0 = f(x)$. When $x = 1, x^n = 1, \forall n \implies f_n(1) \to_{n \to \infty} f(1)$. $\blacksquare$

Claim 2: $(f_n)$ doesn't converge uniformly to any function.

*Proof*: Consider $\epsilon = 1/2$. If $f_n \rightrightarrows f$, then $\forall k \in \mathbb Z_+$, $\exists N \in \mathbb N, \forall n \geq N, f_n(1 - \frac{1}{k}) \lt \frac{1}{2}$, that is, $(1 - \frac{1}{k})^n \lt \frac{1}{2}$. We have 

$$
\begin{align*}
    1 - \frac{1}{k} \lt \frac{1}{\sqrt[n]{2}} 
    &\iff \frac{1}{k} \gt 1 - \frac{1}{\sqrt[n]{2}} = \frac{\sqrt[n]{2} - 1}{\sqrt[n]{2}} \\
    &\iff \frac{\sqrt[n]{2}}{\sqrt[n]{2} - 1} \gt k
\end{align*}
$$


**Theorem**: If $A \subseteq \mathbb R$ is a non-empty set, $(f_n)$ is a seuqence of functions continuous on $A$, such that $f_n \rightrightarrows_A f$, then $f$ is continuous on $A$.

*Proof*: Let $a \in A$ and $\epsilon \gt 0$. Choose $N_0 \in \mathbb N$ such that $\forall n \geq N_0, \forall x \in A, \vert f_n(x) - f(x) \vert \lt \epsilon/3$. Choose $\delta \gt 0$ such that $\forall x \in A, \vert x - a \vert \lt \delta \implies \vert f_{N_0}(x) - f_{N_0}(a) \vert \lt \epsilon/3$. Now, $\forall x \in A$, 

$$
\begin{align*}
    \vert x - a \vert \lt \delta &\implies \vert f(x) - f(a) \vert \\
    &= \vert f(x) - f_N(x) + f_N(x) - f_N(a) + f_N(a) - f(a) \vert \\
    &\leq \epsilon/3 + \epsilon/3 + \epsilon/3 = \epsilon
\end{align*}
$$

**Definition**: Given $A \subseteq \mathbb R$ non-empty, a **series of functions on $A$** $\sum_{n = 0}^\infty f_n$ is a pair of sequences $((f_n), (s_n))$, where all $f_n: A \to \mathbb R$, $(f_n)$ is the sequence of terms, $(s_n)$ is the sequence of partial sums, and $s_n(x) = \sum_{k = 0}^n f_k(x)$ for all $x \in A, n \in \mathbb N$.

We say $\sum f_n$ is convergent to a function $f: A \to \mathbb R$
* **pointwise** when $(s_n)$ is pointwise convergent to $f$
* **uniformly** when $(s_n) \rightrightarrows_A f$
* **absolutely convergent** when $\forall x \in A, \sum \vert f_n(x) \vert$ is convergent.