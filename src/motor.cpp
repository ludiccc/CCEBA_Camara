//
//  motor.cpp
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#include "motor.h"

Motor::Motor() {
    posicionProxima = -1;
    estado = INICIALIZANDO;
#if !defined(__APPLE__)
    wiringPiSetup () ;
    pinMode (0, OUTPUT) ;
    pinMode (1, OUTPUT) ;

    // le indico que debe moverse a la derecha por default durante 10 segundos para llegar al tope
    digitalWrite (0, HIGH) ;
    digitalWrite (1,  LOW) ;
    
#endif
    proximoTimeout = ofGetElapsedTimeMillis() + 10;
}

void Motor::update() {
    if (ofGetElapsedTimeMillis() > proximoTimeout) {
        if (estado == INICIALIZANDO) {
            estado = READY;
        } else if (estado == MOVIENDO) {
            estado = READY;
#if !defined(__APPLE__)
            digitalWrite (0,  LOW) ;
            digitalWrite (1,  LOW) ;
#endif
        }
        
        
        
        if (estado == READY && posicionProxima > -1) {
            estado = MOVIENDO;
            if (posicionActual > posicionProxima) {
#if !defined(__APPLE__)
                digitalWrite (0,  HIGH) ;
                digitalWrite (1,  LOW) ;
#endif
            } else {
#if !defined(__APPLE__)
                digitalWrite (0,  LOW) ;
                digitalWrite (1,  HIGH) ;
#endif
            }
            
            int tiempoDeDesplazamiento = abs(posicionActual-posicionProxima)*tiempoDeGiro;

            posicionActual = posicionProxima;
            posicionProxima = -1;

            proximoTimeout = ofGetElapsedTimeMillis()+tiempoDeDesplazamiento; // el tiempo que se tarde en llegar a esa posicion.
        }
    }

#if !defined(__APPLE__)
    
    if (estado == READY) {
        // hago el cálculo de para donde se tiene que mover...
        
    }
    
    if (pos == 100) {
        digitalWrite (0, HIGH) ;
        digitalWrite (1,  LOW) ;
    } else if (pos == 200) {
        digitalWrite (0,  LOW) ;
        digitalWrite (1,  HIGH) ;
    } else {
        digitalWrite (0,  LOW) ;
        digitalWrite (1,  LOW) ;
    }
#endif
}

void Motor::setPosicion(int pos) {
    posicionProxima = pos;

}