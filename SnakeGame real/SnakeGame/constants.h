#pragma once
enum class directions
{
	up,
	down,
	left,
	right
};
enum class Gamestate              //never got implemented
{
	menu,       //Main Menu
	play,       //Player vs Ai
	pvp,        //Player vs Player
	endscreen,  //End of the game
	restarting, //Resetting everything

};
enum class itmes
{
	null,
	water,
	wall,
	fruit,
	snake,
	air
};

constexpr int snakeSize = 25;
constexpr int maxAir = 100;                // 100 seems good
constexpr int gameTime = 90;               // 90 secounds in game
constexpr int width = 34 * snakeSize;    //34      30 play area + 2 for the walls +2 for splitting up the snake info
constexpr int height = 32 * snakeSize;    //32     30 play area + 2 for the walls
constexpr int infoHeight = 7 * snakeSize;  //7     see the paint sheat for reference