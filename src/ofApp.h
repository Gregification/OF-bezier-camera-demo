#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "fancyIdleCamera.h"
#include <AreaSelector.h>
#include <Evaluator.h>

class ofApp : public ofBaseApp {

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

		fancyIdleCamera fancyIdleCam;
		AreaSelector areaSelector;
		Evaluator evaluator;

	private:
		static ofVec3f getRandVec3(float min, float max) {
			return ofVec3f(ofRandom(min, max), ofRandom(min, max), ofRandom(min, max));
		}

		enum State {opening,locationPicker, analizer};
		State state = State::opening;
		void transistionState(State newState);
};
