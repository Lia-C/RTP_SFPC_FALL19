#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(640,480);
    tracker.setup();
    
    tracker_mask.setup();
    mask1.load("calm_nic.png");
    mask2.load("excited_nic.png");

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    if (grabber.isFrameNew()){
        tracker.update(grabber);
    }
    
    tracker_mask.update(mask1);
    

}

vector<ofPoint> getEyeAvg(ofxFaceTracker2 tracker){
    
    ofPolyline leye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::LEFT_EYE);
            
            ofPoint lavg;
            for (int i = 0; i < leye.size(); i++){
                lavg += leye[i];
            }
            lavg /= (float)leye.size();
            
        
             ofPolyline reye = tracker.getInstances()[0].getLandmarks().getImageFeature(ofxFaceTracker2Landmarks::RIGHT_EYE);
            
            ofPoint ravg;
            for (int i = 0; i < reye.size(); i++){
                ravg += reye[i];
            }
            ravg /= (float)reye.size();
    
    return vector<ofPoint>{lavg, ravg};
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    mask1.draw(0,0);
    tracker_mask.drawDebug();
    
//    grabber.draw(0,0);
//     tracker.drawDebug();
    
    
    
//    vector<ofPoint> cam_eyes = getEyeAvg(tracker);
//    vector<ofPoint> mask_eyes = getEyeAvg(tracker_mask);
    
    if (tracker.size() > 0){
        
//        ofDrawLine(cam_eyes[0], cam_eyes[1]);
//
//        ofPoint cam_diff = cam_eyes[1] - cam_eyes[0];
//        ofPoint mask_diff = mask_eyes[1] - mask_eyes[0];
//
//        ofPoint diff_vec = cam_diff - mask_diff;
//
//        float cam_length = cam_diff.length();
//        float mask_length = mask_diff.length();
//
//        float mask_scale = cam_length / mask_length;
//        float angle = atan2();
        
        
        
        //draw right eye circle
//        ofCircle(ravg,5);
        
        // comment these lines more :)
//        ofPoint diff = ravg - lavg;
//        float angle = atan2(diff.y, diff.x);
//        float length = diff.length();
//        float scale = 300.0 / length;
    
        
        ofPushMatrix();
        ofTranslate(300,300);
        
//        grabber.setAnchorPoint(lavg.x, lavg.y);
//        ofRotateZRad(-angle);
//        ofScale(scale,scale);
        
//        grabber.draw(0,0);
        ofPopMatrix();
        
        
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
