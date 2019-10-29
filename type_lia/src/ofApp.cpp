#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    font.load("framd.ttf", 200, true, true, true);
    
//    font.load("AdobeFanHeitiStd-Bold.otf", 36);
    
    ofTrueTypeFontSettings settings("AdobeFanHeitiStd-Bold.otf", 12);
    settings.addRange(ofUnicode::CJKUnified);
    font.load(settings);
    
    ofBuffer buffer = ofBufferFromFile("chars.csv");
    for (auto line : buffer.getLines()){
        chars.push_back(line);
    }

    ofBuffer buffer2 = ofBufferFromFile("chars_freq.csv");
    for (string line : buffer2.getLines()){
        int freq = stoi(line);
        char_freq.push_back(freq);
    }
    
//    //scale down to 1
//    for (int i = 0; i < char_freq.size(); i++){
//        char_freq[i] = char_freq[i] / char_freq[char_freq.size()-1];
//     }
//    max_char_freq = char_freq[0];
    
    for (int i = 0; i < char_freq.size(); i++){
        char_time_left.push_back(char_freq[i]);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float sum = 0;
    for (int i = 0; i < char_time_left.size(); i++){
        char_time_left[i] -= ofGetElapsedTimeMillis();
        if (char_time_left[i] < 0){
            char_time_left[i] = 0;
        }
        sum += char_time_left[i];
    }
    
   
    // if all are depleted, start over
    if (sum < 1.0){
        for (int i = 0; i < char_freq.size(); i++){
            char_time_left[i] = char_freq[i];
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofEnableDepthTest();
    ofSetColor(255, 50);
      
        int grid_side = 44;
        for (int x = 0; x < grid_side; x++){
            for (int y = 0; y < grid_side; y++){
                
                int i = y * grid_side + x;
                
                if (i < 2000) {
                
//                    int alpha = 255*sin(char_freq[i] * ofGetElapsedTimef());
//
//                    ofSetColor(255, alpha);
                    if (char_time_left[i] > 1.0){
                        //on
                        ofSetColor(255);
                    }
                    else{
                        //off
                        ofSetColor(255, 50);
                    }
                    
                    string word = chars[i];
                    font.drawString(word, 20 + x*20, 10 + y*20);
                }
            }
        }
//        font.drawString("a", 500, 500);
        
//        ofTranslate(300,300);
//    }

    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < char_freq.size(); i++){
        char_time_left[i] = char_freq[i];
    }
    
     std::cout << "whee" << std::endl;
    
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
