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
	if (this->etiquettes.empty())
	{
		this->etiquettes.push_back(e);
		return true;
	}
	else
	{
		bool nouvelleEtiquetteDominee = false;
		for (vector<Etiquette>::iterator it = this->etiquettes.begin(); it != this->etiquettes.end();)
		{
			bool ancienneEtiquetteDominee = false;
			if ((it->cout >= e.cout && it->ressource > e.ressource))
			{
				ancienneEtiquetteDominee = true;

			}
			if (it->cout <= e.cout && it->ressource < e.ressource)
			{
				nouvelleEtiquetteDominee = true;
			}
			if (ancienneEtiquetteDominee)
			{
					it = this->etiquettes.erase(it);
			}
			else
			{
				it++;
			}
		}
		if (!nouvelleEtiquetteDominee)
		{
			this->etiquettes.push_back(e);
			return true;
		}
		return false;
	}
	
}