#include "mushroom.h"

Mushroom::Mushroom(QPointF initialPos, Entity* parent) :
	Entity(initialPos, QPixmap(), 100)
{
	setSprite(QPixmap("Ressources/mushroom.png"));

	setSpriteSize(25);
}

Mushroom::~Mushroom() {}