 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description:    Header file for the orb class
 ************************************************************************/
#ifndef ORB_H
#define ORB_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
using namespace std;

#include "Shape.h"

class Orb : public Shape
{
    protected:
	float radius;

    public:
	//constructor 
	Orb( float r = 1.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	~Orb();
        void translate() const;
	void rotate() const;
	void draw( int i, double day, double year, float wireframe ) const ;
	void drawName() const;
        void printAll() const;
	void printName() const;
	void printDate() const;
	void printRadius() const;
	void printDistance() const;
        void pushV( Shape* obj ) const;
};


#endif
