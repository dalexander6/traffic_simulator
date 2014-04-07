#include "Vehicle.h"
#include "Car.h"
#include "Street.h"
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "QStreetWidget.h"
#include "QTest.h"

using namespace std;


int main(int argc, char* argv[]) {
	double accelMax = 2;
	double length = 40;
	double speedMax = 10;
	Vehicle* car = new Car(100, length, speedMax, accelMax);
	cout << car->getPositionBack() << endl;

	Street street(1000, 100);
	street.addVehicle(new Car(0, length, speedMax, accelMax));
	street.addVehicle(new Car(100, length, speedMax, accelMax));
	street.addVehicle(new Car(200, length, speedMax, accelMax));

	QApplication app(argc, argv);
	QWidget* window = new QWidget;
	window->setWindowTitle("Traffic Simulator");

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(new QStreetWidget(street));

	QPushButton* pushbutton = new QPushButton("Quit");
	pushbutton->setFixedWidth(100);
	layout->addWidget(pushbutton);
	QObject::connect(pushbutton, SIGNAL(clicked()), &app, SLOT(quit()));
//	QTest* test = new QTest();
//	layout->addWidget(test);

//	layout->addWidget(label);

	window->setLayout(layout);
	window->show();



	return app.exec();
}
