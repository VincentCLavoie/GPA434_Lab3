#pragma once
#include <cmath>

class Animaux
{
public:
	//constructeur 
	Animaux();

	//destructeur
	~Animaux();

	//Accesseur 
	int getNbAniDepart() const;
	bool getFaim() const; 

	//Mutateur 
	void setNbAniDepart(int const& NbAni); //nombre d'animaux au depart de la simulation
	void setFaim(bool const& faim);

	//Fonctions membres
	void manger(); // si on a ou non deja mangé
	void collisionAnimauxNourriture(); //$ parametres on ne sait pas trop quoi mettre
	int  move();
	bool runAway();
	void reproduction();
	void ageLimite(); //$vérifier si on retourne qqch
	

protected:

	int mSexe; 
	bool mEnceinte;


private:

	int mAge;
	bool mMange; // variable qui dit si l'annimaux decide de manger ou pas
	bool mFaim;
	int mNbAni;
};
