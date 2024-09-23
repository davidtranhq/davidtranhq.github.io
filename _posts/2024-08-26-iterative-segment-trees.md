---
layout: post
title: Iterative Segment Trees
---

Let $A$ be an array of $n$ values and $f$ an associative operation on the values of $A$. A **segment tree** is a flat data structure that allows computing $f$ over any contiguous subarray of $A$ and updating the values of any contiguous subarray of $A$ in logarithmic time and linear space with respect to $n$. Some common instances of this problem:

The most common implementation of this online is recursive. Below is an iterative implementation based on TODO, which has the benefit of taking less space ($2n$ versus $4n$) and running faster. We start with a simple but less powerful implementation and build towards the full implementation.

# Idea

The idea is to precompute the value of $f$ over specific subarrays of $A$, such that the value of $f$ over any subarray of $A$ can be computed from at most $O(\log n)$ pre-computed values. A tree-like data structure accomplishes this. Let $T$ be a perfect binary tree with the $i$-th leaf from the left containing the value $f(A[i])$. Let every internal node contain the value $f(L, R)$, where $L$ and $R$ are the values of the internal node's two direct children. Note then that the internal node $I$ that is the ancestor of leaves $l_i, \dots, l_j$ contains the value of $f$ over the contiguous subarray $A[i..j]$, since $f$ is associative and consecutive leaves correspond to consecutive values in $A$. We can then compute $f$ over any subarray of $A$ by choosing the right nodes $x_1, \dots, x_k$ 

