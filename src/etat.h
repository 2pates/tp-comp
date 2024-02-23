#ifndef __ETAT__
#define __ETAT__

class Analyseur;

#include "symbole.h"



class Etat {
	public:
		Etat(){}

		virtual bool transition(Analyseur& a, Symbole* s) = 0;
};


class I0:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I1:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I2:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I3:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I4:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I5:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I6:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I7:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I8:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};


class I9:public Etat {
	public:
	bool transition(Analyseur& a, Symbole* s);
};



#endif
