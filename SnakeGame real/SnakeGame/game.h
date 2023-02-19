#pragma once
#include <iostream>
#include "snake.h"
#include "constants.h"
#include "graphNode.h"
// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>

class game
{
public:
	bool player1 = false;
	bool player2 = false;
	int ai = 0;
	int numOfSsnakes;
	int numOfAlive;
	float gamespeed;
	int winner;

	void GameOver(std::vector<snake> s, int alive, int start);
	game();
	void run(bool p1, bool p2, int numAi, float speed);
	
};

