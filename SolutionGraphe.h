#pragma once
//!
//! \file SolutionGraphe.h
//!

#include <string>
#include "Graphe.h"
using namespace std;

//!
//! \class SolutionGraphe
//!
class SolutionGraphe
{
private:
	Graphe solution;
	float tempsCalculSolution;
	string cleGraphe;

public:
	//!
	//! \brief Constructeur par defaut
	//!
	SolutionGraphe();
	
	//!
	//! On souhaite pouvoir construire un graphe a partir d'un fichier
	//!
	SolutionGraphe(const string & path);
	
	//!
	//! \brief Constructeur
	//!
	SolutionGraphe(string cle, const Graphe & g);

	//!
	//! \brief Destructeur
	//!
	virtual ~SolutionGraphe();

	//!
	//! \return cleGraphe
	//!
	string getCleGraphe() const;

	void setTempsCalculSolution(float f);
	
	//!
	//! On veut pouvoir automatiser le calcul du temps d'execution de l'algorithme pour le graphe
	//!
	void resoudreGraphe();

	//!
	//! \brief surcharge operateur <<
	//!
	friend ostream & operator<<(ostream & os, SolutionGraphe & sg);
};
