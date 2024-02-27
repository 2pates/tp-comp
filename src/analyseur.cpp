#include <iostream>
#include "analyseur.h"

Analyseur::Analyseur()
{
    automate = new Automate();
    lexer = nullptr;
    accepted = false;
}

Analyseur::~Analyseur()
{
    delete automate;
}

bool Analyseur::analyser(string chaine)
{
    lexer = new Lexer(chaine);
    Symbole *s;
    accepted = false;
    while (!accepted)
    {
        s = lexer->Consulter();
        if (!automate->pile_etats.back()->transition(*this, s))
        {
            cout << "Erreur de syntaxe" << endl;
            break;
        }
    }

    if (accepted)
    {
        cout << "Analyse terminée" << endl;
        Expr *expr = (Expr *)automate->pile_symboles.back();
        expr->Affiche();
        cout << " = " << expr->Eval() << endl;
        // delete expr;
    }
    delete lexer;
    lexer = nullptr;
    return accepted;
}
