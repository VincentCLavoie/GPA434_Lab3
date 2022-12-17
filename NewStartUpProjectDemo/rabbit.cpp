#include "rabbit.h"

Rabbit::Rabbit(QPointF initialPos, Animal* parent) :
	Animal(initialPos, QPixmap(), 50)
{
	setSprite(QPixmap("Ressources/rabbit.png"));
	setSpriteSize(50);
}

Rabbit::~Rabbit() {}