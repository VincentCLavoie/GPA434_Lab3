#include "Entity.h"

Entity::Entity(QPointF initialPos, QPixmap sprites, QGraphicsItem* parent) :
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

void Entity::setSprite(QPixmap pixmap) {
	mSprite = pixmap;
}

QRectF Entity::boundingRect() const
{
	QPolygonF mShape;
	mShape << QPointF(0, 0)
		<< QPointF(-0.25, 0.5)
		<< QPointF(1, 0)
		<< QPointF(-0.25, -0.5);

	return mShape.boundingRect();
}

void Entity::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QPixmap bush("Ressources/bush_1.png");

	painter->drawPixmap(mPos.x()-50,mPos.y()-50, mSprite.scaled(100, 100));
}