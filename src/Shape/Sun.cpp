#include "Sun.h"

Sun::Sun( float r, float d, string n, string i, float c[3] )
{
    radius = r;
    distance = 0.0;
    totalYear = 0.0;
    totalDay = d;
    name = n;
    img = i;
    type = "Sun";
    copy(c, c + 3, color);
}

Sun::~Sun()
{
}
