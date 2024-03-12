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
3. Powers are preserved under homomorphism.
4. The kernel is a subgroup of $G$.
5. The image of $G$ under $\varphi$ is a subgroup of $H$.

*Proof*: (1) $\varphi(1 \cdot 1) = \varphi(1)\varphi(1) = \varphi(1)$, so $\varphi(1) = 1_H$ by cancellation. $\blacksquare$

(2) $\varphi(1) = \varphi(gg^{-1}) = \varphi(g)\varphi(g^{-1}) = 1$, and multiplying on the left by $\varphi(g)^{-1}$ gives $\varphi(g^{-1}) = \varphi(g)^{-1}$. $\blacksquare$

(3) By induction: suppose $\varphi(g^n) = \varphi(g)^n$. Then $\varphi(g^n \cdot g) = \varphi(g)^n\varphi(g) = \varphi(g^{n + 1})$. And the base case holds for $n = 1$ trivially. $\blacksquare$

(4) $1 \in \operatorname{ker} \varphi$ so it is non-empty. Let $a, b \in \operatorname{ker} \varphi$. Then $\varphi(ab^{-1}) = \varphi(a)\varphi(b^{-1}) = 1$ so $ab^{-1} \in \operatorname{ker} \varphi$. $\blacksquare$

(5) $\varphi(G)$ is non-empty since identity is preserved. Let $a, b \in \varphi(G)$. Then $\varphi(x) = a$ and $\varphi(y) = b$ for some $x. y \in G$. $\varphi(y^{-1}) = b^{-1}$, so $\varphi(xy^{-1}) = ab^{-1}$. $\blacksquare$

**Definition**: Let $\varphi: G \to H$ be a homomorphism with kernel $K$. The **quotient group** or **factor group**, $G/K$ (read **$G$ modulo $K$** or **$G$ mod $K$**) is the group whose elements are the fibers of $\varphi$ with the group operation between two fibers above $a$ and $b$ as the fiber above the product $ab$.

**Proposition 2**: Let $\varphi: G \to H$ be a homormophism of groups with kernel $K$. Let $X \in G/K$ be the fiber above $a$. Then
1. For any $u \in X, X = \lbrace uk \mid k \in K \rbrace$.
2. For any $u \in X, X = \lbrace ku \mid k \in K \rbrace$.

*Proof*: (1) Let $u \in X$. We first show $X \subseteq uK$. Let $g \in X$. Let $k = u^{-1}g$. Then $\varphi(k) = 1$ so $k \in \operatorname{ker} \varphi$, $g = uk$, so $g \in uK$. Thus $X \subseteq uK$. Now let $g \in uK$. Then $\varphi(g) = \varphi(u)\varphi(k) = \varphi(u) = a$ since $u \in X$, so $g \in X$. Thus $uK \subseteq X$. $\blacksquare$

(2) Proceeds symmetrically as (1).

**Definition**: For any $N \subseteq G$ and any $g \in G$, let

$$
gN = \lbrace gn \mid n \in N \rbrace
$$

and

$$
Ng = \lbrace ng \mid n \in N \rbrace
$$

be the **left coset** and **right coset** of $N$ in $G$, respectively. Any element of a coset is called a **representative** for the coset.

Note that Proposition 2 tells us that $gN = g'N$ for any $g' \in gN$, motivating the nomenclature of a coset representative.

**Lemma 3**: Let $N \leq G, u, v \in G$. The following are equivalent:
1. $uN = vN$
2. $u \in vN$
3. $v^{-1}u \in N$
4. $u, v$ are representatives of the same coset.

*Proof*: $(1 \to 2)$. Suppose $uN = vN$. Then $x = un_u = vn_v$ for some $x \in uN, n_u, n_v \in N$.So $u = vn_vn_u^{-1} \in vN$.

$(2 \to 3)$ Suppose $u \in vN$. Then $u = vn$ for some $n \in N$, so $v^{-1}u = n$, so $v^{-1}u \in N$.

$(3 \to 1)$ Suppose $v^{-1}u \in N$. Let $x \in uN$. Then $x = un$ for some $n \in N$, so $u = xn^{-1}$. Thus $v^{-1}u = vxn^{-1}$, so $x = v^{-1}(v^{-1}u)n$. By the assumption, $v^{-1}u \in N$, so $v^{-1}un \in N$, so $x \in vN$. So $uN \subseteq vN$. Symmetrically, $vN \subseteq uN$, so $uN = vN$.


**Theorem 3**: Let $G$ be a group and let $K$ be a kernel of some homomorphisms from $G$ to another group. Then the set whose elements are the left cosets of $K$ in $G$ with operation defined by

$$
uK \circ vK = (uv)K
$$

is well-defined.

*Proof*: First we show the operation is well-defined. Let $uK = u'K$ and $vK = v'K$. By Proposition 2, it suffices to show that $u'v' \in (uv)K$. By Proposition 2, $u' \in uK$, so $u' = uk_u$. Similarily, $v' = vk_v$. So $u'v' = (uk_u)(vk_v)$, and $\varphi(u'v') = \varphi(uk_u)\varphi(vk_v) = \varphi(u)\varphi(v)$. So $u'v'$ and $uv$ are in the same coset of $K$, that is, $u'v' \in (uv)K$.

**Examples**:
* The fibers of $\varphi: \mathbb Z \to Z_n$, $\varphi(k) = k \pmod n$ are $a + n\mathbb Z$. The group $\mathbb Z/n\mathbb Z$ is thus isomorphic to $Z_n$.
* If $\varphi: G \to H$ is an isomorphism, then $K = 1$, and the fibers of $\varphi$ are the singleton subsets of $G$.
* The trivial homomorphism of $G$ (the homomorphism mapping everything to $1$) has a kernel of $G$, and shows $G/G \cong \lbrace 1 \rbrace$.
* The projection of vectors in $\mathbb R^2$ on the x-axis is a homomorphism, with fibers being the vertical lines crossing the x-axis, and the kernel the vertical line crossing the orgin.
* To show that $Q_8/\lbrace \pm 1 \rbrace \cong V_4$, define the homomorphism $\varphi: Q_8 \to V_4$ as $\varphi: \pm 1 \mapsto 1, \pm i \mapsto a, \pm j \mapsto b, \pm k \mapsto c$. 

$(2 = 4)$ $u \in vN$ if and only if $u$ is a representative of $vN$, so $uN = vN$ if and only if $u$ and $v$ are representatives of the same coset. $\blacksquare$

**Proposition 4**: Let $N \leq G$. The set of left cosets of $N$ form a partition of $G$. 

*Proof*: First we show $\bigcup_{g \in G} gN = G$. Let $x \in gN$. Then $x = gn$ for some $g \in G$, $n \in N \subseteq G$ so $x \in G$ by closure. Now suppose $x \in G$. Since $N \leq G$, $1 \in N$, so $x = x1 \in gN$. This shows subset inclusion in both directions, so $\bigcup_{g \in G} gN = G$.

Next we show that $uN \cap vN = \emptyset$ for $uN \neq vN$. Suppose $uN \cap vN \neq \emptyset$. Then $x = un_u = vn_v$ for some $x \in uN \cap vN$, $n_u, n_v \in N$. In particular, $u = vn_vn_u^{-1} \in vN$, so $uN = vN$. $\blacksquare$

**Proposition 5**: Let $G$ be a group and $N \leq G$. The operation on left cosets $uN \cdot vN = (uv)N$ is well defined if and only if $gng^{-1} \in N$ for all $g \in G$ and $n \in N$. This operation also defines a group on the set of left cosets of $N$.

*Proof*: Suppose $gng^{-1} \in N$ for all $g \in G, n \in N$. Then $gn = n'g$ for some $n' \in N$. We show that if $u' \in uN$ and $v' \in vN$,

$$
\begin{align*}
    u'v' &= (un_u)(vn_v) \\
         &= uv(n_u'n_v) \\ 
         &\in (uv)N
\end{align*}
$$

whre $n_u, n_v, n'_u \in N$, and the second line uses the assumption.

Now suppose the operation is well-defined. Then for all $u, u' \in uN$ and $v, v' \in vN$, $uvN = u'v'N$. Let $g \in G, n \in N$. In particular, choose $u = 1$, $u' = n$, $v = v' = g^{-1}$. Note that $u \in u'N$ since $1 \in N$ and $v \in v'N$ since $v = v'$, both by Lemma 3. We have $g^{-1}N = ng^{-1}N$, so $gng^{-1}N = N$, so $gng^{-1} \in N$, by Lemma 3.

That this operation defines a group follows from the associativity of $G$. It can also be shown that the identity is $1N$ and the inverse for some coset $aN$ is $a^{-1}N$. $\blacksquare$

**Definition**: The element $gng^{-1}$ is called the **conjugate** of $n \in N$ by $g$. The set $gNg^{-1} = \lbrace gng{-1} \mid n \in N \rbrace$ is called the **conjugate** of $N$ by $g$. The element $g$ **normalizes** $N$ if $gNg^{-1} = N$. A subgroup $N \leq G$ is called **normal** if every element of $G$ normalizes $N$, and is written $N \trianglelefteq G$

**Theorem 6**: Let $N \trianglelefteq G$. The following are equivalent:
1. $N \trianglelefteq G$
2. $N_G(N) = G$
3. $gN = Ng$ for all $g \in G$
4. The operations on left cosets of $N$ in $G$ in Proposition 5 makes the set of left cosets into a group.
5. $gNg^{-1} \subseteq N$ for all $g \in G$

*Proof*: $(1 \to 2)$ by definition.

$(2 \to 3)$ Suppose $gNg^{-1} = N$ for all $g \in G$. If $gn \in gN$, then $gng^{-1} = n'$ for some $n' \in N$, so $gn = n'g$ and $gn \in Ng$. So $gN \subseteq Ng$, and symmetrically, $Ng \subseteq gN$. So $gN = Ng$.

$(3 \to 4)$ If $gN = Ng$ then $gng^{-1} \in N$ for all $g \in G, n \in N$, and $(4)$ follows from Proposition 5.

$(4 \to 5)$ If $(4)$, then $gng^{-1} \in N$ by Proposition 5, so $(5)$.

$(5 \to 1)$ Let $n \in N$, $g \in G$. Then $g^{-1}ng = n'$ for some $n' \in N$, so $n = gn'g^{-1} \in gNg^{-1}$. So $N \subseteq gNg^{-1}$ and $N = gNg^{-1}$, thus $N \trianglelefteq G$, by definition. $\blacksquare$

**Proposition 7**: A subgroup $N \trianglelefteq G$ if and only if it is the kernel of some homomorphism.

*Proof*: Suppose $N \trianglelefteq G$. Define $\phi: G \to G/N$ as $\phi(g) = gN$. It is a homomorphism since $\phi(xy) = (xy)N = (xN)(yN) = \phi(x)\phi(y)$, since the operation is well-defined by Proposition 5. Also $\operatorname{ker}(\phi) = N$ since $gN = 1N = N$ if and only if $g \in N$ by Lemma 3.

Now suppose $N$ is the kernel of some homomorphism. We show that $gNg^{-1} \subseteq N$, from which $N \trianglelefteq G$ follows from Theorem 6. Let $gng^{-1} \in gNg^{-1}$. and $\phi$ the homomorphism for which $N$ is a kernel. Then $\phi(gng^{-1}) = \phi(g)\phi(n)\phi(g^{-1}) = \phi(g)\phi(g^{-1}) = 1$, so $gng^{-1} \in \operatorname{ker}\phi = N$. 

(For an even shorter proof of this converse, note that by Proposition 2 the left and right cosets of the kernel coincide, thus by $(3)$ in Theorem 6, $N \trianglelefteq G$.)
$\blacksquare$

**Definition**: Let $N \trianglelefteq G$. The homomorphism $\pi: G \to G/N$ defined by $\pi(g) = gN$ is the **natural projection (homomorphism)** of $G$ onto $G/N$. If $\overline H \leq G/N$ is a subgroup of $G/N$, the **complete preimage** of $\overline H$ is $\pi^{-1}(\overline H)$.

**Examples**:
* The subgroups $1$ and $G$ are always normal in $G$.
* If $G$ is abelian, any subgroup $N \leq G$ is normal since $gng^{-1} = gg^{-1}n = n$, for $g \in G, n \in N$. 
  * Note that it is not sufficient for $N$ to be abelian, since $H = \lbrace 1, (12) \rbrace \leq S_3$ is abelian, but $gHg^{-1} = \lbrace 1, (23), \rbrace \neq H$ for $g = (13)$.
* If $N \leq Z(G)$, then $N \trianglelefteq Z(G)$ since $gng^{-1} = n \in N$.
* Let $G$ be a cyclic group of order $k$. Let $N \leq G$. Then $N = \langle x^d \rangle$ for some $x$ \in G$ where $d$ is the smallest power such that $x^d \in N$. Then $G/N$ is cyclic since 
  
$$
G/N = \lbrace gN \mid g \in G \rbrace = \lbrace x^aN \mid a \in \mathbb Z \rbrace = \lbrace (xN)^a \mid a \in \mathbb Z \rbrace
$$

by Exercise 4. Thus, quotient groups of cyclic groups are cyclic.

The exercises below highlight some additional important properties, e.g.

* The preimage of a homomorphism of a subgroup is a subgroup (Exercise 1).
* The preimage of a homomorphism of a snormal subgroup is a normal subgroup (Exercise 1).
* The quotient group of an abelian group is itself abelian. (Exercise 3).
* The order of $gN$ in a quotient group $G/N$ is the smallest $n$ such that $g^n \in N$ (note, this is NOT the order of $g \in G$). (Exercise 5)

### Exercises

**Exercise 1**: Let $\phi: G \to H$ be a homomorphism and $E \leq H$. Then $\phi^{-1}(E) \leq G$. If $E \trianglelefteq H$, then $\phi^{-1}(E) \trianglelefteq G$. And, $\operatorname{ker} \phi \trianglelefteq G$.

*Proof*: $1 \in \phi^{-1}(E)$ since $1 \in E$ and $\phi(1^{-1}) = \phi(1)^{-1}$. So $\phi^{-1}(E)$ is non-empty. Now let $a, b \in \phi^{-1}(E)$. Then $\phi(a), \phi(b) \in E$, so $\phi(a)\phi(b)^{-1} = \phi(ab^{-1}) \in E$, so $ab^{-1} \in \phi^{-1}(E)$. 

Now suppose $E \trianglelefteq H$. Let $g \in G$ and $x \in \phi^{-1}(E)$. Then $\phi(gxg^{-1}) \in E$ by normality of $E$ so $gxg^{-1} \in \phi^{-1}(E)$.

Finally, $\operatorname{ker} \phi \trianglelefteq G$ by Proposition 7.

$\blacksquare$

**Exercise 2**: Let $\phi: G \to H$ be a homomorphism with kernel $K$ and $a, b \in \phi(G)$ with corresponding fibers $X, Y$. Let $u \in X$. Show that if $XY = Z$ in $G/K$ and $w \in Z$, then there is a $v \in Y$ with $uv = w$.

*Proof*: Since $XY = Z, Y = X^{-1}Z = (u^{-1}K)(wK) = (u^{-1}w)K$. So $u^{-1}w \in Y$. $\blacksquare$

**Exercise 3**: Let $A$ be an abelian group and $B \leq A$. Then $A/B$ is abelian. Give an example of a non-abelian group containing a proper normal subgroup $N$ with $G/N$ abelian.

*Proof*: Let $X, Y \in A/B$. Let $x \in X, y \in Y$ Then $XY = xByB = xyB = yxB = yBxB$. 

(Note we use Proposition 2 in the claim that $X = xB$ and $Y = yB$). $\blacksquare$

For an example, consider $S_3/\lbrace 1, (12) \rbrace$, which is abelian.

**Exercise 4**: Prove that in the quotient gruop $G/N, (gN)^\alpha = g^\alpha N$ for all $\alpha \in \mathbb Z$.

*Proof*: $(gN)(gN) = ggN = g^2N$, and the exercise follows by induction. Negative powers proceed likewise with $g^{-1}$. $\blacksquare$

**Exercise 5**: Prove the order of $gN$ in $G/N$ is $n$, where $n$ is the smallest positive integer such that $g^n \in N$, and infinite order if no such $n$ exists.

*Proof*: By Exercise 4, the smallest $n$ such that $(gN)^n = N$ is precisely the smallest such $n$ such that $g^n \in N$. since if $g^n \in N$ then $g^nN = N$ (and likewise for the infinite case).$\blacksquare$  

The example holds whenever $g \in N$ but $g \neq 1$. For example, let $G = \mathbb Z_6$ and $N = \mathbb Z_3$. Then the order of $g = 3$ is 2 but the order of $gN = 3 + \mathbb Z_3 = \mathbb Z_3$ is 1.

**Exercise 14**: Consider the additive quotient group $\mathbb Q/\mathbb Z$.

**a.** Show that every coset of $\mathbb Z$ in $\mathbb Q$ contains exactly one representative $q \in \mathbb Q$ in the range $0 \leq q \lt 1$.

*Proof*: Consider $r + \mathbb Z$, $r \in \mathbb Q$. The sole representative is $r - k$ where $k$ is the largest integer smaller than $r$. $0 \leq r - k \lt 1$ since $0 \leq r - k$ since $r$ is larger than $k$ and $r - k \lt 1$ since if it weren't, then $1 \leq r - k$ and $k + 1$ would be a larger integer smaller than $r$; a contradiction. $\blacksquare$

**b.** Show that every element of $\mathbb Q/\mathbb Z$ has finite order, but there are elements of arbitrarily large order.

*Proof*: Every element $a/b + \mathbb Z$ has finite order since $b(a/b) \in \mathbb Z$. The order is $\operatorname{lcm}(a, b)$, so orders can be made arbitrarily large by choosing $a, b$ with arbitrarily large LCMs. $\blacksquare$

**c.**: Show that $\mathbb Q/\mathbb Z$ is the torsion subgroup of $\mathbb R/\mathbb Z$.

*Proof*: If $r + \mathbb Z$ where $r \in \mathbb R$ is irrational, then $kr \neq n$ for any $n \in \mathbb Z$ for all $k \in \mathbb Z$ since if it did, then $r = k/n$, contradicting that $r$ is irrational. $\blacksquare$

**Exercise 15**: Prove that the quotient of a divisible abelian group by any proper subgroup is also divisible.

*Proof*: Let $G$ be a divisible abelian group with $H \lt G$. Let $X \in G/H$ and $k \in \mathbb Z$. Let $x \in X$ and $y \in Y$ such that $y^k = x$, by divisibility. Then $Y^k = (yH)^k = xH = X$. $\blacksquare$

**Exercise 16**: Let $G$ be a group and $N \trianglelefteq G$. Define $\overline G = G/N$. Show that if $G = \langle S \rangle$ for any $S \subseteq G$, then $\overline G = \langle \overline S \rangle$.

*Proof*: Let $X \in \overline G$ and $x \in X$. Then $x$ is some finite product of elements in $S$. So $X$ is some finite product of elements in $\overline S$ since $aNbN = abN$. So $X \in \langle \overline S \rangle$ and $\overline G \subseteq \langle \overline S \rangle$. Similar in the opposite direction. $\blacksquare$

**Exercise 42**: Let $H, K \trianglelefteq G$ with $H \cap K = 1$. Prove that $xy = yx$ for all $x \in H$ and $y \in K$.

*Proof*: Let $x \in H, y \in K$. Then $x^{-1}y^{-1}xy = x^{-1}h \in H$ where $h = y^{-1}xy \in H$ by normality of $H$. Similarily, $x^{-1}y^{-1}xy = ky \in K$ where $k = x^{-1}y^{-1}x \in K$ by normality of $K$. So $x^{-1}y^{-1}xy \in H \cap K = 1$, so $xy = yx$. $\blacksquare$

## More on Cosets and Lagrange's Theorem

**Theorem 8 (Lagrange's Theorem)**: If $G$ is a finite group and $H$ is a subgroup of $G$, then the order of $H$ divides the order of $G$, and the number of left cosets of $H$ in $G$ equals $\vert G \vert/\vert H \vert$.

*Proof*: By Proposition 4, the cosets of $H$ define a partition over $G$, so it suffices to show that $\vert gH \vert = \vert H \vert$ for any coset $gH$. Define $\sigma_g: H \to gH$ as $h \mapsto gh$, which is surjective since $gh = \sigma_g(h)$ and injective since if $gh = gh'$ then $h = h'$ by cancellation. So $\vert G \vert = k\vert H \vert$, where $k$ is the number of cosets of $H$.

Consequently, $k = \vert G \vert / \vert H \vert$. $\blacksquare$

**Definition**: If $G$ is a group and $H \leq G$, the number of left cosets of $H$ in $G$ is called the **index** of $H$ in $G$ and denoted $\vert G : H \vert$.

**Corollary 9**: If $G$ is a finite group and $x \in G$, then the order of $x$ divides the order of $G$.

*Proof*: $\langle x \rangle$ is a subgroup of $G$, so $\vert \langle x \rangle \vert = \vert x \vert \mid \vert G \vert$. $\blacksquare$

**Corollary 10**: If $G$ is a group of prime order $p$, then $G$ is cyclic.

*Proof*: $G$ must not be trivial, so let $x \in G - \lbrace 0 \rbrace$. Then by Lagrange's, $\vert \langle x \rangle \vert = p$ (not 1 since $x \neq 1$), so $\langle x \rangle = G$.

**Example**: Any subgroup $H \leq G$ of index 2 is normal in $G$.

*Proof*: Consider the 2 cosets of $H$, $H$ and $gH$. Since cosets form a partition, $gH = G - H$. Similarily, the 2 right cosets of $H$ are $H$ and $Hg$, and $Hg = G - H$. $gH = Hg$ so $H$ is normal. $\blacksquare$

**Theorem 11 (Cauchy's Theorem)**: If $G$ is a finite group and $p$ is a prime dividing $\vert G \vert$, then $G$ has an element of order $p$.

*Proof*: Later. $\blacksquare$

**Theorem 12 (Sylow)**: If $G$ is a finite group of order $p^\alpha m$, where $p$ is prime and $p \nmid m$, then $G$ has a subgroup of order $p^\alpha$.

*Proof*: Later. $\blacksquare$

**Definition**: Let $H$ and $K$ be subgroups of a group. Then the **direct product** $HK = \lbrace hk \mid h \in H, k \in K \rbrace$.

**Proposition 13**: If $H$ and $K$ are finite subgroups of a group, then

$$
\vert HK \vert = \frac{\vert H \vert \vert K \vert}{\vert H \cap K \vert}
$$

*Proof*: Note that $HK = \bigcup_{h \in H} hK$. The distinct cosets of $hK$ are the distinct cosets of $h(H \cap K)$, since if $h_1, h_2 \in K$ then $h_1K = h_2K$. By Lagrange's Theorem, $\vert H : H \cap K\vert = \vert H \vert/\vert H \cap K \vert$. We showed in the proof of Lagrange's Theorem that $\vert hK \vert = \vert K \vert$. Multiplying the number of distinct cosets by the order of each coset gives the result. $\blacksquare$

**Proposition 14**: If $H$ and $K$ are subgroups of a group, $HK$ is a subgroup if and only if $HK = KH$.

*Proof*: Suppose $HK = KH$. First note that $HK$ is non-empty since $H$ and $K$ are non-empty. Let $a, b \in HK$. Then $ab^{-1} = hkk'^{-1}h'^{-1}$ for some $h, h' \in H$ and $k, k' \in K$. Since $KH = HK$, $kk'^{-1}h'^{-1} = h^\star k^\star$ for some $h^\star \in H$ and $k^\star \in K$. So $ab^{-1} \in HK$, and $HK$ is a subgroup by the subgroup criterion.

Now suppose $HK$ is a subgroup. Let $x \in HK$. Since $HK$ is a subgroup, $x = (hk)^{-1}$ for some $hk \in HK$. Then $x^{-1} = (h'k')^{-1} = k'^{-1}h'^{-1} \in KH$, so $HK \subseteq KH$. A symmetric argument shows $KH \subseteq HK$.
$\blacksquare$

**Definition**: If $A \subseteq N_G(K)$ (or $C_G(K)$), then $A$ **normalizes** $K$ (**centralizes** $K$).

**Corollary 15**: If $H$ and $K$ are subgroups of $G$ and $H$ normalizes $K$, then $HK \leq G$.

*Proof*: Let $hk \in HK$. Since $H$ normalizes $K$ $k = h^{-1}k'h$ for some $k'$, so $hk = hh^{-1}k'h = k'h \in KH$ so $HK \subseteq KH$. Similarily KH \subseteq HK$, so by Proposition 14, $HK \leq G$. $\blacksquare$

Some properties shown in the exercises:
* If a subgroup is the sole subgroup of its order, then it is normal. (Exercise 5)
* Let $K \leq H \leq G$ where $H$ has finite index in $G$. Then $\vert G : K\vert = \vert G : H\vert\vert H : K\vert$. (used in Exercise 11).
* The number of left cosets equals the number of right cosets by the correspondence $x \mapsto x^{-1}$ (Exercise 12).

### Exercises

**Exercise 1**: Only the orders $n$ that divide 120, and their corresponding index is $120/n$.

**Exercise 4**: Show that if $\vert G \vert = pq$ for some primes $p, q$ (not necessarily distinct), then $G$ is abelian or $Z(G) = 1$.

*Proof*: By Lagrange's theorem, the order of $Z(G)$ is either $pq, p, q$ or 1. If the order is $pq$, then $Z(G) = G$ so $G$ is Abelian. If it is $p$ (or $q$), then $\vert G/Z(G) \vert = q$ (or $p$), so it is cyclic and thus Abelian by Corollary 10. Thus, $G$ is either Abelian or $\vert Z(G) \vert = 1$ so $Z(G) = 1$. $\blacksquare$

**Exercise 5**: Let $H$ be a subgroup of $G$ and let $g \in G$.

**a.** Prove that $gHg^{-1}$ is a subgroup of $G$ and of same order as $H$.

*Proof*: $H' = gHg^{-1}$ is non-empty since $H$ is non-empty. Let $a, b \in H'$. Then $ab^{-1} = (gxg^{-1})(gyg^{-1}) = gxyg^{-1} \in H'$ for some $x, y \in H$. So $H'$ is a subgroup. To show that $\vert H' \vert = \vert H \vert$, define the map $\phi: H \to H'$ as $h \mapsto ghg^{-1}$, which can easily be shown to be an isomorphism. $\blacksquare$

**b.** Deduce that if $n \in \mathbb Z^+$ and $H$ is the unique subgroup of $G$ of order $n$ then $H \trianglelefteq G$. 

*Proof*: By (a), $gHg^{-1}$ is a subgroup of $G$ of order $n$, so $H = gHg^{-1}$. $\blacksquare$

**Exercise 6**: Let $H \leq G$ and let $g \in G$. Prove that if $Hg$ equals some left coset of $H$, then $Hg = gH$ and $g \in N_G(H)$.

*Proof*: Suppose $Hg = xH$ where $x \in G$. Note that $g \in gH$ and $g \in Hg$ since $1 \in H$, so $g \in xH$. Since $xH$ and $gH$ share an element, $gH = xH$. So $Hg = gH$ and $g$ normalizes $H$. $\blacksquare$

**Exercise 8**: Prove that if $H$ and $K$ are finite subgroups of $G$ whose orders are relatively prime then $H \cap K = 1$.

*Proof*: Since $H \cap K$ is a subgroup of $H$ and of $K$, if $\vert H \cap K \vert = n \neq 1$, then by Lagrange's, $n$ divides $H$ and $K$, so their orders are not relatively prime. $\blacksquare$

**Exercise 10**: Suppose $H$ and $K$ are subgroups of finite index $m$, $n$, respectively, in $G$ (possibly infinite). Prove that $\operatorname{lcm}(m,n) \leq \vert G : H \cap K \vert \leq mn$.

*Proof*: First, note that $a(H \cap K) = aH \cap aK$, so the number of cosets of $H \cap K$ is at most the product of the number of cosets of $aH$ and of $aK$, that is, $mn$. For the lower bound, note that since $H \cap K \leq H$ and $H \cap K \leq K$,

$$
\vert G : H \cap K\vert = \vert G : K\vert\vert K : H \cap K\vert = \vert G : H\vert\vert H : H \cap K\vert
$$

since $H \cap K$ partitions $H$ which partitions $G$ (likewise for $H \cap K$ paritioning $K$ partitioning $G$) (see Exercise 11 for a complete proof). So $m$ and $n$ divide $\vert G : H \cap K\vert$, so $\operatorname{lcm}(m, n) \leq \vert G : H \cap K\vert$. $\blacksquare$

**Exercise 11**: Let $H \leq K \leq G$. Prove that $\vert G : H \vert = \vert G : K \vert \cdot \vert K : H \vert$.

*Proof*: Let $n = \vert G : K \vert, m = \vert K : H \vert$. We have

$$
\begin{align*}
G = \bigsqcup_{g \in G} gK = \bigsqcup_{g \in G}g\bigsqcup_{k \in K}kH = \bigsqcup_{g \in G, k \in K} gkH
\end{align*}
$$

and there are $mn$ distinct cosets of $gkH$. $\blacksquare$

**Exercise 12**: Let $H \leq G$. Prove that $x \mapsto x^{-1}$ maps each left coset of $H$ in $G$ onto a right coset of $H$ and gives a bijection between the set of left cosets and the set of right cosets of $H$ in $G$.