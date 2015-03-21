#pragma once

//!
//! \file Graphe.h
//!

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
	//! \return Sommet*
	//!
	Sommet getSource() const;
	//!
	//! \param s, const Sommet &
	//!
	void setSource(const Sommet &s);
	//!
	//! \return Sommet*
	//!
	Sommet getPuits() const;
	//!
	//! \param s, cons Sommet &
	//!
	void setPuits(const Sommet &s);
	
	//!
	//! \param cle
	//! \return pointeur sur le sommet si existe, NULL sinon
	//!
	Sommet* getPtrSommet(int cle) const; /*change par florian, const*/
	
	//!
	//! \brief retourne arc entre deux sommets
	//!
	Arc getArcEntreDeux(int cleSommet1, int cleSommet2) const; /*change const*/
	vector<Sommet> successeurs(const Sommet &s);
	void initialiserEtiquettesSommets();

	friend ostream & operator<<(ostream &os, Graphe &g);
};
