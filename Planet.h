#ifndef PLANET_H
#define PLANET_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
using namespace std;

#include "Orb.h"

class Planet : public Orb
{

    public:
	//constructor 
	Planet( float r = 0.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null");
	~Planet();
};


#endif
