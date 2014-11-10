//
//  animacion2.cpp
//  camaraExterior2
//
//  Created by el5jinete on 11/9/14.
//
//

#include "animacion2.h"

void Animacion2::setup(){
    ofTrueTypeFont::setGlobalDpi(72);
    margen=10;
    barraArribaMagenta.load("miscelaneas2/barraMagenta.svg");
    barraAbajoCyan.load("miscelaneas2/barraCyan.svg");
    pantalla.loadImage("pantalla2.png");

  
}

void Animacion2::update(){
    
}

void Animacion2::draw(){
    
    // ---- barras arriba y abajo ----
   /* ofPushMatrix();
    ofTranslate(0, margen);
    barraArribaMagenta.draw();
    ofPopMatrix();*/
    
    // ---- barra cyan -----
   /* ofPushMatrix();
    ofTranslate( 0, ofGetHeight() - barraAbajoCyan.getHeight() - margen);
    barraAbajoCyan.draw();
    ofPopMatrix();
    
    ofPushStyle();
    
    ofPopStyle();*/
    
    pantalla.draw( 0,0);
    
   
    
    
    
}
