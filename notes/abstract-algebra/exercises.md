---
layout: default
order: 100
toc: true
---

# Exercises

## Chapter 2

### 2.1 

#### 1

(a) injective since $x + 3 = x' + 3 \implies x = x'$

surjective since given $y \in \mathbb R$, $f(y - 3) = y - 3 + 3 = y$.

(b) injective since $x'^2 + 2x' + 1 = x^2 + 2x + 1 \implies x' = x$ (use quadratic formula on both sides)

surjective since for any $y \in \mathbb C$, $y = x^2 + 2x + 1 \implies x^2 + 2x + 1 - y = 0$, which has a solution by the Fundamental Theorem of Algebra.

(c) injective since if $[mx + b] = [mx' + b]$ then $[x] = [x']$ (subtracting by $[b]$ and dividing by $[m]$).

surjective since any $f([x]) = [y]$ is given by $[x] = []

(d) injective since if $\ln x' = \ln x$ then $x' = x$ (raising both sides to the power of $e$)

surjective since if $y \in \mathbb R$ then $\ln x = y$ when $x = e^y$,

### 2.2

#### 3
(a) Reflexivity holds, transitivity holds, symmetry does not (e.g. $5 \leq 10 \not\implies 10 \leq 5$)

(b) Reflexive since $a - a = 0 \in \mathbb Q$. 

Symmetric since if $a - b \in \mathbb Q$ then $b - a \in \mathbb Q$ since if $a - b = m/n$ then $b - a = -m/n$. 

Transitive since if $a - b \in \mathbb Q$ and $b - c \in \mathbb Q$, then $(a - b) + (b - c) = a - c \in \mathbb Q$ since $+$ is a binary operation on $\mathbb Q$.

(c) Reflexive since $\vert a - a \vert = 0 \leq 1$.

Symmetric since $\vert a - b \vert = \vert b - a \vert$.

Not transitive since $\vert 0 - 1 \vert \leq 1$ and $\vert 1 - 2 \vert \leq 1$ but $\vert 0 - 2 \gt 1$.

#### 4
Reflexive since $a_1 + a_2 = a_2 + a_1$.

Symmetric since $a_1 + b_2 = a_2 + b_1 \implies b_1 + a_2 = b_2 + a_1$.

Transitive since if $a_1 + b_2 = a_2 + b_1$ and $b_1 + c_2 = b_2 + c_1$ then, adding the second equation to the first and subtracting $b_1 + b_2$ yields $a_1 + c_2 = a_2 + c_1$, as desired.

#### 5
Note that $a_1^2 + a_2^2$ is the square of the distance of $(a_1, a_2)$ to the origin. It is easy to show that it is an equivalence relation. The equivalence classes are cirlces in $\mathbb R^2$.

#### 10
(a) Reflexive since $A \sim A$ by the identity function.

Symmetric since the inverse of a bijective function is itself bijective.

Transitive since the composition of a bijective function is itself bijective.

(b) $2^S = \lbrace \emptyset, \lbrace 1 \rbrace, \lbrace 2 \rbrace, \lbrace 3 \rbrace, \lbrace 4 \rbrace, \lbrace 1, 2 \rbrace, \dots \rbrace$ (all subsets of $S$)

$2^S / \sim \quad = \lbrace [\emptyset], [\lbrace 1 \rbrace], [\lbrace 1, 2 \rbrace], [\lbrace 1, 2, 3 \rbrace], [\lbrace 1, 2, 3, 4 \rbrace] \rbrace$

## Chapter 3

### 3.5

#### 1
 $a^12 = e$, so order of $a^j$ is $12/\operatorname{gcd}(j, 12)$.

#### 2 
$a^30 = e$, $a^j$ has order $k$ when $30 \mid jk$. So $j = 15, 10, 6$ for $k = 2, 3, 5$.

#### 7
 $\mathbb Z_{18}^\times, \mathbb Z_{27}^\times$

#### 8
 $\langle \pi \rangle = \lbrace \pi^k \mid k \in \mathbb Z \rbrace$

#### 9
 $\mathbb Z_4 \times \mathbb Z_2 = \lbrace (0, 0), (0, 1), (1, 0), (1, 1), \dots, (3, 0), (3, 1) \rbrace$

$\langle (0, 0) \rangle = \lbrace (0, 0) \rbrace$

$\langle (0, 1) \rangle = \lbrace (0, 1), (0, 0) \rbrace$

$\langle (1, 0) \rangle = \lbrace (1, 0), (2, 0), (3, 0), (0, 0) \rbrace$

$\langle (1, 1) \rangle = \lbrace (1, 1), (2, 0), (3, 1), (0, 0) \rbrace$

...

(see the back of the book for the rest, all elements are generators of a cyclic subgroup)

#### 10
 Write out all subgroups generated from every $(x, y) \in \mathbb Z_6 \times \mathbb Z_3$...

### 3.7

#### 2
$\phi(x) = [mx]_{12}$ where $m$ and $12$ are coprime define all homomorphisms. (See Example 3.7.6).

#### 3
(a) $\phi(xy) = \vert xy \vert = \vert x \vert \vert y \vert = \phi(x)\phi(y)$

(b) $\phi(xy) = \frac{xy}{\vert xy \vert} = \frac{x}{\vert x \vert} \frac{y}{\vert y \vert} = \phi(x)\phi(y)$

(c) same as (b)

#### 4
$\phi(x * y) = (x * y)^n = x^n * y^n = \phi(x) * \phi(y)$. Note that the distirbution of $n$ is only possible because $G$ is abelian.

#### 7
$\phi((a + bi)(c + di)) = \phi((ac - bd) + i(ad + bc)) = (ac - bd)^2 + (ad + bc)^2 = ... = (a^2 + b^2)(c^2 + d^2) = \phi(a + bi)\phi(c + di)$ (see [here for the algebra](https://www.symbolab.com/solver/simplify-calculator/simplify%20%5Cleft(ac%20-%20bd%5Cright)%5E%7B2%7D%2B%5Cleft(ad%2Bbc%5Cright)%5E%7B2%7D?or=input))


#### 11

*If $G_1$ is abelian then so is $G_2$*.

*Proof*: Suppose $G_1$ is abelian. Let $c, d \in G_2$. By surjectivity of $f$, choose $a, b$ such that $c = f(a)$ and $d = f(b)$. Then $ab = ba$, so $cd = f(a)f(b) = f(ab) = f(ba) = f(b)f(a) = dc$. $\blacksquare$

*Counterexample of the converse*: Let $G_1 = GL_2(\mathbb R)$ and $G_2 = \lbrace e \rbrace$, with $f$ mapping everything to $e$. Then $G_2$ is abelian and $f$ is a surjective homomorphism, but $G_1$ is not abelian.

*If $G_1$ is cyclic then so is $G_2$*.

*Proof*: Suppose $G_1$ is cyclic. Let $G_1 = \langle a \rangle$. Let $b = f(a)$. $\langle b \rangle \subseteq G_2$ from the closure property of groups. Let $x \in G_2$. By surjectivity of $G_2$, $x = f(a^n)$ for some $n$. Then, $x = f(a^n) = f(a)^n = b^n$. So $x \in \langle b \rangle$, and $G_2 \subseteq \langle b \rangle$. So $G_2$ is cyclic. $\blacksquare$

*Counterexample of the converse*: Let $G_1 = \mathbb Z_2 \times \mathbb Z_2$ and $G_2 = \lbrace e \rbrace$, with $f$ mapping everything to $e$. Then $G_2$ is cyclic and $f$ is a surjective homomorphism, but $G_1$ is not cyclic.