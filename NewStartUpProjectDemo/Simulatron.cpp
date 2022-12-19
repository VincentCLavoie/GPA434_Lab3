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

size_t	const Simulatron::sMaxNbrOfItems{ 100 };

const QString Simulatron::sAboutButtonText("À propos...");
const QString Simulatron::sAboutText(
	R"..(GPA434 
Ingénierie des systèmes orientés objets

Laboratoire  3
Simulation d'un écosystème

Ceci est un simulateur d'un écosystème comprenant des végétaux, des herbivores et des carnivores.

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

#pragma region Simulation

void Simulatron::advance()
{
	mGraphicsScene.advance();

	#pragma region GetEntityLocations
	QPointF validBushPos[100], validRabbitPos[100];
	int i = 0, j = 0;
	
	for (auto& item : mGraphicsScene.items()) {

		//Find all bushes with berries and add their position to a list
		Bush* bush{ dynamic_cast<Bush*>(item) };
		if (bush && bush->getBerries() > 0) {
			validBushPos[i] = (bush->getPosition());
			i++;
		}

		//Find all rabbits and add their position to a list
		Rabbit* rabbit{ dynamic_cast<Rabbit*>(item) };
		if (rabbit) {
			validRabbitPos[j] = (rabbit->getPosition());
			j++;
		}
	}
	#pragma endregion
	
	#pragma region ProcessEntities
	for (auto& item : mGraphicsScene.items()) {

		//Change visual time of day changing transparancy of a rectangle overlay
		QGraphicsRectItem* dark{ dynamic_cast<QGraphicsRectItem*>(item) };
		if (dark) {
			int darkness = 100.0 * sin(simElapsedTime / 200.0) + 100.0;
			dark->setBrush(QColor(0, 0, 0, darkness));
		}

		//Manage rabbits
		Rabbit* rabbit{ dynamic_cast<Rabbit*>(item) };
		if (rabbit) {
			//If rabbit has an objective, move towards objective
			if (rabbit->getHasObjective()) {
				rabbit->move();
			}
			//If not and also if hungry, find closest bush with berries and set as objective
			else if (rabbit->getHunger() < 100) {
				//Check for collisions if already colliding with a bush
				QList<QGraphicsItem*> objs = rabbit->collidingItems();

				for each (QGraphicsItem * obj in objs){
					Bush* yummyBush{ dynamic_cast<Bush*>(obj) };
					if (yummyBush) {
						if (yummyBush->getBerries() >= 1) {
							yummyBush->setBerries(yummyBush->getBerries() - 1);
							rabbit->setHunger(1000);
							rabbit->setHasObjective(false);
						}
					}
				}

				//If the berry bush is too far, set it as a new objective
				rabbit->findObjective(validBushPos);
			}
			//Each frame, reduce hunger. If hunger reaches 0, kill the rabbit.
			rabbit->setHunger(rabbit->getHunger() - 1);
			if (rabbit->getHunger() <= 0) {
				rabbit->setAlive(false);
			}
		}

		//Manage foxes
		Fox* fox{ dynamic_cast<Fox*>(item) };
		if (fox) {
			//If rabbit has an objective, move towards objective
			if (fox->getHasObjective()) {
				fox->move();
			}
			else {
				if (fox->getHunger() < 100) {
					//Check for collisions if already colliding with a rabbit
					QList<QGraphicsItem*> objs = fox->collidingItems();

					for each (QGraphicsItem * obj in objs)
					{
						Rabbit* yummyRabbit{ dynamic_cast<Rabbit*>(obj) };
						if (yummyRabbit) {
							fox->setHunger(1000);
							fox->setHasObjective(false);
							yummyRabbit->setAlive(false);
						}
					}

					fox->findObjective(validRabbitPos);
				}
			}
			//Each frame, reduce hunger. If hunger reaches 0, kill the fox.
			fox->setHunger(fox->getHunger() - 1);
			if (fox->getHunger() <= 0) {
				fox->setAlive(false);
			}
		}
	}
	#pragma endregion

	#pragma region DeleteEntities
	for (auto& item : mGraphicsScene.items()) {
		Entity* entity{ dynamic_cast<Entity*>(item) };
		if (entity && !entity->getAlive()) {
			mGraphicsScene.removeItem(entity);

			//Create Mushroom
			mGraphicsScene.addItem(new Mushroom(entity->getPosition()));

			delete entity;
		}
	}
	#pragma endregion

	simElapsedTime++;
}

void Simulatron::startSimulation()
{
	// Vide la scène pour démarrer une nouvelle démo
	mGraphicsScene.clear();

	// Remettre le temps écoulé à 0
	simElapsedTime = 0;

	// Dessine le fond d'écran de la scène
	QPixmap pixmap("Ressources/background.png");
	mGraphicsScene.addPixmap(pixmap)->setPos(-mGraphicsScene.width() / 2, -mGraphicsScene.height() / 2);

	//Ajoute les n buissons
	for (int i{0}; i < mParameters->nbrOfBushes(); ++i) {
		mGraphicsScene.addItem(new Bush(QPointF(random(-80, 80)*10, random(-45,45)*10)));
	}

	//Ajoute les n lapins
	for (int i{ 0 }; i < mParameters->nbrOfRabbits(); ++i) {
		mGraphicsScene.addItem(new Rabbit(QPointF(random(-80, 80) * 10, random(-45, 45) * 10)));
	}

	//Ajoute les n renards
	for (int i{ 0 }; i < mParameters->nbrOfFoxes(); ++i) {
		mGraphicsScene.addItem(new Fox(QPointF(random(-80, 80) * 10, random(-45, 45) * 10)));
	}
	
	//$Ajoute un rectangle noir qui change de transparance pour simuler la noirceur
	QGraphicsRectItem* Darkness = new QGraphicsRectItem(mGraphicsScene.sceneRect());
	Darkness->setPen(Qt::NoPen);
	Darkness->setBrush(QColor(0, 0, 0, 128));
	mGraphicsScene.addItem(Darkness);

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