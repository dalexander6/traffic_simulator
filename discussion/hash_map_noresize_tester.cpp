#include <iostream>
#include "hash_map_noresize.h"
#include <string>

using namespace std;

int main(){
	
	hash_map_noresize<int, string> hm(10);
	hm[3] = "hi";
	cout << hm[3] << endl;
	hm[4];
	cout << hm[4] << endl;
	hm[3] = "hey";
	cout << hm[3] << endl;
	cout << hm.hasher(3) << endl;
	
	hash_map_noresize<int, string> hm2(3);
	//cout << hm[3] << endl;
	for(int i = 0; i < 5; i++){
		hm2[i] = "s" + to_string(i);
		//hm2.print();
	}
	hm2.print();
	hm2.erase(3);
	hm2.print();

	return 0;
}
