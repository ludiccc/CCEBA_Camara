//
//  imagenCamara.cpp
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#include "imagenCamara.h"

void ImagenCamara::setup() {
    video.listDevices();
    video.setDeviceID(0);
    video.setDesiredFrameRate(60);
    video.initGrabber(320/2,240/2);
    
}

void ImagenCamara::update() {
    video.update();
     /*
    if (video.isFrameNew()){

       
        // Me fijo si el thread de análisis está libre y si es así, le cargo una imagen
        // nueva para su detección, y le aviso.
        if (analizadorDeCaras.available()) {
            //analizadorDeCaras.search(video.getPixels(), video.width, video.height);
            ofImage imagen;
            imagen.setFromPixels(video.getPixels(), video.width, video.height, OF_IMAGE_COLOR);
            analizadorDeCaras.search(imagen);
        }
         
    }*/
}