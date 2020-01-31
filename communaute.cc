#include "communaute.hh"
//Constructeur en utilisant un vecteur de Couple.
Communaute::Communaute(vector<Couple> v):_V(v){}
//Ce methode peux faire un classement de situation d'environment,et les afficher.
void Communaute::classement()
{
	float j;
	int n=1;
	string label;
	multimap<float,string> m;
	for(auto i : _V)
	{
		j = i.influence_environnement();
		label = i.label();
		m.insert(pair<float,string>(j,label));
	}
	cout<<"________________________________"<<endl;
	cout<<"rank      label        dommage"<<endl;
	for(auto k : m){
	  cout <<n<<"        "<<k.second <<"         "<< k.first << endl;
		n++;
	}
	cout<<"________________________________"<<endl;
}
//Ce methode retourne le nom de personne qui a l'influence d'environment plus bas.

string Communaute::le_mieux(){
	float cpt = _V[0].influence_environnement();
	string name = _V[0].label();
	for(auto i : _V)
	{
		if((i.influence_environnement()) < cpt)
		{
			cpt = i.influence_environnement();
			name = i.label();
		}
	}
	return name;
}

//Ce methode retourne un valeur moyen d'influence d'environment dans ce communaute.
float Communaute::valeur_moyen(){
	float cpt = 0;
	float val = 0;
	for(auto i : _V)
	{
		cpt += 1;
		val += i.influence_environnement();
	}
	return (val/cpt);
}
