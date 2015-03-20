#include "Sommet.h"
#include "Arc.h"
#include "Etiquette.h"
#include "Graphe.h"
#include <iostream>
using namespace std;


int main()
{
	Sommet * s0 = new Sommet(0, 0, 5);
	Sommet * s1 = new Sommet(0, 0, 8);
	Arc * arc01 = new Arc(*s0, *s1, 4, 3);

	Graphe * g0 = new Graphe();
	g0->add(*s0);
	g0->add(*s1);
	g0->add(*arc01);
	cout << *g0;
	system("pause");
	return 0;
}