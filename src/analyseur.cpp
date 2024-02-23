#include <iostream>
#include "analyseur.h"

Analyseur::Analyseur()
{
    automate = new Automate();
    lexer = nullptr;
}

bool Analyseur::analyser(string chaine)
{
    lexer = new Lexer(chaine);
    Symbole *s;
    while (*(s = lexer->Consulter()) != FIN)
    {
        s->Affiche();
        std::cout << std::endl;
        // lexer->Avancer();
        automate->pile_etats.back()->transition(*this, s);
    }
    
    
    delete lexer;
    lexer = nullptr;
    return true;
}
