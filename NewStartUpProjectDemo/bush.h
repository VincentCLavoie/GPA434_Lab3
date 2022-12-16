#pragma once
#include "Entity.h"
#include <iostream>
#include <string>

class Bush : public Entity
{
public:
	Bush(QPointF pos, Entity* parent = new Entity);
	~Bush();

	int getBerries();

	void setBerries(int berries);

protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;

	int mBerries;
};