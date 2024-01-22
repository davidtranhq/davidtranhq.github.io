---
toc: true
order: 2
layout: default
---

# Subgroups

**Definition**: Let $G$ be any group. Then a subset $H \subseteq G$ is a **subgroup** of $G$ if
1. $1_G \in H$
2. $H$ is closed under products and inverses

That is, $H$ is a group using the operation inherited from $G$. In this case, we write $H \leq G$.

If $H \leq G$ but $H \neq G$, then $H \lt G$ and is called a **proper subgroup** of $G$.

**Definition**: $H = \lbrace 1 \rbrace$ is called the **trivial subgroup**. We write $H = 1$. 

**Example**:
* $\mathbb Z \leq \mathbb Q \leq \mathbb R \leq \mathbb C$
* $n\mathbb Z \leq \mathbb Z, \forall n \in \mathbb Z$
* $\mathbb Z^+ \nleq (\mathbb Z, +)$
* $\mathbb Z^+ \nleq (\mathbb R^+, \cdot)$
* $\mathbb Q^+ \leq \mathbb R^+$

**Example**: We can replace the condition that $1_G \in H$ by $H \neq \emptyset$.

*Proof*: If $H \neq \emptyset$, then there is an $x \in H$. So by $b$, $x^{-1} \in H$. So $1_G = xx^{-1} \in H$. $\blacksquare$

**Proposition**: If $G$ is any group and $H \subseteq G$ is finite such tht $H \neq \emptyset$ and $H$ is closed under products, then $H \leq G$.

*Proof*: It suffices to show that $H$ is closed under inverses. Let $x \in H$. Then $x, x^2, x^3, \dots \in H$. Since $H$ is finite, for some $a \lt b \in \mathbb Z^+$, $x^a = x^b$. Then

$$
x^{b - a} = x^bx^{-a} = (x^b)(x^a)^{-1} = (x^b)(x^b)^{-1} = 1
$$

Let $n = b - a \in \mathbb Z^+$. So $1 = x^n = x^{n - 1}x \implies x^{-1} = x^{n - 1} \in H$, since $n - 1 \geq 0$. $\blacksquare$
