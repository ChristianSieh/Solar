 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Date: 
   Description:    Sun object
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/
#ifndef SUN_H
#define SUN_H

#include "Orb.h"

class Sun : public Orb
{
    public:
	Sun( float r = 1.0, float d = 0.0, string n = "null", string i = "null", float c[3] = (float*)Yellow  );
	~Sun();
	void drawOrbit() const;
	void drawWireFrame(double day, double year, float wireframe) const;
	void drawSolid(double day, double year) const;
	int drawImg(double day, double year) const;
};

#endif
