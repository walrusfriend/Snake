#include "point.h"
#include "Figure.h"

void Figure::Draw()
{
	for (point p : pList)
		p.Draw();
}

bool Figure::IsHit(Figure figure)
{
	for (point p : pList)
	{
		if (figure.IsHit(p)) return true;
	}
	return false;
}

bool Figure::IsHit(point Point)
{
	for (point p : pList)
	{
		if (p.IsHit(Point)) return true;
	}
	return false;
}