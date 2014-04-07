#include "Car.h"

Car::Car(double location, double length, double speedMax, double accelMax) : Vehicle(location, length) {
	this->speedMax = speedMax;
	accelerationMax = accelMax;

}

void Car::updatePosition(const Vehicle*& nearest, double dt) {
	updateAcceleration(nearest, dt);
	speed += getAcceleration()*dt;
	if (speed > speedMax) 
		speed = speedMax;

	positionFront += speed*dt;
}

double Car::getSpeed() const {
	return speed;
}

double Car::getAcceleration() const {
	return acceleration;
}

void Car::setSpeed(double speed) {
	this->speed = speed;
}

void Car::setAcceleration(double acceleration) {
	this->acceleration = acceleration;
}

void Car::updateAcceleration(const Vehicle*& nearest, double dt) {
	//if no car in front of us, we accelerate.
	if (!nearest) {
		acceleration = accelerationMax;
		return;
	}
	double distance = nearest->getPositionFront() - positionFront;
	double speedDesired;
	if (1.0 / distance >= 1) {
		speedDesired = 0;
	}
	else {
		speedDesired = speedMax * (1 - 1./distance);
	}
	if (speed > speedDesired) {
		acceleration = -accelerationMax;
	}
	else {
		acceleration = accelerationMax;
	}

}

Car::~Car() {}
	
