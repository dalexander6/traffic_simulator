#ifndef __HASH__
#define __HASH__

template<class Key>
class hash {
public:
	unsigned int operator()(const Key& key) const{
		const char* p = reinterpret_cast<const char*>(&key);
		unsigned int h = 0;

		for (unsigned int i = 0; i < sizeof(Key); i++) {
			h = (h << 4) ^ (h >> 28) ^ p[i];
		}

		return h;
	}
};











#endif
