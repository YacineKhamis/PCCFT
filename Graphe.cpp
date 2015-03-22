//!
//! \file Graphe.cpp
//!
#include "Graphe.h"
#include "Algo.h"


void Graphe::addSommet(const Sommet &sommet)
{
	this->sommets.push_back(sommet);
}

void Graphe::addArc(const Arc &arc)
{
	this->arcs.push_back(arc);
}

void Graphe::initialiserEtiquettesSommets()
{
	for (auto sommet : this->sommets)
		sommet.initialiserSommet();
}

vector<Sommet> Graphe::successeurs(const Sommet &s)
{
	vector<Sommet> solution;
	for (auto arc : this->arcs)
	{
		if (arc.debut == s)
			solution.push_back(arc.fin);
	}
	return solution;
}

/*
string Graphe::getPtrSommet(const string & cle) const
{
	for (vector<Sommet>::iterator it = sommets.begin(); it != this->sommets.end(); ++it)
	{
		if (it->getCle() == cle)
			return it->getCle();
	}
	
	return "";
}*/

//!
//! \return sommet si existe, NULL sinon
//!
Sommet* Graphe::getPtrSommet(string cle) const
{
	Sommet* pt = NULL;
	for (auto sommet : this->sommets)
	{
		if (sommet.getCle() == cle)
			pt = new Sommet(sommet);
	}

	return pt;
}

Sommet& Graphe::getSource()
{
	return source;
}

void Graphe::setSource(const Sommet &s)
{
	this->source = s;
}

Sommet& Graphe::getPuits()
{
	return puits;
}

void Graphe::setPuits(const Sommet &s)
{
	this->puits = s;
}

Arc Graphe::getArcEntreDeux(string cleSommet1, string cleSommet2) const
{
	Arc solution;
	for (auto arc : this->arcs)
	{
		if (arc.debut.getCle() == cleSommet1 && arc.fin.getCle() == cleSommet2)
			solution = arc;
	}
	return solution;
}


ostream & operator<<(ostream &os, Graphe &g)
{
	os << "------------Graphe---------------" << endl;
	for (auto sommet : g.sommets)
		os << sommet;
	for (auto arc : g.arcs)
		os << arc;
	os << "---Chemin solution---" << endl;
	if (!g.solution.empty())
	{
		for (auto sommet : g.solution)
			os << sommet.getCle() << " ";
		os << endl;
	}
	else
		os << "Solution non calculee" << endl;
	return os;
}
