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
	Orb( float r = 0.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	~Orb();
	void drawWireFrame();
	void drawSolid();
	void drawImg();
        void printAll();
	void printDate();
	void printRadius();
	void printDistance();
};


#endif
