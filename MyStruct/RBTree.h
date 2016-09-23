#ifndef RBTREE_H
#define RBTREE_H
#include"RBNode.h"
#include<vector>
template<typename T> class RBTree {
public:
	RBTree();
	~RBTree();
	void RBInser(const T &key);
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

template<typename T> void RBTree<T>::RBInser(const T &key) {
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

#endif