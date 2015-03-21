#include "Sommet.h"
using namespace std;


ostream & operator<<(ostream &os, Sommet &s)
{
	os << "-----Sommet-----" << endl;
	os << "Cle : " << s.cle << endl << "Borne inf : " << s.borneInf << "        Borne sup : " << s.borneSup << endl;
	for (auto etiq : s.etiquettes)
		os << etiq;
	return os;
}

Sommet::Sommet(const Sommet &s)
{
	cle = s.cle;
	borneInf = s.borneInf;
	borneSup = s.borneSup;
	etiquettes = s.etiquettes;
}

int Sommet::getCle()
{
	return this->cle;
}

void Sommet::ajoutEtiquette(const Etiquette &e)
{
	this->etiquettes.push_back(e);
}

void Sommet::initialiserSommet()
{
	this->etiquettes.clear();
}

bool Sommet::operator==(const Sommet &s)
{
	return (this->borneInf == s.borneInf && this->borneSup == s.borneSup && this->cle == s.cle);
}

//Ajout Pareto. Renvoie vrai si l'élement a été ajouté, faux sinon.
bool Sommet::ajoutPareto(const Etiquette &e)
{
	int i = 0;
	bool etiquetteDominee = false;
	for (auto etiquette : this->etiquettes)
	{
		i++;
		if ((etiquette.cout >= e.cout && etiquette.ressource > e.ressource))
		{
			this->etiquettes.erase(etiquettes.begin()+i);
		}
		if (etiquette.cout <= e.cout && etiquette.ressource < e.ressource)
		{
			etiquetteDominee = true;
		}
	}
	if (!etiquetteDominee)
	{
		etiquettes.push_back(e);
		return true;
	}
	return false;
}