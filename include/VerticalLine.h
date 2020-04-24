#include <iostream>
#include <list>

class point;

class VerticalLine : public Figure
{
	
public:

	VerticalLine(int yTop, int yBot, int x, char sym)
	{
		for (int y = yTop; y <= yBot; y++)
		{
			point p(x, y, sym);
			pList.push_back(p);
		}
	}
};

