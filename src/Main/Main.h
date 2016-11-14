#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <vector>
#include <GL/freeglut.h>

//shape classes
#include "../Shape/Shape.h"
#include "../Shape/Orb.h"
#include "../Shape/Sun.h"
#include "../Shape/Planet.h"


// global variables
static GLenum spinMode = GL_TRUE;
static GLenum singleStep = GL_FALSE;
extern vector<Shape*> shapeList;

//rotation info
extern GLfloat theta[];
extern GLint axis;

// these three variables control the animation's state and speed.
static float HourOfDay = 0.0;
static float currDay = 0.0;
static float AnimateIncrement = 24.0;  // Time step for animation (hours)


void Animate( void );
void ResizeWindow( int w, int h);
void Key_r( void );
void Key_s( void );
void Key_up( void );
void Key_down( void );
void KeyPressFunc( unsigned char Key, int x, int y );
void SpecialKeyFunc( int Key, int x, int y );

#endif 
