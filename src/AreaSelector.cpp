#include "AreaSelector.h"

void AreaSelector::setup() {
	gui.setup("location editor");

	gui.add(apiKey.setup("google maps api key", ""));
	gui.add(apiSignature.setup("google maps api signature", ""));
	gui.add(latitudeField.setup("latitude", 0));
		latitudeField.setMax(90);
		latitudeField.setMin(-90);
	gui.add(longitudeField.setup("longitude", 0));
		longitudeField.setMax(180);
		longitudeField.setMin(-180);
	gui.add(zoomLevelSlider.setup("zoom", 17, 14, 22));
}

void AreaSelector::draw() {
	gui.draw();
}

void AreaSelector::update()
{
}

void AreaSelector::keyPressed(int key)
{
}

void AreaSelector::keyReleased(int key)
{
}

void AreaSelector::mouseMoved(int x, int y)
{
}

void AreaSelector::mouseDragged(int x, int y, int button)
{
}

void AreaSelector::mousePressed(int x, int y, int button)
{
}

void AreaSelector::mouseReleased(int x, int y, int button)
{
}

void AreaSelector::mouseEntered(int x, int y)
{
}

void AreaSelector::mouseExited(int x, int y)
{
}

bool AreaSelector::isReady() {
	return false;
}
