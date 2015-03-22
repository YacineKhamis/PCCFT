#pragma once
#include "Sommet.h"
#include "Arc.h"
#include <list>

class Graphe
{
public:
	//Collection de noeuds
	vector<Sommet> sommets;

	//Collection d'arcs
	vector<Arc> arcs;

	//Solution propre au graphe
	list<Sommet> solution;

	//Noeud source
	Sommet source;
	//Noeud puits
	Sommet puits;

	Graphe(){};

	void add(const Sommet &sommet);
	void add(const Arc &arc);
	void setSource(const Sommet &s);
	void setPuits(const Sommet &s);
	int getPtrSommet(int cle);
	Arc getArcEntreDeux(int cleSommet1,int cleSommet2);
	vector<Sommet> successeurs(const Sommet &s);
	void initialiserEtiquettesSommets();
	friend ostream & operator<<(ostream &os, Graphe &g);
	~Graphe();
};

