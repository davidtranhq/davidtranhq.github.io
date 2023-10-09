---
layout: default
order: 100
toc: true
---

# Exercises

## Chapter 2

### 2.1 

(1a) injective since $x + 3 = x' + 3 \implies x = x'$

surjective since given $y \in \mathbb R$, $f(y - 3) = y - 3 + 3 = y$.

(1b) injective since $x'^2 + 2x' + 1 = x^2 + 2x + 1 \implies x' = x$ (use quadratic formula on both sides)

surjective since for any $y \in \mathbb C$, $y = x^2 + 2x + 1 \implies x^2 + 2x + 1 - y = 0$, which has a solution by the Fundamental Theorem of Algebra.

(1c) injective since if $[mx + b] = [mx' + b]$ then $[x] = [x']$ (subtracting by $[b]$ and dividing by $[m]$).

surjective since any $f([x]) = [y]$ is given by $[x] = []

(1d) injective since if $\ln x' = \ln x$ then $x' = x$ (raising both sides to the power of $e$)

surjective since if $y \in \mathbb R$ then $\ln x = y$ when $x = e^y$,


(2)

(5)

(6)

(15)

(16)

(18)

(19)


### 2.2

(3a) Reflexivity holds, transitivity holds, symmetry does not (e.g. $5 \leq 10 \not\implies 10 \leq 5$)

(3b) Reflexive since $a - a = 0 \in \mathbb Q$. 

Symmetric since if $a - b \in \mathbb Q$ then $b - a \in \mathbb Q$ since if $a - b = m/n$ then $b - a = -m/n$. 

Transitive since if $a - b \in \mathbb Q$ and $b - c \in \mathbb Q$, then $(a - b) + (b - c) = a - c \in \mathbb Q$ since $+$ is a binary operation on $\mathbb Q$.

(3c) Reflexive since $\vert a - a \vert = 0 \leq 1$.

Symmetric since $\vert a - b \vert = \vert b - a \vert$.

Not transitive since $\vert 0 - 1 \vert \leq 1$ and $\vert 1 - 2 \vert \leq 1$ but $\vert 0 - 2 \gt 1$.

(4) Reflexive since $a_1 + a_2 = a_2 + a_1$.

Symmetric since $a_1 + b_2 = a_2 + b_1 \implies b_1 + a_2 = b_2 + a_1$.

Transitive since if $a_1 + b_2 = a_2 + b_1$ and $b_1 + c_2 = b_2 + c_1$ then, adding the second equation to the first and subtracting $b_1 + b_2$ yields $a_1 + c_2 = a_2 + c_1$, as desired.

(5) Note that $a_1^2 + a_2^2$ is the square of the distance of $(a_1, a_2)$ to the origin. It is easy to show that it is an equivalence relation. The equivalence classes are cirlces in $\mathbb R^2$.

(10a) Reflexive since $A \sim A$ by the identity function.

Symmetric since the inverse of a bijective function is itself bijective.

Transitive since the composition of a bijective function is itself bijective.

(10b) $2^S = \lbrace \emptyset, \lbrace 1 \rbrace, \lbrace 2 \rbrace, \lbrace 3 \rbrace, \lbrace 4 \rbrace, \lbrace 1, 2 \rbrace, \dots \rbrace$ (all subsets of $S$)

$2^S / \sim \quad = \lbrace [\emptyset], [\lbrace 1 \rbrace], [\lbrace 1, 2 \rbrace], [\lbrace 1, 2, 3 \rbrace], [\lbrace 1, 2, 3, 4 \rbrace] \rbrace$