#include "etat.h"
#include "analyseur.h"



void decalage(Analyseur& a, Etat* e, Symbole* s) {
	a.automate.pile_etats.push_back(e);
	a.automate.pile_symboles.push_back(s);
	a.lexer.Avancer();
}

void reduction(Analyseur& a, Symbole* s, int nbReducedSymbol)
{
	for(int i=0; i < nbReducedSymbol; i++)
	{
		a.automate.pile_etats.pop_back();
		a.automate.pile_symboles.pop_back();
	}
	a.automate.pile_symboles.push_back(s);
}


void transition_simple(Analyseur& a, Etat* e, Symbole* s) {
	a.automate.pile_etats.push_back(e);
	a.automate.pile_symboles.push_back(s);
}


bool I0::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;

	case E:
		transition_simple(a, new I1(), s);
	
	default:
		return false;
		break;
	}

	return true;
}


bool I1::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
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
	switch ((int)s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;
	
	case E:
		transition_simple(a, new I6(), s);
	
	default:
		return false;
		break;
	}

	return true;
}


bool I3::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
	case PLUS:
		reduction(a, s, 5);
		break;

	case MULT:
		reduction(a, s, 5);
		break;
	
	case CLOSEPAR:
		reduction(a, s, 5);
		break;
	
	case FIN:
		reduction(a, s, 5);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I4::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;
	
	case E:
		transition_simple(a, new I7(), s);
	
	default:
		return false;
		break;
	}

	return true;
}


bool I5::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I2(), s);
		break;
	
	case E:
		transition_simple(a, new I8(), s);
	
	default:
		return false;
		break;
	}

	return true;
}


bool I6::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
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
	switch ((int)s) {
	case PLUS:
		reduction(a, s, 2);
		break;

	case MULT:
		decalage(a, new I5(), s);
		break;
	
	case CLOSEPAR:
		reduction(a, s, 2);
		break;

	case FIN:
		reduction(a, s, 2);
		break;

	default:
		return false;
		break;
	}

	return true;
}


bool I8::transition(Analyseur& a, Symbole* s) {
	switch ((int)s) {
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
	switch ((int)s) {
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


