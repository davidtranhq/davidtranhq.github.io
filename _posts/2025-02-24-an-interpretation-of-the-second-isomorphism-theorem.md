---
layout: post
toc: true
title: An Interpretation of the Second Isomorphism Theorem
---

The following theorem is fundamental in group theory but is often introduced opaquely: most texts don’t present the motivation behind it.

**Theorem (The Second Isomorphism Theorem)**: Let $G$ be a group, $H \leq G$ and $N \trianglelefteq G$. Then $HN$ is a subgroup of $G$, $H \cap N \trianglelefteq G$ and $HN/N \cong H/(H \cap N)$.

The purpose of this theorem is justified by the following natural manipulation of groups one might want to perform: let $H \leq G$ and $N \trianglelefteq G$. How might we quotient $H$ by $N$? If $H$ contains $N$ then $H/N$ is already well-defined. Otherwise, we have the following two options, each of which try to solve the problem of the $H$ not containing the group by which we want to quotient by, namely $N$:

* Extend the subgroup $H$ to “fit” $N$, then quotient by $N$
* Restrict $N$ to only the elements contained in $H$, then quotient by this restriction

The first is achieved by “extending” $H$ to $HN$—this is the smallest subgroup containing $H$ and $N$— and taking the quotient: $HN/N$. The second restricts $N$ by taking the intersection of $H$ and $N$ and taking the quotient by it: $H / (H \cap N)$. The Second Isomorphism Theorem proves that these two techniques are equivalent.

$$
HN/N \cong H/(H \cap N)
$$
