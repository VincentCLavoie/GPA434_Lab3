#pragma once
#include "animal.h"

class Rabbit : public Animal
{
public:
	Rabbit(QPointF pos, Animal* parent = new Animal);
	~Rabbit();



protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;
};