#pragma once
#include "qgraphicsitem.h"
#include "qvector2d.h"
#include "qpixmap.h"


class Entity
{
public:
	Entity();
	~Entity();

	//fonctions
	void setPosition(QVector2D _pos);
	QVector2D getPosition();
	void setAlive(bool _alive);
	bool getAlive();

private:

	QVector2D pos;
	bool alive;


};
