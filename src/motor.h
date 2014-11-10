//
//  motor.h
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#ifndef __camaraExterior__motor__
#define __camaraExterior__motor__

#include <stdio.h>

#if !defined(__APPLE__)
#include "wiringPi.h"
#endif

class Motor {
public:
    Motor();
    void setPosicion(int pos);
    int getPosicion();
};

#endif /* defined(__camaraExterior__motor__) */
