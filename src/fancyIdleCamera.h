#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class fancyIdleCamera {
	public:
		void setup();
		void begin();
		void end();
		void draw();
		void doIdel();
		void makeShapeField();

		vector<unique_ptr<ofNode>> nodes;
		ofEasyCam camera;

		ofxPanel gui;
		ofParameterGroup optionsGroup;
		ofParameter<int> 
			jiggleParam,
			numAnchorsParam;
		ofParameter<float>
			tParam,
			minTParam,
			maxTParam,
			damperParam,
			deltaTMaxParam,
			stepSizeParam;
		ofParameter<bool> lookAtRandomParam;

	private:
		inline long binom(size_t n, size_t k) noexcept;

		struct coeffPoint {
			double coeff;
			ofVec3f point;
			coeffPoint() : coeffPoint(0, ofVec3f(0, 0, 0)) {}
			coeffPoint(double d, ofVec3f vec) : coeff(d), point(vec) {}
		};

		float
			stepSign = 1,
			deltaT = 0;
		int idx = 0;
		vector<coeffPoint> coeffs;

		std::chrono::milliseconds formerTime;

		static ofVec3f getRandVec3(float min, float max) {
			return ofVec3f(ofRandom(min, max), ofRandom(min, max), ofRandom(min, max));
		}
};

