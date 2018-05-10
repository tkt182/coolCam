#pragma once

#include "ofMain.h"
#include "ofxRollingCam.h"
#include "ofxTrackingCamera.h"
#include "ofxPostGlitch.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioIn(float * input, int bufferSize, int nChannels);
    
        ofSoundStream soundStream;
        float curVol;
        int   blockCnt;
    
        ofxRollingCam rollCam;
        ofxTrackingCamera trackingCam;
        ofCamera *cam;
    
        bool cameraType = 0;
    
        ofLight lig;
        std::vector <ofVec3f> pos;
        bool hide;
		
        ofImage			lenna;
        bool			bDrawLenna;
        bool			bShowHelp;

    
        ofFbo			myFbo;
    
        ofTexture		texture;
    
        /*Addon instance*/
        ofxPostGlitch	myGlitch;
    
    
};
