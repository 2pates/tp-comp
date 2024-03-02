#include "etat.h"
#include "analyseur.h"
#include <iostream>
using namespace std;

#ifdef DEBUG
#define print(lettre,nombre) (std::cout << __FILE__ << ":" << __LINE__ << \
" -> " << lettre << nombre << std::endl)
#else
#define print(lettre,nombre) ((void)0)
#endif



void decalage(Analyseur &a, Etat *e, Symbole *s)
{
	print("D",e->ident);
	a.automate->pile_etats.push_back(e);
	a.automate->pile_symboles.push_back(s);
	a.lexer->Avancer();
}

void pop_se(Analyseur &a) // pop symbole & etat
{
	a.automate->pile_symboles.pop_back();
	delete a.automate->pile_etats.back();
	a.automate->pile_etats.pop_back();
}

void reduction(Analyseur &a, int ruleNumber)
{
	print("R",ruleNumber);
	Symbole *createdExpr = nullptr;
	switch (ruleNumber) // r1, r2, ... , r5
	{
	case 1:
	{
		break;
	}
	case 2:
	{
		Expr *right = (Expr *)a.automate->pile_symboles.back();
		pop_se(a);

		delete a.automate->pile_symboles.back();
		pop_se(a); // pop plus

		Expr *left = (Expr *)a.automate->pile_symboles.back();
		pop_se(a);

		createdExpr = new ExprPlus(left, right);
		break;
	}
	case 3:
	{
		Expr *right = (Expr *)a.automate->pile_symboles.back();
		pop_se(a);

		delete a.automate->pile_symboles.back();
		pop_se(a); // pop mult

		Expr *left = (Expr *)a.automate->pile_symboles.back();
		pop_se(a);

		createdExpr = new ExprMult(left, right);
		break;
	}
	case 4:
	{
		delete a.automate->pile_symboles.back();
		pop_se(a); // pop right parenthesis

		Expr *expr = (Expr *)a.automate->pile_symboles.back();
		a.automate->pile_symboles.pop_back();
		delete a.automate->pile_etats.back();
		a.automate->pile_etats.pop_back();

		delete a.automate->pile_symboles.back();
		pop_se(a); // pop left parenthesis

		createdExpr = expr;

		break;
	}
	case 5:
	{
		Entier *val = (Entier *)a.automate->pile_symboles.back();
		pop_se(a); // pop value

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

void transition_simple(Analyseur &a, Etat *e)
{
	print("T",e->ident);
	a.automate->pile_etats.push_back(e);
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
		transition_simple(a, new I1());
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
		a.accepted = true;
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
		transition_simple(a, new I6());
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
		transition_simple(a, new I7());
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
		transition_simple(a, new I8());
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




