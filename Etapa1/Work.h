#ifndef WORK_H
#define WORK_H

#include<stdio.h>
#include<string.h>
#include"Template_lista.h"
#include<fstream>
 
class Work
{
	
protected:
	static int id;
	char *nume_fisier;
	char *tip;
	Lista<char*> virusi;
public:
	Work(){};  
	Work(char*);
	virtual void scan(char *,char*w=NULL)=0;
	virtual void strict_scan(char*, int p,char*w=NULL)=0;
	char *get_tip(){return tip;};
	static int get_id();
	 char *get_nume_fisier();
}; 
#endif