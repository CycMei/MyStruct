#ifndef RBNODE_H
#define RBNODE_H
#include<iostream>
template<typename T> class RBNode {
public:
	RBNode(RBNode *l, RBNode *r, RBNode *p, bool c, T k);
	RBNode();
	RBNode(bool col);
	RBNode(const T &k);
	RBNode(bool col, const T &k);

	~RBNode();

	RBNode *left;
	RBNode *right;
	RBNode *parent;
	bool color;	//true red,false black
	T key;
	

};

template<typename T>
RBNode<T>::RBNode(RBNode *l, RBNode *r, RBNode *p, bool c, T k) :left(l), right(r), parent(p), color(c), key(k) {
	std::cout << "left right parent color key........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode() : RBNode(nullptr, nullptr, nullptr, false, T()) {
	std::cout << "left right parent........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode(bool col) : RBNode(nullptr, nullptr, nullptr, col, T()) {
	std::cout << "color........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode(const T &k) : RBNode(nullptr, nullptr, nullptr, false, k) {
	std::cout << "key........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode(bool col, const T &k) : RBNode(nullptr, nullptr, nullptr, col, k) {
	std::cout << "color key ........" << std::endl;
}

template<typename T> RBNode<T>::~RBNode() {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}


#endif