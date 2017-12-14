#include "welcomeLayer.h"


WelcomeLayer::WelcomeLayer() {}

WelcomeLayer::~WelcomeLayer() {}


bool WelcomeLayer::init() {

	if (!Layer::init()) return false;

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	auto bg = Sprite::createWithSpriteFrameName("background.png");
	bg->setAnchorPoint(Point::ZERO);
	bg->setPosition(Point::ZERO);
	addChild(bg);

	Label* label = Label::createWithSystemFont("Numb Brick", "Arial", 40);
	label->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 120));
	label->setTextColor(Color4B(0, 0, 0, 120));
	this->addChild(label, 1);

	Button* startGameBtn = Button::create("restart.png");
	startGameBtn->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 250));
	startGameBtn->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type) {
		if (Widget::TouchEventType::ENDED == type) {
			auto scene = GameScene::create();
			//TransitionScene *transition = TransitionFadeBL::create(0.1f, scene);
			Director::getInstance()->replaceScene(scene);
		}
	});

	addChild(startGameBtn);

	

	return true;
}
