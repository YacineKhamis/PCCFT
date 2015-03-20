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

Graphe::~Graphe()
{
}
