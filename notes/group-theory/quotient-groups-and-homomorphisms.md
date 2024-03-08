---
toc: true
layout: default
order: 3
---

# Quotient Groups and Homomorphisms

## Definition and Examples

**Definition**: Let $\varphi: G \to H$ be a homomoprhism. A **fiber** of $\varphi$ is a subset of $G$ that maps to a single element in $H$.

**Definition**: If $\varphi: G \to H$ is a homomorphism, then the **kernel of $\varphi$** is the fiber mapping to the identity element in $H$.

**Proposition 1**: Let $G, H$ be groups and $\varphi: G \to H$ a homomorphism.
1. Identity is preserved under homomorphism.
2. Inverse is preserved under homomorphism.
3. Powers preserved under homomorphism.
4. The kernel is a subgroup of $G$.
5. The image of $G$ under $\varphi$ is a subgroup of $H$.

## The Isomorphism Theorems

---
### Exercises
1. Let $F$ be a finite field of order $q$ and let $n \in \mathbb Z^+$. Prove that $\vert GL_n(F) : SL_n(F) \vert = q - 1$.

*Proof*: Define a homomorphism $\varphi: GL_n(F) \to F$, $\varphi: M \mapsto \det M$. Then $SL_n(F) = \operatorname{ker} \varphi$, so by the First Isomorphism Theorem, $\vert GL_n(F) : SL_n(F) \vert = \vert \varphi \vert = F - \lbrace 0 \rbrace = q - 1$. $\blacksquare$

2. Prove all parts of the Lattice Isomorphism Theorem.

(0) There is a bijection from $\mathcal A$, the set of subgroups $A$ of $G$ containing $N$, onto $\overline {\mathcal A}$, the set of subgroups $A/N$ of $G/N$.

*Proof*: Define $\phi: \mathcal A \to \overline{\mathcal A}$, $\phi(A) = A/N$. It is surjective since if $A/N \in \overline{\mathcal A}$, 

(1) $A \leq B$ if and only if $A/N \leq B/N$.

$ab^{-1} \in A \iff (ab^{-1})N \in A/N \iff (aN)(bN)^{-1} \in A/N$ $\blacksquare$.

(2) If $A \leq B$, then $\vert B : A \vert = \vert B/N : A/N \vert$.

$\vert B : A \vert = \vert B \vert / \vert A \vert = \vert B/N \vert / \vert A/N \vert = \vert B/N : A/N \vert$ by the Third Isomorphism Theorem.

(3) $\langle A, B \rangle / N = \langle A/N, B/N \rangle$.



---