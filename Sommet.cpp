//!
//! \file Sommet.cpp
//!
#include "Sommet.h"


Sommet::Sommet() : borneInf(0), borneSup(0), cle(0)
{} /*change par florian*/

Sommet::Sommet(const Sommet &s) : borneInf(s.borneInf), borneSup(s.borneSup), cle(s.cle), etiquettes(s.etiquettes)
{} /*change par florian*/

Sommet::Sommet(int inf, int sup, int cle) : borneInf(inf), borneSup(sup), cle(cle)
{} /*change par florian*/

ostream & operator<<(ostream &os, Sommet &s)
{
	os << "-----Sommet-----" << endl;
	os << "Cle : " << s.cle << endl << "Borne inf : " << s.borneInf << "        Borne sup : " << s.borneSup << endl;
	for (auto etiq : s.etiquettes)
		os << etiq;
	return os;
}


int Sommet::getCle() const
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
