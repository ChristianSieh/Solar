
#include "Orb.h"

Orb::Orb(float r, float di, float y, float da, string n, string i)
{
    radius = r;
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
}

Orb::~Orb()
{
}

void Orb::translate() const
{
   cerr << " translate " << endl;
}

void Orb::rotate() const
{
    cerr << " rotate " << endl;
}

void Orb::draw() const
{
    cerr << " draw " << endl;
}

void Orb::printAll() const
{
    printDate();
    printRadius();
    printDistance();
}

void Orb::printName() const
{
    cerr << "name: " << name << endl;
}
void Orb::printDate() const 
{
   cerr << "date: " << totalYear <<  endl;
}

void Orb::printRadius() const
{
    cerr << "radius: " << radius << endl;
}

void Orb::printDistance() const
{
    cerr << "distance: " << distance << endl;
}

