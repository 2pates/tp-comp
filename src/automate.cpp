#include "automate.h"


Automate::Automate() {
	pile_etats.push_back(new I0());
}

Automate::~Automate() {
	for (auto it = pile_etats.begin(); it != pile_etats.end(); it++)
	{
		delete *it;
	}
	for (auto it = pile_symboles.begin(); it != pile_symboles.end(); it++)
	{
		delete *it;
	}
}
