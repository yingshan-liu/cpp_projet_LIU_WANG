#ifndef PLANTE_HH
#define PLANTE_HH

#include "membre.hh"
#include "humain.hh"
#include "fonction.hh"

class Plante : public Membre
{
public:
	Plante(int ages):Membre("non",ages){};
	Plante(int ages,Humain people1,Humain people2 = Humain(0,0,0));
	float influence_sante();
	float influence_environnement();
protected:
  //represent les 2 personne vivant dans la famille.
	Humain _people1,_people2;
};
#endif
