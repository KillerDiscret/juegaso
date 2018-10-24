#pragma once
#include"circuloG.h"
class Arrcg
{
private:
	int *N;
	cg**arreglo;
public:
	Arrcg();
	void agregar(cg*obj);
	cg* obtener(int indice);
	int get_N();
	~Arrcg();
};
Arrcg::Arrcg()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void Arrcg::agregar(cg*obj)
{
	cg**temporal;
	temporal = new cg*[*N + 1];
	if (temporal !=NULL)
	{
		for (int i=0; i<*N;i++)
		{
			temporal[i] = arreglo[i];
		}
		temporal[*N] = obj;
		*N = *N + 1;
		arreglo = temporal;
	}
}
 cg* Arrcg::obtener(int indice)
{
	return arreglo[indice];
}
 int Arrcg::get_N()
 {
	 return *N;
 }
Arrcg::~Arrcg()
{

}