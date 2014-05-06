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
using namespace std::placeholders;

struct isDivisibleByK{
	int k;

	bool operator()(int a) {
		return (a % k == 0);
	}
};

template<typename T>
void print(const T& i) {
	cout << i << " ";
}

bool isDivisByK(int a, int k) {
	return a % k == 0;
}

template<typename T>
void printVec(const vector<T>& v) {
	for_each(v.begin(), v.end(), print<T>);
	cout << endl;
}

int main(int argc, char *argv[]) {
	vector<int> v1 = {5, 3, 7, 18, 9, 6};
	//auto it = remove_if(v1.begin(), v1.end(), bind1st(less<int>(), 10));
	isDivisByK(21, 3);
	isDivisByK(21, 5);
	auto isDivisBy3 = bind(isDivisByK, _1, 3);
	auto isAFactorOf21 = bind(isDivisByK, 21, _1);
	auto silly = bind(isDivisByK, _1, _2); //this is the same as isDivisByK
	//auto it = remove_if(v1.begin(), v1.end(), isDivisBy3);
	auto it = remove_if(v1.begin(), v1.end(), isAFactorOf21);
	cout << "Before cleaning garbage: ";
	printVec(v1);
	v1.resize(it - v1.begin());
	cout << "After: ";
	printVec(v1);
	vector<string> v2 = {"hi", "this", "one"};
	auto it2 = remove(v2.begin(), v2.end(), "one");
	v2.resize(it2 - v2.begin());
	for (const auto& i : v2) {
		cout << i << ", ";
	}
	printVec(vector<int>());
	cout << endl;
	set<int> s1;
	s1.insert(5);
	s1.insert(-1);
	s1.insert(8);
	for_each(s1.begin(), s1.end(), print<int>);
	//equivalent to:
	for (const auto& i : s1) {
		print(i);
	}
	cout << endl;
	return 0;
}

