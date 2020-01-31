#ifndef MEMBRE_HH
#define MEMBRE_HH

#include <iostream>
#include <string>
#include <cstdlib>
#include "fonction.hh"

using namespace std;
/*Le class Member definit un class abstrat pour tous les vivant,
  y compris les hommes,animal et plant.
*/
class Membre
{
public:
	Membre(){}
	Membre(string name,int ages);
  //Apres calculer,ce methode va retourner le coeffcient d'influence de sante.
        virtual float influence_sante()=0;
   //Apres calculer,ce methode va retourner le coeffcient d'influence d'environment.
	virtual float influence_environnement()=0;
	string nom();
	int age();
protected:
	string _nom;
	int _age;
};
#endif
