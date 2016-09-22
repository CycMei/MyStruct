#ifndef RBNODE_H
#define RBNODE_H
#include<iostream>
template<typename T> class RBNode {
public:
	RBNode();
	RBNode(bool col);
	RBNode(const T &k);
	RBNode(const T &k, bool col);
	~RBNode();

	RBNode *left;
	RBNode *right;
	RBNode *parent;
	bool color;	//true red,false black
	T key;
	

};
template<typename T>
RBNode<T>::RBNode() :left(nullptr), right(nullptr), parent(nullptr) {
	std::cout << "left right parent........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode(bool col) : RBNode(), color(col) {
	std::cout << "color........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode(const T &k) : RBNode(false), key(k) {
	std::cout << "key........" << std::endl;
}

template<typename T>
RBNode<T>::RBNode(const T &k, bool col) : RBNode(), RBNode(col), key(k) {
	std::cout << "color key ........" << std::endl;
}

template<typename T> RBNode<T>::~RBNode() {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}


#endif