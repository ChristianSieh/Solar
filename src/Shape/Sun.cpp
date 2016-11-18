#include "Sun.h"

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
}

Sun::~Sun()
{
}

void Sun::drawWireFrame() const
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
    glutWireSphere( radius, 30, 30 );
}

void Sun::drawSolid() const
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
    glutSolidSphere( radius, 30, 30 );
}

int Sun::drawImg() const
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
