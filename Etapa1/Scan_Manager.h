#ifndef SCAN_MANAGER_H
#define SCAN_MANAGER_H

#include"Scan_Worker.h"

class Scan_Manager
{
private:
	int nr_Max_Workeri;
	char *nume_fisier;
	int nr_Workeri;
	int id;
	static Lista<char*>files;
		Scan_Manager(char *x="Fisier Neintrodus", int n=0): nr_Max_Workeri(n), nr_Workeri(0),nume_fisier(x),id(0)
	{   
		ScanWorkeri=new Scan_Worker; 
	}
	static Scan_Manager *ScanManager;
	Scan_Manager(const Scan_Manager &M):nume_fisier(M.nume_fisier),nr_Workeri(0){};
	~Scan_Manager(){}; 
	Scan_Worker *ScanWorkeri ;

public:
	static void distruge();
	static Scan_Manager &Get_ScanManager();
	static Scan_Manager *Get_ScanManager(char *,int);
	void add_virus(char*);
	void scan(int p=0);
}; 
#endif