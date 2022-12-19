#include "animal.h"


//constructeur
Animal::Animal(QPointF initialPos, QPixmap sprite, int spriteSize, Entity* parent)
	: Entity(initialPos, QPixmap(), spriteSize),
	mAge(0),
	mSexe(-1),
	mEnceinte(false),
	mHunger(0),
	mSpeed(0),
	mObjective{},
	mHasObjective(false)
{
}

//Destructeur
Animal::~Animal(){}

//Accesseur 
int Animal::getHunger() const
{
	return mHunger;
}

bool Animal::getHasObjective() const
{
	return mHasObjective;
}

//Mutateur 
void Animal::setHunger(int const& faim)
{
	mHunger = faim;
}

void Animal::setAnimalSpeed(int const& speed)
{
	mSpeed = speed;
}

void Animal::setHasObjective(bool const& objective)
{
	mHasObjective = objective;
}
//Fonctions membres

void Animal::manger()
{
	
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

void Animal::move()
{
	float x = getPosition().x();
	float y = getPosition().y();

	QPointF posActuel = { x,y };
	QPointF vecteurDirecteur = (mObjective - posActuel);
	double distance = sqrt(pow(mObjective.x() - x, 2) + pow(mObjective.y() - y, 2));

	//Checks if has arrived to objective
	if (distance < mSpeed) {
		mHasObjective = false;
		return;
	}

	QPointF vecUnitaire = vecteurDirecteur / abs(distance);

	double opposeSurAdja = (mObjective.y() - y) / (mObjective.x() - x);
	double theta = atan(abs(opposeSurAdja)); // si dans cadran un


	if (posActuel != mObjective){
		posActuel += vecUnitaire * theta;
		setPosition(QPointF(posActuel.x(), posActuel.y()));
	}
}

//QPointF* pos[] peut etre mettre ca en parametre 
void Animal :: findObjective(QPointF pos[100])
{
	int i = 0;
	int smallestLenght = distanceBetween2Points(pos[0], mPos);
	int closestPoint = 0;
	for each (QPointF objective in pos){
		int distance = distanceBetween2Points(objective, mPos);
		if (distance < smallestLenght) {
			smallestLenght = distance;
			closestPoint = i;
		}
		i++;
	}

	mObjective = pos[closestPoint];
	mHasObjective = true;
}

double Animal::distanceBetween2Points(QPointF pos1, QPointF pos2) {
	return sqrt(pow(pos1.x() - pos2.x(), 2) + pow(pos1.y() - pos2.y(), 2));
}