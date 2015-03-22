#pragma once
#include "Graphe.h"
class SolutionGraphe
{
private:
	Graphe solution;
	float tempsCalculSolution;
public:
	int cleGraphe;
	SolutionGraphe();
	void setTempsCalculSolution(float f);
	SolutionGraphe(int cle, const Graphe& g) : cleGraphe(cle), solution(g){};
	friend ostream & operator<<(ostream & os, SolutionGraphe & sg);
	//On souhaite pouvoir construire un graphe a partir d'un fichier
	SolutionGraphe(string path);
	//On veut pouvoir automatiser le calcul du temps d'execution de l'algorithme pour le graphe
	void resoudreGraphe();
	~SolutionGraphe();
};

