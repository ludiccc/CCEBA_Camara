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

void Operador::update(ofImage img) {
    ofBuffer * buffer = new ofBuffer;
    
    
    img.resize(320/3,240/3);
    ofSaveImage(img.getPixelsRef(), *buffer);
    
    ofxOscMessage m;
    m.setAddress("/image");
    m.addBlobArg(*buffer);
    maquinaOperador.sendMessage(m);
    
    m.setAddress("/test");
    m.addIntArg(1);
    m.addFloatArg(3.5f);
    m.addStringArg("hello");
    m.addFloatArg(ofGetElapsedTimef());
    maquinaOperador.sendMessage(m);

}