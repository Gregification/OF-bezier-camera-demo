#include "ofApp.h"

void ofApp::setup() {
	transistionState(State::opening);
}

void ofApp::update(){
	switch (state) {
		case State::opening: break;

		case State::locationPicker: {
			areaSelector.update();
		} break;

		case State::analizer: {
			evaluator.draw();
		} break;
	}
}

void ofApp::draw() {
	switch (state) {
		case State::opening: {
			fancyIdleCam.draw();
			ofDrawBitmapString("press SPACE to get started", ofGetWidth() / 2, ofGetHeight() / 2);;
		} break;

		case State::locationPicker: {
			areaSelector.draw();
		} break;

		case State::analizer: {
			evaluator.draw();
		} break;
	}
}

void ofApp::keyPressed(int key) {
	switch (state) {
		case State::opening: {
			if (key == ' ') transistionState(State::locationPicker);				
		} break;

		case State::locationPicker: {
			areaSelector.keyPressed(key);
		} break;

		case State::analizer: {
			evaluator.keyPressed(key);
		} break;
	}
}

void ofApp::keyReleased(int key)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.keyReleased(key);
		} break;

		case State::analizer: {
			evaluator.keyReleased(key);
		} break;
	}
}

void ofApp::mouseMoved(int x, int y)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.mouseMoved(x,y);
		} break;

		case State::analizer: {
			evaluator.mouseMoved(x,y);
		} break;
	}
}

void ofApp::mouseDragged(int x, int y, int button)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.mouseDragged(x,y, button);
		} break;

		case State::analizer: {
			evaluator.mouseDragged(x, y, button);
		} break;
	}
}

void ofApp::mousePressed(int x, int y, int button)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.mousePressed(x, y, button);
		} break;

		case State::analizer: {
			evaluator.mousePressed(x, y, button);
		} break;
	}
}

void ofApp::mouseReleased(int x, int y, int button)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.mouseReleased(x, y, button);
		} break;

		case State::analizer: {
			evaluator.mouseReleased(x, y, button);
		} break;
	}
}

void ofApp::mouseEntered(int x, int y)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.mouseEntered(x, y);
		} break;

		case State::analizer: {
			evaluator.mouseEntered(x, y);
		} break;
	}
}

void ofApp::mouseExited(int x, int y)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.mouseExited(x, y);
		} break;

		case State::analizer: {
			evaluator.mouseExited(x, y);
		} break;
	}
}

void ofApp::windowResized(int w, int h)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.windowResized(w, h);
		} break;

		case State::analizer: {
			evaluator.windowResized(w, h);
		} break;
	}
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.dragEvent(dragInfo);
		} break;

		case State::analizer: {
			evaluator.dragEvent(dragInfo);
		} break;
	}
}

void ofApp::gotMessage(ofMessage msg){
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.gotMessage(msg);
		} break;

		case State::analizer: {
			evaluator.gotMessage(msg);
		} break;
	}
}

void ofApp::transistionState(State newState)
{
	switch (newState)
	{
		case State::opening: {
			fancyIdleCam.setup();
		} break;

		case State::locationPicker: {
			areaSelector.setup();
		} break;

		case State::analizer: {
			if(areaSelector.isReady())
				evaluator.setup();
		} break;
	}

	if (state != State::opening)
		fancyIdleCam.disable();

	state = newState;
}
