
#include "Planet.h"

Planet::Planet( float r, float di, float y, float da, string n, string i)
{
    radius = r;
    distance = di;
    totalYear = y;
    currDay = 0.0;
    totalDay = da;
    currDay = 0.0;
    name = n;
    img = i; 
}

Planet::~Planet()
{
}

void Planet::drawWireFrame()
{
}

void Planet::drawSolid()
{
}

void Planet::drawImg()
{
}


