#include "Sun.h"

Sun::Sun( float r, float d, string n, string i )
{
    radius = r;
    distance = 0.0;
    totalYear = 0.0;
    totalDay = d;
    name = n;
    img = i;
}

Sun::~Sun()
{
}

void Sun::drawWireFrame() const 
{
    glColor3fv(Yellow);
    glRotatef( 90.0, 0.0, 0.0, 0.0);
    glTranslatef( distance, 0.0, 0.0 );
    glutWireSphere( radius, 1500000, 1500000);
}
