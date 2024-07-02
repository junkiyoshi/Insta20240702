#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 50, true, true, true);
	this->word = "01";
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofSeedRandom(39);
	for (int i = 0; i < 36; i++) {

		auto location = glm::vec3(-25, -250, 0);

		ofPath chara_path = this->font.getCharacterAsPoints(this->word[(int)ofRandom(this->word.size())], true, false);
		vector<ofPolyline> outline = chara_path.getOutline();

		ofFill();
		ofSetColor(255);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			ofNextContour(true);

			//outline[outline_index] = outline[outline_index].getResampledByCount(500);
			auto vertices = outline[outline_index].getVertices();
			for (auto& vertex : vertices) {

				float rotate_deg = i * 10;

				glm::vec3 v = location + vertex;
				auto rotation = glm::rotate(glm::mat4(), rotate_deg * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));
				v = glm::vec4(v, 0) * rotation;

				int len = glm::length(v);
				len = (len / 15) * 15;
				rotate_deg = ofMap(ofNoise(len * 0.0035 - ofGetFrameNum() * 0.02), 0, 1, -90, 90);
				rotation = glm::rotate(glm::mat4(), rotate_deg * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));
				v = glm::vec4(v, 0) * rotation;

				ofVertex(v);
			}
		}
		ofEndShape(true);

		ofNoFill();
		ofSetColor(0);
		ofBeginShape();
		for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

			ofNextContour(true);

			//outline[outline_index] = outline[outline_index].getResampledByCount(500);
			auto vertices = outline[outline_index].getVertices();
			for (auto& vertex : vertices) {

				float rotate_deg = i * 10;

				glm::vec3 v = location + vertex;
				auto rotation = glm::rotate(glm::mat4(), rotate_deg * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));
				v = glm::vec4(v, 0) * rotation;

				int len = glm::length(v);
				len = (len / 15) * 15;
				rotate_deg = ofMap(ofNoise(len * 0.0035 - ofGetFrameNum() * 0.02), 0, 1, -90, 90);
				rotation = glm::rotate(glm::mat4(), rotate_deg * (float)DEG_TO_RAD, glm::vec3(0, 0, 1));
				v = glm::vec4(v, 0) * rotation;

				ofVertex(v);
			}
		}
		ofEndShape(true);
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}