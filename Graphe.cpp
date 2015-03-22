#include "Graphe.h"
#include "Algo.h"

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
