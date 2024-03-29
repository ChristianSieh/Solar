 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description:    Header for the moon class
 ************************************************************************/#ifndef MOON_H
#define MOON_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>

#include "Orb.h"

using namespace std;

class Moon: public Orb
{
    protected:
	float pradius;
	float pdistance;
	float pyear;
        float pday;
	
    public:
	//constructor 
	Moon( float r = 0.0, float di = 0.0, float y = 0.0, float da = 0.0, string n = "null", string i = "null" , float c[4] = (float*)BlueA, float pr =0.0, float pd = 0.0, float py = 0.0, float pda = 0.0 );
	~Moon();
	void drawOrbit() const;
        void drawWireFrame(double day, double year, float wireframe) const;
	void drawSolid(double day, double year) const;
	int drawImg(double day, double year) const;

};


#endif
