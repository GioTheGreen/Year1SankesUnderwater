#include "graphNode.h"

graphNode::graphNode(float x, float y)
{
	X = x;
	Y = y;
}

void graphNode::addChild(graphNode* a)
{
	childran.push_back(a);
}

void graphNode::changeData(itmes d)
{
	data = d;
}

