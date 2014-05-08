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

int f() {
	return 1;
}

struct incrementer {
	int count;
	incrementer(int n) : count(n) {};
	int operator()() { return ++count; };
};

int g(int n) {
	return 2*n;
}

int binaryTransform(int a, int b) {
	return a + b;
}

int main(int argc, char *argv[]) {
	vector<int> v1 = {5, 3, 7, 18, 9, 6};


	vector<int> v2;
	//generate_n(back_inserter(v2), 10, incrementer(5));
	incrementer myI(5);
	for (int i = 0; i < 10; i++) {
		v2.push_back(myI());
	}

	cout << "Generated v2: ";
	for (const auto& i : v2) {
		cout << i << ", ";
	}
	cout << endl;

	cout << "Post-transformation v2: ";
	//transform(v2.begin(), v2.end(), back_inserter(v1), g);
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;

	vector<int> v3(15);

	copy(v2.begin(), v2.end(), v3.begin());
	cout << "After copying v2 to v3: " << endl;
	for (const auto& i : v3) {
		cout << i << ", ";
	}
	cout << endl;
	copy_n(v2.begin(), 4, v3.rbegin());
	for (const auto& i : v3) {
		cout << i << ", ";
	}
	cout << endl;

	vector<int> v4;
	transform(v1.begin(), v1.end(), v2.begin(), back_inserter(v4), binaryTransform);
	cout << "Binary transform output: " << endl;
	for (const auto& i : v4) {
		cout << i << ", ";
	}
	cout << endl;


	return 0;
}

