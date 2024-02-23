#ifndef __AUTOMATE__
#define __AUTOMATE__

#include <deque>
#include "etat.h"
#include "symbole.h"



class Automate {
	private:
		/* data */
	public:
		Automate(/* args */);
		~Automate();

		deque<Etat*> pile_etats;
		deque<Symbole*> pile_symboles;
};


#endif
