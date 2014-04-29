#ifndef __QSTREETWIDGET__
#define __QSTREETWIDGET__

#include <QWidget>
#include <iostream>
#include <QPainter>
#include "Street.h"
#include <QPointF>

class QStreetWidget : public QWidget {
	Q_OBJECT

private:
	Street* street;
	int height;
	int width;

public:
	explicit QStreetWidget(Street& s, QWidget* parent = 0) : 
		QWidget(parent),
		street(&s) {
		height = street->getWidth();
		width = street->getLength();
		setMinimumHeight(height);

		setMinimumWidth(width);

	}

	virtual ~QStreetWidget() {};

	virtual void paintEvent(QPaintEvent* e) {
		int buffer = 10;
		QPainter painter(this);
		painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));

		//draw street
		painter.drawLine(QPointF(0, buffer), QPointF(width, buffer));
		painter.drawLine(QPointF(0, height-buffer), QPointF(width, height-buffer));

		//draw cars
		painter.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
		int y = height/4;
		for (const auto& vehiclePtr : *street) {
			int x = vehiclePtr->getPositionBack();
			painter.drawRect(QRectF(x, y, vehiclePtr->getLength(), height/2));
			int centerX = x + vehiclePtr->getLength()/2;
			int centerY = height/2;
			QString license = QString::number(vehiclePtr->getLicense());
			painter.drawText(centerX, centerY, license);

			std::cout << "(" << x << ", " << y << "), " << vehiclePtr->getLength() << " x " << height/2 << std::endl;
		}
		QWidget::paintEvent(e);
	}

public slots:
	virtual void advance() {
		double dt = 1;
		street->advance(dt);
		repaint();
	}


};

#endif
