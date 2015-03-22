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

int Graphe::getPtrSommet(int cle)
{
	for (vector<Sommet>::iterator it = this->sommets.begin(); it != this->sommets.end(); it++)
	{
		if (it->cle == cle)
			return it->cle;
	}
		return -1;
}

//!
//! \return pointeur sur le sommet si existe, NULL sinon
//!
/*
Sommet* Graphe::getPtrSommet(int cle) const
{
	for (vector<Sommet>::iterator it = this->sommets.begin(); it != this->sommets.end(); it++)
	{
		if (it->cle == cle)
			//Petit doute quand meme
			return &*it;
	}
	return NULL;
}
*/

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

Arc Graphe::getArcEntreDeux(int cleSommet1, int cleSommet2) const
{
	Arc solution;
	for (auto arc : this->arcs)
	{
		if (arc.debut.cle == cleSommet1 && arc.fin.cle == cleSommet2)
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
			os << sommet.cle << " ";
		os << endl;
	}
	else
		os << "Solution non calculee" << endl;
	return os;
}
