---
layout: default
toc: true
order: 1
---

## Orthogonal Matrices

**Definition**: A set of vectors is called **orthonormal** if they are mutually orthogonal and all of length 1.

**Definition**: An **orthogonal matrix** is a square matrix whose columns form an orthonormal set.

**Proposition**: $Q$ is an orthogonal matrix if and only if $Q^TQ = I$.

*Proof*: Since the columns form an orthonormal basis, the dot product of any two non-equal vectors is 0, where the dot product of each vector with itself (along the diagonal of $Q^TQ$ is 1). $\blacksquare$

The following properties follow from the above:
* $Q^T = Q^{-1}$
* $Q^T$ is orthogonal
* The rows of $Q$ form an orthonormal set.

**Proposition**: In $\mathbb R^2$, every orthogonal matrix is either a reflection or a rotation.

The following properties follow from above: