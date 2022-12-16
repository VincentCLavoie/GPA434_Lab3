#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simulatron.h"

#include <QGraphicsScene>
#include <QTimer>

#include <QRandomGenerator>
#include <QGraphicsView>
#include "QControlBar.h"
#include "QParameters.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include "QArrowItem.h"

#include <math.h>

#include <QGraphicsPixmapItem>

#include "Entity.h"
#include "bush.h"

class QGraphicsView;
class QControlBar;
class QParameters;
class QPushButton;


class Simulatron : public QMainWindow
{
	Q_OBJECT

public:
	Simulatron(QWidget* parent = Q_NULLPTR);

private:
	Ui::Simulatron ui;

	QGraphicsScene mGraphicsScene;
	QGraphicsView* mSimulationView;
	QParameters* mParameters;
	QControlBar* mControlBar;
	QPushButton* mAboutButton;

	QTimer mTimer;

	// Fonctions utilitaires de g�n�ration de valeurs al�atoires : devraient �tre ailleurs.
	double random(qreal maxValue);
	double random(qreal minValue, qreal maxValue);
	QColor randomColor();
	QPointF randomPoint(qreal min, qreal max);


	//$
	QGraphicsRectItem* Darkness;
	double simElapsedTime;

private slots:
	void startSimulation();
	void stepSimulation();
	void pauseSimulation();
	void resumeSimulation();
	void stopSimulation();

	void advance();

	void about();

private:
	// Lit�raux et variables symboliques utilis�s
	static QSize	const sSceneSize;				// Taille de la sc�ne
	static size_t	const sMaxNbrOfItems;			// Nombre maximum de fl�che
	static QString	const sAboutButtonText;			// Text du bouton "� propos"
	static QString	const sAboutText;				// Text pour la bo�te � propos
	static QString	const sControlStartText;		// Textes pour les contr�les
	static QString	const sControlStopText;			//    "
	static QString	const sControlPauseText;		//    "
	static QString	const sControlResumeText;		//    "
	static QString	const sControlStepText;			//    "
	static QColor	const sControlRunningColor;		//    "
	static QColor	const sControlPauseColor;		//    "
	static QColor	const sControlStoppedColor;		//    "
	static QColor	const sControlNotReadyColor;	//    "
	static qreal	const sMinLifeExpectancy;		// Constantes li�es � la cr�ation al�atoire des fl�ches
	static qreal	const sMaxLifeExpectancy;		//	  "
	static qreal	const sCenterRadius;			//    "
	static qreal	const sMinOrientationDegrees;	//    "
	static qreal	const sMaxOrientationDegrees;	//    "
	static qreal	const sMinSpeed;				//    "
	static qreal	const sMaxSpeed;				//    "
	static qreal	const sMinSize;					//    "
	static qreal	const sMaxSize;					//    "
	
	static int		const sBushes;
};
