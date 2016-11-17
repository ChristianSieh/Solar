
#include "Planet.h"

Planet::Planet( float r, float di, float y, float da, string n, string i, float c[3])
{
    radius = r / 1000;
    distance = di * .5 ;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i;
    type = "Planet"; 
    copy(c, c + 3, color);
}

Planet::~Planet()
{
}
