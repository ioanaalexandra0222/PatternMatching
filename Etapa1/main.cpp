#include"Scan_Manager.h" 

void main()
{
	Scan_Manager *pSM = Scan_Manager::Get_ScanManager("fisiere.txt",7);
	pSM->add_virus("semnatura");
	pSM->add_virus("semnatura2");
	pSM->scan(); 

	Scan_Manager::distruge();  
}