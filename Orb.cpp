
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

void Orb::drawWireFrame() const
{
    //set color
    glColor3fv(Yellow); // defautling to yellow
    //rotate around centerpoint
    //glRotatef( 360.0 * currDay / totalYear, 0.0, 1.0, 0.0) ;
    // Translate Sphere to location
    //glRotatef( 0.0, 0.0, 1.0, 0.0 );
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
    printDate();
    printRadius();
    printDistance();
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

