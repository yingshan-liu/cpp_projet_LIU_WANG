#ifndef HOPITAL_HH
#define HOPITAL_HH

#include "social.hh"
#include "humain.hh"
#include <vector>
#include <map>


class Hopital : public Social
{
public:
	Hopital(vector<Humain> v);
	void classement();
	string le_mieux();
	string le_pire();
	float valeur_moyen();
	float poucentage();
private:
	vector<Humain> _V;
	

	
};



#endif