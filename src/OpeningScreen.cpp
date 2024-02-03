#include "OpeningScreen.h"

void OpeningScreen::setup() {
	fancyIdleCam.setup();
}

void OpeningScreen::update() {
}

void OpeningScreen::draw() {
	fancyIdleCam.draw();

	ofDrawBitmapString("press SPACE to get started", ofGetWidth() / 2, ofGetHeight() / 2);
}

void OpeningScreen::keyPressed(int key) {
	if (key == ' ')

		;

}
