#include "Sun.h"

Sun::Sun( float r, float d, string n, string i, float color[3] )
{
    radius = r;
    distance = 0.0;
    totalYear = 0.0;
    totalDay = d;
    name = n;
    img = i;
    type = "Sun";
    color = color;
}

Sun::~Sun()
{
}

void Sun::drawWireFrame() const 
{

    glColor3fv(color);
    //glRotatef( 90.0, 0.0, 0.0, 0.0);
    glTranslatef( distance, 0.0, 0.0 );
    glutWireSphere( radius, 15, 15);

}
