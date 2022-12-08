#include "Entity.h"

Entity::Entity() :
	  pos{0,0}
	, alive(true)
{
	pos = QVector2D(0, 0);
}

Entity::~Entity(){}

QVector2D Entity::getPosition()
{
	return pos;
}

void Entity::setPosition(QVector2D _pos)
{
	pos = _pos;
}

bool Entity::getAlive()
{
	return alive;
}

void Entity::setAlive(bool _alive)
{
	alive = _alive;
}