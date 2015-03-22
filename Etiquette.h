#pragma once

//!
//! \file Etiquette.h
//!

#include <ostream>
#include <string>
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
	string cleSommet;
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
	Etiquette(string cle, int cout, int ressource);
	
	//!
	//! \brief Destructeur
	//!
	virtual ~Etiquette()
	{}

	//!
	//! \brief surcharge operateur <<
	//!
	friend ostream & operator<<(ostream &os, Etiquette &s);
	bool operator==(const Etiquette &e);

};
