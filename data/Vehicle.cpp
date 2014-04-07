#include "Vehicle.h"

int Vehicle::count = 0;

Vehicle::Vehicle(double positionFront, double length) : positionFront(positionFront) {
	vehicleLength = length;
	licensePlate = count;
	++count;
}

double Vehicle::getPositionFront() const {
	return positionFront;
}

double Vehicle::getPositionBack() const {
	return positionFront - vehicleLength;
}

double Vehicle::getLength() const {
	return vehicleLength;
}

bool Vehicle::operator<(const Vehicle& other) const {
	return positionFront < other.positionFront;
}

Vehicle::~Vehicle() {}

Vehicle::Vehicle() {}
