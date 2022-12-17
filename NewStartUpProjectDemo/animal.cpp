#include "animal.h"


//constructeur
Animal::Animal(QPointF initialPos, QPixmap sprite, int spriteSize, Entity* parent)
	: Entity(initialPos, QPixmap(), spriteSize),
	mAge(0),
	mSexe(-1),
	mEnceinte(false),
	mFaim(true),
	mSpeed(0),
	mObjective{},
	mAsObjective(false)
{
}

//Destructeur
Animal::~Animal(){}

//Accesseur 
int Animal::getNbAniDepart() const
{
	return mNbAni;
}

bool Animal::getFaim() const
{
	return mFaim;
}

bool Animal::getAsObjective() const
{
	return mAsObjective;
}

//Mutateur 
void Animal::setNbAniDepart(int const& NbAni)
{
	mNbAni = NbAni;
}

void Animal::setFaim(bool const& faim)
{
	mFaim = faim;
}

void Animal::setAnimalSpeed(int const& speed)
{
	mSpeed = speed;
}

void Animal::setAsObjective(bool const& objective)
{
	mAsObjective = objective;
}
//Fonctions membres

void Animal::manger()
{
	//if (/*mettre une condition*/)// proche ou non de la bouffe
	//{
	if (getFaim() == false) //$ faudrait ajouter la condition s'il veut se reproduire
	{
		//Ne pas manger
	}
	else if (getFaim() == true)
	{
		//enlever une berrie ou un mushroom ou un animaux

	}
	//}
}

//$cette fonction devra aller dans entity
//Le but serait de cr�er une fonction qui 
//gere la collision avec n'importe quel entit� � partir
//de n'importe quel autre entit� pour �viter la redondance
void Animal::collisionAnimauxNourriture()
{
	// Le rayon du cercle entourant l'animaux et la nouriture.
	float rayonLarge = 25.0f, rayonpetit = 15.0f;

	// Calculer la distance entre la position les objets
	//float distance = sqrt(pow(,2));

	//� effacer
	/*float distance = sqrt(pow(ship.position().x() - asteroid.position().x(), 2) + pow(ship.position().y() - asteroid.position().y(), 2));
	if (distance <= rayonVaisseau + rayonAsteriod) {

		asteroid.randomize(5.0f, 20.0f, 0.0f, mWidth, -mHeight, -5.0f, 5.0f, 50.0f, 0.2f, 1.0f, 0.0f, 0.6f);

		mCollisionAsteroide = true;
		ship.collison();
	}
	*/
}

void Animal :: move()
{
	int tailleXScreen = 1700;
	int tailleYScreen = 1000;
	double nbAleatoireX = (rand()%tailleXScreen ) + 1;
	double nbAleatoireY = (rand()%tailleYScreen) + 1;

	mObjective = { nbAleatoireX,nbAleatoireY };

	float x = getPosition().x();
	float y = getPosition().y();
	double opposeSurAdja = (mObjective.y() - getPosition().y()) / (mObjective.x() - getPosition().x());



	double theta = atan(opposeSurAdja);

	if (x < mObjective.x())
	{
		x += cos(theta) * mSpeed;
	}
	else
	{
		x -= cos(theta) * mSpeed;
	}

	if (y < mObjective.y())
	{
		y += sin(theta) * mSpeed;
	}
	else
	{
		y -= sin(theta) * mSpeed;
	}

	setPosition(QPointF(x, y));
	
	
}

/*
//QPointF* pos[] peut etre mettre ca en parametre 
QPointF Animal :: findObjectif(QPointF* pos)
{
	//QPointF direction;
	//direction.setX(mObjective.x() - getPosition().x());
	//direction.setY(mObjective.y() - getPosition().y());
	double nbAleatoireX, nbAleatoireY;
	nbAleatoireX = (rand() % 1500) + 1;
	nbAleatoireY = (rand() % 1000) + 1;
	pos->setX(nbAleatoireX);
	pos->setY(nbAleatoireY);

	return * pos;
	//mais ca c'est plus aller vers objectif...
//	pos->setX(mObjective.x() - getPosition().x());
	//pos->setY(mObjective.y() - getPosition().y());

}
void Animal::rabbitMove(QPointF* pos)
{
	if (mAsObjective == true)
	{
		move();
	}
	else if (mAsObjective == false)
	{
		findObjectif(pos);
	}
}
*/