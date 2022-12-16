#include "rabbit.h"

Rabbit::Rabbit(QPointF initialPos, Animal* parent) :
	Animal(initialPos, QPixmap(), 50)
{
	setSprite(QPixmap("Ressources/rabbit.png"));
}

Rabbit::~Rabbit() {}