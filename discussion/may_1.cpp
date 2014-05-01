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

bool gtComp(int a, int b) {
	return a > b;
}

bool strPtrComp(string* a, string* b) {
	return *a < *b;
}

bool isEven(int a) {
	return (a % 2 == 0);
}

struct isDivisibleByK{
	int k;

	bool operator()(int a) {
		return (a % k == 0);
	}
};

int main(int argc, char *argv[]) {
	vector<int> v1 = {5, 3, 7, 18, 9};
	vector<int> v2 = {5, 8, 10, 18, 9};
	vector<string*> v3 = {new string("c"), new string("b")};
	sort(v1.begin(), v1.end(), gtComp);
	sort(v3.begin(), v3.end(), strPtrComp);
	isDivisibleByK x;
	x.k = 3;
	vector<int> output(5); 
	//cout << less<int>(5, 7) << endl;
	//cout << (5 < 7) << endl;

	remove_copy_if(v1.begin(), v1.end(), output.begin(), bind2nd(greater<int>(), 10));
	for (const auto& i : output) {
		cout << i << ", ";
	}
	cout << endl;
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;
	for (const auto& i : v3) {
		cout << *i << ", ";
	}
	cout << endl;


  return 0;
}

