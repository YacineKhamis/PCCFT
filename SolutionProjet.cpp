//!
//! \file SolutionProjet.cpp
//!
#include "SolutionProjet.h"


SolutionProjet::SolutionProjet()
{
	Sommet * s0 = new Sommet(0, 0, "0");
	Sommet * i1 = new Sommet(0, 5, "1");
	Sommet * i2 = new Sommet(0, 7, "2");
	Sommet * i3 = new Sommet(0, 8, "3");
	Sommet * p0 = new Sommet(0, 10, "4");

	Arc * arc01 = new Arc(*s0, *i1, 4, 3);
	Arc * arc02 = new Arc(*s0, *i2, 8, 2);
	Arc * arc03 = new Arc(*i1, *i2, 4, 3);
	Arc * arc04 = new Arc(*i1, *i3, 2, 6);
	Arc * arc05 = new Arc(*i2, *i3, 3, 4);
	Arc * arc06 = new Arc(*i2, *p0, 2, 6);
	Arc * arc07 = new Arc(*i3, *p0, 3, 4);

	Graphe * g0 = new Graphe();
	g0->addSommet(*s0);
	g0->addSommet(*i1);
	g0->addSommet(*i2);
	g0->addSommet(*i3);
	g0->addSommet(*p0);
	g0->addArc(*arc01);
	g0->addArc(*arc02);
	g0->addArc(*arc03);
	g0->addArc(*arc04);
	g0->addArc(*arc05);
	g0->addArc(*arc06);
	g0->addArc(*arc07);

	g0->setSource(*s0);
	g0->setPuits(*p0);
	SolutionGraphe graphe0(0,*g0);
	graphesProjet.push_back(graphe0);
}


SolutionProjet::~SolutionProjet()
{
}

void SolutionProjet::run()
{
	for (auto &solution : this->graphesProjet)
		solution.resoudreGraphe();
}

ostream & operator<<(ostream & os, SolutionProjet & sp)
{
	for (auto solution : sp.graphesProjet)
		os << solution << endl;
	return os;
}