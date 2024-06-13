---
order: 6
toc: true
layout: default
---

# Further Topics in Group Theory

## $p$-groups, Nilpotent Groups, and Solvable Groups

**Definition**: A **maximal subgroup** is a proper subgroup $M$ of $G$ such that there are no subgroups $H$ of $G$ with $M \lt H \lt G$.

**Theorem 1**: Let $p$ be a prime and $P$ a $p$-group of order $p^a, a \geq 1$. Then
1. $Z(P)$ is non-trivial.
2. If $H$ is a non-trivial normal subgroup of $P$ then $H$ intersects the center non-trivially. In particular, every normal subgroup of order $p$ is contained in the center.
3. If $H$ is a normal subgroup of $P$ then $H$ contains a subgroup of order $p^b$ that is normal in $P$ for every divisor $p^b$ of $\vert H \vert$. In particular, $P$ has a normal subgroup of order $p^b$ for every $b \in \lbrace 0, 1, \dots, a \rbrace$.
4. If $H \lt P$ then $H \lt N_P(H)$.
5. TODO.
 
*Proof*: $(1)$ The order of the conjugacy classes of $P$ divide $p^\alpha$ so by the class equation, so must the order of $Z(G)$. So $\vert Z(G) \vert \neq 1$.

$(2)$ $H$ is normal so it is partitioned by conjugacy classes, in particular $\vert H \vert = \vert H \cap Z(P) \vert + \sum \vert C_i \vert$ for conjugacy classes $C_1, \dots, C_s$. $p$ divides $\vert H \vert$ and the sum of conjugacy class orders so it divides $\vert H \cap Z(P) \vert$, so $H \cap Z(P)$ can't be trivial. If $\vert H \vert = p$ then $H \cap Z(P) = H$ so $H \leq Z(P)$.

$(3)$ TODO.

$(4)$ By induction. If $P$ abelian then trivial, so suppose otherwise. So $\vert P \vert \gt p$. Let $H \lt P$. $H \trianglelefteq Z(P)$ so if $H \not\leq Z(P)$ then $H \lt \langle Z(P), H \rangle \leq N_P(H)$, and we are done. So suppose $    

**Theorem 3**: Let $G$ be a finite group, $p_1, \dots, p_s$ the distinct primes dividing its order and $P_i \in Syl_{p_i}(G), 1 \leq i \leq s$. Then the following are equivalent:
1. $G$ is nilpotent.
2. If $H \lt G$ then $H \lt N_G(H)$
3. If $P \in Syl_{p_i}(G)$, then $P \trianglelefteq G$.
4. $G \cong P_1 \times \dots \times P_s$

*Proof*:

$(1)$ U