#ifndef __CAR__
#define __CAR__

#include "Vehicle.h"

class Car : public Vehicle {
private:
	double speed;
	double acceleration;
	double speedMax;
	double accelerationMax;

	void updateAcceleration(const Vehicle*& nearest, double dt);
	virtual void setSpeed(double speed);
	virtual void setAcceleration(double acceleration);


public:
	Car(double location, double length, double speedMax, double accelMax);

	virtual double getSpeed() const;
	virtual double getAcceleration() const;
	virtual void updatePosition(const Vehicle*& nearest, double dt);

	virtual ~Car();



};

#endif
