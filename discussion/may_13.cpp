#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <set>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

struct oddComp {
	bool operator()(int a, int b) {
		if (a <= 10 && b > 10) 
			return true;
		else
			return false;
	}
};

int main(int argc, char *argv[]) {
	vector<int> v1 = {5, 3, 7, 18, 9, 6, 17};
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;
	//fill_n(v1.begin(), 5, 3);
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;
	auto it = stable_partition(v1.begin(), v1.end(), bind1st(less<int>(), 10));
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;
	cout << *it << endl;
	multiset<int, oddComp> s2;
	s2.insert(5);
	s2.insert(3);
	s2.insert(7);
	s2.insert(18);
	s2.insert(9);
	s2.insert(6);
	s2.insert(17);
	cout << "s2: ";
	for (const auto& i : s2) {
		cout << i << ", ";
	}
	cout << endl;
	/*
	set<int> s1;
	s1.insert(5);
	s1.insert(8);
	stable_partition(s1.cbegin(), s1.cend(), bind1st(less<int>(), 10));
	for (auto it = s1.begin(); it != s1.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
	*/
	rotate(v1.begin(), v1.begin()+4, v1.begin()+3);
	cout << "v1, post-rotation: ";
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;

	return 0;
}

