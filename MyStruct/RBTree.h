#ifndef RBTREE_H
#define RBTREE_H
#include"RBNode.h"
template<typename T> class RBTree {
public:
	RBTree();
	~RBTree();
	void RBInser(const T &key);
	bool isEmpty() const;
private:
	RBNode<T> *root;
	RBNode<T> *copyRoot;
	RBNode<T> *nptr = nullptr;
};

template<typename T> RBTree<T>::RBTree() :root(nullptr), copyRoot(nullptr) {

}

template<typename T> RBTree<T>::~RBTree() {

}

template<typename T> bool RBTree<T>::isEmpty() const {
	return root == nullptr;
}
template<typename T> void RBTree<T>::RBInser(const T &key) {
	if (isEmpty) {
		root = new RBNode<T>(key,false);
		copyRoot = root;
	}
	else {
		RBNode<T> *pre = nullptr;
		RBNode<T> *next
	}

}

#endif