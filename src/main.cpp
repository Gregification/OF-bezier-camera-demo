#include "ofMain.h"
#include "ofApp.h"

/**
* apparently state management is not a concept openframework recoginizes, neither is inheritance it seems too
*/

//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	shared_ptr<ofAppBaseWindow> window = ofCreateWindow(settings);
	auto opening = make_shared<ofApp>();

	ofRunApp(window, opening);
	ofRunMainLoop();
}
