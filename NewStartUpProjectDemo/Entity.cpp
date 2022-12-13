#include "Entity.h"

Entity::Entity(QPointF initialPos, QBrush const & brush, QGraphicsItem* parent) :
	QGraphicsItem(parent)
	, pos{0,0}
	, alive(true)
{
	setPosition(initialPos);

	mShape << QPointF(0, 0)
		<< QPointF(-0.25, 0.5)
		<< QPointF(1, 0)
		<< QPointF(-0.25, -0.5);

}

Entity::~Entity(){}

QPointF Entity::getPosition()
{
	return pos;
}

void Entity::setPosition(QPointF _pos)
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

QRectF Entity::boundingRect() const
{
	return mShape.boundingRect();
}

void Entity::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(mBrush);
	painter->drawPolygon(mShape);
}