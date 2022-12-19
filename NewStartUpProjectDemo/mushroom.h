#pragma once
#include "Entity.h"
#include <iostream>
#include <string>

class Mushroom : public Entity
{
public:
	Mushroom(QPointF pos, Entity* parent = new Entity);
	~Mushroom();

protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;
};