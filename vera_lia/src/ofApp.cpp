#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

void ofApp::draw(){

    ofBackground(255);//20);
    ofNoFill();
    
    int side_len = ofGetWidth();
    int start_x = 0;
    int start_y = side_len;
    int end_x = side_len;
    int end_y = side_len;
    
    std::vector <ofPolyline> polylines;
    
    int numLines = 10;
    for (int l = 0; l < numLines; l++){
        ofPolyline line;
        for(int x = start_x; x < end_x; x++){
            
            int movement = 500+ ((ofGetFrameNum()/2)  % 700);
            
            // y_base: independent of l
            float scale = 400;
            //float base_noise = 20*ofNoise(1000*mouseX, x);
            float base_sin_wave = 100*sin((x*movement/100000.0)-movement);
            float sub_sin_wave =  100*sin((x*movement/10000.0)-movement);
            float y_base;
//            if (ofNoise(1000*mouseX, x) > 0.9){
//                y_base = base_sin_wave - 0.5*sub_sin_wave + 300;
//            } else {
//                y_base = base_sin_wave + 0.5*sub_sin_wave + 300;
//            }
            y_base = base_sin_wave + 0.2*sub_sin_wave;
            
            
            // y_noise: depends on l
            float noise = ofNoise(1000*movement, x);
//            float noise_amplification = 1.0;
            float slide_offset = 100*sin((x*movement/10000.0)-movement);
            float noise_amplification = 100-0.001*pow(x - (side_len/2) - slide_offset, 2);
            if (noise_amplification <= 0){
                noise_amplification = 0;
            }
            float y_noise = noise + noise_amplification;
            
            float noise_scale = sin(l*13 + 10*ofNoise(l, 100*movement));
            float y = -(y_base + noise_scale*y_noise) + 500;
            line.curveTo(ofVec3f(x,y,0));
        }
//        line.setClosed(false);
        polylines.push_back(line);
//        line.draw();
        //line.clear();
    }
    for (int m = 0 ; m < polylines.size() ; m++) {
        ofPolyline l = polylines.at(m);
        //cout << l.getVertices()[0] << endl;
        int r = mouseY*(m+1)*131 % 256;
        int g = mouseY*(m+1)*267 % 256;
        int b = mouseY*(m+1)*102 % 256;
        cout << (r,g,b) << endl;
        ofColor c = ofColor(r,g,b);
        c.setBrightness(240);
        ofSetColor(c);
        
        int line_width = 1 + mouseY*(m+1)*131 % 100 ;
        ofSetLineWidth(line_width);
        l.draw();
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
