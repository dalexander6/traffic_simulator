#ifndef __VEHICLE__
#define __VEHICLE__

class Vehicle {
private:
	double vehicleLength;
	int licensePlate;
	static int count;

public:
	Vehicle();
	Vehicle(double positionFront, double length);

	double getPositionFront() const;
	double getPositionBack() const;
	double getLength() const;
	virtual void updatePosition(const Vehicle*& nearest, double dt) = 0;
	bool operator<(const Vehicle& other) const;
	int getLicense() const { return licensePlate; }

	virtual ~Vehicle();

protected:
	double positionFront;

};







#endif
