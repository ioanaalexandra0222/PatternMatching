#ifndef WORK_EXE_H
#define WORK__EXE_H

#include"Work.h"


class Work_Exe:public Work
{
	static int count;
public: 
	Work_Exe(){};
	Work_Exe(char *nume):Work(nume)
	{id++;
	this->tip=new char[6];
	strcpy(this->tip,"Exe");
	} 
	void scan(char *,char*w=NULL);
	void strict_scan(char*, int p,char*w=NULL);
	static int &get_count();
};
#endif