#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lillian.load("image.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofColor c  = lillian.getColor(mouseX, mouseY);
//
//    ofBackground(c);
//
//    ofPushStyle();
//        ofSetColor(255, 90, 90);
//        lillian.draw(0, 0);
//    ofPopStyle();
//
//    lillian.draw(400, 0);
    
    float ratio = lillian.getHeight() / lillian.getWidth();
    int newWidth = ratio*ofGetHeight();
    int newHeight = ofGetHeight();
    lillian.draw(0, 0, newWidth, newHeight);
    
    int step = mouseX / 50.0;
    if (step < 1) {step = 1;}
    
    for (int x = 0; x < lillian.getWidth(); x += step){
        for(int y = 0; y < lillian.getHeight(); y += step){
            ofColor c  = lillian.getColor(x,y);
            ofSetColor(c);
            int radius = step/2;
            ofDrawCircle(
                         100 + ratio*x, //x + 5*sin(y+ofGetElapsedTimef()),
                         100 + ratio*y, //y,
                         radius
            );
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
