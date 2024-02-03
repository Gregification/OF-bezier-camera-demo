#include "ofApp.h"

void ofApp::setup() {
	fancyIdleCam.setup();
}

void ofApp::update(){
}

void ofApp::draw() {
	fancyIdleCam.draw();

	ofDrawBitmapString("press SPACE to get started", ofGetWidth()/2, ofGetHeight()/2);
}

void ofApp::keyPressed(int key) {
	if (key == ' ')
		;
}

void ofApp::keyReleased(int key)
{
}

void ofApp::mouseMoved(int x, int y)
{
}

void ofApp::mouseDragged(int x, int y, int button)
{
}

void ofApp::mousePressed(int x, int y, int button)
{
}

void ofApp::mouseReleased(int x, int y, int button)
{
}

void ofApp::mouseEntered(int x, int y)
{
}

void ofApp::mouseExited(int x, int y)
{
}

void ofApp::windowResized(int w, int h)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

void ofApp::gotMessage(ofMessage msg){

}