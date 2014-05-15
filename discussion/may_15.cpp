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

class Person {
private:
	int age;
	std::function<string()> mood;
public:
	Person(int age) : age(age) { 
		mood = []() { return "neutral"; };
	}
	int getAge() const { return age; }
	void setMood(std::function<string()> newMood) {
		mood = newMood;
	}
	string getMood() const { return mood(); }

};

template <typename T>
class smartPointer {
private:
public:
	T* ptr;
	smartPointer(T* other) { ptr = other; }
	smartPointer& operator=(smartPointer<T>& other) {
		if (this == &other) {
			return *this;
		}
		delete ptr;
		ptr = other.ptr;
		return *this;
	}

	~smartPointer() { if (ptr) delete ptr; }
};


int operator+(int x, const Person& other) { return x + other.getAge(); }

int ageAdd(int x, const Person& other) { return x + other.getAge(); }

int main(int argc, char *argv[]) {
	vector<int> v1 = {5, 3, 7, 18, 9, 6, 17};
	for (const auto& i : v1) {
		cout << i << ", ";
	}
	cout << endl;

	cout << accumulate(v1.begin(), v1.end(), 0) << endl;

	vector<string> v2 = {"hello, ", "world", "!"};

	cout << accumulate(v2.begin(), v2.end(), string("")) << endl;

	vector<Person> v3 = {Person(5), Person(8), Person(90), Person(40)};

	std::function<int(int, const Person&)> f = [](int x, const Person& p) { return x + p.getAge(); };
	cout << accumulate(v3.begin(), v3.end(), 0, f) << endl;

	int total = 0;
	for (const auto& p : v3) {
		total += p.getAge();
	}
	cout << total << endl;

	Person p(10);
	p.setMood([]() { return "happy"; });
	cout << p.getMood() << endl;

	//sort(v1.begin(), v1.end());
	//
	smartPointer<Person> sp(new Person(10));
	{
		smartPointer<Person> sp2(new Person(12));
		sp2 = sp;
	}

	//cout << sp.ptr->getAge() << endl;
	return 0;
}

