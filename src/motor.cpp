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
    ofSleepMillis(20);
    
#endif
    proximoTimeout = ofGetElapsedTimeMillis() + 10*1000;
}

void Motor::update() {
    if (ofGetElapsedTimeMillis() > proximoTimeout) {
        if (estado == INICIALIZANDO) {
            cout << "Se termino de inicializar..\n";
            estado = READY;
#if !defined(__APPLE__)
            digitalWrite (0,  LOW) ;
            digitalWrite (1,  LOW) ;
            ofSleepMillis(20);
#endif
        } else if (estado == MOVIENDO) {
            cout << "Se termino de mover..\n";
            estado = READY;
#if !defined(__APPLE__)
            digitalWrite (0,  LOW) ;
            digitalWrite (1,  LOW) ;
            ofSleepMillis(20);
#endif
        }
        
        
        
        if (estado == READY && posicionProxima > -1) {
            estado = MOVIENDO;
            if (posicionActual > posicionProxima) {
                cout << "Se movera en direccion 1..\n";
#if !defined(__APPLE__)
                digitalWrite (0,  HIGH) ;
                digitalWrite (1,  LOW) ;
                ofSleepMillis(20);
#endif
            } else {
                cout << "Se movera en direccion -1..\n";
#if !defined(__APPLE__)
                digitalWrite (0,  LOW) ;
                digitalWrite (1,  HIGH) ;
                ofSleepMillis(20);
#endif
            }
            
            int tiempoDeDesplazamiento = abs(posicionActual-posicionProxima)*tiempoDeGiro;

            posicionActual = posicionProxima;
            posicionProxima = -1;

            proximoTimeout = ofGetElapsedTimeMillis()+tiempoDeDesplazamiento; // el tiempo que se tarde en llegar a esa posicion.
        }
    }
}

void Motor::setPosicion(int pos) {
    cout << "Seteando proxima posicion: " << pos << " (posicion actual: " << posicionActual << ")\n";
    posicionProxima = pos;

}