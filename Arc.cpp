//!
//! \file Arc.cpp
//!
#include "Arc.h"


Arc::Arc() : debut(), fin(), cout(0), ressource(0)
{}

Arc::Arc(const Sommet &debut, const Sommet &fin, int cout, int ressource) : debut(debut), fin(fin), cout(cout), ressource(ressource)
{}

ostream & operator<<(ostream &os, Arc &a)
{
	os << "---Arc---" << endl;
	os << "Debut : " << a.debut.getCle() << "  ----->  Fin : " << a.fin.getCle() << endl;
	os << "Cout : " << a.cout << "       Ressource : " << a.ressource << endl;
	return os;
}
