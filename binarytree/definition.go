package binarytree

import "golang.org/x/exp/constraints"

/**
 * Definiciones de las structs del árbol binario.
 */

type Node[T constraints.Ordered] struct {
	Left  *Node[T]
	Right *Node[T]
	Data  T
}

type BinaryTree[T constraints.Ordered] struct {
	Root *Node[T]
}
