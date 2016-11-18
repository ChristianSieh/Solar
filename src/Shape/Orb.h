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
    void draw() const;
    void printAll() const;
	void printName() const;
	void printDate() const;
	void printRadius() const;
	void printDistance() const;
};


#endif
