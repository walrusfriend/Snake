#include <iostream>
#include <list>
#include "Figure.h"

class point;

class HorizontalLine : public Figure
{
	
public:
		
	HorizontalLine(int xLeft, int xRight, int y, char sym)
	{
		for (int x = xLeft; x <= xRight; x++)
		{
			point p(x, y, sym);
			pList.push_back(p);
		}
	}
};

