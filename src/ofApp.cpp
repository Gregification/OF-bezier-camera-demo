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
	}
}

void ofApp::draw() {
	switch (state) {
		case State::opening: {
			fancyIdleCam.draw();
			//ofDrawBitmapString("press SPACE to get started", ofGetWidth() / 2, ofGetHeight() / 2);;
		} break;

		case State::locationPicker: {
			areaSelector.draw();
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

	}
}

void ofApp::gotMessage(ofMessage msg){
	switch (state) {
		case State::opening: {

		} break;

		case State::locationPicker: {
			areaSelector.gotMessage(msg);
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

	}

	if (state != State::opening)
		fancyIdleCam.disable();

	state = newState;
}
