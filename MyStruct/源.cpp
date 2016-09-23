#include"LruCache.h"
#include"RBTree.h"

#include<vld.h>
void mtest() {
	DefineLruCache decache;
	decache.displayNodes();
}

void mtest1() {
	RBTree<int> rbTree;
	rbTree.RBInsert(10);
	rbTree.RBInsert(5);
}

void main() {
	mtest1();
}