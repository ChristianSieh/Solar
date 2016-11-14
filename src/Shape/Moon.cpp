
#include "Moon.h"

Moon::Moon( float r, float di, float y, float da, string n, string i)
{
    radius = r;
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
    type = "Moon";
}

Moon::~Moon()
{
}


