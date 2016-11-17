#include "Gen.h"



void generate(vector<Shape*> &shapeList)
{
    //genSun(shapeList);
    genMercury(shapeList);
    genVenus(shapeList);
    genEarth(shapeList);
    genMars(shapeList);
    genJupiter(shapeList);
    genSaturn(shapeList);
    genUranus(shapeList);
    genNeptune(shapeList);


}
void genSun(vector<Shape*> &shapeList)
{
     shapeList.push_back( new Sun( 10.0, 25,  "Sun", "../src/PlanetImg/sun.bmp" ) );
     //apeList.push_back( new Sun( 696000, 25,  "Sun", "none" ) );
}
void genMercury(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 2439, 58, 88, 1416, "Mercury", "none" ) );
}
void genVenus(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 6052, 108, 225, 5832, "Venus", "none" ) );
}
void genEarth(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 6378, 150, 365, 24, "Earth", "none" ) );
}
void genMars(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 3394, 228, 687, 24.6, "Mars", "none" ) );
}
void genJupiter(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 71398, 779, 4332, 9.8, "Jupiter", "none" ) );
}
void genSaturn(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 60270, 1424, 10761, 10.2, "Saturn", "none" ) );
}
void genUranus(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 25550, 2867, 30682, 15.5, "Uranus", "none" ) );
}
void genNeptune(vector<Shape*> &shapeList)
{
    shapeList.push_back( new Planet( 24750, 4492, 60195, 15.8, "Neptune", "none" ) );
}
