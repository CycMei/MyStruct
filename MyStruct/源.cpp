#include"LruCache.h"
#include"RBTree.h"

#include<vld.h>
void mtest() {
	DefineLruCache decache;
	decache.displayNodes();
}

void mtest1() {
	RBTree<int> rbTree;
	rbTree.RBInser(10);
	rbTree.RBInser(5);
}

void main() {
	mtest1();
}