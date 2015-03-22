#pragma once
#include "SolutionGraphe.h"

class SolutionProjet
{
public:
	vector<SolutionGraphe> graphesProjet;
	SolutionProjet();
	void run();
	friend ostream & operator<<(ostream & os, SolutionProjet & sp);
	~SolutionProjet();
};

