#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
class collectables
{
private:
	int score;
	float posx;
	float posy;
	sf::RectangleShape fruit;
	sf::Color colour;
	bool live{false};
public:
	collectables(int s);
	collectables();
	void spwan(float x, float y);
	void kill();
	int getScore();
	bool getLive();
	sf::Vector2f getPos();
	void render(sf::RenderWindow& window);
};

