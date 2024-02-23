#include "etat.h"
#include "analyseur.h"



void decalage(Analyseur& a, Etat* e, Symbole* s) {
	a.automate->pile_etats.push_back(e);
	a.automate->pile_symboles.push_back(s);
	a.lexer->Avancer();
}

void reduction(Analyseur& a, Symbole* createdNonTerminal, int nbReducedSymbol)
{
	for(int i=0; i < nbReducedSymbol; i++)
	{
		a.automate->pile_etats.pop_back();
		a.automate->pile_symboles.pop_back();
	}
	a.automate->pile_symboles.push_back(createdNonTerminal);
}


void transition_simple(Analyseur& a, Etat* e, Symbole* s) {
	a.automate->pile_etats.push_back(e);
	a.automate->pile_symboles.push_back(s);
}


bool I0::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;

	case E:
		transition_simple(a, new I1(), s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I1::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case PLUS:
		decalage(a, new I4(), s);
		break;

	case MULT:
		decalage(a, new I5(), s);
		break;
	
	case FIN:
		// idk ?
		break;

	default:
		return false;
		break;
	}

	return true;
}


bool I2::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;
	
	case E:
		transition_simple(a, new I6(), s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I3::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case PLUS:
		reduction(a, new Symbole(E), 1);
		break;

	case MULT:
		reduction(a, new Symbole(E), 1);
		break;
	
	case CLOSEPAR:
		reduction(a, new Symbole(E), 1);
		break;
	
	case FIN:
		reduction(a, new Symbole(E), 1);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I4::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;
	
	case E:
		transition_simple(a, new I7(), s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I5::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;
	
	case E:
		transition_simple(a, new I8(), s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I6::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case PLUS:
		decalage(a, new I4(), s);
		break;

	case MULT:
		decalage(a, new I5(), s);
		break;
	
	case CLOSEPAR:
		decalage(a, new I9(), s);
		break;

	default:
		return false;
		break;
	}

	return true;
}


bool I7::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case PLUS:
		reduction(a, new Symbole(E), 3);
		break;

	case MULT:
		decalage(a, new I5(), s);
		break;
	
	case CLOSEPAR:
		reduction(a, new Symbole(E), 2);
		break;

	case FIN:
		reduction(a, new Symbole(E), 3);
		break;

	default:
		return false;
		break;
	}

	return true;
}


bool I8::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case PLUS:
		reduction(a, new Symbole(E), 3);
		break;
	case MULT:
		reduction(a, new Symbole(E), 3);
		break;
	case CLOSEPAR:
		reduction(a, new Symbole(E), 3);
		break;
	case FIN:
		reduction(a, new Symbole(E), 3);
		break;
	default:
		return false;
		break;
	}

	return true;
}


bool I9::transition(Analyseur& a, Symbole* s) {
	switch (*s) {
	case PLUS:
		reduction(a, new Symbole(E), 3);
		break;
	case MULT:
		reduction(a, new Symbole(E), 3);
		break;
	case CLOSEPAR:
		reduction(a, new Symbole(E), 3);
		break;
	case FIN:
		reduction(a, new Symbole(E), 3);
		break;
	default:
		return false;
		break;
	}

	return true;
}


