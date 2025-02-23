---
layout: default
order: 2
toc: true
---

# Constructions on Categories

## Duality

Categorical duality is the process of reversing all arrows. For example, the dual statement of $f: a \to b$ is $f: b \to a$; the dual statement of "$f$ is monic" is "$f$ is epi", and the dual of "$t$ is terminal" is "$t$ is initial".

The duality principle also applies to statements involving several categories and functors between them. Note that the duality here reverses the arrows in the category, not the functor between them.

## Contravariance and Opposites

Each category $C$ has an **opposite category** $C^{op}$: the transpose of the  category’s graph. A **contravariant functor** $\overline S$ on $C$ to $B$ maps from $C^{op}$ to $B$. Note that as a result the order of the requirement of composition is inverted for a contravariant functor: $\overline S(f g) = (\overline S g)(\overline S f)$. An example of a contravariant functor on the category of rings is the association of a ring with its opposite. A functor $T: C \to B$ as previously defined is a **covariant functor** on $C$ to $B$.

