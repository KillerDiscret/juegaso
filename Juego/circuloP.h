#pragma once
#include "circuloPadre.h"
#include "Jugador.h"
class cp:public padre
{
private:
	CJugador*obj;
public:
	cp(Graphics^g, int dx, int dy, int radio, int tiempo, int veces);
	int get_tiempo();
	int get_veces();
	void mover(Graphics ^gr);
	~cp();
};
cp::cp(Graphics^g, int dx, int dy, int radio, int tiempo, int veces) :padre(g, dx, dy, radio, tiempo, veces)
{
	obj = new CJugador();
}
void cp::mover(Graphics ^gr)
{
	borrar(gr);
	if (y==obj->get_y()&& x<obj->get_x())
	{
		x++;
		x += dx;
	}
	if (y == obj->get_y() && x>obj->get_x())
	{
		x--;
		x -= dx;
	}
	if (x==obj->get_x()&&y<obj->get_y())
	{
		y++;
		y += dy;
	}
	if (x == obj->get_x() && y>obj->get_y())
	{
		y--;
		y -= dy;
	}
//falta poner el movimiento en diagonal
	dibujar(gr);

}
int cp::get_tiempo()
{
	return tiempo;
}
int cp::get_veces()
{
	return veces;
}
cp::~cp()
{

}