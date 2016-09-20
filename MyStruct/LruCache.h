#ifndef LRUCACHE_H
#define LRUCACHE_H
class LruCache {
public:
	int key;
	int value;
	LruCache *next;
	LruCache *pre;

};
class DefineLruCache {
public:
	DefineLruCache(int cacheSize = 10);
	~DefineLruCache();
	int getValue(const int &key);
	bool putValue(int key, int value);
	void displayNodes() const;
private:
	int cache_size;
	int cache_real_size;
	LruCache *pHeadNode;
	LruCache *pNearNode;
	void detachNode(LruCache *node);
	void addToFront(LruCache *node);
};
#endif