#ifndef RBTREE_H
#define RBTREE_H
#include"RBNode.h"
template<typename T> class RBTree {
public:
	RBTree();
	~RBTree();
private:
	RBNode<T> *root;
};
#endif