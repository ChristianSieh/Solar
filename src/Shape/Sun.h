#ifndef SUN_H
#define SUN_H

#include "Orb.h"

class Sun : public Orb
{
    public:
	Sun( float r = 1.0, string n = "null", string i = "null"  );
	~Sun();
        void drawWireFrame() const;
};

#endif
