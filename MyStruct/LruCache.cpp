#include"LruCache.h"
#include<iostream>

DefineLruCache::DefineLruCache(int cacheSize) :
	cache_size(cacheSize), cache_real_size(0),
	pHeadNode(new LruCache()), pNearNode(new LruCache()) {
	pHeadNode->next = pNearNode;
	pHeadNode->pre = nullptr;
	pNearNode->next = nullptr;
	pNearNode->pre = pHeadNode;
}
DefineLruCache::~DefineLruCache() {
	LruCache *p = pHeadNode->next;
	while (p) {
		delete p->pre;
		p = p->next;
	}
	delete pNearNode;
}
void DefineLruCache::detachNode(LruCache *node) {
	node->pre->next = node->next;
	node->next->pre = node->pre;
}
void DefineLruCache::addToFront(LruCache *node) {
	node->next = pHeadNode->next;
	pHeadNode->next->pre = node;
	pHeadNode->next = node;
	node->pre = pHeadNode;
}
int DefineLruCache::getValue(const int &key) {
	LruCache *node = pHeadNode->next;
	while (node->next) {
		if (key == node->key) {
			detachNode(node);
			addToFront(node);
			return node->value;
		}
		node = node->next;
	}
	return -1;
}
bool DefineLruCache::putValue(int key, int value) {
	LruCache *node = pHeadNode->next;
	while (node->next) {
		if (node->key == key) {
			node->value = value;
			getValue(key);
			return true;
		}
		node = node->next;
	}
	if (cache_real_size >= cache_size) {
		std::cout << "free............" << std::endl;
		node = node->pre->pre;
		delete node->next;
		node->next = pNearNode;
		pNearNode->pre = node;
	}
	node = new LruCache();
	if (!node)
		return false;
	addToFront(node);
	node->key = key;
	node->value = value;
	cache_real_size++;
	return true;
}
void DefineLruCache::displayNodes() const {
	LruCache *node = pHeadNode->next;
	while (node->next) {
		std::cout << "key:  " << node->key << "value:  " << node->value << std::endl;
		node = node->next;
	}
	std::cout << std::endl;
}