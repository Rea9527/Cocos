#include "gameoverLayer.h"


GameOverLayer::GameOverLayer() {}

GameOverLayer::GameOverLayer(int score) : finalScore(score) {}

GameOverLayer::~GameOverLayer() {}


bool GameOverLayer::init() {
	if (!LayerColor::initWithColor(Color4B(252, 255, 255, 255))) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	Label* over = Label::createWithSystemFont("Game Over", "Trebuchet-BoldItalic", 44);
	over->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 1.3));
	over->setTextColor(Color4B(0, 0, 0, 200));
	addChild(over);

	finalScore = (dynamic_cast<StatusLayer*>(Director::getInstance()->getRunningScene()->getChildByTag(20)))->getScore();

	Label* score = Label::createWithSystemFont(String::createWithFormat("Your final score is %d", finalScore)->getCString(), "Trebuchet-BoldItalic", 36);
	score->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 1.6));
	score->setTextColor(Color4B(0, 0, 0, 200));
	addChild(score);

	Button* startGameBtn = Button::create("restart.png");
	startGameBtn->setPosition(Point(origin.x + visibleSize.width / 2-80, origin.y + visibleSize.height/2.3));
	startGameBtn->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type) {
		if (Widget::TouchEventType::ENDED == type) {
			auto scene = GameScene::create();
			Director::getInstance()->replaceScene(scene);
		}
	});

	addChild(startGameBtn);

	Button* stopGameBtn = Button::create("stop.png");
	stopGameBtn->setPosition(Point(origin.x + visibleSize.width / 2+80, origin.y + visibleSize.height / 2.3));
	stopGameBtn->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			auto scene = WelcomeScene::create();
			Director::getInstance()->replaceScene(scene);
		}
	});
	addChild(stopGameBtn);
	return true;
}