#include"Work.h"

int Work::id=0;

Work::Work(char*denumire)
{
	id++;
	this->nume_fisier=new char[strlen(denumire)+1];
	strcpy(this->nume_fisier,denumire);
}

int Work::get_id()
{
	return id;
}

char *Work::get_nume_fisier()
{
	return this->nume_fisier;
}