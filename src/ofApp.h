#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "motor.h"
#include "imagenCamara.h"
#include "sonido.h"
#include "animacion.h"
#include "animacion2.h"
#include "animacion3.h"
#include "animacion4.h"
#include "operador.h"
#include "ofxXmlSettings.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxXmlSettings XML;
    
    Operador operador;
    unsigned int proximoEnvioAlperador;

    Motor motor;
    ImagenCamara imagenCamara;
    Animacion animacion0;
    Animacion animacion1;
    Animacion2 animacion2;
    Animacion3 animacion3;
    Animacion4 animacion4;
    
   
    
    Sonido sonido;
    
    ofxOscReceiver receiver;
    
    int thisPort;
    int remotePort;
    string remoteIP;
    int thisAnimation;
    
    
};
