#include "Figure.h"
#include "point.h"
#include "Snake.h"
#include "Direction.h"
#include <conio.h>

void Snake::Move()
{
	point tail = pList.front();
	pList.pop_front();
	point head = GetNextPoint();
	pList.push_back(head);

	tail.Clear();
	head.Draw();
}

void Snake::Behavior()
{
    if (GetAsyncKeyState(VK_LEFT))
        direction = LEFT;
    else if (GetAsyncKeyState(VK_UP))
        direction = UP;
    else if (GetAsyncKeyState(VK_RIGHT))
        direction = RIGHT;
    else if (GetAsyncKeyState(VK_DOWN))
        direction = DOWN;
}

bool Snake::Eat(point *food)
{
    point head = GetNextPoint();
    if (head.IsHit(*food))
    {
        (*food).sym = head.sym;
        pList.push_back(*food);
        return true;
    }
    else
        return false;
}

bool Snake::IsHitTail()
{
    point head = pList.back();
    pList.pop_back();
    for (std::list<point>::const_iterator it = pList.begin(); it != pList.end(); ++it)
        if (head.IsHit(*it))
        {
            pList.push_back(head);
            return true;
        }
    pList.push_back(head);
    return false;

}