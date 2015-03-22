#pragma once

//!
//! \file Sommet.h
//!

#include <ostream>
#include <vector>
#include <string>
#include "Etiquette.h"
using namespace std;

//!
//! \class Sommet 
//! \brief muni d'une borne inf, d'une borne sup et d'une collection d'étiquette
//!
class Sommet
{
private:
	//!
	//! \brief Cle permettant d'identifier le sommet
	//!
	string cle;

public:
	//! \brief Borne sup et inf du sommet (contraintes)
	int borneInf;
	int borneSup;

	//! \brief Chaque sommet possède une collection d'étiquette
	vector<Etiquette> etiquettes;

	//!
	//! \brief Construteur par defaut
	//!
	Sommet();
	//!
	//! \brief Construteur par copie
	//!
	Sommet(const Sommet &s);
	//!
	//! \brief Construteur
	//!
	Sommet(int inf, int sup, string cle); /*change par florian*/

	//!
	//! \biref Destructeur
	//!
	virtual ~Sommet() /*change par florian*/
	{}

	//!
	//! \brief initialise les sommets
	//!
	void initialiserSommet();

	//!
	//! \return cle
	//!
	string getCle() const;		/*ici const change*/

	//!
	//! \param string
	//!
	void setCle(const string &);

	//!
	//! \param e, const Etiquette &
	//!
	void ajoutEtiquette(const Etiquette &e);
	
	//!
	//! \brief surcharge operateur == 
	//!
	bool operator==(const Sommet &s);
	
	//!
	//! \brief Ajout Pareto.
	//! \return true si l'élement a été ajouté, false sinon.
	//!
	bool ajoutPareto(const Etiquette &e);

	//!
	//! \brief surcharge operateur << 
	//!
	friend ostream & operator<<(ostream &os, Sommet &s);
};
