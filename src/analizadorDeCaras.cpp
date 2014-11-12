//
//  analizadorDeCaras.cpp
//  camaraExterior2
//
//  Created by Federico Joselevich Puiggrós on 11/11/14.
//
//

#include "analizadorDeCaras.h"
static ofxCvGrayscaleImage gI;

AnalizadorDeCaras::AnalizadorDeCaras() {
    finder.setup("haarcascade_frontalface_alt.xml");
    processing = false;
    grayscaleImage.allocate(160,120);
}

void AnalizadorDeCaras::search(unsigned char * pixs, int w, int h) {
    if (!processing) {
        pixels = pixs;
        processing = true;
    }
    
}

void AnalizadorDeCaras::search(ofPixelsRef pixelsRef) {
    grayscaleImage.setFromPixels(pixelsRef);
    finder.findHaarObjects(grayscaleImage, 100, 100);
    /*if (!processing) {
        grayscaleImage.setFromPixels(pixelsRef);
        finder.findHaarObjects(grayscaleImage, 100, 100);
        processing = true;
    }*/
}

void AnalizadorDeCaras::search(ofImage img) {
    grayscaleImage.setFromPixels(img.getPixels(), img.width, img.height);
    processing = true;
}


void AnalizadorDeCaras::threadedFunction() {
    
    // start
    
    while( isThreadRunning() == true ){
        lock();
        
        if (processing) {
            
            cout << "Searching...\n";
            finder.findHaarObjects(grayscaleImage, 100, 100);
            //
             cout << "threaded encontró " << finder.blobs.size() << std::endl;
            processing = false;
        }
        unlock();
        
        ofSleepMillis(100);
    }
    
    // done
}