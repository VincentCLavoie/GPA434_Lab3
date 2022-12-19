#include "mushroom.h"

Mushroom::Mushroom(QPointF initialPos, Entity* parent) :
	Entity(initialPos)
{
	setSprite(QPixmap("Ressources/mushroom.png"));
	setSpriteSize(25);
}

Mushroom::~Mushroom() {}