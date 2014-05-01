#ifndef __HASH_MAP_NORESIZE__
#define __HASH_MAP_NORESIZE__
#include "hash.h"
#include <iostream>
#include <vector>

template<class Key, class Val, class Hasher = hash<Key> >
class hash_map_noresize {
public:
	hash_map_noresize(unsigned int bucket_count = 101);
	Val& operator[] (const Key& key);

	void erase(const Key& key);
	Hasher hasher;
	void print();
	~hash_map_noresize();
	
private:
	struct Entry {
		Key key;
		Val val;
		Entry* next;
		Entry* prev;
		Entry(Key k, Val v, Entry* n, Entry* p) : key(k), val(v), next(n), prev(p) { }
		~Entry(){
		}
	};

	Entry** buckets;
	unsigned int numBuckets;
	

};

template<class Key, class Val, class Hasher>
hash_map_noresize<Key, Val, Hasher>::hash_map_noresize(unsigned int bucket_count) {
	numBuckets = bucket_count;
	buckets = new Entry*[numBuckets];
	for(unsigned int i = 0; i < numBuckets; i++){
		buckets[i] = nullptr;
	}
}

template<class Key, class Val, class Hasher>
Val& hash_map_noresize<Key, Val, Hasher>::operator[] (const Key& key) {
	unsigned int i = hasher(key)%numBuckets; //hash

	for(Entry* p = buckets[i]; p != nullptr; p = p->next) {
		//if found:
		if(key == p->key) {
			return p->val;
		}
	}

	buckets[i] = new Entry(key, Val(), buckets[i], nullptr);
	if (buckets[i]->next) {
		buckets[i]->next->prev = buckets[i];
	}
	
	return buckets[i]->val;
}

template<class Key, class Val, class Hasher>
void hash_map_noresize<Key, Val, Hasher>::erase(const Key& key) {
	unsigned int i = hasher(key)%numBuckets; //hash

	//Entry** prevPtr = &buckets[i];
	for(Entry* p = buckets[i]; p != nullptr; p = p->next) {
		//if found:
		if(key == p->key) {
			if(p->next != nullptr) {
				p->next->prev = p->prev;
			}
			if(p->prev != nullptr) {
				p->prev->next = p->next;
			}
			else{
				//in this case, prev must have been the bucket ptr
				buckets[i] = p->next;
			}
			delete p;
			break;
		}
		//prevPtr = &p->next;
	
	}
	//not found, do nothing

}

template<class Key, class Val, class Hasher>
void hash_map_noresize<Key, Val, Hasher>::print() {
	std::cout << "Buckets: index, address" << std::endl;
	for (unsigned int i = 0; i < numBuckets; i++) {
		std::cout << i << ", " << buckets[i] << std::endl;
	}

	std::cout << "Entries: address, key, hash, value, next address, prev address" << std::endl;
	for (unsigned int i = 0; i < numBuckets; i++) {
		Entry* p = buckets[i];
		while (p != nullptr) {
			std::cout << p << " " << p->key << " " << hasher(p->key)%numBuckets << " " << p->val << " " << p->next << " " << p->prev << std::endl;
			p = p->next;
		}
	}
}

template<class Key, class Val, class Hasher>
hash_map_noresize<Key, Val, Hasher>::~hash_map_noresize() {
	
	for (unsigned int i = 0; i < numBuckets; i++){
		Entry* p = buckets[i];
		while(p != nullptr) {
			Entry* next = p->next;
			delete p;
			p = next;
		}
	}

	delete[] buckets;
}





#endif
