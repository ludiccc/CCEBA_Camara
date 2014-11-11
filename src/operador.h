//
//  operador.h
//  camaraExterior2
//
//  Created by Federico Joselevich Puiggrós on 10/11/14.
//
//

#ifndef __camaraExterior2__operador__
#define __camaraExterior2__operador__

#include <stdio.h>
#include "ofxOsc.h"

//#define HOST "192.168.0.101"
#define HOST "192.168.1.131"
#define PORT 12345


class Operador {
public:
    void setup(string remoteIP, int remotePort);
    ofxOscSender maquinaOperador;
    
    void update(ofImage img, int caras);
};

#endif /* defined(__camaraExterior2__operador__) */
