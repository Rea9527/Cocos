#include "bgLayer.h"


BgLayer::BgLayer() {}

BgLayer::~BgLayer() {}


bool BgLayer::init() {
	
	if (!Layer::init()) return false;

	auto background = Sprite::createWithSpriteFrameName("background.png");
	background->setAnchorPoint(Point::ZERO);
	background->setPosition(Point::ZERO);
	addChild(background);

	return true;
}