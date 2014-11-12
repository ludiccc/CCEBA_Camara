//
//  imagenCamara.cpp
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#include "imagenCamara.h"

void ImagenCamara::setup() {
/*    ofx::HTTP::BasicIPVideoServerSettings settings;
    
    // Many other settings are available.
    settings.setPort(7890);
    
    // The default maximum number of client connections is 5.
    // settings.setMaxClientConnections(10);
    
    // Apply the settings.
    server = ofx::HTTP::BasicIPVideoServer::makeShared(settings);
    
    // Start the server.
    server->start();*/
    
    video.listDevices();
    video.setDeviceID(0);
    video.setDesiredFrameRate(60);
    video.initGrabber(320/2,240/2);
    
    analizadorDeCaras.startThread();
}

void ImagenCamara::update() {
    
    // si el analizador no está tocando el finder, entonces copio el vector de blobs.
    if (analizadorDeCaras.available()) {
        blobs = analizadorDeCaras.finder.blobs;
    }
    
    video.update();
    
    if (video.isFrameNew()){

        /*
        // Me fijo si el thread de análisis está libre y si es así, le cargo una imagen
        // nueva para su detección, y le aviso.
        if (analizadorDeCaras.available()) {
            //analizadorDeCaras.search(video.getPixels(), video.width, video.height);
            ofImage imagen;
            imagen.setFromPixels(video.getPixels(), video.width, video.height, OF_IMAGE_COLOR);
            analizadorDeCaras.search(imagen);
        }
         */
    }
}