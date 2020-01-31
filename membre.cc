#include "membre.hh"

using namespace std;

Membre::Membre(string name,int ages):_nom(name),_age(ages){}

string Membre::nom(){return _nom;}

int Membre::age(){return _age;}