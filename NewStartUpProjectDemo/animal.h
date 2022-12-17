#pragma once
#include "Entity.h"
#include <cmath>

class Animal : public Entity
{
public:
	//constructeur 
	Animal() = default;
	Animal(QPointF pos, QPixmap sprite, int spriteSize, Entity* parent = new Entity);

	//destructeur
	~Animal();

	//Accesseur 
	int getNbAniDepart() const;
	bool getFaim() const;
	bool getAsObjective() const;

	//Mutateur 
	void setNbAniDepart(int const& NbAni); //nombre d'animaux au depart de la simulation
	void setFaim(bool const& faim);
	void setAnimalSpeed(int const& speed);
	void setAsObjective(bool const& objective);

	//Fonctions membres
	void manger(); // si on a ou non deja mangé
	void collisionAnimauxNourriture(); //$ parametres on ne sait pas trop quoi mettre
	void move();
	bool runAway();
	void reproduction();
	void ageLimite(); //$vérifier si on retourne qqch
	//QPointF findObjectif(QPointF* pos); //permet de savoir ou il veut aller.
	void rabbitMove(QPointF* pos);

	//Fonction random


protected:

	int mSexe;
	bool mEnceinte;


private:

	int mAge;
	bool mMange; // variable qui dit si l'annimaux decide de manger ou pas
	bool mFaim;
	int mNbAni;
	QPointF mObjective;
	int mSpeed;
	bool mAsObjective;
};