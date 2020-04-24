#include "point.h"
#include "Direction.h"

void point::Move(int offset, Direction direction)
{
    if (direction == RIGHT) x += offset;
    else if (direction == LEFT) x -= offset;
    else if (direction == UP) y -= offset;
    else if (direction == DOWN) y += offset;
}

void point::Draw()
{
    COORD position;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(console, position);
    std::cout << sym;
}

void point::Clear()
{
    sym = ' ';
    Draw();
}

bool point::IsHit(point p)
{
    if (p.x == this->x && p.y == this->y)
        return true;
    else
        return false;
}