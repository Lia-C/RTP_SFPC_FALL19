#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    // Set initial values
    pos0 = ofPoint(512, 300);
    pos = ofPoint(600, 200);
    velocity = ofPoint(100, 0);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float dt = 1.0 / 60.0; // time step
    float mass = 0.1; // mass of ball
    float rubberLen = 200.0; // segment length
    float k = 0.5; // segment's stiffness
    ofPoint g(0.0, 9.8);  // gravity
    
    ofPoint delta = pos - pos0;
    float len = delta.length();
    float hookeValue = k * (len - rubberLen);
    delta.normalize();
    ofPoint hookeForce = delta * (-hookeValue);
    
    ofPoint force = hookeForce + g;
    ofPoint a = force / mass;
    velocity += a * dt;
    pos += velocity * dt;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofSetColor(0, 0, 255);
    ofDrawLine(pos0.x, pos0.y, pos.x, pos.y);
    
    ofSetColor(255, 0, 0);
    ofFill();
    ofDrawCircle(pos.x, pos.y, 20);
    
    
    
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
