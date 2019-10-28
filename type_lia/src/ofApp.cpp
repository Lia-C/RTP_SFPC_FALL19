#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    font.load("framd.ttf", 200, true, true, true);
    
//    font.load("AdobeFanHeitiStd-Bold.otf", 200);
    
//    ofBuffer buffer = ofBufferFromFile("chars.csv");
//    for (auto line : buffer.getLines()){
//        chars.push_back(line);
//    }
//
//    ofBuffer buffer2 = ofBufferFromFile("chars_freq.csv");
//    for (auto line : buffer2.getLines()){
//        char_freq.push_back(line);
//    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofEnableDepthTest();
    
    ofTrueTypeFontSettings settings("AdobeHeitiStd-Regular.otf", 200);
    settings.addRange(ofUnicode::CJKUnified);
    settings.antialiased = true;
////    settings.addRange(ofUnicode::Hiragana);
////    settings.addRange(ofUnicode::Katakana);
////    settings.addRange(ofUnicode::Latin);
    font.load(settings);
    
//    for(int i = 0; i < 1; i ++){
        
        string word = "的";
        font.drawString("的", 200, 200);
        font.drawString("a", 500, 500);
//        ofTranslate(300,300);
//    }

    
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
