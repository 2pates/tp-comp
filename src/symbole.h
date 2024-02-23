#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, E };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};



// class Openpar : public Symbole {
//    public:
//       Openpar(int v) : Symbole(OPENPAR) { }
//       ~Openpar() { }
//       virtual void Affiche();
//    protected:
// };



// class Closepar : public Symbole {
//    public:
//       Closepar(int v) : Symbole(CLOSEPAR) { }
//       ~Closepar() { }
//       virtual void Affiche();
//    protected:
// };



// class Plus : public Symbole {
//    public:
//       Plus(int v) : Symbole(PLUS) { }
//       ~Plus() { }
//       virtual void Affiche();
//    protected:
// };



// class Mult : public Symbole {
//    public:
//       Mult(int v) : Symbole(MULT) { }
//       ~Mult() { }
//       virtual void Affiche();
//    protected:
// };



// class Fin : public Symbole {
//    public:
//       Fin(int v) : Symbole(FIN) { }
//       ~Fin() { }
//       virtual void Affiche();
//    protected:
// };



// class Erreur : public Symbole {
//    public:
//       Erreur(int v) : Symbole(ERREUR) { }
//       ~Erreur() { }
//       virtual void Affiche();
//    protected:
// };




