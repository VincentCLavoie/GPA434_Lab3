#include "animaux.h"


//constructeur
Animaux::Animaux()
	: mAge(-1),
	mSexe(-1),
	mEnceinte(false),
	mFaim(true)
{
}

//Destructeur
Animaux::~Animaux()
{
}

//Accesseur 
int Animaux :: getNbAniDepart() const
{
	return mNbAni;
}

bool Animaux::getFaim() const
{
	return mFaim;
}

//Mutateur 
void Animaux::setNbAniDepart(int const& NbAni)
{
	mNbAni = NbAni;
}

void Animaux::setFaim(bool const& faim)
{
	mFaim = faim;
}

//Fonctions membres

void Animaux::manger()
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
//Le but serait de créer une fonction qui 
//gere la collision avec n'importe quel entité à partir
//de n'importe quel autre entité pour éviter la redondance
void Animaux::collisionAnimauxNourriture() 
{
	// Le rayon du cercle entourant l'animaux et la nouriture.
	float rayonLarge= 25.0f, rayonpetit = 15.0f;

	// Calculer la distance entre la position les objets
	//float distance = sqrt(pow(,2));

	//à effacer
	/*float distance = sqrt(pow(ship.position().x() - asteroid.position().x(), 2) + pow(ship.position().y() - asteroid.position().y(), 2));
	if (distance <= rayonVaisseau + rayonAsteriod) {

		asteroid.randomize(5.0f, 20.0f, 0.0f, mWidth, -mHeight, -5.0f, 5.0f, 50.0f, 0.2f, 1.0f, 0.0f, 0.6f);

		mCollisionAsteroide = true;
		ship.collison();
	}
	*/
}

int Animaux::move() 
{
	return //poisiiton future;
}