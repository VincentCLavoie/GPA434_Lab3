#pragma once
#include <qgraphicsitem.h>
#include "qvector2d.h"
#include <QPixmap>
#include <QBrush>
#include <QPainter>


class Entity : public QGraphicsItem
{
public:
	Entity(QPointF pos, QGraphicsItem* parent = nullptr);
	~Entity();// override = default;

	// Fonction abstraite de QGraphicsItem (DOIT être "override") : retourne la taille de l'item
	QRectF boundingRect() const override;
	// Fonction abstraite de QGraphicsItem (DOIT être "override") : dessine la forme
	//void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	//fonctions
	void setPosition(QPointF _pos);
	QPointF getPosition();
	void setAlive(bool _alive);
	bool getAlive();

private:
	QPointF pos;
	bool alive;
};