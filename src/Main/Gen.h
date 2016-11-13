#ifndef GEN_H
#define GEN_H

#include <GL/freeglut.h>
#include <functional>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "../Shape/Shape.h"

using namespace std;

void generate();
void openfile( string filename );
void genPick( function<void ()> &myfunc );
void planet();
#endif
