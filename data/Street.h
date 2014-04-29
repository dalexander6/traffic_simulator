#ifndef __STREET__
#define __STREET__


#include "Vehicle.h"
#include <vector>

class Street {
private:
	std::vector<Vehicle*> vehicles;

	int length;
	int width;

public:
	Street(int length, int width);
	int getLength() const;
	int getWidth() const;

	void addVehicle(Vehicle* v);
	void advance(double dt);

	bool empty() const;

	typedef std::vector<Vehicle*>::const_iterator const_iterator;
	const_iterator begin() const { return vehicles.cbegin(); }
	const_iterator end() const { return vehicles.cend(); }


	~Street();


};







#endif
