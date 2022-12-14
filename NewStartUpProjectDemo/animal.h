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
	int getHunger() const;
	bool getHasObjective() const;

	//Mutateur 
	void setNbAniDepart(int const& NbAni); //nombre d'animaux au depart de la simulation
	void setHunger(int const& hungerValue);
	void setAnimalSpeed(int const& speed);
	void setHasObjective(bool const& objective);

	//Fonctions membres
	void manger(); // si on a ou non deja mang?
	void collisionAnimauxNourriture(); //$ parametres on ne sait pas trop quoi mettre
	void move();
	bool runAway();
	void reproduction();
	void ageLimite(); //$v?rifier si on retourne qqch
	//QPointF findObjectif(QPointF* pos); //permet de savoir ou il veut aller.
	void rabbitMove();
	void findObjective(QPointF pos[100]);
	
private:
	double distanceBetween2Points(QPointF pos1, QPointF pos2);

protected:
	int mSexe;
	bool mEnceinte;

private:
	int mAge;
	int mHunger;
	QPointF mObjective;
	int mSpeed;
	bool mHasObjective;
};