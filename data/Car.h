#ifndef __CAR__
#define __CAR__

#include "Vehicle.h"
#include <iostream>

template <typename getAccelerationObj>
class Car : public Vehicle {
private:
	double speed;
	double acceleration;
	double speedMax;
	double accelerationMax;

//	void updateAcceleration(const Vehicle*& nearest) {
	virtual void setSpeed(double speed);
	virtual void setAcceleration(double acceleration);

public:
	Car(double location, double length, double speedMax, double accelMax);

	virtual double getSpeed() const;
	virtual double getAcceleration() const;
	virtual double getAccelerationMax() const { return accelerationMax; }
	virtual double getSpeedMax() const { return speedMax; }
	virtual void advance(const Vehicle* const& nearest, double dt);

	virtual ~Car();

};

template<typename getAccelerationObj>
Car<getAccelerationObj>::Car(double location, double length, double speedMax, double accelMax) : Vehicle(location, length) {
	this->speedMax = speedMax;
	accelerationMax = accelMax;

}

template<typename getAccelerationObj>
void Car<getAccelerationObj>::advance(const Vehicle* const& nearest, double dt) {
	acceleration = getAccelerationObj().getAcceleration(this, nearest);
	std::cout << acceleration << std::endl;
	std::cout << speed << std::endl;
	speed += getAcceleration()*dt;
	if (speed > speedMax) 
		speed = speedMax;

	positionFront += speed*dt;
}

template<typename getAccelerationObj>
double Car<getAccelerationObj>::getSpeed() const {
	return speed;
}

template<typename getAccelerationObj>
double Car<getAccelerationObj>::getAcceleration() const {
	return acceleration;
}

template<typename getAccelerationObj>
void Car<getAccelerationObj>::setSpeed(double speed) {
	this->speed = speed;
}

template<typename getAccelerationObj>
void Car<getAccelerationObj>::setAcceleration(double acceleration) {
	this->acceleration = acceleration;
}

/*
template<typename T>
void Car::updateAcceleration(const Vehicle*& nearest) {
	acceleration = T.getAcceleration(*this, nearest);
}
}
*/

template<typename getAccelerationObj>
Car<getAccelerationObj>::~Car() {}
	
#endif
