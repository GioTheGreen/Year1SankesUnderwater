#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "constants.h"
#include "collectables.h"
#include <iostream>
class snake
{
private:
	float posx;
	float posy;
	float peposx;
	float peposy;
	int survived = 0;
	int airLeft;
	int finalscore;
	int snakesize = 1;
	bool alive = false;
	bool ai = false;

	bool directionchanged = true;
	sf::Color headColour;
	directions headDir = directions::right;
	sf::RectangleShape head;
	std::list <sf::Vector2f> tailpos;
public:
	snake(float x, float y,sf::Color c);
	void update(float airlevel);
	void render(sf::RenderWindow& window);
	void setDir(directions d);
	directions getDir();
	void addTail(int n);
	void loseTail();
	std::list <sf::Vector2f> getTailpos();
	sf::Vector2f getPos();
	int getSnakeSize();
	void setAlive(bool a);
	bool getAlive();
	int getAirLeft();
	void setAirLeft(int a);
	int getSurvived();
	directions closestFruit(std::list<collectables> fruits, float airlevel);
};

