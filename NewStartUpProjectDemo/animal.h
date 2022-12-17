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

	//Mutateur 
	void setNbAniDepart(int const& NbAni); //nombre d'animaux au depart de la simulation
	void setFaim(bool const& faim);

	//Fonctions membres
	void manger(); // si on a ou non deja mang�
	void collisionAnimauxNourriture(); //$ parametres on ne sait pas trop quoi mettre
	void move();
	bool runAway();
	void reproduction();
	void ageLimite(); //$v�rifier si on retourne qqch


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
};