 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Date:
   Description:    header class for planet object
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/
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
	Planet( float r = 0.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null", float c[4] = (float*)BlueA);
	~Planet();
	void drawOrbit() const;
	void drawWireFrame(double day, double year, float wireframe) const;
	void drawSolid(double day, double year) const;
	int drawImg(double day, double year) const;
};


#endif
