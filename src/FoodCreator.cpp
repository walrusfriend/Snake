#include "point.h"
#include "FoodCreator.h"
#include <math.h>
#include <ctime>

point FoodCreator::CreateFood()
{
	srand(time(0));
	int x = rand() % (mapWidht - 3) + 2;
	int y = rand() % (mapHeight - 3) + 2;
	return point(x, y, sym);
}