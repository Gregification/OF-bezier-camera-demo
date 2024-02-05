#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class AreaSelector : public ofBaseApp {
	public:
		void setup();
		void draw();
		void update();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h) {};
		void dragEvent(ofDragInfo dragInfo) {};
		void gotMessage(ofMessage msg) {};

		bool isReady();

	private:
		void onFetchimagePress(const void* src);
		shared_ptr<ofImage> loadImage(std::string url);

		shared_ptr<ofImage> image;

		ofxPanel gui;
		
		ofxFloatField
			latitudeField,
			longitudeField;
		ofxIntField
			resolutionX,
			resolutionY;
		ofxIntSlider
			zoomLevelSlider;
		ofxTextField
			apiKey,
			apiSignature;
		ofxButton
			getImgButton;
};
