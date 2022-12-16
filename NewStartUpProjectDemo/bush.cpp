#include "bush.h"

Bush::Bush(QPointF initialPos, Entity* parent) :
	Entity(initialPos, QPixmap(), 100)
{
	setSprite(QPixmap("Ressources/bush1.png"));

	setBerries(3);
	setSpriteSize(100);
}

Bush::~Bush(){}

int Bush::getBerries()
{
	return mBerries;
}

void Bush::setBerries(int berries)
{
	mBerries = berries;

	if (!mAlive) {
		setSprite(QPixmap("Ressources/bush2.png"));
	}
	else {
		if (berries == 0)
			setSprite(QPixmap("Ressources/bush0.png"));
		else
			setSprite(QPixmap("Ressources/bush1.png"));
	}
}