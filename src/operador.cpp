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

void Operador::update(ofImage img, int caras) {
    ofBuffer * buffer = new ofBuffer;
    
    
    img.resize(320/3,240/3);
    ofSaveImage(img.getPixelsRef(), *buffer); //, OF_IMAGE_FORMAT_JPEG, OF_IMAGE_QUALITY_WORST);
    
    ofxOscMessage m;
    m.setAddress("/image");
    m.addBlobArg(*buffer);
    maquinaOperador.sendMessage(m);
    
    m.setAddress("/carasDetectadas");
    m.addIntArg(caras);
    maquinaOperador.sendMessage(m);

}