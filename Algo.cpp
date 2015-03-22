#include "Algo.h"


void Algo::fixationEtiquette(Graphe &g)
{
	g.initialiserEtiquettesSommets();
	vector<Sommet> ouverts;
	
	Etiquette * e = new Etiquette(g.source.cle,0,0);
	g.source.ajoutEtiquette(*e);
	ouverts.push_back(g.source);
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
	int cleCourante = g.puits.cle;
	while (cleCourante != g.source.cle)
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
	g.solution.push_front(g.sommets[g.getPtrSommet(g.source.cle)]);
}

Algo::Algo()
{
}


Algo::~Algo()
{
}

/*
string content((istreambuf_iterator<char>(Fichier)),
	(istreambuf_iterator<char>()));
string d = content;
G = new Graphe<InfoAreteCarte, InfoSommetCarte>();
const char * texte = d.c_str();
texte = strchr(texte, '\n') + 1;			//On se deplace apres le commentaire
texte = strchr(texte, '\n') + 1;			//On se deplace sur le saut de ligne qui suit

texte = strchr(texte, ' ') + 1; // On se deplace apres  ressource
const char * p = strchr(texte, '\n');  // On se deplace apres le nombre de ressource

char num[LONGUEUR_ENTIER];
int ressource;

int lnum = p - texte;
strncpy_s(num, texte, lnum);		// recopie du texte du numérateur


num[lnum] = '\0';		// on n'oublie pas de mettre le caractère fin de chaîne !!!
int ok = sscanf_s(num, "%d", &ressource);  // On prend la ressource

texte = strchr(texte, '\n') + 1;			//On se deplace apres le commentaire
texte = strchr(texte, '\n') + 1;			//Devant le sectionSommets
texte = strchr(texte, '\n') + 1;			//premiere ligne de sommet potentiels

std::map<string, Sommet<InfoSommetCarte>*> Sommets = std::map<string, Sommet<InfoSommetCarte>*>();

while (*texte != '\n'){
	int x, y;

	p = strchr(texte, ' ');
	int lnum = p - texte;
	strncpy_s(num, texte, lnum);
	std::string s(num);  // On a recuperer le nom

	texte = p + 1;
	while (*texte == ' ')
		texte = texte + 1;
	p = strchr(texte, ' ');
	lnum = p - texte;
	strncpy_s(num, texte, lnum);		// recopie du texte du numérateur
	ok = sscanf_s(num, "%d", &x);  // On prend la ressource

	texte = p + 1;
	while (*texte == ' ')
		texte = texte + 1;
	p = strchr(texte, '\n');
	lnum = p - texte;
	strncpy_s(num, texte, lnum);		// recopie du texte du numérateur
	ok = sscanf_s(num, "%d", &y);  // On prend la ressource

	texte = p + 1;

	Sommet<InfoSommetCarte> * S = G->creeSommet(InfoSommetCarte(s, Vecteur2D(x, y)));
	Sommets[S->v.nom] = S;
}
/////////////////////////////////////////////
texte = strchr(texte, '\n') + 1;
texte = strchr(texte, '\n') + 1;
p = strchr(texte, '\n');
lnum = p - texte;
strncpy_s(num, texte, lnum);
std::string Source(num);  // On a recuperer le nom de la source
source = Sommets[Source];

texte = strchr(texte, '\n') + 1;
texte = strchr(texte, '\n') + 1;
texte = strchr(texte, '\n') + 1;
p = strchr(texte, ' ');
lnum = p - texte;
strncpy_s(num, texte, lnum);
std::string Puits(num);  // On a recuperer le nom des puits
puits = Sommets[Puits];

texte = strchr(texte, '\n') + 1;
texte = strchr(texte, '\n') + 1;
texte = strchr(texte, '\n') + 1;
// On commence à traiter les arcs
while (*texte != '\n'){
	int x, y;

	p = strchr(texte, ' ');
	int lnum = p - texte;
	strncpy_s(num, texte, lnum);
	std::string s(num);  // On a recuperer le nom

	texte = p + 1;
	while (*texte == ' ')
		texte = texte + 1;
	p = strchr(texte, ' ');
	lnum = p - texte;
	strncpy_s(num, texte, lnum);
	std::string origine(num);  // On a recuperer le premier

	texte = p + 1;
	while (*texte == ' ')
		texte = texte + 1;
	p = strchr(texte, ' ');
	lnum = p - texte;
	strncpy_s(num, texte, lnum);
	std::string destination(num);  // On a recuperer le deuxieme

	texte = p + 1;
	while (*texte == ' ')
		texte = texte + 1;
	p = strchr(texte, ' ');
	lnum = p - texte;
	strncpy_s(num, texte, lnum);		// recopie du texte du numérateur
	ok = sscanf_s(num, "%d", &x);  // On prend la ressource

	texte = p + 1;
	p = strchr(texte, '\n');
	lnum = p - texte;
	strncpy_s(num, texte, lnum);		// recopie du texte du numérateur
	ok = sscanf_s(num, "%d", &y);  // On prend la ressource
	texte = p + 1;

	G->creeArete(Sommets[origine], Sommets[destination], InfoAreteCarte(x, y));

}
*/