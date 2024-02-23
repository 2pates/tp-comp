#ifndef __ANALYSEUR__
#define __ANALYSEUR__

#include "automate.h"
#include "lexer.h"


class Analyseur {
	public:
	Analyseur();

	Automate & automate;
	Lexer& lexer;
};



#endif

