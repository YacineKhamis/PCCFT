//!
//! \file Main.cpp
//!
#include <iostream>
#include "Sommet.h"
#include "Arc.h"
#include "Etiquette.h"
#include "Graphe.h"
#include "Algo.h"
#include "SolutionProjet.h"
using namespace std;


int main()
{
	//Mise en place du DP factory. On crée tous les graphes 
	//dans le constructeur par défaut de SolutionProjet 
	SolutionProjet s;

	//On calcule toutes les solutions
	s.run();

	//Affichage des résultats
	cout << s;

	system("pause");
	return 0;
}