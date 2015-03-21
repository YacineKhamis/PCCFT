#pragma once

//!
//! \file Etiquette.h
//!

#include <ostream>
using namespace std;

class Sommet;

//!
//! \class Etiquette
//!
class Etiquette
{
public:
	//!
	//! \brief Sommet de provenance
	//!
	int cleSommet;
	int cout;
	int ressource;

	//!
	//! \brief Constructeur par defaut
	//!
	Etiquette();

	//!
	//! \brief Constructeur
	//! \param cle, cout, ressource
	//!
	Etiquette(int cle, int cout, int ressource);
	
	//!
	//! \brief Destructeur
	//!
	virtual ~Etiquette()
	{}

	//!
	//! \brief surcharge operateur <<
	//!
	friend ostream & operator<<(ostream &os, Etiquette &s);
};
