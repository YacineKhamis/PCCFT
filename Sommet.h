#pragma once
#include <ostream>
#include <vector>
#include "Etiquette.h"

using namespace std;

/*
*Objet Sommet muni d'une borne inf, d'une borne sup et d'une collection d'étiquette 
*/
class Sommet
{
public:
	//Borne sup et inf du sommet (contraintes)
	int borneInf;
	int borneSup;

	//Cle permettant d'identifier le sommet
	int cle;

	//Chaque sommet possède une collection d'étiquette
	vector<Etiquette> etiquettes;

	Sommet() : borneInf(0), borneSup(0), cle(0) {};
	Sommet(const Sommet &s);
	Sommet(int inf, int sup, int cle): borneInf(inf), borneSup(sup), cle(cle) {};

	friend ostream & operator<<(ostream &os, Sommet &s);

	void initialiserSommet();
	int getCle();
	void ajoutEtiquette(const Etiquette &e);
	bool operator==(const Sommet &s);
	bool ajoutPareto(const Etiquette &e);
	~Sommet() {};
};

