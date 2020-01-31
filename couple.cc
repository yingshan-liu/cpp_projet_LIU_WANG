#include "couple.hh"

Couple::Couple(string label,Humain people1,Humain people2,Plante plante):_label(label),_people1(people1),_people2(people2),_plante(plante){}
//Apres les calcule ,il retourne un influence de sante global au humain.
float Couple::influence_sante(){
	float influ;
	influ = _people1.influence_environnement() + 
			_people2.influence_environnement();
	influ *= 1.3;
	return influ;
}
//Apres les calcule ,il retourne un influence d'environment global au humain.
float Couple::influence_environnement(){
	float influ;
	influ = _people1.influence_environnement() + 
			_people2.influence_environnement() - 
			_plante.influence_environnement();
	return influ;
}


string Couple::label(){
	return _label;
}
