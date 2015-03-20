#pragma once
#include <ostream>
class Sommet;
using namespace std;

class Etiquette
{
public:
	//Sommet de provenance
	int cleSommet;
	int cout;
	int ressource;
	Etiquette() : cleSommet(0), cout(0), ressource(0) {};
	Etiquette(int cle, int cout, int ressource) : cleSommet(cle), cout(cout), ressource(ressource){};
	friend ostream & operator<<(ostream &os, Etiquette &s);
	~Etiquette() {};
};

