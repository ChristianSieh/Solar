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
extern GLenum spinMode;
extern GLenum singleStep;
extern vector<Shape*> shapeList;

//rotation info
extern GLint axis;

// these three variables control the animation's state and speed
extern float HourOfDay;
extern float currDay;
extern float AnimateIncrement;  // Time step for animation (hours)

//display
void Animate( void );
void ResizeWindow( int w, int h);

//events
void Key_r( void );
void Key_s( void );
void Key_up( void );
void Key_down( void );
void KeyPressFunc( unsigned char Key, int x, int y );
void SpecialKeyFunc( int Key, int x, int y );

//menu
void createMenu();
void MainMenuHandler( int item );
void PlanetMenuHandler( int item );


#endif 
