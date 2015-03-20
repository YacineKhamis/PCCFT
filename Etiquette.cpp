#include "Etiquette.h"

ostream & operator<<(ostream &os, Etiquette &s)
{
	return os << "---------------Etiquette--------------"<<endl
		<<"Sommet source : "<< s.cleSommet << "      Cout : "<< s.cout <<"    Ressource : " << s.ressource <<endl;
}
