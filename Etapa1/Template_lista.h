#ifndef TEMPLATE_LISTA_H
#define TEMPLATE_LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<string.h> 

using namespace std;
 
template <class T>
class Lista
{
	struct elemente
	{
		T val;
		elemente *next;
		elemente *get_next(){return next;};
	}; 
	int contor;
public:
	elemente *varf; 
	Lista(); 
	~Lista(){};
	void add_element(char*);
	elemente *get_Varf(){return varf;};
	T get_val(){return val;}; 
	Lista(const Lista&);
	int &get_contor(){return contor;};
};
#endif


template<class T>
Lista<T>::Lista()
{
	this->varf=NULL; 
	contor=0;
};
 

 template <class T> 
void Lista<T>::add_element(char* element)
{
	elemente *aux=new elemente;
	contor++;
	aux->val=new char[strlen(element)+1];
	strcpy(aux->val,element); 
	aux->next=NULL;
	if (varf==NULL)
	{
		varf=new elemente;
		varf=aux; 
	}
	else
	{
		aux->next=varf;
		varf=aux;
	}
}; 


 template<class T>
Lista<T>::Lista(const Lista &a)
{
	this->varf=a.get_Varf();
	return *this; 
};
