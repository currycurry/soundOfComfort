#pragma once

#include "ofMain.h"
#define NPINS 12

class ofApp : public ofBaseApp{
    
    public:
        void setup();
        void serialFunction();
        void update();
        void draw();
        
        void keyPressed  (int key);
        void keyReleased (int key);
        
        bool fullscreen;
        bool singlePlay;
        
        ofSerial serial;
        
        int boxX, boxY;
        
        bool touched[ NPINS ];
        bool lastTouched[ NPINS ];
        ofColor color[ NPINS ];
        ofSoundPlayer   track[ NPINS ];
        
        string mode;
    
        int trackNumber, lastTrackNumber;
    
    
};
