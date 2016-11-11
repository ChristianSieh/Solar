
#include "Orb.h"

Orb::Orb(float r, float di, float y, float da, string n, string i)
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

Orb::~Orb()
{
}

void Orb::drawWireFrame() const
{
    string color = "Yellow";    
    //set color
    glColor3fv(Yellow);
    // Translate Sphere to location
    glTranslatef( distance, 0.0, 0.0 );
    // draw Sphere (radius, slices, stacks)
    glutWireSphere( radius, 15, 15 );
    glFlush();    
}

void Orb::drawSolid() const
{
   cerr << "solid orb" << endl;
}

void Orb::drawImg() const
{
   cerr << " draw img" << endl;
}

void Orb::printAll() const
{
    cerr << "orb" << endl;
}

void Orb::printDate() const 
{
   cerr << "date" << endl;
}

void Orb::printRadius() const
{
    cerr << "radius: " << radius << endl;
}

void Orb::printDistance() const
{
    cerr << "distance" << endl;
}

