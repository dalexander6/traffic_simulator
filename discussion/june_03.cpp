#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double Sqrt(double x) {
	if ( x < 0 ) {
		throw std::invalid_argument("sqrt received negative argument");
	}
	return std::sqrt(x);
}

double f(int x) {
	return Sqrt(x);
}

int x = 2;

int main(int argc, char *argv[]) {
	int* a = new int(3);
	//cout << *(a+1000000) << endl;
	int x = 7;
	cout << x << endl;


	try {
		double s = f(-1);
	}
	catch (std::exception& e) {
		std::cout << "Caught " << e.what() << std::endl;
	}
	
	return 0;
}

