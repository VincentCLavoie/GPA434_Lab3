#include "animal.h"


//constructeur
Animal::Animal(QPointF initialPos, QPixmap sprite, int spriteSize, Entity* parent)
	: Entity(initialPos, QPixmap(), spriteSize),
	mAge(-1),
	mSexe(-1),
	mEnceinte(false),
	mFaim(true)
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

//Mutateur 
void Animal::setNbAniDepart(int const& NbAni)
{
	mNbAni = NbAni;
}

void Animal::setFaim(bool const& faim)
{
	mFaim = faim;
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

void Animal::move()
{
	//Find objective

	
	int finalpoint = (sqrt(pow(.x()- getPosition().x(), 2) + pow(objective.y() - getPosition().y(),2)));
	
	
	mSpeed = 5;
	mObjective = QPointF(60,60);

	float x = getPosition().x();
	float y = getPosition().y();

	if (x < mObjective.x()) {
		x += mSpeed;
	}
	else {
		x -= mSpeed;
	}

	if (y < mObjective.y()) {
		y += mSpeed;
	}
	else {
		y -= mSpeed;
	}

	setPosition(QPointF(x, y));

}