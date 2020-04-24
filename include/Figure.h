#include <list>

class point;

class Figure
{
protected:
	std::list<point> pList;

public:
	void Draw();
	bool IsHit(Figure figure);
	bool IsHit(point p);
};

