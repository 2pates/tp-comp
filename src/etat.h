#ifndef __ETAT__
#define __ETAT__

class Analyseur;

#include "symbole.h"



class Etat {
	public:
		Etat(int ident_): ident(ident_) {}
		virtual ~Etat() {}
		virtual bool transition(Analyseur& a, Symbole* s) = 0;

		int ident;
};


class I0:public Etat {
	public:
	I0(): Etat(0) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I1:public Etat {
	public:
	I1(): Etat(1) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I2:public Etat {
	public:
	I2(): Etat(2) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I3:public Etat {
	public:
	I3(): Etat(3) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I4:public Etat {
	public:
	I4(): Etat(4) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I5:public Etat {
	public:
	I5(): Etat(5) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I6:public Etat {
	public:
	I6(): Etat(6) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I7:public Etat {
	public:
	I7(): Etat(7) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I8:public Etat {
	public:
	I8(): Etat(8) {}
	bool transition(Analyseur& a, Symbole* s);
};


class I9:public Etat {
	public:
	I9(): Etat(9) {}
	bool transition(Analyseur& a, Symbole* s);
};



#endif
