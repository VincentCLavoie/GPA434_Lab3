#include "bush.h"

Bush::Bush(QPointF initialPos, Entity* parent) :
	Entity(initialPos, QPixmap())
{
	setSprite(QPixmap("Ressources/bush1.png"));

	setBerries(3);
	mSize = 1;
}

Bush::~Bush(){}

int Bush::getBerries()
{
	return mBerries;
}

int Bush::getSize()
{
	return mSize;
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

void Bush::setSize(int size)
{
	mSize = size;
}