//
//  operador.cpp
//  camaraExterior2
//
//  Created by Federico Joselevich Puiggrós on 10/11/14.
//
//

#include "operador.h"

void Operador::setup(string remoteIP, int remotePort) {
    maquinaOperador.setup(remoteIP, remotePort);
    
    //estaMaquina.setup(PORT);
    
}

void Operador::update(ofPixelsRef pixelsref, int caras) {
    if (!processing) {
        buffer = new ofBuffer;
    
    
        //img.resize(320/3,240/3);
        ofSaveImage(pixelsref, *buffer); //, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_WORST);
        processing = true;
    }
    
    
    
/*    m.setAddress("/carasDetectadas");
    m.addIntArg(caras);
    maquinaOperador.sendMessage(m);
*/
}

void Operador::threadedFunction() {
    
    // start
    
    while( isThreadRunning() == true ){
        lock();
        
        if (processing) {
            ofxOscMessage m;
            m.setAddress("/image");
            m.addBlobArg(*buffer);
            //maquinaOperador.sendMessage(m);
            
            processing = false;
        }
        unlock();
        
        ofSleepMillis(100);
    }
    
    // done
}