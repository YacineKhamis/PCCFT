#pragma once

//!
//! \file LectureGraphe.h
//!

#include <string>
#include "Graphe.h"

//!
//! \class LectureGraphe
//!
class LectureGraphe
{
public:
	LectureGraphe();
	virtual ~LectureGraphe();

	static Graphe chargerGraphe(const string & nomFichier);
};
