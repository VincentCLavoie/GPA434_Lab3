#pragma once
#include "Entity.h"

class Bush : Entity
{
public:
	Bush(QPointF pos, Entity* parent = nullptr);
	~Bush();

protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;

private:
	int berries;
	int size;
};