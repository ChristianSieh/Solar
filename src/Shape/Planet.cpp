
#include "Planet.h"

Planet::Planet( float r, float di, float y, float da, string n, string i)
{
    radius = r / 1000;
    distance = di * .5 ;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i;
    type = "Planet"; 
}

Planet::~Planet()
{
}

void Planet::drawWireFrame() const
{
   glPushMatrix();

    glColor3fv(White);
    //glRotatef( 90.0, 0.0, 0.0, 0.0 );
    glTranslatef( distance, 0.0, 0.0 );
    glutWireSphere( radius, 15, 15 );

    glPopMatrix();
}

void Planet::drawSolid() const
{
    glPushMatrix();
    glColor3fv(White);
    glTranslatef( distance, 0.0, 0.0 );
    glutSolidSphere( radius, 15, 15 );

    glPopMatrix();
}
