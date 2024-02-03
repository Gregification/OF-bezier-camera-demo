#pragma once
#include "ofMain.h"
#include "fancyIdleCamera.h"

class OpeningScreen : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		fancyIdleCamera fancyIdleCam;

};

