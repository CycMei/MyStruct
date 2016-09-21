#ifndef RBNODE_H
#define RBNODE_H
template<typename T> class RBNode {
public:
	RBNode();
	//RBNode(T k);
	RBNode(T k, bool col);
	~RBNode();

	T key;
	bool color;	//true red,false black
	RBNode *left;
	RBNode *right;
	RBNode *parent;
};
template<typename T>
RBNode<T>::RBNode() :key(), color(false), left(nullptr), right(nullptr), parent(nullptr) {

}

template<typename T>
RBNode<T>::RBNode(T k, bool col) : key(k), color(col), left(nullptr), right(nullptr), parent(nullptr) {

}

template<typename T> RBNode<T>::~RBNode() {
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}


#endif