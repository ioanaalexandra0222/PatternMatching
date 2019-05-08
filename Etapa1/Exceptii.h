#ifndef EXCEPTII_H
#define EXCEPTII_H

#include<stdio.h>
#include<string.h>

class Exceptii
{
	char *denumire_exceptie;
	char *functia;
public:
	Exceptii();
	Exceptii(char*,char*);
	void print() const;
	char *get_denum(){return this->denumire_exceptie;};
	char *get_functie(){return this->functia;}
};
#endif