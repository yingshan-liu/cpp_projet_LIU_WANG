#include "plante.hh"
//Construteur en entrant l'age et maitre de ce plant.
Plante::Plante(int ages,Humain people1,Humain people2/* = Humain(0,0,0)*/):Membre("non",ages),
																	   _people1(people1),
																	   _people2(people2){}

//represent la influence de ce plant a cause des actions de fumer.
float Plante::influence_sante(){
	float influ;
	influ = _people1.influence_environnement() + _people2.influence_environnement();
	influ *= 1.1;
	return influ;
}
//represent la bon influence de ce plant.
float Plante::influence_environnement(){
	float influ;
	influ = _age*0.15;
	return influ;
}
