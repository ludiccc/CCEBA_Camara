//
//  analizadorDeCaras.h
//  camaraExterior2
//
//  Created by Federico Joselevich Puiggrós on 11/11/14.
//
//

#ifndef __camaraExterior2__analizadorDeCaras__
#define __camaraExterior2__analizadorDeCaras__

#include <stdio.h>
#include "ofxCvHaarFinder.h"
#include "ofMain.h"
#include "Poco/Mutex.h"


class AnalizadorDeCaras : public ofThread {
public:
    AnalizadorDeCaras();

    //-------------------------------
    // non blocking functions
    bool available() { return !processing; };

    //-------------------------------
    // blocking functions
    void search(unsigned char *pixels, int w, int h);
    void search(ofxCvGrayscaleImage img);
    
    
    ofxCvGrayscaleImage grayscaleImage;
    ofxCvHaarFinder finder;

    // the thread function
    void threadedFunction();

protected:
    bool processing;
    
};

#endif /* defined(__camaraExterior2__analizadorDeCaras__) */
