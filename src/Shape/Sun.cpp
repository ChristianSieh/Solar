 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description: Sun object class which handles code directly related
            to the sun
 ************************************************************************/
#include "Sun.h"

 /************************************************************************
   Function: sun constructor
   Author: Charles Bonn and Christian Sieh
   Description: sun constructor
   Parameters:
	float r - radius
	float d - distance
	string n - name
	string i - image name
	float c[] - color
 ************************************************************************/
Sun::Sun( float r, float d, string n, string i, float c[4] )
{
    radius = r;
    distance = 0.0;
    totalYear = 0.0;
    totalDay = d;
    name = n;
    img = i;
    type = "Sun";
    copy(c, c + 4, color);
    object = gluNewQuadric();
    gluQuadricNormals( object, GLU_SMOOTH );
}

 /************************************************************************
   Function: sun deconstructor
   Author: Charles Bonn and Christian Sieh
   Description: sun deconstructor
   Parameters:
 ************************************************************************/
Sun::~Sun()
{
}


 /************************************************************************
   Function: drawOrbit
   Author: Charles Bonn and Christian Sieh
   Description: draws a wireframe orb
   Parameters:
 ************************************************************************/
void Sun::drawOrbit() const
{
}


 /************************************************************************
   Function: drawWireframe
   Author: Charles Bonn and Christian Sieh
   Description: draws a wireframe orb
   Parameters:
 ************************************************************************/
void Sun::drawWireFrame(double day, double year, float wireframe) const
{
    // specify material reflectivity
    GLfloat mat_diffuse[] = { 1.0, 0.549019608, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess = { 100.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); 

    //set color
    glRotatef( 160.0, 0.0, 1.0, 0.0 );
    glTranslatef( distance, 0.0, 0.0 );

    
    // draw Sphere (radius, slices, stacks)
    glutWireSphere( radius, wireframe, wireframe );
}

 /************************************************************************
   Function: drawSolid
   Author: Charles Bonn and Christian Sieh
   Description: draws a solid orb
   Parameters:
 ************************************************************************/
void Sun::drawSolid(double day, double year) const
{
    // specify material reflectivity
    //GLfloat mat_ambient[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 0.549019608, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess = { 100.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); 

    //set color
    //glColor3fv(color);
    glTranslatef( distance, 0.0, 0.0 );

    // draw Sphere (radius, slices, stacks)
    glutSolidSphere( radius, 50, 50 );
}

 /************************************************************************
   Function: drawImg
   Author: Charles Bonn and Chrisitan Sieh
   Description: draws a textmap img
   Parameters:
 ************************************************************************/
int Sun::drawImg(double day, double year) const
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

    // Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
    // Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    
    gluQuadricTexture( object, GL_TRUE );
    
    gluSphere(object, radius, 50, 50);

    return 0;
}

