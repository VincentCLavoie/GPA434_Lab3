#include "QArrowItem.h"


#include <QPainter>
#include <QRandomGenerator>
#include <QtMath>
#include <QGraphicsScene>
#include <QtMath>


QArrowItem::QArrowItem(double lifeExpectancy, QPointF const & initialPosition, qreal initialOrientationDegrees, qreal initialSpeed, qreal scale, QBrush const & brush, QGraphicsItem * parent)
	:	QGraphicsItem(parent),
		mLifeExpectancy{ lifeExpectancy },
		mAge{ 0.0 },
        mBrush(brush),
		mSpeed{ initialSpeed }
{
	mShape	<< QPointF(0, 0)
			<< QPointF(-0.25, 0.5)
			<< QPointF(1, 0)
			<< QPointF(-0.25, -0.5);

	setPos(initialPosition);
	setRotation(initialOrientationDegrees);
	setScale(scale);
}

void QArrowItem::setColor(QBrush const & brush)
{
	mBrush = brush;
}

void QArrowItem::setSpeed(qreal speed)
{
	mSpeed = speed;
}

QRectF QArrowItem::boundingRect() const
{
	return mShape.boundingRect();
}

void QArrowItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(mBrush);
	painter->drawPolygon(mShape);
}

void QArrowItem::advance(int phase)
{
	//
	// D�termine le comportement
	if (phase == 0) {
		static qreal const maxDeltaOrientation{ 12.5 }; // in �
		// D�termine la nouvelle orientation selon une variation al�atoire dans l'intervalle [-maxDeltaOrientation, maxDeltaOrientation] => � 12.5�
		mNewOrientation = rotation() + QRandomGenerator::global()->bounded(2.0 * maxDeltaOrientation) - maxDeltaOrientation;
		// D�termine la nouvelle position selon la nouvelle orientation et la vitesse
		qreal newOrientationRadians{ qDegreesToRadians(mNewOrientation) };
		mNewPosition = pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * mSpeed;
		// Si la nouvelle position est � l'ext�rieur de la sc�ne, la nouvelle position est t�l�port�e � la r�gion oppos�e de la sc�ne
		warp(mNewPosition);
	//
	// Applique le comportement
	} else if (phase == 1) {
		// Applique la nouvelle orientation et la nouvelle position
		setRotation(mNewOrientation);
		setPos(mNewPosition);

		// Plus vieux... le temps fil si rapidement...
		mAge += 0.030;
	}
}

bool QArrowItem::isAlive() const
{
    return mAge <= mLifeExpectancy;
}

qreal QArrowItem::warp(qreal value, qreal begin, qreal end) {
	qreal const width = end - begin;
	return value - qFloor((value - begin) / width) * width;
}

void QArrowItem::warp(QPointF & point) {
	point.setX(warp(point.x(), scene()->sceneRect().left(), scene()->sceneRect().right()));
	point.setY(warp(point.y(), scene()->sceneRect().top(), scene()->sceneRect().bottom()));
}



class Point
{
private:
	int x;
	int y;
public:
	Point(int vx, int vy)
		: x{ vx }, y{ vy }
	{
	};
	Point(Point& point) 
	{
		x = point.x;
		y = point.y;
	}
	void setX(int val) { x = val; }
	void setY(int val) { y = val; }

};

Point p1(10,10);