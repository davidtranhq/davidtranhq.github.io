---
layout: default
order: 100
toc: true
---

# Group Theory

## Finite Groups

Let $G$ be a finite group.

1. If for all positive integers $n$ dividing its order, $G$ contains at most $n$ elements $x$ satisfying $x^n = 1$, then $G$ is cyclic.
    * *Proof: Show $G$ is nilpotent, and each of its Sylow subgroups are cyclic.*
2. If $H \trianglelefteq G$ and $P \in Syl_p(H)$, then $G = HN_G(P)$ and $\vert G : H \vert \mid \vert N_G(P) \vert$.
    * *Proof: Show $G \leq HN_G(P)$ since $P^g = P^h$. Use Second Isomorphism Theorem for the second part.*
3. If $\vert G \vert = p^aq^b$ for primes $p, q$, then $G$ is solvable.
4. If for every prime $p$ dividing $\vert G \vert$, $\vert G \vert = p^\alpha m$, $G$ has a subgroup of order $m$, then $G$ is solvable.
5. If $\vert G \vert$ is odd then $G$ is solvable.
6. If for every pair of elements $x, y \in G$, $\langle x, y \rangle$ is a solvable group.

## Finite Abelian Groups

Let $A$ be a finite abelian group.
1. If $\vert A \vert$ is the product of distinct primes, then up to isomorphism the only abelian group of order $n$ is $Z_n$.
    * *Proof: Use the Classification Theorem for Finitely Generated Abelian Groups.*
2. $A$ is direct product of its Sylow subgroups. 
    * *Proof: Use finite nilpotent groups*.

## Direct Products

Let $G = G_1 \times \dots \times G_n$. Identify $G_i$ with $\lbrace (1, \dots, g_i \dots, 1) \mid g_i \in G_i \rbrace$ when necesssary.

1. The order of a direct product is the product of the orders of its factors.
2. $G/G_i \cong G_1 \times \dots G_{i - 1} \times G_{i + 1} \times G_n$.
3. The projection of $G \to G_i$ is a surjective homomorphism.
4. If $x \in G_i$ and $y \in G_j$ then $xy = yx$ for $i \neq j$.

## Finitely Generated Abelian Groups

Let $A$ be a finitely generated abelian group.

1. $A \cong \mathbb Z^r \times Z_{n_1} \times \dots \times Z_{n_s}$ is unique with $n_s \mid \dots \mid n_1$.
2. If $n$ is the product of distinct primes, then up to isomorphism the only abelian group of order $n$ is $Z_n$. 

## Commutator Subgroups

Let $G'$ be the commutator subgroup of $G$.

1. The homomorphic image of a commutator subgroup is a commutator subgroup.
2. $G'$ char $G$.
3. $G/G'$ is abelian.
4. $G/G'$ is the largest abelian quotient of $G$: $G/H$ is abelian if and only if $G' \leq H$.

## p-groups

Let $P$ be a $p$-group of order $p^\alpha$.

1. $Z(P) \neq 1$.
   * *Proof: Use class equation.*
2. proper normal subgroups of $P$ intersect the center non-trivially.
   * *Proof: Normal subgroups are partitioned by conjugacy classes + class equation.*
3. normal subgroups $H$ of $P$ contain normal subgroups of order $p^b$ for every divisor $p^b$ of $\vert H \vert$
   * *Proof: By induction on $a$, use Cauchy's Theorem to generate a normal subgroup $N \trianglelefteq H \cap Z(P)$ and induct on $P/N$.*
4. proper subgroups of $P$ are contained in their normalizer.
   * *Proof: By induction on $\vert P \vert$, induct on $P/Z(P)$.*
5. every maximal subgroup of $P$ has index $p$ and is thus normal in $P$
   * *Proof: Show $P/M$ contains no proper nontrivial subgroups, so by $(3)$ $\vert P/M \vert = p$*
6. $P$ is nilpotent of class at most $a - 1$.
   * *Proof: Show $\vert H_i \vert \geq p\vert H_{i - 1} \vert$ since $Z(P/H_{i - 1}) \neq 1$*.

### Examples

* $Z_2, Z_4, Z_8, D_8, D_{16}, D_{32}, P \in Syl_2(S_3)$

## Nilpotent Groups

### Finite Nilpotent Groups

Let $G$ be a finite nilpotent group with distinct primes $p_i$ dividing $\vert G \vert$ and corresponding Sylow-$p_i$ groups $P_i$.

1. The following are equivalent
   1. $G$ is nilpotent.
        * *Proof:*
   2. If $H \lt G$ then $H \lt N_G(H)$
        * *Proof: (i $\to$ ii) Same argument as for $p$-groups, using the fact that if $G$ is nilpotent then so is $G/Z(G)$*.
   3. $G$'s Sylow groups are normal in $G$.
   4. $G$ is the direct product of its Sylow groups.
   5. Every maximal subgroup is normal.
   6. $G^n = 1$ for some $n \geq 0$. $G$ is of class $c$ iff $c$ is the smallest non-negative integer with $G^c = 1$.

### Examples

## Solvable Groups

Let $G$ be a solvable group.

1. The following are equivalent.
   1. $G$ is solvable.
   2. $G^{(n)} = 1$ for some $n \geq 0$.
2. Subgroups of solvable groups are solvable.
    * *Proof: Show $H^{(i)} \leq G^{(i)}$ for $H \leq G$.*
3. Homomorphic images and quotient groups of solvable groups are solvable.
    * *Proof: Show $\varphi(G^{(i)}) = K^{(i)}$.*
4. If $N$ is normal in $G$ and both $N$ and $G/N$ are solvable then so is $G$.
    * *Proof: Use the above property with the natural projection.*
