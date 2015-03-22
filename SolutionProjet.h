#pragma once

//!
//! \file SolutionProjet.h
//!

#include "SolutionGraphe.h"

//!
//! \class SolutionProjet
//!
class SolutionProjet
{
public:
	vector<SolutionGraphe> graphesProjet;
	
	//!
	//! \brief Constructeur
	//!
	SolutionProjet();
	//!
	//! \brief Destructeur
	//!
	virtual ~SolutionProjet();

	void run();

	friend ostream & operator<<(ostream & os, SolutionProjet & sp);
};
