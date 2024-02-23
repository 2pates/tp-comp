#include "etat.h"
#include "analyseur.h"



void decalage(Analyseur& a, Etat* e, Symbole* s) {
	a.automate.pile_etats.push_back(e);
	a.automate.pile_symboles.push_back(s);
	a.lexer.Avancer();
}

void reduction(Analyseur& a, Etat* e, Symbole* s, int nbReducedSymbol)
{
	
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


bool I1::transition(Analyseur& automate, Symbole* s) {
	switch ((int)s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I3(), s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I0::transition(Analyseur& automate, Symbole* s) {
	switch ((int)s) {
	case INT:
		decalage(a, new I3(), s);
		break;

	case OPENPAR:
		decalage(a, new I3(), s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I0::transition(Analyseur& automate, Symbole* s) {
	switch ((int)s) {
	case INT:
		automate.pile_etats.push_back(new I3());
		automate.pile_symboles.push_back(s);
		break;

	case OPENPAR:
		automate.pile_etats.push_back(new I2());
		automate.pile_symboles.push_back(s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I0::transition(Analyseur& automate, Symbole* s) {
	switch ((int)s) {
	case INT:
		automate.pile_etats.push_back(new I3());
		automate.pile_symboles.push_back(s);
		break;

	case OPENPAR:
		automate.pile_etats.push_back(new I2());
		automate.pile_symboles.push_back(s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}


bool I0::transition(Analyseur& automate, Symbole* s) {
	switch ((int)s) {
	case INT:
		automate.pile_etats.push_back(new I3());
		automate.pile_symboles.push_back(s);
		break;

	case OPENPAR:
		automate.pile_etats.push_back(new I2());
		automate.pile_symboles.push_back(s);
		break;
	
	default:
		return false;
		break;
	}

	return true;
}



