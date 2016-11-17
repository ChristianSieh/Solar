
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

void Orb::translate() const
{
   cerr << " translate " << endl;
}

void Orb::rotate() const
{
    cerr << " rotate " << endl;
}

void Orb::draw() const
{
    cerr << " draw " << endl;
}

void Orb::drawWireFrame() const
{
    //set color
    glColor3fv(White); // defautling to white
    glTranslatef( distance, 0.0, 0.0 );
    // draw Sphere (radius, slices, stacks)
    glutWireSphere( radius, 15, 15 );
}

void Orb::drawSolid() const
{
    //set color
    glColor3fv(White); // defautling to white
    glTranslatef( distance, 0.0, 0.0 );
    // draw Sphere (radius, slices, stacks)
    glutSolidSphere( radius, 15, 15 );
}

int Orb::drawImg() const
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

void Orb::printAll() const
{
    printDate();
    printRadius();
    printDistance();
}

void Orb::printName() const
{
    cerr << "name: " << name << endl;
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

