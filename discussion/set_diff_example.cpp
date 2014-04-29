#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int> v1 = {5, 3, 7, 18, 9};
	vector<int> v2 = {5, 8, 10, 18, 9};
	vector<int> diff;
	auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(diff));
	for (const auto& i : diff) {
		cout << i << ", ";
	}
	cout << endl;


  return 0;
}

