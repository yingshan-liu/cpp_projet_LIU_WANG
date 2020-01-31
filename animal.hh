#ifndef ANIMAL_HH
#define ANIMAL_HH

#include "membre.hh"
#include "humain.hh"
#include "fonction.hh"

class Animal : public Membre
{
public:
	Animal(string name,int ages,Humain people1,Humain people2 = Humain(0,0,0));
	virtual float influence_sante();
	virtual float influence_environnement();
protected:
  //represent les maitres de cet animal.
	Humain _people1,_people2;
};
#endif
