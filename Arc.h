#pragma once
#include "Sommet.h"
class Arc
{
public:
	//Sommets debut et fin de l'arc
	Sommet debut;
	Sommet fin;

	//Valuation de l'arc
	int cout;
	int ressource;

	Arc() : debut(), fin(), cout(0), ressource(0) {};
	Arc(const Sommet &debut, const Sommet &fin, int cout, int ressource) : debut(debut), fin(fin), cout(cout), ressource(ressource) {};
	friend ostream & operator<<(ostream &os, Arc &a);
	~Arc() {};
};

