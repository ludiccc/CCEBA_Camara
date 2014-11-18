//
//  sonido.cpp
//  camaraExterior
//
//  Created by Federico Joselevich Puiggrós on 9/11/14.
//
//

#include "sonido.h"

void Sonido::setup(string path) {
    base.loadSound(path);
    base.setVolume(0.75f);
    base.setLoop(true);
    base.play();

    
}

void Sonido::update(){
    ofSoundUpdate();
}
