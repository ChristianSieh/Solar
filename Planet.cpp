
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

void Shape::printDate()
{
    cerr << "Planet: " << name << " has the current date of: \n" ;
    cerr << "\t Day: " << currday << "/" << totalDay << endl;
    cerr << "\t Year: " << currYear << "/" << totalYear << end;
}

void Shape::printRadius()
{
    cerr << "Planet: " << name << " has a radius of: " << radius << endl;
}

void Shape::printDistance()
{
    cerr << "Planet: " << name << " has a distance of: " << distance << endl;
}

