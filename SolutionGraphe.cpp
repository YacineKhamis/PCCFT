//!
//! \file SolutionGraphe.cpp
//!
#include <time.h>
#include "SolutionGraphe.h"
#include "Algo.h"
#include "LectureGraphe.h"


SolutionGraphe::SolutionGraphe()
{}

SolutionGraphe::SolutionGraphe(string cle, const Graphe& g) : cleGraphe(cle), solution(g)
{}

SolutionGraphe::SolutionGraphe(const string & path)
{
	solution = LectureGraphe::chargerGraphe(path);
}

SolutionGraphe::~SolutionGraphe()
{}


string SolutionGraphe::getCleGraphe() const
{
	return cleGraphe;
}


void SolutionGraphe::resoudreGraphe()
{
	const clock_t begin_time = clock();
	Algo::fixationEtiquette(this->solution);
	this->setTempsCalculSolution( float(clock() - begin_time) / CLOCKS_PER_SEC );
}


void SolutionGraphe::setTempsCalculSolution(float f)
{
	this->tempsCalculSolution = f;
}


ostream & operator<<(ostream & os, SolutionGraphe & sg)
{
	os << "_____ Graphe no " << sg.cleGraphe << "_____" << endl;
	os << "Temps de calcul : " << sg.tempsCalculSolution << endl;
	os << "Chemin solution : ";
	for (auto sommet : sg.solution.solution)
		os << sommet.getCle() << " ";
	os << endl;
	return os;
}
