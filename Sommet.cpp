#include "Sommet.h"


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