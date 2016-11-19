 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christain Sieh
   Date: 11/18/16
   Description: Header file for gen.cpp
 ************************************************************************/
#ifndef GEN_H
#define GEN_H

#include <GL/freeglut.h>
#include <functional>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>

//shape class includes
#include "../Shape/Shape.h"
#include "../Shape/Orb.h"
#include "../Shape/Sun.h"
#include "../Shape/Planet.h"
#include "../Shape/Moon.h"

using namespace std;

/*********************** function prototypes ***************************/
void generate(vector<Shape*> &shapeList);
void genSun(vector<Shape*> &shapeList);
void genMercury(vector<Shape*> &shapeList);
void genVenus(vector<Shape*> &shapeList);
void genEarth(vector<Shape*> &shapeList);
void genMars(vector<Shape*> &shapeList);
void genJupiter(vector<Shape*> &shapeList);
void genSaturn(vector<Shape*> &shapeList);
void genUranus(vector<Shape*> &shapeList);
void genNeptune(vector<Shape*> &shapeList);
#endif
