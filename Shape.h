#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
using namespace std;

class Shape
{
    protected:
	float distance;
	float totalYear;
	float currYear;
	float totalDay;
	float currDay;
	string name;
	string img;

    public:
	//constructor 
	Shape( float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	virtual ~Shape();
	virtual void drawWireFrame() const = 0;
	virtual void drawSolid() const = 0;
	virtual void drawImg() const = 0;
	virtual void printAll() const = 0;
	virtual void printDate() const = 0;
	virtual void printDistance() const = 0;
};


#endif
