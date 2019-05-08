#include"Work_Exe.h"
#include"Exceptii.h"
int Work_Exe::count=0;

void Work_Exe::scan(char *virusi,char*w)
{
	try{
	FILE *op=fopen(virusi,"rb");
	
	char *vir;
	char *vir2;

	FILE *f=fopen(this->nume_fisier,"rb");
	if(f==NULL)
	{
		if(!w)
		throw new Exceptii("Eroare la deschiderea fisierului ",this->nume_fisier);
		else throw new Exceptii("Eroare la deschiderea fisierului ",w);
	}
	Lista<char*> baza_date_virus;
	Lista<char*>*iterrator=new Lista<char*>;

	//while(!feof(op))
	//{
	//	vir2=new char[9];
	//	vir2[8]='\0';
	//	if(fread(vir2,1,8,op))
	//	{
	//		baza_date_virus.add_element(vir2);
	//	}

	//}

		fseek(op, 0, SEEK_END);
		int len=ftell(op);
		rewind(op);

		vir2=new char[len+1];
		vir2[len]='\0';
		if(fread(vir2,1,len,op))
		{
			baza_date_virus.add_element(vir2);
		}

	fclose(op);

	if (f!=NULL)
	{
		while (!feof(f))
		{ 
			char *aux;
			aux=new char[len+1];
			if(fread(aux,1,len,f)){
				aux[len]='\0';
				for(iterrator->varf=baza_date_virus.get_Varf();iterrator->varf;iterrator->varf=iterrator->varf->next)
					if (memcmp(iterrator->varf->val,aux,strlen(aux))==0)
				{
					count++;
				} 
		}
		}
	}
	fclose(f);
	}
	catch(Exceptii*e)
	{
		ofstream h("raport.txt", ios :: app);
		h<<"\n"<<e->get_denum()<<" "<<e->get_functie();
		delete e;
		h.close();
		throw 0;
	}
}


void Work_Exe::strict_scan(char* virusi, int p,char *w)
{
	try{
	FILE *op=fopen(virusi,"rb");
	
	char *vir;
	char *vir2;

	FILE *f=fopen(this->nume_fisier,"rb");
		if(f==NULL)
	{
		if(!w)
		throw new Exceptii("Eroare la deschiderea fisierului ",this->nume_fisier);
		else throw new Exceptii("Eroare la deschiderea fisierului ",w);
	}
	Lista<char*> baza_date_virus;
	Lista<char*>*iterrator=new Lista<char*>;

	while(!feof(op))
	{
		vir2=new char[9];
		vir2[8]='\0';
		if(fread(vir2,1,8,op))
		{
			baza_date_virus.add_element(vir2);
		}
	}

	fclose(op);

	if (f!=NULL)
	{
		while (!feof(f))
		{ 
			char *aux;
			aux=new char[9];
			if(fread(aux,1,8,f)){
				aux[8]='\0';
				for(iterrator->varf=baza_date_virus.get_Varf();iterrator->varf;iterrator->varf=iterrator->varf->next)
					if (memcmp(iterrator->varf->val,aux,(strlen(aux)*p)/100)==0)
				{
					count++;
				} 
		}
		}
	 
	}
	fclose(f);
	}
	catch(Exceptii*e)
	{
		ofstream h("raport.txt", ios :: app);
		h<<"\n"<<e->get_denum()<<" "<<e->get_functie();
		delete e;
		h.close();
		throw 0;
	}
}

int &Work_Exe::get_count()
{
	return count;
}