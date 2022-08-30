package binarytree

import "fmt"

/**
 * Funciones de recorrido del árbol binario.
 */

func (tree *BinaryTree[T]) InOrder(node *Node[T]) {
	if node == nil {
		return
	}

	tree.InOrder(node.Left)
	fmt.Println(node.Data)
	tree.InOrder(node.Right)
}

func (tree *BinaryTree[T]) PostOrder(node *Node[T]) {
	if node == nil {
		return
	}

	tree.PostOrder(node.Left)
	tree.PostOrder(node.Right)
	fmt.Println(node.Data)
}

func (tree *BinaryTree[T]) PreOrder(node *Node[T]) {
	if node == nil {
		return
	}

	fmt.Println(node.Data)
	tree.PreOrder(node.Left)
	tree.PreOrder(node.Right)
}
