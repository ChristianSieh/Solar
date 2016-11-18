 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Date:
   Description:   Moon class handles function related to moon objects
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/
#include "Moon.h"

/************************************************************************
   Function: Moon Constructor
   Author: Charles Bonn and Christian Sieh
   Description: the constructor for the moon class
   Parameters:
	float r - radius
	float di - distance
	float y - total year
	float da - total day
	string n - name 
	string i - image name
 ************************************************************************/
Moon::Moon( float r, float di, float y, float da, string n, string i)
{
    radius = r;
    distance = di;
    totalYear = y;
    totalDay = da;
    name = n;
    img = i; 
    type = "Moon";
}

/************************************************************************
   Function: moon deconstructor 
   Author: Charles Bonn and Christain Sieh
   Description: deconstructor for the moon class
   Parameters:
 ************************************************************************/
Moon::~Moon()
{
}


