//http://www.cnblogs.com/zhoutaotao/p/4096237.html

#include<vector>
#include<iostream>
namespace tree {
	template<typename T> class TreeNode {
	public:
		T key;
		TreeNode *parent;
		TreeNode *left;
		TreeNode *right;
		TreeNode() :key(), parent(nullptr), left(nullptr), right(nullptr) {}
		~TreeNode() {
			parent = nullptr;
			left = nullptr;
			right = nullptr;
		}
	};

	template<typename T> class SearchTree {
	public:
		SearchTree() :root(nullptr),copyRoot(root) {}
		~SearchTree() {
			for (auto &c : treeNodeVec) {
				delete c;
				c = nullptr;
			}
			if (copyRoot) {
				delete copyRoot;
				copyRoot = nullptr;
				if (root) {
					root = nullptr;
				}
			}
	
		}
		bool empty() const;
		void insert(const T &elem);
		TreeNode<T> *seachNode(const T &elem) const;
		TreeNode<T> *minNode(TreeNode<T> *cur=nullptr) const;
		TreeNode<T> *maxNode(TreeNode<T> *cur = nullptr) const;
		TreeNode<T> *nextNode(const T &elem) const;
		TreeNode<T> *preNode(const T &elem) const;
		void transplant(TreeNode<T> *pre, TreeNode<T> *next);
		void remove(const T &elem);
	private:
		TreeNode<T> *root;
		TreeNode<T> *copyRoot;
		std::vector<TreeNode<T>*> treeNodeVec;
	};
	template<typename T> bool SearchTree<T>::empty() const {
		return (root == nullptr);
	}
	template<typename T> TreeNode<T> *SearchTree<T>::seachNode(const T &elem) const {
		TreeNode<T> *preNode = root;
		TreeNode<T> *nextNode = nullptr;
		while (preNode) {
			if (preNode->key > elem)
				preNode = preNode->left;
			else if (preNode->key < elem)
				preNode = preNode->right;
			else if (preNode->key == elem)
				return preNode;
		}
		return nullptr;
	}
	template<typename T> void SearchTree<T>::insert(const T &elem) {
		if (empty()) {
			root = new TreeNode<T>();
			root->key = elem;
			root->parent = nullptr;
			root->left = nullptr;
			root->right = nullptr;
			copyRoot = root;
		}
		else {
			TreeNode<T> *preNode = root;
			TreeNode<T> *nextNode = nullptr;
			TreeNode<T> *newNode = new TreeNode<T>();
			newNode->key = elem;
			treeNodeVec.push_back(newNode);
			while (preNode) {
				nextNode = preNode;
				if (preNode->key > elem)
					preNode = preNode->left;
				else
					preNode = preNode->right;
			}
			if (nextNode->key > elem)
				nextNode->left = newNode;
			else
				nextNode->right = newNode;
			newNode->parent = nextNode;
		}
	}
	template<typename T> TreeNode<T> *SearchTree<T>::minNode(TreeNode<T> *cur=nullptr) const {
		TreeNode<T> *preNode = (!cur ? root : cur);
		TreeNode<T> *nextNode = nullptr;
		while (preNode) {
			nextNode = preNode;
			preNode = preNode->left;
		}
		return nextNode;
	}
	template<typename T> TreeNode<T> *SearchTree<T>::maxNode(TreeNode<T> *cur = nullptr) const {
		TreeNode<T> *perNode = (!cur ? root : cur);
		TreeNode<T> *nextNode = nullptr;
		while (perNode) {
			nextNode = perNode;
			perNode = perNode->right;
		}
		return nextNode;
	}
	template<typename T> TreeNode<T> *SearchTree<T>::nextNode(const T &elem) const {
		TreeNode<T> *curNode=seachNode(elem);
		if (curNode == nullptr) {
			std::cout << "没有该关键字。。。。。。。。。";
			return nullptr;
		}
		if (curNode->right) {
			return minNode(curNode->right);
		}
		else {
			TreeNode<T> *parent = curNode->parent;
			while (parent&&curNode == parent->right) {
				curNode = parent;
				parent = parent->parent;
			}
			return parent;
		}
	}
	template<typename T> TreeNode<T> *SearchTree<T>::preNode(const T &elem) const {
		TreeNode<T> *curNode = seachNode(elem);
		if (!curNode) {
			std::cout << "没有该关键字。。。。。。。。。";
			return nullptr;
		}
		if (curNode->left) {
			return maxNode(curNode->left);
		}
		else {
			TreeNode<T> *parent = curNode->parent;
			while (parent&&curNode == parent->left) {
				curNode = parent;
				parent = parent->parent;
			}
			return parent;
		}
	}
	template<typename T> void SearchTree<T>::transplant(TreeNode<T> *pre, TreeNode<T> *next) {
		if (!pre->parent) {
			root = next;
		}
			
		else if (pre == pre->parent->left)
			pre->parent->left = next;
		else
			pre->parent->right = next;
		if (next)
			next->parent = pre->parent;
	}
	template<typename T> void SearchTree<T>::remove(const T &elem) {
		TreeNode<T> *curNode = seachNode(elem);
		if (!curNode) {
			std::cout << "删除的节点不存在。。。。。。。。。";
		}
		if (!curNode->left) {
			transplant(curNode, curNode->right);
		}
		else if (!curNode->right) {
			transplant(curNode, curNode->left);
		}
		else {
			TreeNode<T> *nexts = nextNode(curNode->key);
			if (nexts->parent != curNode) {
				transplant(nexts, nexts->right);
				nexts->right = curNode->right;
				nexts->right->parent = nexts;
			}
			nexts->left = curNode->left;
			transplant(curNode, nexts);
		}
	}
	void test() {
		SearchTree<int> tree;
		std::vector<int> vec{ 1,2,4,3,6,5 };
		for (const auto &c : vec) {
			tree.insert(c);
		}
		auto res = tree.seachNode(2);
		if ( res== nullptr) {
			std::cout << "没有改节点。。。。。。。。。。。。";
		}
		else {
			std::cout << "有改节点。。。。。。。。。。。。";
		}
		std::cout << std::endl;
		std::cout << (tree.minNode()->key) << std::endl;
		std::cout << (tree.maxNode()->key) << std::endl;
		std::cout << (tree.nextNode(4)->key) << std::endl;
		std::cout << (tree.nextNode(3)->key) << std::endl;
		std::cout << std::endl;
		std::cout << (tree.preNode(4)->key) << std::endl;
		std::cout << (tree.preNode(3)->key) << std::endl;



		std::cout << "remove ..... " << std::endl;
		tree.remove(2);
		if (tree.seachNode(2))
			std::cout << tree.seachNode(2)->key << std::endl;
		else {
			std::cout << "不存在。。。。。。。。。。。。。。" << std::endl;
		}

		
	}
}