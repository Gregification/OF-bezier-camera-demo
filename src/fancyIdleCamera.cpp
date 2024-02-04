#include "fancyIdleCamera.h"

void fancyIdleCamera::setup() {
	optionsGroup.setName("fancy idle camera");

	optionsGroup.add(numAnchorsParam.set("anchors", 4, 2, 30));
	optionsGroup.add(damperParam.set("damper", .7f, 0, 1));
	optionsGroup.add(stepSizeParam.set("step size", .02f, .001, 1));
	optionsGroup.add(minTParam.set("min T", -.2, -2, 2));
	optionsGroup.add(maxTParam.set("max T", 1, -2, 2));
	optionsGroup.add(deltaTMaxParam.set("delta T trigger", 1, .1, 2));
	optionsGroup.add(tParam.set("t", 0, -2, 2));
	optionsGroup.add(lookAtRandomParam.set("flouride stare", true));
	optionsGroup.add(jiggleParam.set("jiggle", 1, 0, 90));

	gui.setup(optionsGroup);

	makeShapeField();
}

void fancyIdleCamera::begin() {
	camera.begin();
}

void fancyIdleCamera::end() {
	camera.end();
}

void fancyIdleCamera::draw(){
	doIdel();

	camera.begin();

	for (auto& node : nodes) {
		node.get()->rotateDeg(jiggleParam, getRandVec3(-1, 1));
		node.get()->draw();
	}

	camera.end();

	gui.draw();
}

void fancyIdleCamera::doIdel() {
	static auto getCurTimeMili = []() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()); };

	int n = numAnchorsParam;
	float
		stepSize = stepSizeParam / 1000, // per second. ".5 / 1000" => .5 
		deltaTMax = deltaTMaxParam,
		minT = minTParam,
		maxT = maxTParam,
		t = tParam,
		damper = damperParam;

	if (coeffs.size() != n) {
		coeffs.resize(n);
		std::fill(coeffs.begin(), coeffs.end(), coeffPoint());
		
		idx %= n;
		deltaT = n * deltaTMax;
	}

	auto currTime = getCurTimeMili();
	float step = stepSize * (currTime - formerTime).count();
	formerTime = currTime;

	t += step * stepSign;
	deltaT += step;
	
	if (t < minT || t > maxT) {
		t = std::max(minT, std::min(t, maxT));//clamp
		stepSign *= -1;
	}

	int maxLoops = n;
	while (deltaT > deltaTMax) {
		auto& cp = coeffs.at(idx);
		
		if (cp.coeff == 0)
			cp.coeff = binom(n, idx);

		cp.point = nodes.at((int)ofRandom(0, nodes.size())).get()->getGlobalPosition();

		deltaT -= deltaTMax;
		if (maxLoops == 0) deltaT = 0;
		maxLoops--;

		idx++;
		if (idx >= n) idx = 0;
	}

	ofVec3f pos(0, 0, 0);
	float actualT = t;// std::abs(t);
	for (int i = 0; i < n; i++) {
		auto& cp = coeffs[i];
		pos += std::pow(actualT, i) * std::pow(1 - actualT, n - i) * cp.coeff * cp.point;
	}

	tParam.set(t);

	camera.setGlobalPosition(pos * damper);
	if (lookAtRandomParam)
		camera.lookAt(coeffs.at(idx).point);
}

void fancyIdleCamera::makeShapeField() {
	int n = 1000;
	float size = 100;
	float range = 1200;

	static auto getRandColor = []() { return ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)); };

	for (int i = 0; i < n; i++) {
		ofBoxPrimitive box(ofRandom(size / 2, size), ofRandom(size / 2, size), ofRandom(size / 2, size));
		box.setGlobalPosition(getRandVec3(-range, range));

		for (int i = 0; i < 6; i++)
			box.setSideColor(i, getRandColor());

		nodes.push_back(std::make_unique<ofBoxPrimitive>(box));
	}

}

void fancyIdleCamera::disable() {
	nodes.clear();
	coeffs.clear();
}

inline long fancyIdleCamera::binom(size_t n, size_t k) noexcept {
	if (k == 0 || k == n)
		return 1;
	return binom(n - 1, k - 1) + binom(n - 1, k);
}
