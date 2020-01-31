#ifndef COMMUNAUTE_HH
#define COMMUNAUTE_HH

#include "social.hh"
#include "couple.hh"
#include <vector>
#include <map>

/*class Communaute represent un classement d'environment d'une fammile dans un communaute.
 */
class Communaute : public Social
{
public:
	Communaute(vector<Couple> v);
	void classement();
	string le_mieux();
	float valeur_moyen();
private:
	vector<Couple> _V;
};


#endif
