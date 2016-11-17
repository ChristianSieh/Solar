
#include "Planet.h"

Planet::Planet( float r, float di, float y, float da, string n, string i, float color[3])
{
    radius = 1; //r / 100;
    distance = di / 10 ;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i;
    type = "Planet"; 
    color = color;
}

Planet::~Planet()
{
}

void Planet::drawWireFrame() const
{
   glPushMatrix();

    glColor3fv(color);
    //glRotatef( 90.0, 0.0, 0.0, 0.0 );
    glTranslatef( distance, 0.0, 0.0 );
    glutWireSphere( radius, 15, 15 );

    glPopMatrix();
}

void Planet::drawSolid() const
{
    glPushMatrix();
    glColor3fv(color);
    glTranslatef( distance, 0.0, 0.0 );
    glutSolidSphere( radius, 15, 15 );

    glPopMatrix();
}
