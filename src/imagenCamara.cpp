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
    video.initGrabber(320,240);
    
    finder.setup("haarcascade_frontalface_alt.xml");
    
}

void ImagenCamara::update() {
    video.update();
    
    if (video.isFrameNew()){
        
        ofxCvColorImage colorImg;
        colorImg.allocate(video.width,video.height);
        colorImg.setFromPixels(video.getPixelsRef());
        ofxCvGrayscaleImage grayImage;
        grayImage = colorImg;
        /*
         int totalPixels = camWidth*camHeight*3;
         unsigned char * pixels = vidGrabber.getPixels();
         unsigned char * pixelsDest = img.getPixels();
         for (int i = 0; i < totalPixels; i++){
         pixelsDest[i] = pixels[i];
         }*/
        finder.findHaarObjects(grayImage, 80, 80);
    }
}