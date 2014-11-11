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
        
    imagenCamara.setup();
    
    if (thisAnimation == 0) animacion1.setup();
    else if (thisAnimation == 1) animacion2.setup();
    else if (thisAnimation == 2) animacion3.setup();
    else if (thisAnimation == 3) animacion4.setup();
    
    proximoEnvioAlperador = 0;

    cout << "listening for osc messages on port " << thisPort << "\n";
    receiver.setup(thisPort);
    
    operador.setup(remoteIP, remotePort);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    imagenCamara.update();
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        cout << "Mensaje recibido:" << m.getArgAsInt32(0) << "\n";
        
        // check for mouse moved message
        if(m.getAddress() == "/motor/position"){
            motor.setPosicion(m.getArgAsInt32(0));
        }
    }

    if (proximoEnvioAlperador < ofGetElapsedTimeMillis()) {
        ofImage img;

        img.setFromPixels(imagenCamara.video.getPixels(), imagenCamara.video.width, imagenCamara.video.height, OF_IMAGE_COLOR);
    
        operador.update(img, imagenCamara.blobs.size());
        proximoEnvioAlperador = ofGetElapsedTimeMillis() + 500;
    }
    if (thisAnimation == 0) animacion1.update();
    else if (thisAnimation == 1) animacion2.update();
    else if (thisAnimation == 2) animacion3.update();
    else if (thisAnimation == 3) animacion4.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    imagenCamara.video.draw(0,0,1024,768);
    if (thisAnimation == 0) animacion1.draw();
    else if (thisAnimation == 1) animacion2.draw();
    else if (thisAnimation == 2) animacion3.draw();
    else if (thisAnimation == 3) animacion4.draw();
    for(int i = 0; i < imagenCamara.blobs.size(); i++) {
        ofRectangle cur = imagenCamara.blobs[i].boundingRect;
        cur.x *= 3.2;
        cur.y *= 3.2;
        cur.width *= 3.2;
        cur.height *= 3.2;
        ofLine(cur.x,cur.y, cur.x+cur.width, cur.y+cur.height);
        //ofRect(cur);
    }

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
    
    // stop the thread
    imagenCamara.analizadorDeCaras.stopThread();
}
