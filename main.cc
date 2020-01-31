#include <iostream>
#include <string>
#include "membre.hh"
#include "humain.hh"
#include "plante.hh"
#include "animal.hh"
#include "couple.hh"
#include "social.hh"
#include "hopital.hh"
#include "communaute.hh"
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(){
        cout<<"Test1:Calculer un resultat d'un personne. "<<endl;
        vector<Humain> vh,vl;
	vector<Couple> vc;

        Humain h1("a",50,25,10,15,H,T);cout << h1 << endl; vh.push_back(h1);
	Humain h2("b",40,30,5,5,F,R);cout << h2 << endl;vh.push_back(h2);
	Humain h3("c",20,20,0,0,H,N);vh.push_back(h3);
	cout<<"Test2:Comparer les resulat des 2 personne."<<endl;
	cout << "qui a meilleux sante? : ";
	cout << h1.meilleux_sante(h1,h2) << endl << endl;
	
    	Humain h4("d",24,17,7,0,H,G);vh.push_back(h4);
	Humain h5("e",38,30,3,5,F,G);vh.push_back(h5);
	Humain h6("f",68,40,10,18,H,T);vh.push_back(h6);
	Humain h7("g",54,40,14,0,H,R);vh.push_back(h7);
	Humain h8("h",27,27,0,0,F,N);vh.push_back(h8);
	Humain h9("i",46,46,0,0,H,N);vh.push_back(h9);
	Humain h10("j",34,25,9,0,F,R);vh.push_back(h10);
	Humain h11("k",58,50,1,7,H,T);vh.push_back(h11);
	Humain h12("l",26,20,6,0,H,T);vh.push_back(h12);
	Humain h13("m",19,18,1,0,F,R);vh.push_back(h13);
	Humain h14("n",36,36,0,0,H,N);vh.push_back(h14);
	Humain h15("o",22,22,0,0,F,N);vh.push_back(h15);
	Humain h16("p",48,48,0,0,H,N);vh.push_back(h16);
	Humain h17("q",87,60,10,17,H,T);vh.push_back(h17);
	Humain h18("r",44,37,4,3,F,G);vh.push_back(h18);
	Humain h19("s",50,50,0,0,F,N);vh.push_back(h19);
	Humain h20("t",41,24,17,17,F,G);vh.push_back(h20);
        //lire les donnee dans le fichier de hopital,donc on peux faire un analyse.
        ifstream file;
	file.open("hospital_data.txt");
	string s;
	string nom;
	int x1,x2,x3,x4;
	fumerFrequence f;
	membreNature m;
	while(file>>s){
	    nom=s;
	    file>>s;x1=atoi(s.c_str());
	    file>>s;x2=atoi(s.c_str());
	    file>>s;x3=atoi(s.c_str());
	    file>>s;x4=atoi(s.c_str());
	    file>>s;
	    if(s=="H") m=H;
	    else m=F;
	    file>>s;
	    if(s=="T") f=T;
	    else if(s=="G") f=G;
	    else if(s=="R") f=R;
	    else f=N;
	    Humain h(nom,x1,x2,x3,x4,m,f);vl.push_back(h);
	  }
	file.close();
	cout<<"Test3:Calculer les influence au plant dans une famille"<<endl;
	Plante p1(5,h1,h2);

	cout << "le dommage pour la plante a couse du cigarette : " << p1.influence_sante() << endl<< endl;
	cout << "la purification de l'air grace a la plante est : " << p1.influence_environnement() << endl<< endl;

	Plante p2(2,h4,h8);
	Plante p3(10,h17);
	Plante p4(7,h7,h19);
	Plante p5(9,h18,h16);
	Plante p6(1,h20);
	Plante p7(4,h6);
	Plante p8(6,h13,h12);

	
        cout<<"Test4:Calculer les influences au animal dans une famille"<<endl;
	Animal a1("a1",2,h17);

	cout << "le dommage pour l'ainimal a couse du cigarette : " << a1.influence_sante() << endl<< endl;
	
	Animal a2("a2",4,h4,h8);
	Animal a3("a3",7,h18,h16);
	Animal a4("a4",1,h6);
	Animal a5("a5",3,h8);


	Couple c1("c1",h1,h2);vc.push_back(c1);
        cout<<"Test5:calculer les influence global dans un famille de couple:"<<endl;
	cout << "dommage pour l'environnement pour la famille de couple c1 : " << c1.influence_environnement() << endl<< endl;

	Couple c2("c2",h7,h19,p4);vc.push_back(c2);
	Couple c3("c3",h18,h16,p5);vc.push_back(c3);
	Couple c4("c4",h13,h12,p8);vc.push_back(c4);
	Couple c5("c5",h14,h10);vc.push_back(c5);

	Hopital ho(vl);
	Communaute co(vc);

	cout<<"Test6:Un classement et analyse a partir d'un fichier dans un hopital"<<endl;
	ho.classement(); cout << endl;
	cout << "donc le mieux est: " << ho.le_mieux() <<endl
	     << "le pire est: " << ho.le_pire() <<endl
	     << "le dommage moyen est: " << ho.valeur_moyen() <<endl
	     << "le pourcentage de fumer est: " << ho.poucentage() << "%" <<endl << endl;

	cout<<"Test7:Un classement et analyse de famille de couple."<<endl;
	co.classement();cout << endl;
	cout << "donc le mieux est: " << co.le_mieux() <<endl
	     << "le dommage moyen est: " << ho.valeur_moyen() <<endl<< endl;

	

	

	return 0;
}
