#include "AreaSelector.h"
//windows only because openframework's ofImage.loadImage(...) cant handle https redirection

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
	gui.add(resolutionX.setup("resolution X", 400));
		resolutionX.setMin(120);
		resolutionX.setMax(1280);//high end of the reasonable limits
	gui.add(resolutionY.setup("resolution Y", 400));
		resolutionY.setMin(120);
		resolutionY.setMax(1280);
	gui.add(zoomLevelSlider.setup("zoom", 17, 1, 20));
	gui.add(getImgButton.setup("fetch img"));

	onFetchimagePress(NULL);
	getImgButton.addListener(this, &AreaSelector::onFetchimagePress);

	system("powershell {mkdir C:/solarExposureCExtimatorCacheFolder}");

	image = loadImage("https://cataas.com/cat/sad/says/no%20location%20provided");

	std::ifstream f("../.env");
	std::string key;
	f >> key;
	apiKey = key;
	f.close();
}

void AreaSelector::draw() {
	const auto& img = image.get();
	if (img->isAllocated())
		img->draw(ofGetWidth()/2 - img->getWidth()/2, ofGetHeight() / 2 - img->getHeight() / 2);

	gui.draw();
}

void AreaSelector::update() {
	
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

void AreaSelector::onFetchimagePress(const void * src) {
	static auto getCurTimeMili = []() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()); };
	
	//hardcoded spam catch. works good enough
	static auto formerTime = getCurTimeMili();
	auto currTime = getCurTimeMili();
	if ((currTime - formerTime).count() < 1500) return;
	formerTime = currTime;

	auto key = apiKey.getParameter().toString();
	if (key.length() < 5) return;

	//we live in a socitey (a high trust socitey)
	std::string url; 
	{
		auto str = std::stringstream();
		str << "https://maps.googleapis.com/maps/api/staticmap?";
		str << "center="	<< longitudeField	<< ","	<< latitudeField;
		str << "\"&\"zoom="		<< zoomLevelSlider;
		str << "\"&\"size="		<< resolutionX		<< "x"	<< resolutionY;
		str << "\"&\"key="		<< key;
		url = str.str();
	}
	cout << "url " << url << endl;
	image = loadImage(url);
}

shared_ptr<ofImage> AreaSelector::loadImage(std::string src) {
	const char* url = src.c_str();
	//download image
	static const char* destFile = "C:/solarExposureCExtimatorCacheFolder/openFrameworksSucks.png";

	{
		auto str = std::stringstream();
		str << "powershell;";
		str << "wget ";
		str << "'" << url << "'";
		str << " -O " << destFile;
		cout << str.str() << endl;
		system(str.str().c_str());
		cout << "system done" << endl;
	}

	//reopen the image
	ofImage img;
	img.load(destFile);

	return std::make_shared<ofImage>(img);
}
