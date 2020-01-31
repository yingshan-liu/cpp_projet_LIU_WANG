#include "hopital.hh"
//Constructeur en utilisant un vecteur de Humain,soit les class de persone.
Hopital::Hopital(vector<Humain> v):_V(v){}

//Ce methode peux faire un classement de situation de sante,et les afficher.
void Hopital::classement(){
	float j;
	int n=1;
	string name;
	multimap<float,string> m;
	for(auto i : _V)
	{
		j = i.influence_sante();
		name = i.nom();
		m.insert(pair<float,string>(j,name));
	}
	cout<<"________________________________"<<endl;
	cout<<"rank       nom        dommage"<<endl;
	for(auto k : m){
	  cout << n<<"          "<<k.second << "         "<< k.first << endl;
		n++;
	}
	cout<<"________________________________"<<endl;
}
//Ce methode retourne le nom de personne qui a l'influence de sante plus bas.
string Hopital::le_mieux(){
	float cpt = _V[0].influence_sante();
	string name;
	for(auto i : _V)
	{
		//cout << i.nom() << i.influence_sante() << endl;
		if((i.influence_sante()) < cpt)
		{
			cpt = i.influence_sante();
			name = i.nom();
		}
	}
	return name;
}

//Ce methode retourne le nom de personne qui a l'influence de sante plus haut.
string Hopital::le_pire(){
	float cpt = _V[0].influence_sante();
	string name;
	for(auto i : _V)
	{
		if((i.influence_sante()) > cpt)
		{
			cpt = i.influence_sante();
			name = i.nom();
		}
	}
	return name;
}


float Hopital::valeur_moyen(){
	float cpt = 0;
	float val = 0;
	for(auto i : _V)
	{
		cpt += 1;
		val += i.influence_sante();
	}
	return (val/cpt);
}

//Calculer un poucentage de fumer dans ce list de personne de cet hopitgal.
float Hopital::poucentage(){
	float numTotal = 0;
	float numFumer = 0;
	for(auto i : _V)
	{
		numTotal += 1;
		if(i.fumer())
			numFumer += 1;
	}
	return 100*(numFumer/numTotal);
}
