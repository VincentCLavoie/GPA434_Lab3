#pragma once
#include <qgraphicsitem.h>
#include "qvector2d.h"
#include "qpixmap.h"
#include <QBrush>
#include <QPainter>


class Entity : public QGraphicsItem
{
public:
	Entity(QPointF pos, QBrush const& brush, QGraphicsItem* parent = nullptr);
	~Entity();// override = default;
	//Entity(Entity const&) = default;
	//Entity& operator=(Entity const &) = delete;

	// Fonction abstraite de QGraphicsItem (DOIT être "override") : retourne la taille de l'item
	QRectF boundingRect() const override;
	// Fonction abstraite de QGraphicsItem (DOIT être "override") : dessine la forme
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;



	//fonctions
	void setPosition(QPointF _pos);
	QPointF getPosition();
	void setAlive(bool _alive);
	bool getAlive();

protected:
	QPolygonF mShape;
	QBrush mBrush = Qt::black;

private:

	QPointF pos;
	bool alive;


};
