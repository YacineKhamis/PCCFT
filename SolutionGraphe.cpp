#include "SolutionGraphe.h"
#include <time.h>
#include "Algo.h"

SolutionGraphe::SolutionGraphe()
{
}



SolutionGraphe::~SolutionGraphe()
{
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
