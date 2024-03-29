 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description: The planet class inherits the orb class and deals
            specifically with code related to the planets
 ************************************************************************/

#include "Planet.h"

 /************************************************************************
   Function: Planet Constructor
   Author: Charles Bonn and Christian Sieh
   Description: Constructor for planet
   Parameters:
	float r - float
	float di - distance
	float y - total year
	float da - total year
	float c[] - color properties
 ************************************************************************/
Planet::Planet( float r, float di, float y, float da, string n, string i, float c[4])
{
    radius = r / 1000;
    distance = (di * .5) + 40 ;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i;
    type = "Planet"; 
    copy(c, c + 4, color);
    object = gluNewQuadric();
    gluQuadricNormals( object, GLU_SMOOTH );
}

 /************************************************************************
   Function: Planet deconstuctor
   Author: Charles Bonn and Christian Sieh
   Description: Planet deconstuctor
   Parameters:
 ************************************************************************/
Planet::~Planet()
{
}

/************************************************************************
   Function: drawOrbit
   Author:
   Description: draws the orbit path of the planet
   Parameters:
 ************************************************************************/
void Planet::drawOrbit() const
{
    gluQuadricDrawStyle( object, GLU_LINE );
    glPushMatrix();
    glTranslatef( -distance, 0.0, 0.0 ); 
    glColor3fv( color );
    gluCylinder( object, distance - .1, distance + .1, 0.0 , 10 * distance , 10 * distance );
    glPopMatrix();
}


 /************************************************************************
   Function: drawWireFrame
   Author: Charles Bonn and Christian Sieh
   Description: draws the wireframe
   Parameters:
 ************************************************************************/
void Planet::drawWireFrame( double day, double year, float wireframe) const
{
    // specify material reflectivity
    //GLfloat mat_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
    //GLfloat mat_diffuse[] = { 1.0, 0.549019608, 0.0, 1.0 };
    //GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess = { 20.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); 

    //set color
    glRotatef( 360 * fmod(year,totalYear) / totalYear, 0.0, 0.0, 1.0);
    glTranslatef( distance, 0.0,  0.0 );

    glPushMatrix();
    glRotatef( 360  * fmod( day, totalDay)  / totalDay, 0.0, 0.0, 1.0);
    glutWireSphere( radius, wireframe, wireframe );
    glPopMatrix();

/* 
    if( name.compare("Earth") == 0 )
    {
        glPushMatrix();
        glRotatef( 360 * fmod( day, 27.3 ) / 27.3, 0.0,0.0,1.0 );
        glTranslatef( (.384 *.5) +40, 0.0, 0.0 );
	glutWireSphere( .1738, 5.0, 5.0 );
	glPopMatrix();
    }
    else if( name.compare("Saturn") == 0 )
    {
    }
*/
}

 /************************************************************************
   Function: drawSolid
   Author: Charles Bonn and Christian Sieh
   Description: draws a solid planet
   Parameters:
 ************************************************************************/
void Planet::drawSolid(double day, double year) const
{
    glDisable( GL_DEPTH_TEST );

    GLfloat mat_shininess = { 20.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); 

    glRotatef( 360 * fmod(year,totalYear) / totalYear, 0.0, 0.0, 1.0);
    glTranslatef( distance, 0.0, 0.0 );
    glPushMatrix();
    glRotatef( 360  * fmod(day, totalDay) / totalDay, 0.0, 0.0, 1.0);
    glutSolidSphere( radius, 50, 50 );
    glPopMatrix();
}

 /************************************************************************
   Function: drawImg
   Author: Charles Bonn and Christian Sieh
   Description: draws the textmaped image
   Parameters:
 ************************************************************************/
int Planet::drawImg(double day, double year) const
{
    glEnable( GL_DEPTH_TEST );

    int nrows, ncols;
    unsigned char* imageData;
    if ( !LoadBmpFile( img.c_str(), nrows, ncols, imageData ) )
    {
        std::cerr << "Error: unable to load " << img << std::endl;
        return -1;
    }

    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, ncols, nrows, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );

    delete [] imageData;

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    
    gluQuadricDrawStyle( object, GLU_FILL );
    gluQuadricTexture( object, GL_TRUE );
    
    glRotatef( 360 * fmod(year,totalYear) / totalYear, 0.0, 0.0, 1.0);
    glTranslatef( distance, 0.0, 0.0 );
    glPushMatrix();
    glRotatef( 360  * fmod(day,totalDay) / totalDay, 0.0, 0.0, 1.0);
    gluSphere(object, radius, 50, 50);
    glPopMatrix(); 

    return 0;
}

