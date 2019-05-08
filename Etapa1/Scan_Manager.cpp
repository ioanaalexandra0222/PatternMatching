#include"Scan_Manager.h"


Scan_Manager *Scan_Manager::ScanManager=NULL;

Lista<char*> Scan_Manager::files;

Scan_Manager & Scan_Manager::Get_ScanManager()
{
	if  (ScanManager==NULL)
		ScanManager=new Scan_Manager; 
	return *ScanManager;
}


Scan_Manager * Scan_Manager::Get_ScanManager(char *nume_fisier,int nr_Workeri)
{ 

	if (ScanManager==NULL)
		ScanManager=new Scan_Manager(nume_fisier,nr_Workeri); 
	else
	{
		ScanManager->nume_fisier=new char[strlen(nume_fisier)+1];
		strcpy(ScanManager->nume_fisier,nume_fisier);
	}

	FILE *f=fopen(nume_fisier,"r");
	int i=0;
	if (f==NULL) 
		cout<<"Error File!";
	else
	{
		while (!feof(f)&&(ScanManager->id<nr_Workeri))
		{
			char aux[20];
			fscanf(f,"%s",aux); 

			ScanManager->ScanWorkeri->fisiere[ScanManager->id++] = new Work_Exe(aux);
		}

		ScanManager->ScanWorkeri->actualizare_nr_id(ScanManager->id-1);
	}
	while(!feof(f))
	{
		char *s;
		s=new char[256];
		fscanf(f,"%s",s);
		files.add_element(s);
	}

	return ScanManager;
}


void Scan_Manager::distruge()
{
	if (ScanManager==NULL)
	{
		return;
	}  
	delete ScanManager;
	ScanManager=NULL;
}


void Scan_Manager::add_virus(char*virus)
{
	this->ScanWorkeri->add_virus(virus);
}


void Scan_Manager::scan(int p)
{
	this->ScanWorkeri->scanare(&files,p);
}