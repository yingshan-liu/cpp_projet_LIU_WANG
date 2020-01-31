#ifndef COUPLE_HH
#define COUPLE_HH

#include "humain.hh"
#include "plante.hh"
#include "fonction.hh"

/* Ce class definit un influence a sante global a une personne qui vive dans le famille(ex.un enfant..),c'est affecte par les deux maitre et aussi les plants.
 */
class Couple : public Humain
{
public:
	Couple(string label,Humain people1,Humain people2,Plante plante = Plante(0));
	float influence_sante();
	float influence_environnement();
	string label();
private:
	string _label;
	Humain _people1;
	Humain _people2;
	Plante _plante;
};
#endif
