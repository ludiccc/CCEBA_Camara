//
//  animacion2.h
//  camaraExterior2
//
//  Created by el5jinete on 11/9/14.
//
//

#ifndef __camaraExterior2__animacion2__
#define __camaraExterior2__animacion2__

#include <stdio.h>
#include "ofMain.h"
#include "ofxSvg.h"


class Animacion2 {
    
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
    
    // circulo amarillo mediano // categorias
    ofxSVG circuloCategorias;
    
    string dato_1;
    string dato_2;
    string dato_3;
    
    int valor_1;
    int valor_2;
    int valor_3;
    
    //barra magenta
    ofxSVG barraArribaMagenta;
    //barra cyan
    ofxSVG barraAbajoCyan;
    
    //barra Horizontal
    ofxSVG barraHorizontal;
    int cantidadTipoDeIndividuo;
    
    //barras izquierda magentas
    ofxSVG grafico1;
    
    //test
     ofImage pantalla;
    
    
    
};

#endif /* defined(__camaraExterior2__animacion2__) */
