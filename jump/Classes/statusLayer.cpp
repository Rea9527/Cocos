#include "statusLayer.h"


StatusLayer::StatusLayer() {}

StatusLayer::~StatusLayer() {}


bool StatusLayer::init() {

	if (!Layer::init()) return false;

	auto winSize = Director::getInstance()->getWinSize();

	//跑马灯实现
	marquee = Marquee::create();
	marquee->show("Good Luck!!");
	marquee->setPosition(Vec2(440, 550));
	this->addChild(marquee);

	//分数
	_currentPoint = 0;
	_countDownLabel = Label::createWithSystemFont(String::createWithFormat("Score: %d", _currentPoint)->getCString(), "微软雅黑", 24);
	_countDownLabel->setPosition(Point(800, 550));
	_countDownLabel->setTextColor(Color4B(0, 0, 0, 200));
	addChild(_countDownLabel, 2);

	//暂停按钮
	Button* pauseBtn = Button::create("pause.png");
	pauseBtn->setPosition(Point(40, winSize.height - 40));
	pauseBtn->setScale(0.5);
	pauseBtn->addTouchEventListener([=](Ref* sender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			auto _pauseLayer = PauseLayer::create();
			Director::getInstance()->pause();

		}
	});
	addChild(pauseBtn, 2);

	return true;
}

void StatusLayer::addScore() {
		++_currentPoint;
		_countDownLabel->setString(String::createWithFormat("Score: %d", _currentPoint)->getCString());

}

int StatusLayer::getScore() {
	return _currentPoint;
}