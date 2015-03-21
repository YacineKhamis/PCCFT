#include "Graphe.h"

void Graphe::add(const Sommet &sommet)
{
	this->sommets.push_back(sommet);
}
void Graphe::add(const Arc &arc)
{
	this->arcs.push_back(arc);
}

ostream & operator<<(ostream &os, Graphe &g)
{
	os << "------------Graphe---------------" << endl;
	for (auto sommet : g.sommets)
		os << sommet;
	for (auto arc : g.arcs)
		os << arc;
	return os;
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

Sommet* Graphe::getPtrSommet(int cle)
{
	for (auto sommet : this->sommets)
	{
		if (sommet.cle == cle)
			return &sommet;
	}
}

void Graphe::setSource(const Sommet &s)
{
	this->source = s;
}

void Graphe::setPuits(const Sommet &s)
{
	this->puits = s;
}

Arc Graphe::getArcEntreDeux(int cleSommet1, int cleSommet2)
{
	Arc solution;
	for (auto arc : this->arcs)
	{
		if (arc.debut.cle == cleSommet1 && arc.fin.cle == cleSommet2)
			solution = arc;
	}
	return solution;
}

Graphe::~Graphe()
{
}
