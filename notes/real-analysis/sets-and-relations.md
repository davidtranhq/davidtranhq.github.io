---
layout: default
order: 2
---

# Sets and Functions

## Sets

**Axiom (of Belonging)**: For all $x$, either $x \in A$ or else $x \not\in A$.
* note: "or else" means "exclusive or"

**Definition**: A **set** A is an object such that a notion of membership $x \in A$ is defined
and the Axiom of Belonging holds.

**Example (Russel's paradox)**: $A = \lbrace x : x \not\in x \rbrace$ is not a set since the Axiom of Belonging is not satisfied.

**Definition**: For sets $A,B$
* $B$ is a **subset** of $A$, denoted $B \subseteq A$ (or $B \subset A$) if $\forall x, x \in B \implies x \in A$.
* $A,B$ are **equal**, denoted $B = A$ if $\forall x, x \in A \iff x \in B$
* $B$ is a **strict subset** of $A$, denoted $B \subsetneq A$ if $B \subseteq A$ and $B \neq A$.

**Definition**: The **empty set**, the set with no elements, is defined as $\emptyset = \lbrace x : x \neq x \rbrace$

**Theorem**: Let $A$ be any set. Then, $\emptyset \subseteq A$.

*Proof*: Suppose for the sake of contradiction that $\exists x, x \in \emptyset \land x \not\in A$. This contradicts the fact that the empty set is empty. So, $\emptyset \subseteq A$. $\blacksquare$

**Definition**: Given a set $A$, its **power set** is $\mathscr P(A) = \lbrace B : B \subseteq A \rbrace$.

**Definition**: Let $A, B$ be sets.
* **union** of $A$ and $B$ is $A \cup B = \lbrace x : x \in A \lor x \in B \rbrace$
* **intersection** of $A$ and $B$ is $A \cap B = \lbrace x : x \in A \land x \in B \rbrace$
* **difference** of $A$ and $B$ is $A \setminus B = \lbrace x : x \in A \land x \not\in B \rbrace$
* $A$ and $B$ are **disjoint** when $A \cup B = \emptyset$
* When $A \subseteq U$ for some universal set $U$, $A^C = U \setminus A$ is the complement of $A$

**Theorem**: Let $A,B,C \subseteq U$ for some universal set $U$.
1. $(A^C)^C = A$
1. $A \cup A^C = U$
1. $A \cap A^C = \emptyset$
1. $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$
1. $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
1. $A \setminus (B \cup C) = (A \setminus B) \cup (A \setminus C)$
1. $A \setminus (B \cap C) = (A \setminus B) \cup (A \setminus C)$

## Relations

**Definition**: An **ordered pair** of elements $a, b$ is defined as

$$
  (a, b) = \lbrace \lbrace a \rbrace, \lbrace a, b \rbrace \rbrace.
$$

**Theorem**: $(a, b) = (c, d) \iff a = c \land b = d$.

*Proof*: ($\leftarrow$) Suppose $a = c \land b = d$. Then, $\lbrace a \rbrace = \lbrace c \rbrace$ and $\lbrace a, b \rbrace = \lbrace c, d \rbrace$, so $\lbrace \lbrace a \rbrace, \lbrace a, b \rbrace \rbrace = \lbrace \lbrace c \rbrace, \lbrace c, d \rbrace \rbrace$. $\blacksquare$

($\rightarrow$) Suppose $(a, b) = (c, d)$.

<u>Case 1</u>: $a = b$. Then, $\lbrace a, b \rbrace = \lbrace a \rbrace$, so $(a, b) = \lbrace \lbrace a \rbrace \rbrace$. Since $\lbrace \lbrace c, \rbrace, \lbrace c, d \rbrace \rbrace = (c, d) \subseteq (a, b) = \lbrace \lbrace a \rbrace \rbrace$, it follows that $\lbrace c \rbrace = \lbrace c, d \rbrace$ and $\lbrace c \rbrace = \lbrace a \rbrace$, hence $c = d$ and $c = a$.

<u>Case 2</u>: Suppose that $a \neq b$. Then, $\lbrace a, b \rbrace \neq \lbrace a \rbrace$, as $\lbrace a, b \rbrace$ is a 2-element set. Now, $\lbrace c \rbrace \in (c, d) = (a, b) = \lbrace \lbrace a \rbrace,\lbrace a, b \rbrace \rbrace$ implies $\lbrace c \rbrace = \lbrace a \rbrace \lor \lbrace c \rbrace = \lbrace a, b \rbrace$. The latter is impossible since $\lbrace a, b \rbrace$ has 2 elements, and so $\lbrace c \rbrace  = \lbrace a \rbrace $, hence $c = a$. Similarily, $\lbrace a, b \rbrace \in (a, b) = (c, d) = \lbrace \lbrace c \rbrace , \lbrace c, d \rbrace  \rbrace $, so $\lbrace a, b \rbrace  = \lbrace c \rbrace  \lor \lbrace a, b \rbrace  = \lbrace c, d \rbrace$. As above, $\lbrace a, b \rbrace = \lbrace c \rbrace $ is impossible, so $\lbrace a, b \rbrace  = \lbrace c, d \rbrace $. Thus, $\lbrace c, d \rbrace $ is a 2-element set, hence $c \neq d$. Moreover, as $b \in \lbrace c, d \rbrace$  and $b \neq a = c$, it follows that $b = d$. $\blacksquare$

**Definition**: Given sets $A$ and $B$, the **Cartesian product** of $A$ and $B$ is

$$
    A \times B = \lbrace (a,b) : a \in A \land b \in B \rbrace
$$

**Definition**: Given sets $A,B$, a **relation** between $A$ and $B$ is any subset
$R \subseteq A \times B$. If $(a, b) \in R$, we write $aRb$ and say $a$ and $b$ are related by $R$. If $A = B$, then $R$ is a relation on $A$.

**Definition**: $R \subseteq A \times A$ is a **partial order relation** on $A$ when
1. $\forall a \in A, aRa$ (reflexivity)
1. $\forall a, b \in A, (aRb \land bRa) \implies a = b$ (antisymmetry)
1. $\forall a,b,c \in A, (aRb \land bRc) \implies aRc$ (transitivity)

**Definition**: $R$ is a **linear order** on $A$ when it is a partial order
and satisfies $\forall a,b \in A, aRb \lor bRa$ (every elemented is related to some other element).

**Example**: Let $X$ be a set an $A = \mathscr P(X)$. Consider $R = \subseteq$ on $A$. In general, $R$ is not a linear order. For example, consider $X = \mathbb N$. Then, neither $\lbrace 1 \rbrace R \lbrace 2 \rbrace$ nor $\lbrace 2 \rbrace R \lbrace 1 \rbrace$.

**Definition**: A relation $R$ on $A$ is an **equivalence relation** when
1. $R$ is reflexive
1. $R$ is transitive
1. $\forall a, b \in A, aRb \implies bRa$ (symmetry)

**Definition**: For $x \in A$, the **equivalence class** of $x$ with respect to $R$ is

$$
    [x]_R = \lbrace  y \in A : xRy \rbrace
$$

Intuitively, this is the set of all objects that are "equal" to $x$ under the relation $R$.

**Definition**: Let $A$ be a set and $R$ a partial order on $A$. Then, $(A, R)$ is a **partially ordered set** (or **poset**)

## Functions 

**Definition**: Given sets $A, B$, a non-empty relation $f \subseteq A \times B$ is a **function** between $A$ and $B$ when
$$
    \forall a \in A, \forall b_1, b_2 \in B, [(a, b_1) \in f \land (a, b_2) \in f] \implies b_1 = b_2
$$
* The **domain** $\operatorname{Dom}(f) = \lbrace a \in A : \exists b \in B, (a, b) \in f \rbrace$
* The **range** $\operatorname{Rng}(f) = \lbrace b \in B : \exists a \in A (a, b) \in f \rbrace$
* The **codomain** $\operatorname{Codomain}(f) = B$

$f$ is a function from $A$ to $B$ when $\operatorname{Dom}(f) = A$, written as $f: A \to B$.

When $(x, y) \in f$, we write $y = f(x)$ and call $y$ the image of $x$ under $f$.

**Definition**: The **characteristic function** of $A$ for some set $A \subseteq U$, where $U$ is a universal set, is

$$
  \mathcal{X}_A = U \to \lbrace 0, 1 \rbrace, \mathcal{X}_A(x) = \begin{cases}
    0 & x \in A^C \\
    1 & x \in A
  \end{cases}
$$


**Definition**: Let $f: A \to B$ be a function.
* $f$ is **injective** (one-to-one) when $((a_1, b) \in f \land (a_2, b) \in f) \implies a_1 = a_2$
  * also notated as $A \hookrightarrow B$
* $f$ is **surjective** (onto) when $\forall b \in B, \exists a \in A, (a, b) \in f$
  * also notated as $A \twoheadrightarrow B$
* $f$ is **bijective** when $f$ is injective and surjective.
  * also notated as $A \leftrightarrow B$ (our class uses a fusion of $\hookrightarrow$ and $\twoheadrightarrow$; I use $\leftrightarrow$ in these notes)

**Definition**: A **sequence** with values in $X$ is a function $f: \mathbb N \to X$. Usually, we write $f_n$ for $f(n)$.

**Definition**: Let $f: X \to Y$, $A \subseteq X, B \subseteq Y$.
* the **image** of $A$ by $f$: $f(a) = \lbrace y \in Y : \exists a \in A, y = f(a) \rbrace$
* the **inverse image** (or **preimage**) of $B$ by $f$: $f^{-1}(B) = \lbrace x \in X : \exists b \in B, f(x) = b \rbrace$

NOTE: $f^{-1}$ is not to be mistaken for the inverse function of $f$, which may not exist.

**Theorem**: Let $f: X \to Y$, $A, B \subseteq X$ and $E,F \subseteq Y$. Then,
1. $A \subseteq f^{-1}(f(A))$
1. $f(f^{-1}(E)) \subseteq E$
1. $f(A \cap B) \subseteq f(A) \cap f(B)$
1. $f(A \cup B) = f(A) \cap f(B)$
1. $f^{-1}(E \cap F) = f^{-1}(E) \cap f{-1}(F)$
1. $f^{-1}(E \cup F) = f^{-1}(E) \cup f^{-1}(F)$
1. $f^{-1}(E \setminus F) = f^{-1}(E) \setminus f^{-1}(F)$

*Proof*: TODO. $\blacksquare$

**Theorem**: Let $f: X \to Y$, $A,B \subseteq X$ and $E \subseteq Y$. Then,
1. If $f$ is injective, then $f^{-1}(f(A)) = A$.
1. If $f$ is surjective, then $f(f^{-1}(E)) = E$.
1. If $f$ is injective, then $f(A \cap B) = f(A) \cap f(B)$.

*Proof*: TODO. $\blacksquare$

**Definition**: Given $f: X \to Y$ and $g: Y \to Z$, define the **composite function** $g \circ f: X \to Z$ as

$$
g \circ f = \lbrace (x, z) \in X \times Z: \exists y \in Y, (x, y) \in f \land (y, z) \in G \rbrace.
$$

**Theorem**: Let $f: X \to Y, g: Y \to Z$. Then,
1. If $f, g$ are surjective, then so is $g \circ f$.
1. If $f, g$ are injective, then so is $g \circ f$.
1. If $f, g$ are bijective, then so is $g \circ f$.
1. If $g \circ f$ is surjective, then so is $g$.
1. If $g \circ f$ is injective, then so is $f$.
1. If $g \circ f$ is bijective, then $g$ is surjective and $f$ is injective.

*Proof*: TODO. $\blacksquare$

**Definition**: Let $f: X \leftrightarrow Y$. Define the **inverse function** of $f$, denoted $f^{-1}$, as

$$
  f^{-1} = \lbrace (y, x) \in Y \times X : (x, y) \in f \rbrace
$$

Note that since $\forall x \in X, (f^{-1} \circ f)(x) = x$ and $\forall y \in Y, (f \circ f^{-1})(y) = y$, $f^{-1} \circ f$ and $f \circ f^{-1}$ are the identity functions.

**Theorem**: For any function $f: X \to Y$, $f = f \circ \operatorname{id}_X$ and $f = \operatorname{id}_y \circ f$, where $\operatorname{id}_A$ is the identity function for $A$.

*Proof*: TODO. $\blacksquare$

**Theorem**: Let $f: X \leftrightarrow Y, g: Y \leftrightarrow Z$. Then, $g \circ f$ is a bijection and its inverse satisfies $(g \circ f)^{-1} = f^{-1} \circ g^{-1}$.

*Proof*: TODO. $\blacksquare$

**Theorem**: Let $f: X \to Y$ be any function, and suppose $g: Y \to X$ is a function such that $g \circ f = \operatorname{id}_X$ and $f \circ g = \operatorname{id}_Y$. Then, $f$ is bijective and $g = f^{-1}$.

*Proof*: TODO. $\blacksquare$



