#include <list>

class Figure;


class Snake : public Figure
{
public:

	Direction direction;

	Snake(point tall, int lenght, Direction _direction)
	{
		direction = _direction;
		for (int i = 0; i < lenght; i++)
		{
			point p(tall);
			p.Move(i, direction);
			pList.push_back(p);
		}
	}

	void Move();

	point GetNextPoint()
	{
		point head = pList.back();
		point nextPoint(head);
		nextPoint.Move(1, direction);
		return nextPoint;
	}

	void Behavior();
	bool Eat(point *food);
	bool IsHitTail();
};