#define _USE_MATH_DEFINES
 
#include <cmath>
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

float dblWingX(float t){
    return 2 * cos(t) + sin(2*t)*cos(60*t);
}

float dblWingY(float t){
    return sin(2*t) + sin(60*t);
}

float scribbleBallX(float t){
    return sin(33*t)*cos(9*t);
}

float scribbleBallY(float t){
    return sin(40*t)*sin(7*t);
}


void drawRootsOfUnity(int n, int radius=1, int circle_rad=10){
    double theta = M_PI*2/n;
    
    for(int k = 1; k <= n; k++){
        float real = radius * cos(k*theta);
        float imag = radius * sin(k*theta);
        ofDrawCircle(real,imag,circle_rad);
    }
}

void pSetHSV( float h, float s, float v, float a ) {
   // H [0, 360] S, V and A [0.0, 1.0].
   int i = (int)floor(h/60.0f) % 6;
   float f = h/60.0f - floor(h/60.0f);
   float p = v * (float)(1 - s);
   float q = v * (float)(1 - s * f);
   float t = v * (float)(1 - (1 - f) * s);
     
   switch (i) {
      case 0: glColor4f(v, t, p, a);
      break;
      case 1: glColor4f(q, v, p, a);
      break;
      case 2: glColor4f(p, v, t, a);
      break;
      case 3: glColor4f(p, q, v, a);
      break;
      case 4: glColor4f(t, p, v, a);
      break;
      case 5: glColor4f(v, p, q, a);
   }
}

// 0 <= stepNumber <= lastStepNumber
int interpolate(int startValue, int endValue, int stepNumber, int lastStepNumber)
{
    return (endValue - startValue) * stepNumber / lastStepNumber + startValue;
}

void drawYantra(float t, int hue){
    float num_rounds = 100;
    for(int i = 0; i < num_rounds; i++){


     //roots of unity
        int n = 40;
        int r0 = 10 + 3 * i;
//        int w = ofMap(i, 0, 99, 1.0, 3.0);
        int r = 400 * sin(i/50.0 * t);
        
        if(i % 10 == 0){
            r = 400 * sin(i/100.0 * t);
            
        }

        ofPushMatrix();
        ofTranslate(400,400);
        ofRotateZ(2*M_PI*(i+1)/n);
        
        //180 = light blue, 300 = purple
        hue = interpolate(0, 360,
//                          180, 250,
                          i, num_rounds);
        
        float saturation = 1.0;
        float alpha = 0.5;
//        alpha = i * 17 % 100 / 100.0;
        if (i % 10 == 8){
            saturation = 0.0;
            alpha = 1.0;
        }
     // hue = (hue + 1) % 256;
        pSetHSV(hue, saturation, 1.0, alpha);

        int circle_rad = 5 + ((i * 34) % 10);
        
        drawRootsOfUnity(n,
                         r0+r,
                         circle_rad);

        ofPopMatrix();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){

    
    ofBackgroundHex(
                    0xfff6cf);
//                    0x000000);
    
    float mouseYCtrl = mouseY/2000.0;
    
    drawYantra(
        ofGetElapsedTimef() * mouseYCtrl,
        hue
    );
    
//
//    float t = ofGetElapsedTimef() / 2.0;
//    ofPushMatrix();
//    ofTranslate(400,400);
//
//    int scale = 100;
//    ofColor c = ofColor(0,0,0);
//    c.setBrightness(240);
//    ofSetColor(c);
//
////    float x = dblWingX(t);
////    float y = dblWingY(t);
//
////    float x = scribbleBallX(t/2.0);
////    float y = scribbleBallY(t/2.0);
//
//    ofDrawCircle(scale*x,scale*y,3);
//    //add to draw path
//    if (line.size() > 400){
//       line.getVertices().erase(line.getVertices().begin());
//    }
//    line.addVertex(scale*x,scale*y);
//    line.draw();
//
//    ofPopMatrix();
    
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
