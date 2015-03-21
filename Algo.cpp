#include "Algo.h"


void Algo::fixationEtiquette(Graphe &g)
{
	g.initialiserEtiquettesSommets();
	vector<Sommet> ouverts;
	ouverts.push_back(g.source);
	Etiquette * e = new Etiquette(ouverts.back().cle,0,0);
	g.source.ajoutEtiquette(*e);
	while (!ouverts.empty())
	{
		Sommet sommetOuvert = ouverts.front();
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
					g.getPtrSommet(successeur.cle)->ajoutEtiquette(*etiquetteCandidate);
					if (g.getPtrSommet(successeur.cle)->ajoutPareto(*etiquetteCandidate))
						ouverts.push_back(*g.getPtrSommet(successeur.cle));
				}
			}
		}
	}
}

Algo::Algo()
{
}


Algo::~Algo()
{
}
