//
//  imagenCamara.h
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#ifndef __camaraExterior__imagenCamara__
#define __camaraExterior__imagenCamara__

#include <stdio.h>
#include "ofMain.h"
//#include "ofxHTTP.h"
#include "analizadorDeCaras.h"
#include "ofxCvHaarFinder.h"


class ImagenCamara {
//    ofx::HTTP::BasicIPVideoServer::SharedPtr server;
    
public:
    ofVideoGrabber 		video;
    ofxCvColorImage colorImg;
    
    vector<ofxCvBlob> blobs;
    
    void setup();
    void update();
    
    AnalizadorDeCaras analizadorDeCaras;
    int getNumeroDeCaras();
    
};

#endif /* defined(__camaraExterior__imagenCamara__) */
