#ifndef __ETAT__
#define __ETAT__

class Etat;

#include "automate.h"
#include "symbole.h"



class Etat {
	public:
		Etat();

		virtual bool transition(Analyseur& a, Symbole* s) = 0;
};


class I0:public Etat {
	public:
	I0();

	bool transition(Analyseur& a, Symbole* s);
};


class I1:public Etat {
	public:
	I1();

	bool transition(Analyseur& a, Symbole* s);
};


class I2:public Etat {
	public:
	I2();

	bool transition(Analyseur& a, Symbole* s);
};


class I3:public Etat {
	public:
	I3();

	bool transition(Analyseur& a, Symbole* s);
};


class I4:public Etat {
	public:
	I4();

	bool transition(Analyseur& a, Symbole* s);
};


class I5:public Etat {
	public:
	I5();

	bool transition(Analyseur& a, Symbole* s);
};


class I6:public Etat {
	public:
	I6();

	bool transition(Analyseur& a, Symbole* s);
};


class I7:public Etat {
	public:
	I7();

	bool transition(Analyseur& a, Symbole* s);
};


class I8:public Etat {
	public:
	I8();

	bool transition(Analyseur& a, Symbole* s);
};


class I9:public Etat {
	public:
	I9();

	bool transition(Analyseur& a, Symbole* s);
};



#endif
