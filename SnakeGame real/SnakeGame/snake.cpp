#include "snake.h"

snake::snake(float x, float y, sf::Color c)
{
	posx = x;
	posy = y;
	peposx = x;
	peposy = y;
	headColour = c;
	airLeft = maxAir;
	alive = true;
}

void snake::update(float airlevel)
{
	if (alive)
	{
		survived++;
		peposx = posx;
		peposy = posy;
		if (headDir == directions::up)
		{
			posy -= snakeSize;
		}
		else if (headDir == directions::down)
		{
			posy += snakeSize;
		}
		else if (headDir == directions::left)
		{
			posx -= snakeSize;
		}
		else
		{
			posx += snakeSize;
		}
		head.setPosition(posx, posy);
		if (snakesize > 1)
		{
			tailpos.back().x = peposx;
			tailpos.back().y = peposy;
			tailpos.push_front(tailpos.back());
			tailpos.pop_back();
		}
		directionchanged = true;
		airLeft--;
		if (airLeft < 0)
		{
			airLeft = 0;
			loseTail();
		}
		if (posy < airlevel)
		{
			if (headDir == directions::up)
			{
				if ((snakeSize + posx ) > (width - (2*snakeSize) - posx))
				{
					headDir = directions::left;
				}
				else
				{
					headDir = directions::right;
				}
			}
			else
			{
				headDir = directions::down;
			}
		}
	}
}

void snake::render(sf::RenderWindow& window)
{
	if (alive)
	{
		sf::RectangleShape head(sf::Vector2f(snakeSize, snakeSize));
		head.setFillColor(headColour);
		//head.setOrigin(snakeSize / 2, snakeSize / 2);
		head.setPosition(posx, posy);
		window.draw(head);
		std::list <sf::RectangleShape> tails;
		std::list<sf::Vector2f>::iterator currenttail = tailpos.begin();
		std::list<sf::Vector2f>::iterator endtail = tailpos.end();
		for (; currenttail != endtail; ++currenttail)
		{
			tails.push_back(sf::RectangleShape(sf::Vector2f(snakeSize - 5, snakeSize - 5)));
			tails.back().setFillColor(headColour);
			//tails.back().setOrigin((snakeSize-5) / 2, (snakeSize - 5) / 2);
			tails.back().setPosition((*currenttail).x + 2.5, (*currenttail).y + 2.5);
			window.draw(tails.back());
		}
	}
}

void snake::setDir(directions d)
{
	
	if (directionchanged)
	{
		if (((headDir == directions::up or headDir == directions::down) and (d == directions::left or d == directions::right)) or ((headDir == directions::left or headDir == directions::right) and (d == directions::up or d == directions::down)))
		{
			headDir = d;
		}
		directionchanged = false;
	}
	
}

directions snake::getDir()
{
	return directions(headDir);
}

void snake::addTail(int n)
{
	for (size_t i = 0; i < n; i++)
	{
		snakesize++;
		if (snakesize == 2)
		{
			tailpos.push_back(sf::Vector2f(peposx, peposy));
		}
		else
		{
			tailpos.push_back(tailpos.back());
		}
	}
}

void snake::loseTail()
{
	if (snakesize > 1)
	{
		snakesize--;
		tailpos.pop_back();
	}
	else
	{
		setAlive(false);
	}
}


std::list<sf::Vector2f> snake::getTailpos()
{
	return std::list<sf::Vector2f>(tailpos);
}

sf::Vector2f snake::getPos()
{
	return sf::Vector2f(posx, posy);
}

int snake::getSnakeSize()
{
	return snakesize;
}

void snake::setAlive(bool a)
{
	finalscore = snakesize - 1;
	alive = a;
}

bool snake::getAlive()
{
	return alive;
}

int snake::getAirLeft()
{
	return airLeft;
}

void snake::setAirLeft(int a)
{
	airLeft = a;
}

int snake::getSurvived()
{
	return survived;
}

directions snake::closestFruit(std::list<collectables> fruits, float airlevel)
{
	if ((airLeft+5) <= airlevel/3)
	{
		if (headDir == directions::down)
		{
			return directions::right;
		}
		return directions::up;
	}
	collectables closest;
	int dis = INT_MAX;
	for (auto currentFruit : fruits)
	{
		int cDis = (fabsf((posx - currentFruit.getPos().x)) + fabsf((posy - currentFruit.getPos().y)));
		if (currentFruit.getLive() and (dis > cDis))
		{
			closest = currentFruit;
			dis = cDis;
		}
	}
	if (fabsf((posx - closest.getPos().x)) >= fabsf((posy - closest.getPos().y)))
	{
		if ((posx - closest.getPos().x) < 0)
		{
			if (headDir == directions::left)
			{
				return directions::up;
			}
			return directions::right;
		}
		if (headDir == directions::right)
		{
			return directions::up;
		}
		return directions::left;
	}
	else
	{
		if ((posy - closest.getPos().y) < 0)
		{
			if (headDir == directions::up)
			{
				return directions::right;
			}
			return directions::down;
		}
		if (headDir == directions::down)
		{
			return directions::right;
		}
		return directions::up;
	}
	
}


