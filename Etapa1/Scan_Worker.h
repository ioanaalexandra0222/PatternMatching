#ifndef SCAN_WORKER_H
#define SCAN_WORKER_H

#include"Work_Exe.h"

class Scan_Worker
{
private:
	int nr_id;
public: 
	Work *fisiere[25]; 
	Scan_Worker(); 

	Lista<char*> *virusi_exe; 

	Scan_Worker(Lista<char*> *);
	void add_virus(char*);

	void scanare(Lista<char*>*l,int p=NULL);

	void actualizare_nr_id(int id) { nr_id = id; };
	Lista<char*> &get_virusi_exe() {return *virusi_exe;};

};
#endif