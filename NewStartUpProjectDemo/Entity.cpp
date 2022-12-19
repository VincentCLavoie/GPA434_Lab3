#include "Entity.h"

Entity::Entity(QPointF initialPos, QPixmap sprites, int spriteSize, QGraphicsItem* parent) :
	QGraphicsItem(parent)
	, mPos{ 0,0 }
	, mAlive(true)
	, mSprite{}
{
	setPosition(initialPos);
}

Entity::~Entity(){}

QPointF Entity::getPosition()
{
	return mPos;
}

void Entity::setPosition(QPointF pos)
{
	mPos = pos;
}

bool Entity::getAlive()
{
	return mAlive;
}

void Entity::setAlive(bool alive)
{
	mAlive = alive;
}

void Entity::setSprite(QPixmap pixmap)
{
	mSprite = pixmap;
}

void Entity::setSpriteSize(int spriteSize)
{
	mSpriteSize = spriteSize;
}

int Entity::getSpriteSize()
{
	return mSpriteSize;
}

QRectF Entity::boundingRect() const
{
	QPolygonF mShape;
	mShape << QPointF(-1, -1)
		<< QPointF(-1, 1)
		<< QPointF(1, 1)
		<< QPointF(1, -1);

	return mShape.boundingRect();
}

void Entity::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPixmap(mPos.x() - mSpriteSize / 2, mPos.y() - mSpriteSize / 2, mSprite.scaled(mSpriteSize, mSpriteSize));
}