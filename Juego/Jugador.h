#pragma once
#include "String.h"
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna};
using namespace System::Drawing;
using namespace System;
class Jugador
{
private:
	int x, y;
	int dx, dy;
	char*imagen;//nombre del archivo
	int ancho, alto;
	int indicex, indicey;
public:
	Jugador(void);
	~Jugador(void);
	void set_x(int nuevo);
	void set_y(int nuevo);
	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_ancho();
	int get_alto();
	void cambiar_dx_dy(Direcciones teclapulsada);
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr, Direcciones teclapulsada);
};
Jugador::Jugador(void)
{
	x = y = 0;
	dx = 0;
	dy = 1;
	indicex = indicey = 0;
	imagen = new char[50];
}
void Jugador::set_x(int nuevo)
{
	x = nuevo;
}
void Jugador::set_y(int nuevo)
{
	y = nuevo;
}
int  Jugador::get_x()
{
	return x;
}
int  Jugador::get_y()
{
	return y;
}
int  Jugador::get_dx()
{
	return dx;
}
int  Jugador::get_dy()
{
	return dy;
}
int  Jugador::get_ancho()
{
	return ancho;
}
int  Jugador::get_alto()
{
	return alto;
}
void Jugador::cambiar_dx_dy(Direcciones teclapulsada)
{
	switch (teclapulsada)
	{
	case Arriba:
	{
		dy = -1;
		dx = 0;
		break;
	}
	case Abajo:
	{
	dy = 1;
	dx = 0;
		break;
	}
	case Izquierda:
	{
	dy = 0;
	dx = -1;
		break;
	}
	case Derecha:
	{
		dy = 0;
		dx = 1;
		break;
	}
	case Ninguna:
	{
		dy = 0;
		dx = 0;
		break;
	}
	default:
	{
		break;
	}
	}
}
void Jugador::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);//copia de una cadena a otra
	//imagen tiene el nombre del archivo sprite
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	//carga la imagen
	ancho = bmp->Width / 5;//5 imagenes x columna
	alto = bmp->Height / 4;//4 imagenes xcolumna
	delete bmp;
}
void Jugador::mostrar(Graphics^gr)
{
	//clase Bitmap para leer la imagen del archivo
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	//porcion que será un cuadro del sprite
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	//zoom para que la imagen sea más grande que la original
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho, alto);
	//Dibuja la imagen en el canvas
	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);
}
void Jugador::Mover(Graphics^gr,Direcciones teclapulsada)
{
	if (teclapulsada == Direcciones::Abajo) 		indicey = 0;
	if (teclapulsada == Direcciones::Izquierda)	indicey = 1;
	if (teclapulsada == Direcciones::Derecha)		indicey = 2;
	if (teclapulsada == Direcciones::Arriba)		indicey = 3;

	indicex++;
	if (indicex>2)
		indicex = 0;

	x = x + dx;
	y = y + dy;
	mostrar(gr);
}
Jugador::~Jugador()
{
	//Delete imagen
}

