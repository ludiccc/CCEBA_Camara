//
//  animacion3.h
//  camaraExterior2
//
//  Created by el5jinete on 11/9/14.
//
//

#ifndef __camaraExterior2__animacion3__
#define __camaraExterior2__animacion3__


#include <stdio.h>
#include "ofMain.h"
#include "ofxSvg.h"


class Animacion3 {
    
public:
    void setup();
    void update();
    void draw();
    
    // Properties
    int x;
    int y;
    string texto;
    float escala;
    
    //layout
    int margen;
    
    //tipografia
    ofTrueTypeFont tipografia_65;
    ofTrueTypeFont tipografia_36;
    ofTrueTypeFont tipografia_18;
    ofTrueTypeFont tipografia_09;
    
    //test
    ofImage pantalla;
    
        
    
    
};


#endif /* defined(__camaraExterior2__animacion3__) */
