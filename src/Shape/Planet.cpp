 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date:
   Description:    Planet Class
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
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
    gluQuadricDrawStyle( object, GLU_LINE );
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
   Function: draw
   Author:
   Description: draws the orbit path of the planet
   Parameters:
 ************************************************************************/
/*void Planet::draw() const
{
    glPushMatrix();
    drawWireFrame();
    drawOrbit();
    glPopMatrix();
} */

/************************************************************************
   Function: drawOrbit
   Author:
   Description: draws the orbit path of the planet
   Parameters:
 ************************************************************************/
void Planet::drawOrbit() const
{
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
void Planet::drawWireFrame() const
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
    glRotatef( 10.0, 0.0, 1.0, 0.0);
    glTranslatef( distance, 0.0,  0.0 );
    //draw Sphere (radius, slices, stacks)
    glutWireSphere( radius, 50, 50 );
}

 /************************************************************************
   Function: drawSolid
   Author: Charles Bonn and Christian Sieh
   Description: draws a solid planet
   Parameters:
 ************************************************************************/
void Planet::drawSolid() const
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
    //glColor3fv(color);
    glTranslatef( distance, 0.0, 0.0 );
    //draw Sphere (radius, slices, stacks)
    glutSolidSphere( radius, 50, 50 );
}

 /************************************************************************
   Function: drawImg
   Author: Charles Bonn and Christian Sieh
   Description: draws the textmaped image
   Parameters:
 ************************************************************************/
int Planet::drawImg() const
{
    // read texture map from BMP file
    // Ref: Buss, 3D Computer Graphics, 2003.

    int nrows, ncols;
    unsigned char* image;
    if ( !LoadBmpFile( img.c_str(), nrows, ncols, image ) )
    {
        std::cerr << "Error: unable to load " << img << std::endl;
        return -1;
    }

    // Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
    // Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, ncols, nrows, GL_RGB, GL_UNSIGNED_BYTE, image );
    
    delete [] image;

    glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );

    return 0;
}
