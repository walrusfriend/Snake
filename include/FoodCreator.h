#pragma once
class point;

class FoodCreator
{
	int mapWidht, mapHeight;
	char sym;

public:

	FoodCreator(int mapWidht, int mapHeight, char sym)
	{
		this->mapHeight = mapHeight;
		this->mapWidht = mapWidht;
		this->sym = sym;
	}
	
	point CreateFood();
};

