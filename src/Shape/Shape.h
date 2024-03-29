 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description: Header file for shape class
 ************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;


// color constants
const float White[]   = { 1.0, 1.0, 1.0 };
const float Yellow[]  = { 1.0, 1.0, 0.0 };
const float Red[]     = { 1.0, 0.0, 0.0 };
const float Green[]   = { 0.0, 1.0, 0.0 };
const float Blue[]    = { 0.0, 0.0, 1.0 };
const float Magenta[] = { 1.0, 0.0, 1.0 };
const float Cyan[]    = { 0.0, 1.0, 1.0 };

const float YellowA[] = { 1.0, 1.0, 0.0, 1.0 };
const float BlueA[]    = { 0.0, 0.0, 1.0, 1.0 };

class Shape
{
    private:
    short readShort( FILE* infile ) const;
    int readLong( FILE* infile ) const;
    void skipChars( FILE* infile, int numChars ) const;
    inline int GetNumBytesPerRow( int NumCols ) const;

    protected:
	float distance;
	float totalYear;
	float currYear;
	float totalDay;
	string img;
	string type;
    bool LoadBmpFile( const char* filename, int &NumRows, int &NumCols, unsigned char* &ImagePtr ) const;

    public:
	GLUquadricObj* object;
	string name;
	float color[4];
	//constructor 
	Shape( float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null", float c[4] = (float*)(YellowA));
	virtual ~Shape();
        virtual void translate() const = 0;
        virtual void rotate() const = 0;
	virtual void draw( int i , double day, double year, float wireframe ) const = 0;
	virtual void drawOrbit() const = 0;
	virtual void drawWireFrame(double day, double year,float wireframe) const = 0;
	virtual void drawSolid(double day, double year) const = 0;
	virtual int drawImg(double day, double year) const = 0;
	virtual void drawName() const = 0;
	virtual void printAll() const = 0;
	virtual void printName() const = 0;
	virtual void printDate() const = 0;
	virtual void printRadius() const = 0;
	virtual void printDistance() const = 0;
};


#endif
