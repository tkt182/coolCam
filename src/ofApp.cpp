#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofHideCursor();
    rollCam.setup();//rollCam's setup.
    rollCam.setCamSpeed(0.1);//rollCam's speed set;
    ofBackground(0);
    lig.setup();
    lig.setAmbientColor(ofFloatColor(0.5,0.5,0.5,1.0));
    
    blockCnt = 15;
    float r=ofGetHeight()*0.8;
    for (int i=0; i<100; i++) {
        ofVec3f newPos;
        newPos.set(ofRandomf()*r,ofRandomf()*r,ofRandomf()*r);
        pos.push_back(newPos);
    }
    
    //bShowHelp  = false;
    myFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    myGlitch.setup(&myFbo);

    soundStream.setup(this, 0, 1, 44100, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cout << curVol << endl;
    
    if(curVol > 0.005){
        if(blockCnt == 15){
            rollCam.setRandomScale(0.5, 1.5);
            rollCam.setRandomPos(270);
        }
        blockCnt--;
        if(blockCnt < 0){
            blockCnt = 15;
        }
    }
    
    rollCam.update();   //rollCam's rotate update.

    myFbo.begin();
    ofClear(0, 0, 0,255);
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofEnableLighting();
    lig.setPosition(0, -ofGetWindowHeight()/2, ofGetWindowHeight()/3);
    //lig.draw();
    lig.enable();
    ofPopMatrix();
    
    //ofPushMatrix();
    rollCam.begin(); //rollCam begin
    ofEnableDepthTest();
    ofFill();
    ofSetColor(255,255,255);
    ofDrawBox(0, 0, 0, ofGetWindowHeight()/3);
    
    for (int i=0; i<pos.size(); i++) {
        ofSetColor(255*((float)i/pos.size()));
        ofDrawBox(pos[i].x, pos[i].y, pos[i].z, ofGetWindowHeight()/20);
    }
    
    ofPopMatrix();
    
    myFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    myFbo.draw(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='1') {//All Random.
        rollCam.setRandomScale(0.5, 1.5);
        rollCam.setRandomPos(270);
    }
    if (key=='2') {//Random rotate.
        rollCam.setRandomPos(270);
    }
    if (key=='3') {//Inputting optional rotate.
        rollCam.setPos(0, 0, 0);
    }
    if (key=='4') {//Random distance.
        rollCam.setRandomScale(0.5, 1.5);
    }
    if (key=='5') {//Inputting optional distance.
        rollCam.setScale(1);
    }
    
    if (key==' ') {
        ofToggleFullscreen();
    }
    
    if (key == 'q') myGlitch.toggleFx(OFXPOSTGLITCH_CONVERGENCE);
    if (key == 'w') myGlitch.toggleFx(OFXPOSTGLITCH_GLOW);
    if (key == 'e') myGlitch.toggleFx(OFXPOSTGLITCH_SHAKER);
    if (key == 'r') myGlitch.toggleFx(OFXPOSTGLITCH_CUTSLIDER);
    if (key == 't') myGlitch.toggleFx(OFXPOSTGLITCH_TWIST);
    if (key == 'y') myGlitch.toggleFx(OFXPOSTGLITCH_OUTLINE);
    if (key == 'u') myGlitch.toggleFx(OFXPOSTGLITCH_NOISE);
    if (key == 'i') myGlitch.toggleFx(OFXPOSTGLITCH_SLITSCAN);
    if (key == 'o') myGlitch.toggleFx(OFXPOSTGLITCH_SWELL);
    if (key == 'p') myGlitch.toggleFx(OFXPOSTGLITCH_INVERT);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    /*
    if (key == 'a') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == 's') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == 'd') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == 'f') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == 'g') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == 'h') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == 'j') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == 'k') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == 'l') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == ';') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    */
     
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    curVol = 0.0;
    for (int i = 0; i < bufferSize; i++){
        curVol += input[i]*input[i]; // 聴覚上は出力の2乗に比例するので、2乗しています。
    }
    curVol /= bufferSize; // 平均を取ります。
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
