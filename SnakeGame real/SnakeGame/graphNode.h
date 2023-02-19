#pragma once
#include "collectables.h"
#include <list>

class graphNode
{
private:
	itmes data{ itmes::null};
	std::vector<graphNode*> childran;
	float X;
	float Y;
; public:
	graphNode(float x, float y);
	void addChild(graphNode* a);
	void changeData(itmes d);
	sf::Vector2f getplace();
	int getnumchilderen();
};

