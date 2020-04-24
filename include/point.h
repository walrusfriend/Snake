#include <windows.h>
#include <iostream>

enum Direction;

class point
{
public:
	int x;
	int y;
	char sym;

	point(int _x, int _y, char _sym)
	{
		x = _x;
		y = _y;
		sym = _sym;
	}

	point(const point& p) //Copy constructor
	{
		x = p.x;
		y = p.y;
		sym = p.sym;
	}

	void Move(int offset, Direction direction);
	void Draw();
	void Clear();
	bool IsHit(point p);
};

