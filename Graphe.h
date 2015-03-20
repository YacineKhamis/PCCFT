#pragma once
#include "Sommet.h"
#include "Arc.h"

class Graphe
{
public:
	//Collection de noeuds
	vector<Sommet> sommets;

	//Collection d'arcs
	vector<Arc> arcs;

	Graphe(){};

	void add(const Sommet &sommet);
	void add(const Arc &arc);
	friend ostream & operator<<(ostream &os, Graphe &g);
	~Graphe();
};

