#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <set>
#include <cmath>
#include <map>


using namespace std;

class SuperBase {
public:
	SuperBase() { cout << "cstr superbase" << endl; }
	SuperBase(int n) { cout << "cstr superbase(" << n << ")" << endl; }
//	virtual ~SuperBase() {}
};

class Base1 : public SuperBase {
public:
	Base1() : SuperBase(3) { cout << "cstr base1" << endl; }
	virtual ~Base1() {}
};

class Derived : public Base1 {
public:
	Derived() { cout << "cstr derived" << endl; }
};


int main() {
	SuperBase* sbPtr = new SuperBase();
	SuperBase* sbPtr1 = new Base1();  //upcasting ?
	SuperBase* sbPtr2 = new Derived();

	//Derived* dPtr = new Base1(); //not okay: downcasting

	SuperBase s = Base1(); //okay but causes slicing

	//Base1* bPtr = sbPtr1; //okay in "spirit" but compiler isn't that smart

	//Base1* bPtr2 = dynamic_cast<Base1*>(sbPtr1); //downcasting via dynamic cast: okay
	Base1* bPtr3 = new Derived();
	Derived* dPtr = dynamic_cast<Derived*>(bPtr3);

	//vector<int> v = {2, 5, 7, 2, -1};
	set<int> v;
	v.insert(2);
	v.insert(5);
	v.insert(7);
	v.insert(2);

	int maximum = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		maximum = max(maximum, *it);
	}

	map<int, vector<set<double>>> m;
	/*
	for (const auto& p : m) {
		for (const auto& v : p.second) {
			for (const auto& s : v) {
				for (auto d : s) {
					maximum = max(maximum, d);
				}
			}
		}
	}
	*/

}

