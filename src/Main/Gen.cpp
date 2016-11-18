#include "Gen.h"

void generate(vector<Shape*> &shapeList)
{
    genSun(shapeList);
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
    float color[] = {0.992156863, 0.945098039, 0.466666667, 1.0};
    shapeList.push_back( new Sun( 10.0, 25,  "Sun", "../src/PlanetImg/sun.bmp", color ) );
    //apeList.push_back( new Sun( 696000, 25,  "Sun", "none" ) );
}
void genMercury(vector<Shape*> &shapeList)
{
    float color[] = {0.980392157, 0.97254902, 0.949019608, 1.0};
    shapeList.push_back( new Planet( 2439, 58, 88, 1416, "Mercury", "../src/PlanetImg/mercury.bmp", color ) );
}
void genVenus(vector<Shape*> &shapeList)
{
    float color[] = {0.654901961, 0.368627451, 0.070588235, 1.0};
    shapeList.push_back( new Planet( 6052, 108, 225, 5832, "Venus", "../src/PlanetImg/venus.bmp", color ) );
}
void genEarth(vector<Shape*> &shapeList)
{
    float color[] = {0.043137255, 0.360784314, 0.890196078, 1.0};
    shapeList.push_back( new Planet( 6378, 150, 365, 24, "Earth", "../src/PlanetImg/earth.bmp", color ) );
}
void genMars(vector<Shape*> &shapeList)
{
    float color[] = {0.941176471, 0.776470588, 0.11372549, 1.0};
    shapeList.push_back( new Planet( 3394, 228, 687, 24.6, "Mars", "../src/PlanetImg/mars.bmp", color ) );
}
void genJupiter(vector<Shape*> &shapeList)
{
    float color[] = {0.992156863, 0.780392157, 0.568627451, 1.0};
    shapeList.push_back( new Planet( 71398, 779, 4332, 9.8, "Jupiter", "../src/PlanetImg/jupiter.bmp", color ) );
}
void genSaturn(vector<Shape*> &shapeList)
{
    float color[] = {0.878431373, 0.780392157, 0.133333333, 1.0};
    shapeList.push_back( new Planet( 60270, 1424, 10761, 10.2, "Saturn", "../src/PlanetImg/saturn.bmp", color ) );
}
void genUranus(vector<Shape*> &shapeList)
{
    float color[] = {0.862745098, 0.945098039, 0.960784314, 1.0};
    shapeList.push_back( new Planet( 25550, 2867, 30682, 15.5, "Uranus", "../src/PlanetImg/uranus.bmp", color ) );
}
void genNeptune(vector<Shape*> &shapeList)
{
    float color[] = {0.223529412, 0.71372549, 0.968627451, 1.0};
    shapeList.push_back( new Planet( 24750, 4492, 60195, 15.8, "Neptune", "../src/PlanetImg/neptune.bmp", color ) );
}
