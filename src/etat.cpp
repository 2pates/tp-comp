#include "etat.h"
#include "analyseur.h"

void decalage(Analyseur &a, Etat *e, Symbole *s)
{
	a.automate->pile_etats.push_back(e);
	a.automate->pile_symboles.push_back(s);
	a.lexer->Avancer();
}

void reduction(Analyseur &a, int ruleNumber)
{
	Symbole *createdExpr;
	switch (ruleNumber)
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		Symbole *right = a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		a.automate->pile_etats.pop_back();

		a.automate->pile_symboles.pop_back(); // pop plus
		a.automate->pile_etats.pop_back();

		Symbole *left = a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		a.automate->pile_etats.pop_back();

		createdExpr = new ExprPlus(left, right);
		break;
	}
	case 3:
	{
		Symbole *right = a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		a.automate->pile_etats.pop_back();

		a.automate->pile_symboles.pop_back(); // pop mult
		a.automate->pile_etats.pop_back();

		Symbole *left = a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		a.automate->pile_etats.pop_back();

		createdExpr = new ExprMult(left, right);
		break;
	}
	case 4:
	{
		a.automate->pile_symboles.pop_back(); // pop right parenthesis
		a.automate->pile_etats.pop_back();

		Symbole *expr = a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		a.automate->pile_etats.pop_back();

		a.automate->pile_symboles.pop_back(); // pop left parenthesis
		a.automate->pile_etats.pop_back();

		createdExpr = new ExprCst(expr);

		break;
	}
	case 5:
	{
		Symbole *val = a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		a.automate->pile_etats.pop_back();

		createdExpr = new ExprCst(val);
		break;
	}
	default:
	{
		break;
	}
	}
	a.automate->pile_symboles.push_back(createdExpr);
	a.automate->pile_etats.back()->transition(a, createdExpr);
}

void transition_simple(Analyseur &a, Etat *e, Symbole *s)
{
	a.automate->pile_etats.push_back(e);
	a.automate->pile_symboles.push_back(s);
}

bool I0::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
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

bool I1::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
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

bool I2::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
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

bool I3::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
	case PLUS:
		reduction(a, 5);
		break;

	case MULT:
		reduction(a, 5);
		break;

	case CLOSEPAR:
		reduction(a, 5);
		break;

	case FIN:
		reduction(a, 5);
		break;

	default:
		return false;
		break;
	}

	return true;
}

bool I4::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
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

bool I5::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
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

bool I6::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
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

bool I7::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
	case PLUS:
		reduction(a, 2);
		break;

	case MULT:
		decalage(a, new I5(), s);
		break;

	case CLOSEPAR:
		reduction(a, 2);
		break;

	case FIN:
		reduction(a, 2);
		break;

	default:
		return false;
		break;
	}

	return true;
}

bool I8::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
	case PLUS:
		reduction(a, 3);
		break;
	case MULT:
		reduction(a, 3);
		break;
	case CLOSEPAR:
		reduction(a, 3);
		break;
	case FIN:
		reduction(a, 3);
		break;
	default:
		return false;
		break;
	}

	return true;
}

bool I9::transition(Analyseur &a, Symbole *s)
{
	switch (*s)
	{
	case PLUS:
		reduction(a, 4);
		break;
	case MULT:
		reduction(a, 4);
		break;
	case CLOSEPAR:
		reduction(a, 4);
		break;
	case FIN:
		reduction(a, 4);
		break;
	default:
		return false;
		break;
	}

	return true;
}
