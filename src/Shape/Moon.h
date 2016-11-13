#ifndef MOON_H
#define MOON_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
using namespace std;

class Moon
{
    protected:
	float radius;
	float distance;
	float totalYear;
	float totalDay;
	string name;
	string img;

    public:
	//constructor 
	Moon( float r = 0.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	~Moon();
};


#endif
