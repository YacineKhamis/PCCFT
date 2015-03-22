#pragma once

//!
//! \file Arc.h
//!

#include "Sommet.h"

//!
//! \class Arc
//!
class Arc
{
public:
	//!
	//! \brief Sommet debut de l'arc
	//!
	Sommet debut;
	//!
	//! \brief Sommet fin de l'arc
	//!
	Sommet fin;

	//!
	//! \brief Valuation de l'arc
	//!
	int cout;
	//!
	//! \brief Ressource necessaire pour l'arc
	//!
	int ressource;

	//!
	//! \brief Constructeur par defaut
	//!
	Arc();	/*change par florian, voir cpp*/

	//!
	//! \brief Constructeur
	//! \param debut, fin, cout, ressource
	//!
	Arc(const Sommet &debut, const Sommet &fin, int cout, int ressource);

	//!
	//! \brief Destructeur
	//!
	virtual ~Arc()
	{}

	friend ostream & operator<<(ostream &os, Arc &a);
};

