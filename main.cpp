#include "Vehicle.h"
#include "Car.h"
#include "Street.h"
#include "InverseDistanceAcceleration.h"
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "QStreetWidget.h"
#include "QTest.h"
#include "unistd.h"

using namespace std;

int main(int argc, char* argv[]) {

	/*
	QApplication app(argc, argv);
	QWidget* window = new QWidget;
	window->setWindowTitle("Traffic Simulator");
	QVBoxLayout *layout = new QVBoxLayout;
	QPushButton* pushbutton = new QPushButton("Quit");
	layout->addWidget(pushbutton);
	//pushbutton->setFixedWidth(100);
	QObject::connect(pushbutton, SIGNAL(clicked()), &app, SLOT(quit()));
	window->setLayout(layout);
	window->show();
	*/
	double accelMax = 2;
	double length = 40;
	double speedMax = 10;
	double dt = 1;
	Vehicle* car = new Car<InverseDistanceAcceleration>(100, length, speedMax, accelMax);
	cout << car->getPositionBack() << endl;

	Street street(1000, 100);
	street.addVehicle(new Car<InverseDistanceAcceleration>(50, length, speedMax, accelMax));
	street.addVehicle(new Car<InverseDistanceAcceleration>(100, length, speedMax, accelMax));
	street.addVehicle(new Car<InverseDistanceAcceleration>(200, length, speedMax, accelMax));
	street.advance(20);

	QApplication app(argc, argv);
	QWidget* window = new QWidget;
	window->setWindowTitle("Traffic Simulator");

	QVBoxLayout *layout = new QVBoxLayout;
	QStreetWidget* streetWidget = new QStreetWidget(street);
	layout->addWidget(streetWidget);

	/*
	QPushButton* pushbuttonAdvance = new QPushButton("Advance");
	pushbuttonAdvance->setFixedWidth(100);
	layout->addWidget(pushbuttonAdvance);
	QObject::connect(pushbuttonAdvance, SIGNAL(clicked()), streetWidget, SLOT(advance()));
	*/

	QPushButton* pushbutton = new QPushButton("Quit");
	pushbutton->setFixedWidth(100);
	layout->addWidget(pushbutton);
	QObject::connect(pushbutton, SIGNAL(clicked()), &app, SLOT(quit()));
//	QTest* test = new QTest();
//	layout->addWidget(test);

//	layout->addWidget(label);
	
	window->setLayout(layout);
	window->show();

//	chrono::milliseconds sleepTime(100);
	while (!street.empty()) {
//		this_thread::sleep_for(sleepTime);
		usleep(100000);
		streetWidget->advance();
	}




	return app.exec();
}
