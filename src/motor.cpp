//
//  motor.cpp
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#include "motor.h"

Motor::Motor() {
#if !defined(__APPLE__)
    wiringPiSetup () ;
    pinMode (0, OUTPUT) ;
    pinMode (1, OUTPUT) ;
#endif
}

void Motor::setPosicion(int pos) {
#if !defined(__APPLE__)
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