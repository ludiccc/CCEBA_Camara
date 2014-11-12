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
#include <stdlib.h>     /* abs */
#include "ofMain.h"

#define INICIALIZANDO 0x0
#define READY 0x1
#define MOVIENDO 0x2

#if !defined(__APPLE__)
#include "wiringPi.h"
#endif

class Motor {
public:
    Motor();
    void update();
    
    void setPosicion(int pos);
    int getPosicion();
    
    int tiempoDeGiro;
    
    unsigned int proximoTimeout;
    
    int posicionProxima;
    int posicionActual;
    int estado;
    
};

#endif /* defined(__camaraExterior__motor__) */
