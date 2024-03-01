#ifndef __ANALYSEUR__
#define __ANALYSEUR__

#include "automate.h"
#include "lexer.h"




class Analyseur
{
public:
	Analyseur();

	~Analyseur();

	bool analyser(string s);

	Automate *automate;
	Lexer *lexer;
	bool accepted;
};

#endif

