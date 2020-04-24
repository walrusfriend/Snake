#include "point.h"
#include "HorizontalLine.h"
#include "VerticalLine.h"
#include "Walls.h"

void Walls::Draw()
{
	for (Figure wall : wallList)
		wall.Draw();
}

bool Walls::IsHit(Figure figure)
{
	for (Figure wall : wallList)
	{
		if (wall.IsHit(figure)) return true;
	}
	return false;
}