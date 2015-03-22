//!
//! \file Etiquette.cpp
//!
#include "Etiquette.h"


Etiquette::Etiquette() : cleSommet(0), cout(0), ressource(0)
{}

Etiquette::Etiquette(int cle, int cout, int ressource) : cleSommet(cle), cout(cout), ressource(ressource)
{}

ostream & operator<<(ostream &os, Etiquette &s)
{
	return os << "---------------Etiquette--------------"<<endl
		<<"Sommet source : "<< s.cleSommet << "      Cout : "<< s.cout <<"    Ressource : " << s.ressource <<endl;
}

bool Etiquette::operator==(const Etiquette &e)
{
	return (this->cleSommet == e.cleSommet && this->cout == e.cout && this->ressource == e.ressource);
}
