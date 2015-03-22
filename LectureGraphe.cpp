//!
//! \file LectureGraphe.cpp
//!
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "LectureGraphe.h"
using namespace std;

LectureGraphe::LectureGraphe()
{
}


LectureGraphe::~LectureGraphe()
{
}

vector<string> explode(const string & str, char delimiteur)
{
	istringstream split(str);
	vector<string> tokens;
	for (string each; getline(split, each, delimiteur); tokens.push_back(each));
	
	return tokens;
}

void replaceAll(string & str, const string & from, const string & to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}


/*static*/ Graphe LectureGraphe::chargerGraphe(const string & nomFichier)
{
	bool sommets = false, source = false, puit = false;
	Graphe gr;
	ifstream fichier("Graphes/" + nomFichier, ios::in); // lecture
	
	if (fichier)
	{
		string ligne;

		while (getline(fichier, ligne))
		{
			if (sommets && (ligne.substr(0, 1) == "i" || ligne.substr(0, 1) == "p" || ligne.substr(0, 2) == "s0"))
			{
				replaceAll(ligne, "  ", " ");
				vector<string> frag = explode(ligne, ' ');
				gr.addSommet(Sommet(stoi(frag[1]), stoi(frag[2]), frag[0]));
			}
			else if (source && (ligne.substr(0, 1) == "i" || ligne.substr(0, 1) == "s"))
			{
				gr.setSource(*gr.getPtrSommet(ligne));
			}
			else if (puit && (ligne.substr(0, 1) == "i" || ligne.substr(0, 1) == "p"))
			{
				replaceAll(ligne, "  ", " ");
				vector<string> frag = explode(ligne, ' ');
				gr.setPuits(*gr.getPtrSommet(frag[0]));
			}
			else if (ligne.substr(0, 3) == "arc")
			{
				replaceAll(ligne, "  ", " ");
				vector<string> frag = explode(ligne, ' ');
				gr.addArc(Arc(*gr.getPtrSommet(frag[1]), *gr.getPtrSommet(frag[2]), stoi(frag[3]), stoi(frag[4])));
			}

			//-------------- dans quel section sommes nous ? ------------------
			if (ligne == "sectionSommets")
				sommets = true;
			else if (ligne == "sources")
			{
				sommets = false;
				source = true;
			}
			else if (ligne == "puits")
			{
				source = false;
				puit = true;
			}
			else if (ligne == "sectionArcs")
				puit = false;
		}

		fichier.close();
		return gr;
	}
	else
	{
		//cerr << "Impossible d'ouvrir le fichier !" << endl;
		return gr;
	}
}
