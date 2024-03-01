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
   virtual ~Expr() {}
   virtual void Affiche() = 0;
   virtual int Eval() = 0;
};


class ExprPlus : public Expr
{
public:
   ExprPlus(Expr *a, Expr *b) : left(a), right(b) {}
   virtual ~ExprPlus()
   {
      delete left;
      delete right;
   }
   Expr *left, *right;
   virtual void Affiche();
   virtual int Eval();
};

class ExprMult : public Expr
{
public:
   ExprMult(Expr *a, Expr *b) : left(a), right(b) {}
   virtual ~ExprMult()
   {
      delete left;
      delete right;
   }
   Expr *left, *right;
   virtual void Affiche();
   virtual int Eval();
};

class ExprCst : public Expr
{
public:
   ExprCst(Entier *value) : val(value) {}
   virtual ~ExprCst() { delete val; }
   Entier *val;
   virtual void Affiche();
   virtual int Eval();
};



