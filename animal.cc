#include "animal.hh"
//construteur realise en entrant les nom,age et les maitre.
Animal::Animal(string name,int ages,Humain people1,Humain people2/* = Humain(0,0,0)*/):Membre(name,ages),
																				   _people1(people1),
																				   _people2(people2){}
float Animal::influence_environnement(){
	return 0;
}
/*calculer les influence de sante a cet animal a cause des actions de fumer passif.
 */
float Animal::influence_sante(){
	float influ;
	influ = _people1.influence_environnement() + _people2.influence_environnement();
	influ *= 1.4;
	return influ;
}
