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

bool Street::empty() const {
	return vehicles.empty();
}
void Street::advance(double dt) {
	for (unsigned int i = 0; i < vehicles.size(); ++i) {
		Vehicle* nextVehicle = nullptr;
		if (i != vehicles.size() - 1) {
			nextVehicle = vehicles[i+1];
		}
			
		vehicles[i]->advance(nextVehicle, dt);
		if (vehicles[i]->getPositionBack() > length) {
			delete vehicles[i];
			vehicles.erase(vehicles.begin() + i);
		}
	}
}
