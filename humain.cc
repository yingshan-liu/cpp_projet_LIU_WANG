#include "humain.hh"

/*Realiser un constructeur en entrant le nom,age,sex,a quel age il 
a commence a fumer,temp de fumer(ans),temp cesser fumer,frequence de 
fumer .
 */
Humain::Humain(string name,int ages,
			   int taf,int tf,int tcf,
			   membreNature n,fumerFrequence f):
			   Membre(name,ages),
			   _tempsAvantFumer(taf),
			   _tempsFumer(tf),
			   _tempsCesserFumer(tcf),
			   _nature(n),
			   _frequence(f){}
/*Realiser un constructeur en entrant :a quel age il 
a commence a fumer,temp de fumer,temp cesser fumer.
 */
Humain::Humain(int taf,int tf,int tcf):_tempsAvantFumer(taf),_tempsFumer(tf),_tempsCesserFumer(tcf){}

/*A partir de _frequence,calculer un table de coefficient 
d'influence en raison de frequence de fumer pour realiser influence_sante().
*/
void Humain::calculer_fcoeff(float* frequenceCoefficient){
	frequenceCoefficient[0] = 0.7;
	switch(_frequence)
	{
		case T : frequenceCoefficient[1] = 0.75;
				 frequenceCoefficient[2] = 0.38;
				 break;

		case G : frequenceCoefficient[1] = 0.63;
				 frequenceCoefficient[2] = 0.3;
				 break;

		case R : frequenceCoefficient[1] = 0.47;
				 frequenceCoefficient[2] = 0.26;
				 break;

		case N : frequenceCoefficient[1] = 0;
				 frequenceCoefficient[2] = 0;
				 break;
	}
}
/*A partir de _frequence,calculer un table de coefficient 
d'influence en raison de sexe pour realiser influence_sante().
*/
void Humain::calculer_ncoeff(float* natureCoefficient){
	switch(_nature)
	{
		case H : natureCoefficient[0] = 0.7;
				 natureCoefficient[1] = 0.32;
				 natureCoefficient[2] = 0.18;
				 break;

		case F : natureCoefficient[0] = 0.73;
				 natureCoefficient[1] = 0.39;
				 natureCoefficient[2] = 0.25;
				 break;
	}
}
/*A l'aide des 2 methode avant,nous pouvons calculer l'influence a 
sante a cause de l'action de fumer.
 */
float Humain::influence_sante(){
	float frequenceCoefficient[3],natureCoefficient[3],influ;
	calculer_fcoeff(frequenceCoefficient);
	calculer_ncoeff(natureCoefficient);

	influ = _tempsAvantFumer*frequenceCoefficient[0]*natureCoefficient[0] +
		    _tempsFumer*frequenceCoefficient[1]*natureCoefficient[1] +
		    _tempsCesserFumer*frequenceCoefficient[2]*natureCoefficient[2];
	
	return influ;
}
/*A l'aide des 2 methode avant,nous pouvons calculer l'influence a 
environment a cause de l'action de fumer.
 */
float Humain::influence_environnement(){
	float frequenceCoefficient,influ;
	switch(_frequence)
	{
		case T : frequenceCoefficient = 0.9;break;
		case G : frequenceCoefficient = 0.6;break;
		case R : frequenceCoefficient = 0.3;break;
		case N : frequenceCoefficient = 0;  break;
	}
	influ = _tempsFumer*frequenceCoefficient;
	return influ;
}


//Afficher les dommage des sante et environment d'une personne.
ostream& operator<<(ostream& out,Humain& h){
	out << "nom : " << h.nom() << endl;
	out << "age : " << h.age() << endl;
	out << "dommage pour sante : " << h.influence_sante() << endl;
	out << "dommage pour environnement : " << h.influence_environnement() << endl;
	return out;
}
//Comparer les situation d'influence de sante entre 2 personnes.
bool operator<(Humain& h1,Humain& h2){
	return h1.influence_sante() < h2.influence_sante();
}
bool operator>(Humain& h1,Humain& h2){
	return h1.influence_sante() > h2.influence_sante();
}
bool operator==(Humain& h1,Humain& h2){
	return h1.influence_sante() == h2.influence_sante();
}

//Si quelqu'un fume.
bool Humain::fumer(){
	if(_frequence == N)
		return 0;
	else
		return 1;
}
//retourner le nom d'un personne qui ont un meilleur sante.
string Humain::meilleux_sante(Humain h1,Humain h2){
	if(h1<h2)
		return h1.nom();
	else if(h1>h2)
		return h2.nom();
	else
		return "meme";
}
