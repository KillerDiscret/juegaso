#pragma once
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguna, LetraA, LetraS };
using namespace System::Drawing;
class CJugador
{
private:
	int personaje = 1;
	int x, y;
	int dx, dy;
	int ancho, alto;
	int indicex, indicey;
	Direcciones direccion;
	Direcciones ultima;
public:
	CJugador();
	~CJugador();
	CJugador(int, int);
	void dibujarJugador(Graphics^g, Bitmap^bmpJugador);
	void moverJugador(Graphics^g, Bitmap^bmpJugador);
	void setdireccion(Direcciones);
	int get_x();
	int get_y();
};
CJugador::CJugador()
{

}
CJugador::CJugador(int _x, int _y)
{
	x = _x;
	y = _y;
	dx = dy = 0;
	indicex = indicey = 0;
	ancho = 48;
	alto = 48;
	direccion = Ninguna;
	ultima = Abajo;
}
CJugador::~CJugador()
{

}
void CJugador::dibujarJugador(Graphics^g, Bitmap ^bmpJugador)
{
	Rectangle porcionusar = Rectangle(indicex*ancho, indicey*alto, ancho, alto);
	Rectangle aumento = Rectangle(x, y, ancho * 2, ancho * 2);
	g->DrawImage(bmpJugador, aumento, porcionusar, GraphicsUnit::Pixel);
	x += dx;
	y += dy;
}
void CJugador::moverJugador(Graphics^g, Bitmap^bmpJugador)
{

	switch (direccion)
	{
	case Arriba:
	{
		if (personaje == 1)
		{
			indicey = 3;
			if (indicex >= 0 && indicex < 2)
			{
				indicex++;
			}
			else
			{
				indicex = 0;
			}
			dx = 0;
			dy = -10;
			ultima = Arriba;
		}
		if (personaje == 2)
		{
			indicey = 3;
			if (indicex >= 3 && indicex < 5)
			{
				indicex++;
			}
			else
			{
				indicex = 3;
			}
			dx = 0;
			dy = -10;
			ultima = Arriba;
		}
		break;
	}
	case Abajo:
	{
		if (personaje == 1)
		{
			indicey = 0;
			if (indicex >= 0 && indicex < 2)
			{
				indicex++;
			}
			else
			{
				indicex = 0;
			}
			dx = 0;
			dy = +10;
			ultima = Abajo;
		}
		if (personaje == 2)
		{
			indicey = 0;
			if (indicex >= 3 && indicex < 5)
			{
				indicex++;
			}
			else
			{
				indicex = 3;
			}
			dx = 0;
			dy = +10;
			ultima = Abajo;
		}
		break;
	}

	case Izquierda:
	{
		if (personaje == 1)
		{
			indicey = 1;
			if (indicex >= 0 && indicex < 2)
			{
				indicex++;
			}
			else
			{
				indicex = 0;
			}
			dx = -10;
			dy = 0;
			ultima = Izquierda;
		}
		if (personaje == 2)
		{
			indicey = 1;
			if (indicex >= 3 && indicex < 5)
			{
				indicex++;
			}
			else
			{
				indicex = 3;
			}
			dx = -10;
			dy = 0;
			ultima = Izquierda;
		}
		break;
	}
	case Derecha:
	{
		if (personaje == 1)
		{
			indicey = 2;
			if (indicex >= 0 && indicex < 2)
			{
				indicex++;
			}
			else
			{
				indicex = 0;
			}
			dx = +10;
			dy = 0;
			ultima = Derecha;
		}
		if (personaje == 2)
		{
			indicey = 2;
			if (indicex >= 3 && indicex < 5)
			{
				indicex++;
			}
			else
			{
				indicex = 3;
			}
			dx = +10;
			dy = 0;
			ultima = Derecha;
		}


		break;
	}
	case LetraA:
	{
		personaje = 2;
		break;
	}
	case LetraS:
	{
		personaje = 1;
		break;
	}
	case Ninguna:
		dx = 0;
		dy = 0;

		if (ultima == Abajo)
		{
			if (personaje == 1)
			{
				indicex = 0;
				indicey = 0;
			}
			if (personaje == 2)
			{
				indicex = 3;
				indicey = 0;
			}
		}
		if (ultima == Arriba)
		{
			if (personaje == 1)
			{
				indicex = 0;
				indicey = 3;
			}
			if (personaje == 2)
			{
				indicex = 3;
				indicey = 3;
			}
		}

		if (ultima == Derecha)
		{
			if (personaje == 1)
			{
				indicex = 0;
				indicey = 2;
			}
			if (personaje == 2)
			{
				indicex = 3;
				indicey = 2;
			}
		}
		if (ultima == Izquierda)
		{
			if (personaje == 1)
			{
				indicex = 0;
				indicey = 1;
			}

			if (personaje == 2)
			{
				indicex = 3;
				indicey = 1;
			}
		}
		break;
	default:
		break;
	}
	dibujarJugador(g, bmpJugador);
}
void CJugador::setdireccion(Direcciones direcion_actual)
{
	direccion = direcion_actual;
}
int CJugador::get_x()
{
	return x;
}
int CJugador::get_y()
{
	return y;
}
