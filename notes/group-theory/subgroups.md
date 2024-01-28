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


**Definition**: Let $G$ act on a set $S \neq \emptyset$ and let $s \in S$. Then

$$
G_s = \lbrace g \in G \mid gs = s \rbrace
$$

are the set of elements that **fix** $s$, that is, $g$ **fixes** $s$. Then $G_s$ is the **stablizer** of $s$ in $G$.

**Proposition**: $G_s \leq G$.

*Proof*: Note that $1 \in G_s$. Let $x, y \in G_s$. Then $xs = s$ and $ys = s$. So $(xy)s = x(ys) = xs = s$, so $xy \in G_s$, and the stabilizer is closed under products. We can also show it is closed under inverses. $\blacksquare$

## Cyclic Groups

**Definition**: A group $H$ is **cyclic** if there is an $x \in H$ such that $H = \lbrace x ^n \mid n \in \mathbb Z \rbrace$. In this case, we write $H = \langle x \rangle$, that is, $x$ **generates** $H$.

**Example**:
* $\mathbb Z = \langle  1 \rangle = \lbrace n1 \mid n \in \mathbb Z \rbrace = \langle -1 \rangle$
* $\mathbb Z/m\mathbb Z = \langle \overline 1 \rangle$
* Let $i \in Q_8 = \lbrace \pm 1, \pm i, \pm j, \pm k \rbrace$. Then $\langle i \rangle = \lbrace \pm 1, \pm i \rbrace \leq Q_8$ is a cyclic subgroup of $Q_8$.
* $\langle r \rangle = \lbrace 1, r, r^2, \dots, r^{n - 1} \rbrace \leq D_{2n}$ is a cyclic subgroup of the dihedral group.
* $\langle s \rangle = \lbrace 1, s \rbrace \leq D_{2n}$ is also a cyclic subgroup of $D_{2n}$

**Example**: $\mathbb Q$ is not cyclic.

*Proof*: Suppose $\mathbb Q = \langle a/b \rangle$. We can assume $(a, b) = 1$. Let $p$ be a prime such that $p \nmid b$. Then $1/p = na/b$ for some $n \in \mathbb Z$. But then $pna = b$, so $p \mid b$; a contradiction.

**Example**: $\mathbb R$ is not cyclic.

*Proof*: $\mathbb R$ is uncountable. $\blacksquare$
