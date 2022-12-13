#include "Simulatron.h"

#pragma region Constants

QSize	const Simulatron::sSceneSize(1720, 1000);
QString	const Simulatron::sControlStartText("Démarrer la simulation");
QString	const Simulatron::sControlStopText("Terminer la simulation");
QString	const Simulatron::sControlPauseText("Mettre la simulation sur pause");
QString	const Simulatron::sControlResumeText("Reprendre la simulation");
QString	const Simulatron::sControlStepText("Faire un pas de simulation");
QColor	const Simulatron::sControlRunningColor(0, 255, 0);
QColor	const Simulatron::sControlPauseColor(255, 196, 0);
QColor	const Simulatron::sControlStoppedColor(255, 0, 0);
QColor	const Simulatron::sControlNotReadyColor(230, 230, 230);

size_t	const Simulatron::sMaxNbrOfItems{ 1000 };
qreal	const Simulatron::sMinLifeExpectancy{ 1.0 };
qreal	const Simulatron::sMaxLifeExpectancy{ 10.0 };
qreal	const Simulatron::sCenterRadius{ 25 };
qreal	const Simulatron::sMinOrientationDegrees{ 0.0 };
qreal	const Simulatron::sMaxOrientationDegrees{ 360.0 };
qreal	const Simulatron::sMinSpeed{ 1.0 };
qreal	const Simulatron::sMaxSpeed{ 5.0 };
qreal	const Simulatron::sMinSize{ 7.5 };
qreal	const Simulatron::sMaxSize{ 15.0 };

const QString Simulatron::sAboutButtonText("À propos...");
const QString Simulatron::sAboutText(
	R"..(GPA434 
Ingénierie des systèmes orientés objets

Laboratoire  3
Simulation d'un écosystème

Ce projet consiste à ...

Réalisé par :
   - Vincent Lavoie
   - Russel Bulaon
   - Liliam Elena Acosta
)..");

#pragma endregion

Simulatron::Simulatron(QWidget* parent)
	: QMainWindow(parent)
	, mSimulationView{ new QGraphicsView(&mGraphicsScene) }
	, mParameters{ new QParameters(sMaxNbrOfItems) }
	, mControlBar{ new QControlBar(Qt::Vertical) }
	, mAboutButton{ new QPushButton(sAboutButtonText) }
	, simElapsedTime{}
{
	setWindowTitle("Simulatron");
	setWindowIcon(QIcon("Ressources/logo.png"));

	ui.setupUi(this);

	mControlBar->setReady();
	mControlBar->setActionText(QControlBar::Action::Start, sControlStartText);
	mControlBar->setActionText(QControlBar::Action::Stop, sControlStopText);
	mControlBar->setActionText(QControlBar::Action::Pause, sControlPauseText);
	mControlBar->setActionText(QControlBar::Action::Resume, sControlResumeText);
	mControlBar->setActionText(QControlBar::Action::Step, sControlStepText);
	mControlBar->setStateColor(QControlBar::State::NotReady, sControlNotReadyColor);
	mControlBar->setStateColor(QControlBar::State::Paused, sControlPauseColor);
	mControlBar->setStateColor(QControlBar::State::Running, sControlRunningColor);
	mControlBar->setStateColor(QControlBar::State::Stopped, sControlStoppedColor);

	mGraphicsScene.setSceneRect(-sSceneSize.width() / 2, -sSceneSize.height() / 2, sSceneSize.width(), sSceneSize.height());

	QWidget* controlWidget{ new QWidget };
	QVBoxLayout* controlLayout{ new QVBoxLayout };
	controlWidget->setLayout(controlLayout);
	controlLayout->addWidget(mParameters);
	controlLayout->addStretch();
	controlLayout->addWidget(mControlBar);
	controlLayout->addWidget(mAboutButton);

	QWidget* centralWidget{ new QWidget };
	QHBoxLayout* centralLayout{ new QHBoxLayout };
	centralWidget->setLayout(centralLayout);

	centralLayout->addWidget(mSimulationView);
	centralLayout->addWidget(controlWidget);

	setCentralWidget(centralWidget);

	connect(mControlBar, &QControlBar::started, this, &Simulatron::startSimulation);
	connect(mControlBar, &QControlBar::stopped, this, &Simulatron::stopSimulation);
	connect(mControlBar, &QControlBar::paused, this, &Simulatron::pauseSimulation);
	connect(mControlBar, &QControlBar::resumed, this, &Simulatron::resumeSimulation);
	connect(mControlBar, &QControlBar::stepped, this, &Simulatron::stepSimulation);

	connect(&mTimer, &QTimer::timeout, this, &Simulatron::advance);

	connect(mAboutButton, &QPushButton::clicked, this, &Simulatron::about);
}

void Simulatron::advance()
{
	mGraphicsScene.advance();

	for (auto& item : mGraphicsScene.items()) {
		QArrowItem* arrow{ dynamic_cast<QArrowItem*>(item) };
		if (arrow && !arrow->isAlive()) {
			mGraphicsScene.removeItem(arrow);
			delete arrow;
		}
		Entity* entity{ dynamic_cast<Entity*>(item) };
		//QGraphicsRectItem* d{ dynamic_cast<QGraphicsRectItem*>(item) };
		//if (d)
		//{
		//	double darkness = 100.0 * sin(simElapsedTime / 200.0) + 100.0;
		//	d->setBrush(QColor(0, 0, 0, darkness));
		//}

	}

	//Time of day
	//mGraphicsScene.removeItem(Darkness);

	//double darkness = 100.0 * sin(simElapsedTime / 200.0) +100.0;
	//Darkness->setBrush();



	simElapsedTime++;
}

#pragma region Simulation

void Simulatron::startSimulation()
{
	// Vide la scène pour démarrer une nouvelle démo
	mGraphicsScene.clear();

	// Remettre le temps écoulé à 0
	simElapsedTime = 0;

	// Dessine le fond d'écran de la scène
	QPixmap pixmap("Ressources/background.png"); //Test d'image
	mGraphicsScene.addPixmap(pixmap)->setPos(-mGraphicsScene.width() / 2, -mGraphicsScene.height() / 2);

	//$Ajoute un rectangle noir qui change de transparance pour simuler la noirceur
	Darkness = new QGraphicsRectItem(mGraphicsScene.sceneRect());
	Darkness->setPen(Qt::NoPen);
	Darkness->setBrush(QColor(0, 0, 0, 128));
	mGraphicsScene.addItem(Darkness);

	// Ajoute les n flèches
	for (int i{ 0 }; i < mParameters->nbrOfItems(); ++i) {
		mGraphicsScene.addItem(
			new QArrowItem(random(sMinLifeExpectancy, sMaxLifeExpectancy),			// espérance de vie en seconde
				randomPoint(-sCenterRadius, sCenterRadius),				// ils sont tous près de l'origine au départ!
				random(sMinOrientationDegrees, sMaxOrientationDegrees),	// orientation aléatoire
				random(sMinSpeed, sMaxSpeed),							// vitesse aléatoire
				random(sMinSize, sMaxSize),								// taille aléatoire
				randomColor()));										// couleur aléatoire
	}

	Entity* raspBush = new Entity(QPointF(20,20), Qt::black);
	mGraphicsScene.addItem(raspBush);
	

	// Démarre la simulation
	mTimer.start(30);

	mParameters->setEnabled(false);
}

void Simulatron::stepSimulation()
{
	mGraphicsScene.advance();
}

void Simulatron::pauseSimulation()
{
	mTimer.stop();
}

void Simulatron::resumeSimulation()
{
	mTimer.start(30);
}

void Simulatron::stopSimulation()
{
	mTimer.stop();
	mParameters->setEnabled(true);
}

#pragma endregion

void Simulatron::about()
{
	QMessageBox::about(this, "À propos...", sAboutText);
}

#pragma region Random

double Simulatron::random(qreal maxValue)
{
	return QRandomGenerator::global()->bounded(maxValue);
}

double Simulatron::random(qreal minValue, qreal maxValue)
{
	return random(maxValue - minValue) + minValue;
}

QColor Simulatron::randomColor()
{
	return QColor::fromRgb(QRandomGenerator::global()->generate());
}

QPointF Simulatron::randomPoint(qreal min, qreal max)
{
	return QPointF(random(min, max), random(min, max));
}

#pragma endregion