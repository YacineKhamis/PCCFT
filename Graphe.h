#pragma once

//!
//! \file Graphe.h
//!

#include <list>
#include "Sommet.h"
#include "Arc.h"

//!
//! \class Graphe
//!
class Graphe
{
private:
	//!
	//! \brief Noeud source
	//!
	Sommet source;			/*change par florian, devient private, + creation getter*/
	//!
	//! \brief Noeud puits
	//!
	Sommet puits;

public:
	//!
	//! \brief Collection de noeuds
	//!
	vector<Sommet> sommets;
	//!
	//! \brief Collection d'arcs
	//!
	vector<Arc> arcs;


	//Solution propre au graphe
	list<Sommet> solution;


	//!
	//! \brief Constructeur
	//!
	Graphe()
	{}

	//!
	//! \brief Destructeur
	//!
	virtual ~Graphe()
	{}

	//!
	//! \param sommet
	//! \brief ajoute un sommet
	//!
	void addSommet(const Sommet &sommet); /*change nom par florian*/
	//!
	//! \param arc
	//! \brief ajoute un arc
	//!
	void addArc(const Arc &arc); /*change nom par florian*/

	//!
	//! \return Sommet&
	//!
	Sommet& getSource();
	//!
	//! \param s, const Sommet &
	//!
	void setSource(const Sommet &s);
	//!
	//! \return Sommet&
	//!
	Sommet& getPuits();
	//!
	//! \param s, cons Sommet &
	//!
	void setPuits(const Sommet &s);
	//!
	//! \param cle
	//!
	//string getPtrSommet(const string & cle) const;

	
	//!
	//! \param cle
	//! \return pointeur sur le sommet si existe, NULL sinon
	//!
	Sommet* getPtrSommet(string cle) const; /*change par florian, const*/
	
	//!
	//! \brief retourne arc entre deux sommets
	//!
	Arc getArcEntreDeux(string cleSommet1, string cleSommet2) const; /*change const*/
	vector<Sommet> successeurs(const Sommet &s);
	void initialiserEtiquettesSommets();

	friend ostream & operator<<(ostream &os, Graphe &g);
};
