#include "welcomeScene.h"



WelcomeScene::WelcomeScene() {}

WelcomeScene::~WelcomeScene() {}


bool WelcomeScene::init() {
	if (!Scene::init()) return false;

	auto welcomeLayer = WelcomeLayer::create();
	if (welcomeLayer) addChild(welcomeLayer);

	return true;
}


