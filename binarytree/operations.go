package binarytree

/**
 * Funciones de operaciones del árbol binario.
 */

// Checking if the tree is empty.
func (tree *BinaryTree[T]) IsEmpty() bool {
	if tree.Root == nil {
		return true
	} else {
		return false
	}
}

// Creating a node.
func (node *Node[T]) createNode(data T) {
	if node == nil {
		return
	}

	node.Data = data
	node.Right = nil
	node.Left = nil
}

// Creating a node and inserting it into the tree.
func (tree *BinaryTree[T]) Insert(data T) *BinaryTree[T] {
	node := Node[T]{}
	node.createNode(data)
	if tree.Root == nil {
		tree.Root = &node
	} else {
		tree.Root.insert(&node)
	}
	return tree
}

func (node *Node[T]) insert(newNode *Node[T]) {
	if node == nil {
		panic("Error: NIL root")
	}
	if newNode.Data <= node.Data {
		if node.Left == nil {
			node.Left = newNode
		} else {
			node.Left.insert(newNode)
		}
	} else if node.Right == nil {
		node.Right = newNode
	} else {
		node.Right.insert(newNode)
	}
}
