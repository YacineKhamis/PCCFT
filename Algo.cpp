//!
//! \file Algo.cpp
//!
#include "Algo.h"


/*static*/ void Algo::fixationEtiquette(Graphe &g)
{
	g.initialiserEtiquettesSommets();
	vector<Sommet> ouverts;
	
	Etiquette * e = new Etiquette(g.getSource().cle,0,0);
	g.getSource().ajoutEtiquette(*e);
	ouverts.push_back(g.getSource());
	while (!ouverts.empty())
	{
		Sommet sommetOuvert = ouverts.back();
		ouverts.pop_back();
		for (auto successeur : g.successeurs(sommetOuvert))
		{
			for (auto etiquette : sommetOuvert.etiquettes)
			{
				if (etiquette.ressource + g.getArcEntreDeux(sommetOuvert.cle, successeur.cle).ressource <= successeur.borneSup)
				{
					Etiquette * etiquetteCandidate = new Etiquette
						(
						sommetOuvert.cle,
						etiquette.cout + g.getArcEntreDeux(sommetOuvert.cle, successeur.cle).cout,
						etiquette.ressource + g.getArcEntreDeux(sommetOuvert.cle, successeur.cle).ressource
						);
					//On va modifier le sommet qui se trouve dans le graphe. On travaillait avec une copie pour recuperer les donnees.
					if (g.sommets[g.getPtrSommet(successeur.cle)].ajoutPareto(*etiquetteCandidate))
					{
						Sommet debugSommetaOuvrir = g.sommets[g.getPtrSommet(successeur.cle)];
						ouverts.push_back(g.sommets[g.getPtrSommet(successeur.cle)]);
					}
				}
			}
		}
	}

	//Etiquettes calculees
	int cleCourante = g.getPuits().cle;
	while (cleCourante != g.getSource().cle)
	{
		Sommet solution = g.sommets[g.getPtrSommet(cleCourante)];
		g.solution.push_front(solution);
		int prochaineCle = 0;
		int coutMinimum = INT_MAX;
		for (auto etiquette : solution.etiquettes)
		{
			if (etiquette.cout < coutMinimum)
			{
				coutMinimum = etiquette.cout;
				prochaineCle = etiquette.cleSommet;
			}
		}
		cleCourante = prochaineCle;
	}
	g.solution.push_front(g.sommets[g.getPtrSommet(g.getSource().cle)]);
}


Algo::Algo()
{
}


Algo::~Algo()
{
}


