#ifndef PLANET_H
#define PLANET_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
using namespace std;

class Planet
{
    protected:
	float radius;
	float distance;
	float year;
	float day;
	string name;
	string img;

    public:
	//constructor 
	Planet( float r = 0.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	~Planet();
	void printDate();
	void printRadius();
	void printDistance();
};


#endif
