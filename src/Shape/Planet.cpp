
#include "Planet.h"

Planet::Planet( float r, float di, float y, float da, string n, string i)
{
    radius = r;
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
}

Planet::~Planet()
{
}



