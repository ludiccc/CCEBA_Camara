#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if( XML.loadFile("control.xml") ){
        cout << "control.xml loaded!";
    }else{
        cout << "unable to load mySettings.xml check data/ folder";
    }

    thisPort = XML.getValue("PORT", 12345);
    remoteIP = XML.getValue("DESTIP", "localhost");
    remotePort = XML.getValue("DESTPORT", 12345);
    
    thisAnimation = XML.getValue("ANIMACION", 0);
    
    motor.tiempoDeGiro = XML.getValue("TIEMPODEGIRO", 200);
    
    string sonidoMotor = XML.getValue("SONIDOMOTOR", "");
    string sonidoStream = XML.getValue("SONIDODATOS", "");
    
    sonido.isMotor = (sonidoMotor != "");
    sonido.isStream = (sonidoStream != "");
    
    if (sonido.isMotor) sonido.setup(sonidoMotor);
    if (sonido.isStream) sonido.setup(sonidoStream);
    
        
    imagenCamara.setup();
    
    if (thisAnimation == 0) animacion1.setup();
    else if (thisAnimation == 1) animacion2.setup();
    else if (thisAnimation == 2) animacion3.setup();
    else if (thisAnimation == 3) animacion4.setup();
    
    proximoEnvioAlperador = 0;

    cout << "listening for osc messages on port " << thisPort << "\n";
    receiver.setup(thisPort);
    
    operador.setup(remoteIP, remotePort);
    operador.startThread();
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
    motor.update();
    imagenCamara.update();

    if (sonido.isMotor) {
        if (motor.estado != READY) {
            sonido.base.setVolume(0.75);
        } else {
            sonido.base.setVolume(0.0);
        }
        
    }


    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        cout << "Mensaje recibido:" << m.getAddress() << ":" << m.getArgAsInt32(0) << "\n";
        
        // check for mouse moved message
        if(m.getAddress() == "/motor/position"){
            motor.setPosicion(m.getArgAsInt32(0));
        }
    }

    if (thisAnimation == 0) animacion1.update();
    else if (thisAnimation == 1) animacion2.update();
    else if (thisAnimation == 2) animacion3.update();
    else if (thisAnimation == 3) animacion4.update();


    if (proximoEnvioAlperador < ofGetElapsedTimeMillis()) {
        operador.update(imagenCamara.video.getPixelsRef(), 0);
        proximoEnvioAlperador = ofGetElapsedTimeMillis() + 500;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFbo fbo;
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    imagenCamara.video.draw(0,0,1024,768);
    if (thisAnimation == 0) animacion1.draw();
    else if (thisAnimation == 1) animacion2.draw();
    else if (thisAnimation == 2) animacion3.draw();
    else if (thisAnimation == 3) animacion4.draw();
    fbo.end();
    fbo.draw(0,0);


    /* esto lo usar’a si quisiera enviar el fbo
    if (proximoEnvioAlperador < ofGetElapsedTimeMillis()) {
        ofImage img;
        //img.allocate(ofGetWidth(), ofGetHeight(), OF_, <#int h#>, <#ofImageType type#>)
        //ofPixels pixels;
        //fbo.readToPixels(img.getPixelsRef());
        img.setFromPixels(pixels);
        img.resize(160,120);
        
        //operador.update(imagenCamara.video.getPixelsRef(), 0);
        //operador.update(img.getPixelsRef(), 0);
        proximoEnvioAlperador = ofGetElapsedTimeMillis() + 11500;
    }
     */

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit() {
}
