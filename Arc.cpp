#include "Arc.h"

ostream & operator<<(ostream &os, Arc &a)
{
	os << "---Arc---" << endl;
	os << "Debut : " << a.debut.getCle() << "  ----->  Fin : " << a.fin.getCle() << endl;
	os << "Cout : " << a.cout << "       Ressource : " << a.ressource << endl;
	return os;
}