 /************************************************************************
   Program: Solar  
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description:   Orb class is derived from shape and sets up functions
            that will be shared by all orbs such as planets, moons, and
            the sun
 ************************************************************************/
#include "Orb.h"

 /************************************************************************
   Function: Orb constructor
   Author: Charles Bonn and Christian Sieh
   Description: constructor for the orb class
   Parameters:
	float r - radius
	float di - distance
	float y - totalyear
	float da - total day
	string n - name of the orb
	string i - name of the image
 ************************************************************************/
Orb::Orb(float r, float di, float y, float da, string n, string i)
{
	radius = r;
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
}

 /************************************************************************
   Function: orb deconstructor
   Author: Charles Bonn and Christian Sieh
   Description: deconstructor
   Parameters:
 ************************************************************************/
Orb::~Orb()
{
}

 /************************************************************************
   Function: translate
   Author: Charles Bonn and Christian Sieh
   Description: translates orbs position
   Parameters:
 ************************************************************************/
void Orb::translate() const
{
   cerr << " translate " << endl;
}

 /************************************************************************
   Function: rotate
   Author: Charles Bonn and Christian Sieh
   Description: rotates orb
   Parameters:
 ************************************************************************/
void Orb::rotate() const
{
    //glRotatef(20.0, 0.0 , 1.0, 0.0);
}

 /************************************************************************
   Function: drawdraw
   Author: Charles Bonn and Christain Sieh
   Description: draws name above the orb
   Parameters:
 ************************************************************************/
void Orb::draw(int i, double day, double year, float wireframe) const
{
    glPushMatrix();
    //glLoadIdentity();
    switch( i )
    {
	case 1:
             drawWireFrame(day, year, wireframe);	
             break;
	case 2:
             drawSolid(day, year);
             break;
        case 3:
            drawImg(day, year);
            break;
    }
    drawOrbit();
    
    glPopMatrix();
    drawName();
}



 /************************************************************************
   Function: drawName
   Author: Charles Bonn and Christain Sieh
   Description: draws name above the orb
   Parameters:
 ************************************************************************/
void Orb::drawName() const
{
    glPushMatrix();
    unsigned char temp[20];
    strcpy( (char*) temp, name.c_str() );
    glRasterPos3f( distance, radius, radius + 5 );
    glScalef( .15, .15, 1 );
    glColor3fv( White );
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_10, temp);
    glPopMatrix();
}


 /************************************************************************
   Function: printAll
   Author: Charles Bonn and Christian Sieh
   Description: calls all print functions
   Parameters:
 ************************************************************************/
void Orb::printAll() const
{
    printDate();
    printRadius();
    printDistance();
}

 /************************************************************************
   Function: printName
   Author: Charles Bonn and Christian Sieh
   Description: prints the name of the orb
   Parameters:
 ************************************************************************/
void Orb::printName() const
{
    cerr << "name: " << name << endl;
}

 /************************************************************************
   Function: printDate
   Author: Charles Bonn and Christian Sieh
   Description: prints the date of the orb
   Parameters:
 ************************************************************************/
void Orb::printDate() const 
{
   cerr << "date: " << totalYear <<  endl;
   cerr << "day: " << totalDay << endl;
}

 /************************************************************************
   Function: printRadius
   Author: Charles Bonn and Christian Sieh
   Description: prints the radius of the orb
   Parameters:
 ************************************************************************/
void Orb::printRadius() const
{
    cerr << "radius: " << radius << endl;
}

 /************************************************************************
   Function: printDistance
   Author: Charles Bonn and Christian Sieh
   Description: prints the distance of the orb
   Parameters:
 ************************************************************************/
void Orb::printDistance() const
{
    cerr << "distance: " << distance << endl;
}

