#ifndef RBTREE_H
#define RBTREE_H
#include"RBNode.h"
#include<vector>
template<typename T> class RBTree {
public:
	RBTree();
	~RBTree();
	bool leftRotate(RBNode *node);
	bool rightRotate(RBNode *node);
	void RBInsert(const T &key);
	void RBInsertFixUp(RBNode *node);
	bool isEmpty() const;
private:
	RBNode<T> *root;
	RBNode<T> *copyRoot;
	std::vector<RBNode<T>*> RBVec;
};

template<typename T> RBTree<T>::RBTree() :root(nullptr), copyRoot(nullptr) {

}

template<typename T> RBTree<T>::~RBTree() {
	for (auto &c : RBVec) {
		delete c;
		c = nullptr;
	}
	if (copyRoot) {
		delete copyRoot;
		copyRoot = nullptr;
	}
	root = nullptr;
}

template<typename T> bool RBTree<T>::isEmpty() const {
	return root == nullptr;
}

template<typename T> bool RBTree<T>::leftRotate(RBNode<T> *node) {
	if (!node->right) {
		std::cout << "旋转节点的有孩子是空的。。。。。。。。。。。。。" << < std::endl;
		return false;
	}
	RBNode<T> *rightNode = node->right;
	node->right = rightNode->left;
	if (rightNode->left)
		rightNode->left->parent = node;
	rightNode->parent = node->parent;
	if (!node->parent)
		root = rightNode;
	else if (node == node->parent->left)
		node->parent->left = rightNode;
	else
		node->parent->right = rightNode;
	rightNode->left = node;
	node->parent = rightNode;
	return true;
}

template<typename T> bool RBTree<T>::rightRotate(RBNode<T> *node) {
	if (!node->left) {
		std::cout << "右旋点的左孩子是空的。。。。。。。。。。。。。。" << std::endl;
		return false;
	}
	RBNode<T> *leftNode = node->left;
	node->left = leftNode->right;
	if (leftNode->right)
		leftNode->right->parent = node;
	leftNode->parent = node->parent;
	if (!node->parent)
		root = leftNode;
	else if (node == node->parent->left)
		node->parent->left = leftNode;
	else
		node->parent->right = leftNode;
	leftNode->right = node;
	node->parent = leftNode;
	return true;
}

template<typename T> void RBTree<T>::RBInsert(const T &key) {
	if (isEmpty()) {
		root = new RBNode<T>(false,key);
		copyRoot = root;
		std::cout << "root->key----->    "<<root->key << std::endl;
	}
	else {
		RBNode<T> *preNode = root;
		RBNode<T> *nextNode = nullptr;
		RBNode<T> *curNode = new RBNode<T>(false, key);
		RBVec.push_back(curNode);
		while (preNode) {
			nextNode = preNode;
			if (key < preNode->key) {
				preNode = preNode->left;
			}
			else {
				preNode = preNode->right;
			}
		}
		if (key < nextNode->key) {
			nextNode->left = curNode;
		}
		else {
			nextNode->right = curNode;
		}
		curNode->parent=nextNode;
	}
}

template<typename T> void RBTree<T>::RBInsertFixUp(RBNode<T> *node) {
	while (node->parent->color) {
		if (node->parent == node->parent->parent->left) {
			RBNode<T> *yNode = node->parent->parent->right;
			if (yNode->color) {
				node->parent->color = false;
				yNode->color = false;
				node->parent->parent->color = true;
				node = node->parent->parent;
			}
			else if (node == node->parent->right) {
				node = node->parent;
				leftRotate(node);
				node->parent->color = false;
				node->parent->parent->color = true;
				rightRotate(node->parent->parent);
			}
		}
	}
}

#endif