#include <iostream>
#include "lexer.h"
#include "analyseur.h"

int main(int argc, char** argv) {
   string chaine;
   if (argc == 2) {
      chaine = argv[1];
   } else {
      chaine = "(1+34)*123";
   }
   Analyseur a;



   a.analyser(chaine);

   return 0;
}


