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

#include "Poco/Mutex.h"


class Operador : public ofThread {
public:
    //-------------------------------
    // non blocking functions
    bool available() { return !processing; };
    void setup(string remoteIP, int remotePort);
    
    //-------------------------------
    // blocking functions
    void update(ofPixelsRef pixelsref, int caras);
    
    //-------------------------------
    // the thread function
    void threadedFunction();
    
    ofxOscSender maquinaOperador;
    ofBuffer * buffer;

protected:
    bool processing;
    
};

#endif /* defined(__camaraExterior2__operador__) */
