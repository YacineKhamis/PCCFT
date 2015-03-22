//!
//! \file Main.cpp
//!
#include <iostream>
#include "Sommet.h"
#include "Arc.h"
#include "Etiquette.h"
#include "Graphe.h"
#include "Algo.h"
#include "LectureGraphe.h"
#include "SolutionProjet.h"
using namespace std;


int main()
{
	/*
	//Mise en place du DP factory. On cr�e tous les graphes 
	//dans le constructeur par d�faut de SolutionProjet 
	SolutionProjet s;

	//On calcule toutes les solutions
	s.run();

	//Affichage des r�sultats
	cout << s;

	g0->setSource(*s0);
	g0->setPuits(*p0);

	Algo::fixationEtiquette(*g0);
	cout << *g0;
	*/

	Graphe g = LectureGraphe::chargerGraphe("graphe-10.gpr");
	cout << g << endl;

	//system("pause");
	return 0;
}