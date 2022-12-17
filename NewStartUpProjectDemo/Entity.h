#pragma once
#include <qgraphicsitem.h>
#include "qvector2d.h"
#include <QPixmap>
#include <QBrush>
#include <QPainter>
//avec possibilit/ de l<enlever
#include "QArrowItem.h"



class Entity : public QGraphicsItem
{
public:
	Entity()= default;
	Entity(QPointF pos, QPixmap sprite, int spriteSize, QGraphicsItem* parent = nullptr);
	~Entity();// override = default;
	
	// Fonction abstraite de QGraphicsItem (DOIT être "override") : retourne la taille de l'item
	QRectF boundingRect() const override;
	// Fonction abstraite de QGraphicsItem (DOIT être "override") : dessine la forme
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	//fonctions
	void setPosition(QPointF pos);
	QPointF getPosition();
	void setAlive(bool alive);
	bool getAlive();
	void setSprite(QPixmap pixmap);
	int getSpriteSize();
	void setSpriteSize(int size);

protected:
	QPointF mPos;
	bool mAlive;

private:
	QPixmap mSprite;
	int mSpriteSize;
};