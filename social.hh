#ifndef SOCIAL_HH
#define SOCIAL_HH

#include <iostream>
#include <string>

using namespace std;
/*C'est un class abstract pour generer les classes pour faire un classement et analyser les resultat.
 */
class Social
{
public:
	virtual void classement()=0;
	virtual string le_mieux()=0;
	virtual float valeur_moyen()=0;
};



#endif
