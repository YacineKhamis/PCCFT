//!
//! \file Algo.cpp
//!
#include "Algo.h"


/*static*/ void Algo::fixationEtiquette(Graphe &g)
{
	g.initialiserEtiquettesSommets();
	vector<Sommet> ouverts;
	ouverts.push_back(g.getSource());
	Etiquette * e = new Etiquette(ouverts.back().getCle(), 0, 0);
	
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
				if (etiquette.ressource + g.getArcEntreDeux(sommetOuvert.getCle(), successeur.getCle()).ressource <= successeur.borneSup)
				{
					Etiquette * etiquetteCandidate = new Etiquette
						(
						sommetOuvert.getCle(),
						etiquette.cout + g.getArcEntreDeux(sommetOuvert.getCle(), successeur.getCle()).cout,
						etiquette.ressource + g.getArcEntreDeux(sommetOuvert.getCle(), successeur.getCle()).ressource
						);
					//On va modifier le sommet qui se trouve dans le graphe. On travaillait avec une copie pour recuperer les donnees.
					if (g.getPtrSommet(successeur.getCle())->ajoutPareto(*etiquetteCandidate))
					{
						Sommet debugSommetaOuvrir = *g.getPtrSommet(successeur.getCle());
						ouverts.push_back(*g.getPtrSommet(successeur.getCle() ));
					}
				}
			}
		}
	}

	//Etiquettes calculees
	string cleCourante = g.getPuits().getCle();
	while (cleCourante != g.getSource().getCle())
	{
		Sommet solution = *g.getPtrSommet(cleCourante);
		g.solution.push_front(solution);
		string prochaineCle = "";
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
	g.solution.push_front( *g.getPtrSommet(g.getSource().getCle() ) );
}


Algo::Algo()
{
}


Algo::~Algo()
{
}


