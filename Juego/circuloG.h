#pragma once
#include <math.h>
#include "circuloPadre.h"
class cg: public padre
{
public:
	cg(Graphics^g, int dx, int dy, int radio, int tiempo, int veces);
	void mover(Graphics ^gr);
	int get_tiempo();
	int get_veces();
	~cg(void);
};
cg::cg(Graphics^g, int dx, int dy, int radio,int tiempo, int veces) : padre(g,dx, dy, radio,tiempo,veces)
{
	Random r;
	int aux;
	aux = r.Next(1, 5);
	if(aux==1)
	{
		this->dx = dx*-1;
	}
	if (aux == 2)
	{
		this->dy = dy*-1;
	}
	if (aux == 3)
	{
		this->dx = dx*-1;
		this->dy = dy*-1;
	}
	if (aux == 4)
	{
		this->dx = dx;
		this->dy = dy;
	}
}
void cg::mover(Graphics ^gr)
{
	borrar(gr);
	if (x + dx<1 || x + dx + radio>gr->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	if (y + dy<1 || y + dy + radio>gr->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	x += dx;
	y += dy;
	dibujar(gr);
}
int cg::get_tiempo()
{
	return tiempo;
}
int cg::get_veces()
{
	return veces;
}
cg::~cg()
{

}

