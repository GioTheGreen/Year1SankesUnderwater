#include "collectables.h"

collectables::collectables(int s)
{
	score = s;
	fruit.setSize(sf::Vector2f(snakeSize - 5, snakeSize - 5));
	//fruit.setOrigin((snakeSize - 5) / 2, (snakeSize - 5) / 2);
	if (score == 1)
	{
		fruit.setFillColor(sf::Color::Green);
	}
	else if (score == 2)
	{
		fruit.setFillColor(sf::Color::Cyan);
	}
	else
	{
		fruit.setFillColor(sf::Color::Magenta);
	}
}

collectables::collectables()
{
	posx = INT_MAX;
	posy = INT_MAX;
	live = true;
}

void collectables::spwan(float x, float y)
{
	live = true;
	posx = x;
	posy = y;
}

void collectables::kill()
{
	live = false;
}

int collectables::getScore()
{
	return score;
}

bool collectables::getLive()
{
	return live;
}

sf::Vector2f collectables::getPos()
{
	return sf::Vector2f(posx, posy);
}

void collectables::render(sf::RenderWindow& window)
{
	fruit.setPosition(posx +2.5, posy +2.5);
	window.draw(fruit);
}
