#pragma once
using namespace System;
using namespace System::Drawing;
class padre
{
protected:
	int radio, dx, dy;
	int tiempo, veces;
	int x, y;
public:
	padre(Graphics^g, int dx, int dy,int radio, int tiempo, int veces);
	void borrar(Graphics ^gr);
	void dibujar(Graphics ^gr);
	~padre();
};
padre::padre(Graphics^g, int dx, int dy, int radio,int tiempo, int veces)
{
	this->x = (g->VisibleClipBounds.Width)/(2);
	this->y = (g->VisibleClipBounds.Height) / (2);
	this->dx = dx;
	this->dy = dy;
	this->radio = radio;
	this->tiempo = tiempo;
	this->veces = veces;
}
void padre::borrar(Drawing::Graphics ^gr)
{
	gr->DrawEllipse(gcnew Drawing::Pen(Drawing::Color::White), x, y, radio, radio);

}
void padre::dibujar(Drawing::Graphics ^gr)
{
	gr->DrawEllipse(gcnew Drawing::Pen(Drawing::Color::Red), x, y, radio, radio);

}
/*void padre::mover(Drawing::Graphics ^gr)
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
*/
padre::~padre()
{

}