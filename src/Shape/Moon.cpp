 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description:   Moon class handles function related to moon objects
 ************************************************************************/
#include "Moon.h"

/************************************************************************
   Function: Moon Constructor
   Author: Charles Bonn and Christian Sieh
   Description: the constructor for the moon class
   Parameters:
	float r - radius
	float di - distance
	float y - total year
	float da - total day
	string n - name 
	string i - image name
 ************************************************************************/
Moon::Moon( float r, float di, float y, float da, string n, string i, float c[4], float pr, float pd, float py, float pda)
{
    radius = r / 1000;
    distance = (di*.5) + 10 ;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
    type = "Moon";
    copy(c, c + 4, color);
    object = gluNewQuadric();
    gluQuadricNormals( object, GLU_SMOOTH );

    pradius = pr / 1000;
    pdistance = ( pd * .5 )  + 40;
    pyear = py;
    pday = pda;
}

/************************************************************************
   Function: moon deconstructor 
   Author: Charles Bonn and Christain Sieh
   Description: deconstructor for the moon class
   Parameters:
 ************************************************************************/
Moon::~Moon()
{
}

void Moon::drawOrbit() const
{
    glPushMatrix();
    glTranslatef( -distance, 0.0, 0.0 );
    glColor3fv( color );
    glPopMatrix();
}

/************************************************************************
   Function: drawWireFrame
   Author: Charles Bonn and Christian Sieh
   Description: draws the wireframe
   Parameters:
 ************************************************************************/
void Moon::drawWireFrame( double day, double year, float wireframe) const
{
    GLfloat mat_shininess = { 20.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); 

    //set color
    glPushMatrix();
    glRotatef( 360 * fmod(year,pyear) / pyear, 0.0, 0.0, 1.0);
    glTranslatef( pdistance, 0.0,  0.0 );

    //glPushMatrix();
    glRotatef( 360 * 12 * fmod( day, totalYear)  / totalYear, 0.0, 0.0, 1.0);
    glTranslatef( distance , 0.0, 0.0 );
    glutWireSphere( radius, wireframe, wireframe );
    glPopMatrix();
}

 /************************************************************************
   Function: drawSolid
   Author: Charles Bonn and Christian Sieh
   Description: draws a solid planet
   Parameters:
 ************************************************************************/
void Moon::drawSolid(double day, double year) const
{
    glDisable( GL_DEPTH_TEST );

    GLfloat mat_shininess = { 20.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); 

    //set color
    glPushMatrix();
    glRotatef( 360 * fmod(year,pyear) / pyear, 0.0, 0.0, 1.0);
    glTranslatef( pdistance, 0.0,  0.0 );

    //glPushMatrix();
    glRotatef( 360 * 12 * fmod( day, totalYear)  / totalYear, 0.0, 0.0, 1.0);
    glTranslatef( distance , 0.0, 0.0 );
    glutSolidSphere( radius, 50, 50 );
    glPopMatrix();
}

 /************************************************************************
   Function: drawImg
   Author: Charles Bonn and Christian Sieh
   Description: draws the textmaped image
   Parameters:
 ************************************************************************/
int Moon::drawImg(double day, double year) const
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
    
    //set color
    glPushMatrix();
    glRotatef( 360 * fmod(year,pyear) / pyear, 0.0, 0.0, 1.0);
    glTranslatef( pdistance, 0.0,  0.0 );

    //glPushMatrix();
    glRotatef( 360 * 12 * fmod( day, totalYear)  / totalYear, 0.0, 0.0, 1.0);
    glTranslatef( distance , 0.0, 0.0 );
    glPopMatrix(); 

    return 0;
}

