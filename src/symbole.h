#pragma once

#include <string>
using namespace std;

enum Identificateurs
{
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   FIN,
   ERREUR,
   E
};

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "E"};

class Symbole
{
public:
   // Symbole() {}
   Symbole(int i) : ident(i) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   virtual void Affiche();

protected:
   int ident;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();
   int valeur;

protected:
};

class Expr : public Symbole
{
public:
   Expr() : Symbole(E) {}
   // virtual void Affiche();
   int eval();
};

class ExprPlus : public Expr
{
public:
   ExprPlus(Symbole *a, Symbole *b) : left(a), right(b) {}
   Symbole *left, *right;
   // virtual void Affiche();
   int eval();
};

class ExprMult : public Expr
{
public:
   ExprMult(Symbole *a, Symbole *b) : left(a), right(b) {}
   Symbole *left, *right;
   // virtual void Affiche();
   int eval();
};

class ExprCst : public Expr
{
public:
   ExprCst(Symbole *value) : val(value) {}
   Symbole *val;
   // virtual void Affiche();
   int eval();
};
