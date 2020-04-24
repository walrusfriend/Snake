#include <list>

class point;

class Walls
{
    std::list<Figure> wallList;
public:

    Walls(int mapWidth, int mapHeight)
    {
        HorizontalLine topLine(0, mapWidth - 2, 0, '+');
        HorizontalLine botLine(0, mapWidth - 2, mapHeight - 1, '+');
        VerticalLine leftLine(0, mapHeight - 1, 0, '+');
        VerticalLine rightLine(0, mapHeight - 1, mapWidth - 2, '+');
        
        wallList.push_back(topLine);
        wallList.push_back(botLine);
        wallList.push_back(leftLine);
        wallList.push_back(rightLine);
    }

    void Draw();
    bool IsHit(Figure figure);
};

