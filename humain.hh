#ifndef HUMAIN_HH
#define HUMAIN_HH

#include "membre.hh"
#include "fonction.hh"

class Humain : public Membre
{
public:
	Humain(){}
	Humain(int taf,int tf,int tcf);
	Humain(string name,int ages,int taf,int tf,int tcf,membreNature n,fumerFrequence f);
	virtual float influence_sante();
	//virtual string influence_classement();
	virtual float influence_environnement();
	
	friend ostream& operator<<(ostream& out,Humain& h); 
	friend bool operator<(Humain& h1,Humain& h2);
	friend bool operator>(Humain& h1,Humain& h2);
	friend bool operator==(Humain& h1,Humain& h2);
	bool fumer();
	string meilleux_sante(Humain h1,Humain h2);
protected:
	int _tempsAvantFumer,
		_tempsFumer,
		_tempsCesserFumer;
	membreNature _nature;
	fumerFrequence _frequence;
private:
	void calculer_fcoeff(float* frequenceCoefficient);
	void calculer_ncoeff(float* natureCoefficient);
};
#endif