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
	int getSize();

	void setBerries(int berries);
	void setSize(int size);

protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;

	int mBerries;
	int mSize;

	//QPixmap pixmap = QPixmap("Ressources/bush0.png");// = new QPixmap("Ressources/bush_1.png");
	//QPixmap const pixmap2;//= new QPixmap("Ressources/bush_2.png");
};