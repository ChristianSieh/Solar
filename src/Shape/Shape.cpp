
#include "Shape.h"

Shape::Shape( float di, float y, float da, string n, string i)
{
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i;
    type = "Shape"; 
}

Shape::~Shape()
{
}


