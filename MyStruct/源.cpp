#include"LruCache.h"
#include"RBNode.h"

#include<vld.h>
void mtest() {
	DefineLruCache decache;
	decache.displayNodes();
}

void mtest1() {
	//RBNode<int> *rb = new RBNode<int>(3);
	RBNode<int> rb(2);
}

void main() {
	mtest1();
}