---
layout: default
toc: true
order: 4
---

# Line Integrals and Entire Functions

## Properties of the Line Integral

**Definition**: Let $f(t) = u(t) + iv(t)$ be any continuous complex-valued function of the real variable $t, a \leq t \leq b$. Then

$$
\int_a^b f(t) dt = \int_a^b u(t) dt + i\int_a^b v(t) dt
$$

**Definition**: Let $z(t) = x(t) + iy(t), a \leq t \leq b$. The curve determined by $z(t)$ is called **piecewise differentiable** and we set

$$
\dot z(t) = x'(t) + iy'(t)
$$

if $x, y$ are continuous on $[a, b]$ and continuously differentiable on each subinterval of a partition of $[a, b]$.

$z(t)$ is **smooth** if $\dot z(t) \neq 0$ except at a finite number of points.

**Definition**: Let $C$ be a smooth curve given by $z(t), a \leq t \leq b$, and suppose $f$ is continuous at all the points $z(t)$. Then the **integral of $f$ along $C$** is

$$
\int_C f(z) dz = \int_a^b f(z(t))\dot z(t) dt
$$

**Definition**: $C_1: z(t), a \leq t \leq b$ and $C_2: \omega(t), c \leq t \leq d$ are **smoothly equivalent** if there exists a bijective $\mathbb C$ mapping $\lambda: [c, d] \to [a, b]$ such that $\lambda(c) = a, \lambda(d) = b, \lambda'(t) \gt 0$ for all $t$ and $\omega(t) = z(\lambda(t))$.

**Proposition**: If $C_1$ and $C_2$ are smoothly equivalent, then $\int_{C_1} f = \int_{C_2} f$.

*Proof*: TODO. (*Sketch*: Expand both integrands and compare terms through a change-of-variable.)

**Definition**: Let $C: z(t), a \leq t \leq b$. Then $-C$ is defined by $z(b + a - t), a \leq t \leq b$.

**Proposition**: $\int_{-C} f = \int_C f$.

*Proof*: TODO.

**Example**: Suppose $f(z) = x^2 + iy^2$ and consider $C: z(t) = t + it, 0 \leq t \leq 1$. Then $\dot z(t) = 1 + i$ and

$$
\begin{align*}
\int_C f(z) dz &= \int_C f(z(t)) \dot z(t) dt \\
&= \int_0^1 (t^2 + it^2)(1 + i) dt \\
&= \int_0^1 t^2 +it^2 + it^2 - t^2 \\
&= 2i \int_0^1 t^2 dt \\
&= 2i/3
\end{align*}
$$

**Example**: Let $f(z) = \frac{1}{z} = \frac{x}{x^2  +y^2} - i\frac{y}{x^2 + y^2}$ and $C: z(t) = R\cos t + iR \sin t, 0 \leq t \leq 2\pi, R \neq 0$. Then $\dot z(t) = -R \sin t + iR\cos t$.

$$
\begin{align*}
\int_C f(z) dz
&= \int_0^{2\pi} f(z(t)) \dot z(t) dt \\
&= \int_0^{2\pi} \left(\frac{\cos t}{R} - i\frac{\sin t}{R}\right)(-R \sin t + iR \cos t) \\
&= \int_0^{2\pi} -\sin t\cos t + \sin t \cos t + i\cos^2 t + i \sin^2 t dt \\
&= 2\pi i
\end{align*}
$$

**Example**: Suppose $f(z) \equiv 1$ and let $C$ be any smooth curve. Then $\int_C f(z) dz = \int_a^b \dot z(t) dt = z(b) - z(a)$.

**Proposition**: Let $C$ be a smooth curve, $f, g$ continuous functions on $C$, and $\alpha \in \mathbb C$. Then
1. $\int_C (f(z) + g(z)) dz = \int_C f(z) dz + \int_C g(z) dz$
2. $\int_C \alpha f(z) dz = \alpha \int_C f(z) dz$

*Proof*: (1) Let $f(z) = u_f(x, y) + iv_f(x, y)$ and $g(z) = u_g(x, y) + iv_g(x, y)$. Then

$$
\begin{align*}
\int_C f(z) + g(z) dz
&= \int_a^b (f(z(t)) + g(z(t))) \dot z(t) dt \\
&= \int_a^b [u_f(x(t), y(t)) + v_f(x(t), y(t))]
\end{align*}
$$
**Notation**: Let $\alpha, \beta \in \mathbb C$. Then $\alpha \ll \beta \iff \vert \alpha \vert \leq \vert \beta \vert$.

**Lemma**: Suppose $G(t)$ is a continuous complex-valued function of $t$. Then

$$
\int_a^b G(t)dt \ll \int_a^b \vert G(t) \vert dt
$$

*Proof*: TODO.

**Theorem (M-L)**: Suppose that $C$ is a smooth curve of length $L$, that $f$ is continuous on $C$, and $f \ll M$ throughout $C$. Then

$$
\int_C f(z) dz \ll ML
$$

*Proof*: TODO.

**Proposition**: Suppose $(f_n)$ is a sequence of continuous functions and $f_n \to f$ uniformly on the smooth curve $C$. Then

$$
\int_C f(z) dz = \lim_{n \to \infty} \int_C f_n(z) dz
$$

*Proof*: TODO.

**Proposition**: Suppose $f$ is the derivative of an analytic function $F$, that is $f(z) = F'(z)$, where $F$ is analytic on the smooth curve $C$. Then

$$
\int_C f(z) dz = F(z(b)) - F(z(a))
$$

*Proof*: TODO.