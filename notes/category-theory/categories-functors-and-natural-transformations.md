---
layout: default
toc: true
order: 1
---

# Categories, Functors, and Natural Transformations

## Categories

A category is essentially a reflexive and transitive directed graph with the additional constraint that if $(a, b)$ and $(b, c)$ are edges, then $(a, c)$ is also an edge.
A category consists of:

* a collection of **objects** (nodes)
* a collection of **morphisms** or **arrows** (edges)
* operations **domain** and **codomain**, which retrieve the source and target of a morphism, respectively
* a **composition** operation: $(a, b) \circ (b, c) \mapsto (a, c)$

When drawn, the diagram of a category **commutes** if for every pair of nodes, the composition of morphisms corresponding to any of the paths from one node to the other are equal.

In practice, the morphisms of a category are chosen to correspond to structure-preserving transformations between objects. For example:

* The category of groups $\bf Grp$ has all groups as objects and group homomorphisms as morphisms.
* The category of sets $\bf Set$ has all sets as objects and functions as morphisms.
* The category of topological spaces $\bf Top$ has all topological spaces as objects and continuous functions as morphisms.

Other examples:

* $\bf 0$ is the category with no objects and no morphisms.
* $\bf 1$ is the category with one object.
* $\bf 2$ is the category with two objects $a, b$ and one morphism not the identity from $a$ to $b$.
* $\bf 3$ is the category with three objects $a, b, c$ and two morphisms not the identity from $a$ to $b$ and from $b$ to $c$ (and consequently from $a$ to $c$, by the axiom of composition).
* A group $G$ can be seen as a category with one object and all elements of $G$ as morphisms. The composition of morphisms is the group operation.
* A monoid $M$ can be seen as a category with one object and all elements of $M$ as morphisms. The composition of morphisms is the monoid operation.
* A preorder $P$ is a category in which given two objects $a, b$, there is at most one morphism from $a$ to $b$. By defining a morphism from $a$ to $b$ if and only if $a \leq b$ in the preorder, the category represents a set of objects equipped with a reflexive and transitive binary relation.

## Functors

A functor is a morphism of categories, i.e. a transformation between categories mapping objects to objects and morphisms to morphisms, preserving identity, composition, domains, and co-domains.

A functor is **full** if it is surjective on morphisms (and consequently on objects by preservation). A functor is **faithful** if it is injective on morphisms.

---

**Exercises**

(1) Let $\bf{IDom}$ be the category of integral domains and $\bf{Field}$ the category of fields, with morphisms for both as injective ring homomorphisms (note that if the homomorphisms were not injective, the structure of the integral domain could be "lost"). The functor $\mathcal F: \bf IDom \to Field$ maps an integral domain $D$ to its field of fractions $F(D)$. A morphism $f: D \to D'$ is mapped to $\mathcal F f: F(D) \to F(D'): a/b \mapsto f(a)/f(b)$.

(2) A functor $\bm 1 \to C$ maps a single object to a single object in $C$, thus selecting one object in $C$. Similarily, a functor $\bm 2 \to C$ selects a single morphisms in $C$, and a functor $\bm 3 \to C$ selects a composable pair of arrows in $C$.

(3) (b) A functor between two groups (i.e. between two one-object categories) preserves composition, i.e. the group operation: thus it is a group homomorphism. (c) If $G$ is a group, a functor $G \to \bf {Set}$ sending $G$ to its underlying set $A$ and a morphism $f$ to a permutation of $A$, is a permutation representation of $G$.

---

## Natural Transformations

A natural transformation is a morphism of functors. Given two functors $S, T: C \to B$, each object $c$ of $C$ is assigned a morphism $\tau_c: Sc \to Tc$ in $B$, such that for every morphism $f: c \to c'$ in $C$, the diagram commutes:

$$
\begin{array}{ccc}
Sc & \xrightarrow{\tau_c} & Tc \\
\downarrow_{Sf} & & \downarrow_{Tf} \\
Sc' & \xrightarrow{\tau_{c'}} & Tc'
\end{array}
$$

For example, the functors $S, T: \bf{CRng} \to \bf {Grp}$ mapping $K \mapsto \text{GL}_n(K)$ and $K \mapsto K^\times$ (the field of units in $K$) respectively, along with the evident mapping of commutative ring homomorphisms to group homomorphisms, are related through the natural transformation $\det: \text{GL}_n(K) \to K^\times$ mapping a matrix to its determinant, since $\det$ commmutes with any functorially transformed commutative ring homomorphism $f: K \to K'$ by virtue of $\det(f(A)) = f(\det(A))$.

An **equivalency** of categories is a pair of functors $S: C \to D$ and $T: D \to C$ together with natural isomorphisms $1_C \equiv T \circ S$ and $1_D \equiv S \circ T$.

Note the importance of natural transformations in the context of category theory: it was said (by Eilenberg-Maclane) that categories were defined in order to define functors, and functors were defined in order to define natural transformations.

---

**Exercises**

(1) Let $S$ a fixed set and $X^S$ the set of all functions $h: X \to S$. Then $S \mapsto X^S$ is the object function of a functor $\bf Set \to Set$ with arrow function $f \mapsto f \circ h$, which preserves identity and composition.

Next we show that the evaluation function $e_X: X^S \times X \to S$ mapping $(h, x) \mapsto h(x)$ is natural in $X$. Let $T$ be the functor over $\bf Set$ with object function $X \mapsto (X^S, S)$ and arrow function $t: f \mapsto (h, s) \mapsto (f \circ h, s)$ and $U$ the identity functor over $\bf Set$. Then $e$ is a natural transformation between $T$ and $U$ since

$$
(e_{fX} \circ t(f))(h, s) = e_{fX}(f \circ h, s) = (f \circ h)(s)
$$

and

$$
(f \circ e_X)(h, s) = e_X(h, s) = (f \circ h)(s).
$$

(2) Let $H$ be a fixed group. Then $G \mapsto H \times G$ is a functor $H \times -: \bf Grp \to Grp$ with arrow function, $f \mapsto f': (h, g) \mapsto (h, f(g))$. Then every morphism of groups $e_H: H \to K$ is a natural transformation $H \times - \to K \times -$.

(3) Let $B, C$ be groups and $S, T: B \to C$ functors. Then there is a natural transformation $\tau: S \Rightarrow T$ if and only if $S$ and $T$ are conjugate, since naturality requires $Sb \tau_c = \tau_c Tb$ for all $b \in B$.

(4) Let $S, T: C \to P$ be functors from a category $C$ to a preorder $P$. If $Sc \leq Tc$ for all $c \in C$, then $\tau_c: Sc \mapsto Tc \iff Sc \leq Tc$ defines a natural transformation $\tau: S \Rightarrow T$ since $P$ is a pre-order, so $Tf \circ \tau_c = \tau_{c'} \circ Sf$. Conversely, if $\tau_c$ defines a natural transformation, then every object $c$ has a corresponding morphism $Sc \mapsto Tc$, that is, $Sc \leq Tc$. Since $P$ is a pre-order, each of these morphisms is unique, so the entire transformation is unique.

(5) A natural transformation $\eta: S \Rightarrow T$ defines an arrow mapping function $\tau$ sending $f: c \to c'$ to $Tf \circ \eta_c: Sc \to Tc'$. If $\langle g, f \rangle$ is composable, then

$$
Tg \circ \tau f = Tg \circ Tf \circ \eta_c = T(g \circ f) \circ \eta_c = \tau(g \circ f) = \tau g \circ Sf.
$$

---
