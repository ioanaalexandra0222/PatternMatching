#include"Scan_Worker.h"


Scan_Worker::Scan_Worker()
{ 
	this->virusi_exe=new Lista<char*>;
	memset(this->fisiere,0,25); 
}


void Scan_Worker::add_virus(char*virus) 
{
	//if (strstr(virus,".exe"))
	//{
		this->virusi_exe->add_element(virus);
	//}
}


void Scan_Worker::scanare(Lista<char*>*l,int p)
{

	Lista<char*> *aux=new Lista<char*>; 
	Lista<char*> *aux2=new Lista<char*>;

	aux->varf=this->virusi_exe->get_Varf();
	int nr_fisiere_scanate=0;
	int nr_fisiere_infectate = 0;

	ofstream g("raport.txt", ios :: app);
	for(int i=0;i<=nr_id;i++)
	{
		if (strcmp(this->fisiere[i]->get_tip(),"Exe")==0)
		{
			nr_fisiere_scanate++;
			try{
				while (aux->get_Varf()!=NULL)
				{
					//if(p==NULL)
					//{
						this->fisiere[i]->scan(aux->varf->val); 					
					//}
					/*else 
					{
						this->fisiere[i]->strict_scan(aux->varf->val,p);
					}*/

					aux->varf=aux->varf->get_next(); 
				}

				if(this->fisiere[i]->get_nume_fisier())
				{
					if(Work_Exe::get_count()>0)
						g<<endl<<this->fisiere[i]->get_nume_fisier()<<"\t\t infectat ";
					else
						g << endl << this->fisiere[i]->get_nume_fisier() << "\t\t neinfectat ";
					if (Work_Exe::get_count()>0)
					{
						nr_fisiere_infectate++;
					}
					g.flush();
				}
			}
			catch(...){};

			Work_Exe::get_count()=0;
			aux->varf=this->virusi_exe->get_Varf();
		}
	}

	int c=0;
	if(l->get_contor())
		while(l->get_contor()&&l->varf)
		{
			for(int i=0;i<=nr_id;i++)
			{
				if (strcmp(this->fisiere[i]->get_tip(),"Exe")==0&&strstr(l->get_Varf()->val,".exe"))
				{
					nr_fisiere_scanate++;
					try{
						while (aux->get_Varf()!=NULL)
						{
							if(p==NULL)
							{

								this->fisiere[i]->scan(aux->varf->val,l->get_Varf()->val); 	
								break;		
							}
							else 
							{
								this->fisiere[i]->strict_scan(aux->varf->val,p,l->get_Varf()->val);
								break;		
							}

							aux->varf=aux->varf->get_next(); 
						}
						if(Work_Exe::get_count()>0)
							g<<endl<<l->get_Varf()->val<<"\t\t infectat ";
						else
							g << endl << l->get_Varf()->val << "\t\t neinfectat ";
						if (Work_Exe::get_count()>0)
						{
							nr_fisiere_infectate++;
						}
						g.flush();
					}
					catch(...){};
						if(l->varf)
							l->varf=l->varf->get_next();

						Work_Exe::get_count()=0;
						aux->varf=this->virusi_exe->get_Varf();
				}
			}
			l->get_contor()=l->get_contor()-1;
			if(l->varf)
				l->varf=l->varf->get_next();
			else break;

		}
		g.close();
		ofstream h("raport.txt", ios :: app);
		h<<"\nNumar total de fisiere scanate: "<<nr_fisiere_scanate;
		h << "\nNumar total de fisiere infectate: " << nr_fisiere_infectate;

		h.close();

}


Scan_Worker::Scan_Worker(Lista<char*> *a)
{
	this->virusi_exe->varf=a->varf;
}