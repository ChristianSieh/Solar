
#include "Planet.h"

Planet::Planet( float r, float di, float y, float da, string n, string i)
{
    radius = r;
    distance = di * 1000000;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
}

Planet::~Planet()
{
}

void Planet::drawWireFrame() const
{
    glColor3fv(White);
    //glRotatef( 90.0, 0.0, 0.0, 0.0 );
    glTranslatef( distance, 0.0, 0.0 );
    glutWireSphere( radius, 15, 15 );
}


