#pragma once
#include "circuloPadre.h"
class cm : public padre
{private:
	int orientacion;
	bool habilita=true;
	int pos=1;
public:
	cm(Graphics^g, int dx, int dy, int radio, int tiempo, int veces);
	void mover(Graphics ^gr);
	int get_tiempo();
	int get_veces();
	~cm(void);
};
cm::cm(Graphics^g, int dx, int dy, int radio, int tiempo, int veces) : padre(g, dx, dy, radio, tiempo, veces)
{
	Random r;
	int aux;
	aux = r.Next(1, 5);
	if (aux == 1)
	{
		orientacion = 1;
	}
	if (aux == 2)
	{
		orientacion = 2;
	}
	if (aux == 3)
	{
		orientacion = 3;
	}
	if (aux == 4)
	{
		orientacion = 4;
	}
}
void cm::mover(Graphics ^gr)
{
		borrar(gr);
		if (habilita == true)
		{

			if (orientacion == 1)
			{
				//derecha
				x++;
				x = x + dx;
				if (x+ radio >=gr->VisibleClipBounds.Width)
				{
					x = (gr->VisibleClipBounds.Width)-(radio/2);
					habilita = false;
					pos = 2;
				}
			}
			if (orientacion == 2)
			{
				//izquierda
				x--;
				x = x -dx;
				if (x<=0)
				{
					x = -1*(radio / 2);
					habilita = false;
					pos = 4;
				}
			}
			if (orientacion == 3)
			{
				//abajo
				y++;
				y = y + dy;
				if (y+radio >= gr->VisibleClipBounds.Height)
				{
					y = (gr->VisibleClipBounds.Height) - (radio / 2);
					habilita = false;
					pos = 3;
				}
			}
			if (orientacion == 4)
			{
				//arriba
				y--;
				y = y - dy;
				if (y <= 0)
				{
					y = -1 * (radio / 2);
					habilita = false;
					pos = 1;
				}
			}
		}
		else
		{
			//arriba a la derecha
			if (y == -1 * (radio / 2) &&(x<gr->VisibleClipBounds.Width)&&pos==1)
			{
				x++;
				x = x+ dx;
				if (x+dx+(radio/2)>=gr->VisibleClipBounds.Width)
				{
					pos = 2;
					x = (gr->VisibleClipBounds.Width) - (radio / 2);
				}
			}
			//derecha hacia abajo
			if (pos==2&&y < gr->VisibleClipBounds.Height && (x== (gr->VisibleClipBounds.Width) - (radio / 2)))
			{
				y++;
				y = y + dy;
				if (y+ dy + (radio / 2) >=gr->VisibleClipBounds.Height)
				{
					pos =3;
					y = (gr->VisibleClipBounds.Height) - (radio / 2);
				}
			}
			//abajo hacia la izquieda
			if (pos ==3 && (y== (gr->VisibleClipBounds.Height) - (radio / 2)) && x>0)
			{
				x--;
				x=x-dx;
				if (x<=0)
				{
			//falta pulir para que cambie de posicion bien
					pos = 4;
					x = -1 * (radio / 2);
				}
			}
			//izquierda hacia arriba
			if (pos==4&&y>=0 && x == -1 * (radio / 2))
			{
				y--;
				y = y - dy;
				if(y<0)
				{
					pos = 1;
					y = -1 * (radio / 2);
				}
			}

		}
		dibujar(gr);
}
int cm::get_tiempo()
{
	return tiempo;
}
int cm::get_veces()
{
	return veces;
}
cm::~cm()
{

}
