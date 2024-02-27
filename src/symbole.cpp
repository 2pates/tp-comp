#include "symbole.h"
#include <iostream>

void Symbole::Affiche()
{
   cout << Etiquettes[ident];
}

void Entier::Affiche()
{
   Symbole::Affiche();
   cout << "(" << valeur << ")";
}

void ExprPlus::Affiche()
{
   cout << "(";
   left->Affiche();
   cout << "+";
   right->Affiche();
   cout << ")";
}

void ExprMult::Affiche()
{
   cout << "(";
   left->Affiche();
   cout << "*";
   right->Affiche();
   cout << ")";
}

void ExprCst::Affiche()
{
   cout << "(";
   val->Affiche();
   cout << ")";
}

int ExprPlus::Eval()
{
   return left->Eval() + right->Eval();
}

int ExprMult::Eval()
{
   return left->Eval() * right->Eval();
}

int ExprCst::Eval()
{
   return val->valeur;
}
