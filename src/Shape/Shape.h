#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
using namespace std;


const float White[]   = { 1.0, 1.0, 1.0 };
const float Yellow[]  = { 1.0, 1.0, 0.0 };
const float Red[]     = { 1.0, 0.0, 0.0 };
const float Green[]   = { 0.0, 1.0, 0.0 };
const float Blue[]    = { 0.0, 0.0, 1.0 };
const float Magenta[] = { 1.0, 0.0, 1.0 };
const float Cyan[]    = { 0.0, 1.0, 1.0 };

class Shape
{
    protected:
	float distance;
	float totalYear;
	float currYear;
	float totalDay;
	string name;
	string img;
	string type;

    public:
	//constructor 
	Shape( float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	virtual ~Shape();
        virtual void translate() const = 0;
        virtual void rotate() const = 0;
	virtual void draw() const = 0;
	virtual void drawWireFrame() const = 0;
	virtual void drawSolid() const = 0;
	virtual void drawImg() const = 0;
	virtual void printAll() const = 0;
	virtual void printName() const = 0;
	virtual void printDate() const = 0;
	virtual void printRadius() const = 0;
	virtual void printDistance() const = 0;
};


#endif
