#include "Street.h"



Street::Street(int length, int width) : length(length), width(width) {}


Street::~Street() {
	for (auto& ptr : vehicles) {
		delete ptr;
	}
}

int Street::getLength() const {
	return length;
}


int Street::getWidth() const {
	return width;
}

void Street::addVehicle(Vehicle* v) {
	vehicles.push_back(v);
}
