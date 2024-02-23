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

int Expr::eval()
{
   return this->eval();
}

int ExprPlus::eval()
{
   return 0;
}

int ExprMult::eval()
{
   return 0;
}

int ExprCst::eval()
{
   return 0;
}
