//
//  sonido.h
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#ifndef __camaraExterior__sonido__
#define __camaraExterior__sonido__

#include <stdio.h>
#include "ofMain.h"

class Sonido {
public:
    void setup(string path);
    void update();
    bool isMotor;
    bool isStream;
    
    ofSoundPlayer base;
};

#endif /* defined(__camaraExterior__sonido__) */
