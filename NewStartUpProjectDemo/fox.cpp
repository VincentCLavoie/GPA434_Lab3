#include "fox.h"

Fox::Fox(QPointF initialPos, Animal* parent) :
	Animal(initialPos, QPixmap(), 100)
{
	setSprite(QPixmap("Ressources/fox.png"));
	setSpriteSize(100);

	setAnimalSpeed(50);
	setHunger(200);
}

Fox::~Fox() {}