#pragma once
#include "animal.h"

class Fox : public Animal
{
public:
	Fox(QPointF pos, Animal* parent = new Animal);
	~Fox();


protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;
};