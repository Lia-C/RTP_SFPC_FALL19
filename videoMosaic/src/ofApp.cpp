#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    grabber.draw(0, 0);
    for (int x = 0 ; x < grabber.getWidth(); x += 10){
         for (int y = 0 ; y < grabber.getHeight(); y += 10){
//             ofColor c = grabber.getPixels().getColor(x, y);
             
//             unsigned char *
             int index = 3*(y*grabber.getWidth() + x);
             //read only the red value, 3 channels
             
             unsigned char r = grabber.getPixels().getData()[index];
             unsigned char g = grabber.getPixels().getData()[index + 1];
             unsigned char b = grabber.getPixels().getData()[index + 2];
             //first byte of color
             
             // 1d array_index = y * width + x
             // (where x,y are 2d array indices)
             
             ofSetColor(r,g,b); //c = brightness value
             ofDrawCircle(x, y, 5);
         }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
