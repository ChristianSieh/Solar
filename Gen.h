#ifndef GEN_H
#define GEN_H

#include <GL/freeglut.h>
#include <functional>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

void generate();
void openfile( string filename );
void genPick( function<void ()> &myfunc );
void planet();
#endif
