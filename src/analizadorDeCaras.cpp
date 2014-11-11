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
    grayscaleImage.allocate(480,640);
}

void AnalizadorDeCaras::search(unsigned char * pixels, int w, int h) {
    if (!processing) {
        cout << "Searching...\n";
        ofxCvColorImage img;
        img.allocate(w,h);
        img.setFromPixels(pixels, w, h);
        grayscaleImage = img;
        processing = true;
        finder.findHaarObjects(grayscaleImage); //, 80, 80);
        cout << "threaded encontró " << finder.blobs.size() << std::endl;
    }
    
}

void AnalizadorDeCaras::search(ofxCvGrayscaleImage img) {
    if (!processing) {
        cout << "Searching...\n";
        cout << img.width << " x " << img.height << std::endl;
        //processing = true;
        finder.findHaarObjects(img); //, 80, 80);
        cout << "Searching encontró " << finder.blobs.size() << std::endl;
    }
}


void AnalizadorDeCaras::threadedFunction() {
    
    // start
    
    while( isThreadRunning() == true ){
        lock();
        
        if (processing) {
            finder.findHaarObjects(grayscaleImage, 100, 100);
            //
            //cout << "threaded encontró " << finder.blobs.size() << std::endl;
            processing = false;
        }
        unlock();
        
        ofSleepMillis(100);
    }
    
    // done
}