
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
void Planet::printDate()
{
    cerr << "Planet: " << name << " has the current date of: \n" ;
    cerr << "\t Day: " << currDay << "/" << totalDay << endl;
    cerr << "\t Year: " << currYear << "/" << totalYear << endl;
}

void Planet::printRadius()
{
    cerr << "Planet: " << name << " has a radius of: " << radius << endl;
}

void Planet::printDistance()
{
    cerr << "Planet: " << name << " has a distance of: " << distance << endl;
}

