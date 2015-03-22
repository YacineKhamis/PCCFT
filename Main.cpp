//!
//! \file Main.cpp
//!
#include <iostream>
#include "Sommet.h"
#include "Arc.h"
#include "Etiquette.h"
#include "Graphe.h"
#include "Algo.h"
using namespace std;


int main()
{
	Sommet * s0 = new Sommet(0, 0, 0);
	Sommet * i1 = new Sommet(0, 5, 1);
	Sommet * i2 = new Sommet(0, 7, 2);
	Sommet * i3 = new Sommet(0, 8, 3);
	Sommet * p0 = new Sommet(0, 10, 4);

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
	Etiquette * eTest1 = new Etiquette(0, 3, 5);
	Etiquette * eTest2 = new Etiquette(0, 2, 7);
	Etiquette * eTest3 = new Etiquette(0, 2, 3);
	s0->ajoutPareto(*eTest1);
	s0->ajoutPareto(*eTest2);
	s0->ajoutPareto(*eTest3);
	cout << "Graphe initial : " << endl;
	cout << *g0 << endl << endl;
	cout << "Calcul de la solution en cours... " << endl;
	Algo::fixationEtiquette(*g0);
	cout << "Affichage de la solution : " << endl;

	cout << *g0;

	//system("pause");
	return 0;
}