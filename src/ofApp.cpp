#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
	
	ofBackground( 0 );
	ofSetLogLevel(OF_LOG_NOTICE);
    
	//-----------------------------------
	//font.loadFont("DIN.otf", 64);
    
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	serial.setup(0, 9600); //open the first device
	
	serial.setup("/dev/tty.usbmodem12341", 9600); // mac osx example
    serial.flush( true, true );
    
    boxX = ofGetWindowWidth() / NPINS;
    boxY = ofGetWindowHeight() / 3;
    
    trackNumber = 1;
    
    track[ 0 ].loadSound( "sounds/Track1/Bass.aif" );
    track[ 1 ].loadSound( "sounds/Track1/Cowbell.aif" );
    track[ 2 ].loadSound( "sounds/Track1/Didgeridoo.aif" );
    track[ 3 ].loadSound( "sounds/Track1/Drums.aif" );
    track[ 4 ].loadSound( "sounds/Track1/EKit_Claps.aif" );
    track[ 5 ].loadSound( "sounds/Track1/Flute.aif" );
    track[ 6 ].loadSound( "sounds/Track1/Horns.aif" );
    track[ 7 ].loadSound( "sounds/Track1/Keyboard.aif" );
    track[ 8 ].loadSound( "sounds/Track1/Organ.aif" );
    track[ 9 ].loadSound( "sounds/Track1/Tambourine.aif" );
    track[ 10 ].loadSound( "sounds/Track1/Triangle.aif" );
    track[ 11 ].loadSound( "sounds/Track1/Wah_Gtr.aif");
    
    
    for( int i = 0; i < NPINS; i ++  ) {
        color[ i ].set( 255, 0, 0 );
        track[ i ].setVolume( 0.0f );
        track[ i ].setLoop( true );
        track[ i ].setMultiPlay( false );
        track[ i ].play();
        touched[ i ] = false;
        lastTouched[ i ] = false;
    }
    
    fullscreen = true;
    singlePlay = true;
    
    ofHideCursor();
    
    mode = "Track 1 - Original";
}

//--------------------------------------------------------------
void ofApp::update(){
    
    serialFunction();
    
    ofSetFullscreen( fullscreen );
    boxX = ofGetWindowWidth() / NPINS;
    boxY = ofGetWindowHeight() / 3;
    
    //if ( singlePlay ) {
        
        for ( int i = 0; i < NPINS; i ++ ) {
            
            if ( lastTouched[ i ] != touched[ i ] ) {
                if ( touched[ i ] ) {
                    color[ i ].set( 0, 255, 0 );
                    track[ i ].setVolume( 1.0f );
                }
                else {
                    color[ i ].set( 255, 0, 0 );
                    track[ i ].setVolume( 0.0f );
                }
            }
        }
    //}
    
    
    if ( !singlePlay ) {
        
        if ( trackNumber == 1 && touched[ 5 ] == false ) {
            if ( touched[ 11 ] == true ) {
                trackNumber = 2;
            }
        }
        
        if ( trackNumber == 2 && touched[ 11 ] == false ) {
            if ( touched[ 5 ] == true ) {
                trackNumber = 1;
            }
        }
        
        if ( trackNumber == 1 && lastTrackNumber != 1 ) {
            
            mode = "Track 1 - Original";
            trackNumber = 1;
            
            track[ 0 ].loadSound( "sounds/Track1/Bass.aif" );
            track[ 1 ].loadSound( "sounds/Track1/Cowbell.aif" );
            track[ 2 ].loadSound( "sounds/Track1/Didgeridoo.aif" );
            track[ 3 ].loadSound( "sounds/Track1/Drums.aif" );
            track[ 4 ].loadSound( "sounds/Track1/EKit_Claps.aif" );
            track[ 5 ].loadSound( "sounds/Track1/Flute.aif" );
            track[ 6 ].loadSound( "sounds/Track1/Horns.aif" );
            track[ 7 ].loadSound( "sounds/Track1/Keyboard.aif" );
            track[ 8 ].loadSound( "sounds/Track1/Organ.aif" );
            track[ 9 ].loadSound( "sounds/Track1/Tambourine.aif" );
            track[ 10 ].loadSound( "sounds/Track1/Triangle.aif" );
            track[ 11 ].loadSound( "sounds/Track1/Wah_Gtr.aif");
            
            for( int i = 0; i < NPINS; i ++  ) {
                track[ i ].setPosition( 0.0f );
                //track[ i ].setVolume( 0.0f );
                track[ i ].setLoop( true );
                track[ i ].play();
                //touched[ i ] = false;
                //lastTouched[ i ] = false;
            }
            
        }
        
        if ( trackNumber == 2 && lastTrackNumber != 2 ) {
            
            mode = "Track 2 - Blood Orange";
            trackNumber = 2;
            
            track[ 0 ].loadSound( "sounds/Track2/Arp.aif" );
            track[ 1 ].loadSound( "sounds/Track2/Bass.aif" );
            track[ 2 ].loadSound( "sounds/Track2/Beat.aif" );
            track[ 3 ].loadSound( "sounds/Track2/Bells.aif" );
            track[ 4 ].loadSound( "sounds/Track2/Hat_Snare.aif" );
            track[ 5 ].loadSound( "sounds/Track2/Kick.aif" );
            track[ 6 ].loadSound( "sounds/Track2/Lead_1.aif" );
            track[ 7 ].loadSound( "sounds/Track2/Lead_2.aif" );
            track[ 8 ].loadSound( "sounds/Track2/Pads.aif" );
            track[ 9 ].loadSound( "sounds/Track2/Percussion.aif" );
            track[ 10 ].loadSound( "sounds/Track2/Sweeps.aif" );
            track[ 11 ].loadSound( "sounds/Track2/Synth.aif" );
            
            for( int i = 0; i < NPINS; i ++  ) {
                track[ i ].setPosition( 0.0f );
                //track[ i ].setVolume( 0.0f );
                track[ i ].setLoop( true );
                track[ i ].play();
                //touched[ i ] = false;
                //lastTouched[ i ] = false;
            }
            
        }
        lastTrackNumber = trackNumber;
            
    }
        
    
    
    
    if ( track[ 7 ].getPosition() >= 1.0 ) {
        for ( int i = 0; i < NPINS; i ++ ) {
            track[ i ].setPosition( 0.0f );
        }
        
    }
    
    for ( int i = 0; i < NPINS; i ++ ) {
        lastTouched[ i ] = touched[ i ];
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground( 0 );
    
    for ( int i = 0; i < NPINS; i ++ ) {
        ofSetColor( color[ i ] );
        ofRect( i * boxX + 10, boxY, 75, 200 );
    }
    
    ofSetColor( 255 );
    ofDrawBitmapString( mode, 15, 30 );
    

}

//--------------------------------------------------------------
void ofApp::serialFunction(){
	while ( serial.available() > 0 ){
		
		int myByte = 0;
		
		myByte = serial.readByte();
		cout << myByte;
        for ( int i = 0; i < NPINS; i ++ ) {
            if ( myByte == i * 2 ){
                touched[ i ] = true;
            }
            if ( myByte == i * 2 + 1 ){
                touched[ i ] = false;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if ( key == 'f' || key == 'F' ) {
        if ( !fullscreen ) {
            fullscreen = true;
            ofHideCursor();
        }
        else {
            fullscreen = false;
        }
        
    }
    
    
    if ( singlePlay == true ) {
        
        
        
        if ( key == '1' ) { //original
            
            mode = "Track 1 - Original";
            trackNumber = 1;
            
            track[ 0 ].loadSound( "sounds/Track1/Bass.aif" );
            track[ 1 ].loadSound( "sounds/Track1/Cowbell.aif" );
            track[ 2 ].loadSound( "sounds/Track1/Didgeridoo.aif" );
            track[ 3 ].loadSound( "sounds/Track1/Drums.aif" );
            track[ 4 ].loadSound( "sounds/Track1/EKit_Claps.aif" );
            track[ 5 ].loadSound( "sounds/Track1/Flute.aif" );
            track[ 6 ].loadSound( "sounds/Track1/Horns.aif" );
            track[ 7 ].loadSound( "sounds/Track1/Keyboard.aif" );
            track[ 8 ].loadSound( "sounds/Track1/Organ.aif" );
            track[ 9 ].loadSound( "sounds/Track1/Tambourine.aif" );
            track[ 10 ].loadSound( "sounds/Track1/Triangle.aif" );
            track[ 11 ].loadSound( "sounds/Track1/Wah_Gtr.aif");
            
            for( int i = 0; i < NPINS; i ++  ) {
                track[ i ].setPosition( 0.0f );
                track[ i ].setVolume( 0.0f );
                track[ i ].setLoop( true );
                track[ i ].play();
                touched[ i ] = false;
                lastTouched[ i ] = false;
            }
            
        }
        
        if ( key == '2' ) {  //blood orange
            
            mode = "Track 2 - Blood Orange";
            trackNumber = 2;
            
            track[ 0 ].loadSound( "sounds/Track2/Arp.aif" );
            track[ 1 ].loadSound( "sounds/Track2/Bass.aif" );
            track[ 2 ].loadSound( "sounds/Track2/Beat.aif" );
            track[ 3 ].loadSound( "sounds/Track2/Bells.aif" );
            track[ 4 ].loadSound( "sounds/Track2/Hat_Snare.aif" );
            track[ 5 ].loadSound( "sounds/Track2/Kick.aif" );
            track[ 6 ].loadSound( "sounds/Track2/Lead_1.aif" );
            track[ 7 ].loadSound( "sounds/Track2/Lead_2.aif" );
            track[ 8 ].loadSound( "sounds/Track2/Pads.aif" );
            track[ 9 ].loadSound( "sounds/Track2/Percussion.aif" );
            track[ 10 ].loadSound( "sounds/Track2/Sweeps.aif" );
            track[ 11 ].loadSound( "sounds/Track2/Synth.aif" );
            
            for( int i = 0; i < NPINS; i ++  ) {
                track[ i ].setPosition( 0.0f );
                track[ i ].setVolume( 0.0f );
                track[ i ].setLoop( true );
                track[ i ].play();
                touched[ i ] = false;
                lastTouched[ i ] = false;
            }
            
        }
        
    }
    
    /*if ( key == '3' ) { //dual mode
        
        if ( !singlePlay ) {
            singlePlay = true;
        }
        else {
            singlePlay = false;
        }
        
    }*/
    
    
    
    /*if ( key == 'x' || key == 'X' ) {
     serial.flush( true, true );
     }*/
    
    if ( key == 'z' ){
        touched[ 0 ] = true;
    }
    if ( key == 's' ){
        touched[ 1 ] = true;
    }
    if ( key == 'x' ){
        touched[ 2 ] = true;
    }
    if ( key == 'd' ){
        touched[ 3 ] = true;
    }
    if ( key == 'c' ){
        touched[ 4 ] = true;
    }
    if ( key == 'v' ){
        touched[ 5 ] = true;
    }
    if ( key == 'n' ){
        touched[ 6 ] = true;
    }
    if ( key == 'j' ){
        touched[ 7 ] = true;
    }
    if ( key == 'm' ){
        touched[ 8 ] = true;
    }
    if ( key == 'k' ){
        touched[ 9 ] = true;
    }
    if ( key == ',' ){
        touched[ 10 ] = true;
    }
    if ( key == '.' ){
        touched[ 11 ] = true;
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if ( key == 'z' ){
        touched[ 0 ] = false;
    }
    if ( key == 's' ){
        touched[ 1 ] = false;
    }
    if ( key == 'x' ){
        touched[ 2 ] = false;
    }
    if ( key == 'd' ){
        touched[ 3 ] = false;
    }
    if ( key == 'c' ){
        touched[ 4 ] = false;
    }
    if ( key == 'v' ){
        touched[ 5 ] = false;
    }
    if ( key == 'n' ){
        touched[ 6 ] = false;
    }
    if ( key == 'j' ){
        touched[ 7 ] = false;
    }
    if ( key == 'm' ){
        touched[ 8 ] = false;
    }
    if ( key == 'k' ){
        touched[ 9 ] = false;
    }
    if ( key == ',' ){
        touched[ 10 ] = false;
    }
    if ( key == '.' ){
        touched[ 11 ] = false;
    }

}

