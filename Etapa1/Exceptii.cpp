#include"Exceptii.h"


Exceptii::Exceptii()
{
	this->denumire_exceptie=NULL;
	this->functia=NULL;
}


Exceptii::Exceptii(char *denumire,char *functia)
{
	this->denumire_exceptie=new char[strlen(denumire)+1];
	strcpy(this->denumire_exceptie,denumire);

	this->functia=new char[strlen(functia)+1];
	strcpy(this->functia,functia);
}


void Exceptii::print() const
{
	printf("%s",this->denumire_exceptie);
	printf("%s",this->functia);
}