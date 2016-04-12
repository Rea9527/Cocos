#include "gameLayer.h"


GameLayer::GameLayer() {}

GameLayer::~GameLayer() {}

bool GameLayer::init() {

	if (!Layer::init()) return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	gameStatus = GAME_STATUS_READY;

	//边界
	edge = Sprite::create();
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setContactTestBitmask(1);
	edge->setPhysicsBody(edgeBody);
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(edge);

	//地面线
	groundLine = Node::create();
	auto groundBody = PhysicsBody::create();
	groundBody->addShape(PhysicsShapeBox::create(Size(visibleSize.width, 240)));
	groundBody->setDynamic(false);
	groundBody->setLinearDamping(0.0f);
	groundBody->setContactTestBitmask(1);
	groundLine->setPhysicsBody(groundBody);
	groundLine->setAnchorPoint(Point(0, 0));
	groundLine->setPosition(430, 0);
	addChild(groundLine);

	//地面1
	ground_1 = Sprite::createWithSpriteFrameName("ground.png");
	ground_1->setAnchorPoint(Point(0, 0));
	ground_1->setPosition(0, 0);
	addChild(ground_1, -1);

	ground_2 = Sprite::createWithSpriteFrameName("ground.png");
	ground_2->setAnchorPoint(Point(0, 0));
	ground_2->setPosition(ground_1->getContentSize().width-2.0f, 0);
	addChild(ground_2, -1);

	decorator_1 = Sprite::createWithSpriteFrameName("decorator.png");
	decorator_1->setAnchorPoint(Point(0, 0));
	decorator_1->setPosition(0, 0);
	addChild(decorator_1, -3);

	decorator_2 = Sprite::createWithSpriteFrameName("decorator.png");
	decorator_2->setAnchorPoint(Point(0, 0));
	decorator_2->setPosition(decorator_1->getContentSize().width - 2.0f, 0);
	addChild(decorator_2, -3);

	//创建浮木
	_wood = Sprite::createWithSpriteFrameName("Float.png");
	PhysicsBody* wBody = PhysicsBody::createBox(_wood->getContentSize());
	wBody->setDynamic(true);
	wBody->setContactTestBitmask(1);
	wBody->setCategoryBitmask(1);
	wBody->setLinearDamping(0.0f);
	wBody->setRotationEnable(false);
	wBody->setGravityEnable(false);
	CCLOG("aaaaa");
	_wood->setPhysicsBody(wBody);
	CCLOG("bbbbb");
	_wood->setPosition(Point(origin.x + visibleSize.width / 8, origin.y + visibleSize.height / 1.5));
	addChild(_wood);


	//触摸监听
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_0(GameLayer::onTouchBegan, this);
	eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(GameLayer::onContactSeperate, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

bool GameLayer::onTouchBegan() {
	if (this->gameStatus == GAME_STATUS_OVER) {
		return true;
	}
	else if (this->gameStatus == GAME_STATUS_READY) {
		this->gameStatus = GAME_STATUS_START;
		this->_wood->getPhysicsBody()->setGravityEnable(true);
		this->createBarriers();
		schedule(schedule_selector(GameLayer::shiftLand), 0, CC_REPEAT_FOREVER, 0.0f);
	}
	else if (this->gameStatus == GAME_STATUS_START) {
		Point pos = this->_wood->getPosition();
		Point newPos = Point(pos.x, pos.y + 10);
		this->_wood->getPhysicsBody()->setVelocity(Vect(0, 120));
		this->_wood->runAction(MoveTo::create(1, newPos));
	}

	return true;
}

bool GameLayer::onContactBegin(PhysicsContact& contact) {
	gameOver();
	return true;
}

void  GameLayer::onContactSeperate(PhysicsContact& contace) {

}

void GameLayer::shiftLand(float dt) {
	ground_1->setPositionX(ground_1->getPositionX() - 2.0f);
	ground_2->setPositionX(ground_2->getPositionX() - 2.0f);
	decorator_1->setPositionX(decorator_1->getPositionX() - 2.0f);
	decorator_2->setPositionX(decorator_2->getPositionX() - 2.0f);
	if (this->ground_2->getPositionX() == 0) {
		this->ground_1->setPositionX(this->ground_2->getContentSize().width-2.0f);
		this->decorator_1->setPositionX(this->decorator_2->getContentSize().width - 2.0f);
	}
	else if (this->ground_1->getPositionX() == 0) {
		this->ground_2->setPositionX(this->ground_1->getContentSize().width - 2.0f);
		this->decorator_2->setPositionX(this->decorator_1->getContentSize().width - 2.0f);
	}

	for (auto barrier : barriers) {
		barrier->setPositionX(barrier->getPositionX() - 2);
		if (barrier->getPositionX() < -108) {
			Size visibleSize = Director::getInstance()->getVisibleSize();
			barrier->setTag(100);
			barrier->setPositionX(visibleSize.width-70);
			barrier->setPositionY(this->getHeight());
		}
		if (barrier->getTag() == 100) {
			if (barrier->getPositionX()+108 < _wood->getPositionX()) {
				barrier->setTag(101);
				dynamic_cast<StatusLayer*>(getScene()->getChildByTag(20))->addScore();
			}
		}
	}
}

void GameLayer::gameOver() {
	if (gameStatus == GAME_STATUS_OVER) {
		return;
	}
	else {
		this->gameStatus = GAME_STATUS_OVER;
		unschedule(schedule_selector(GameLayer::shiftLand));
		_world->removeBody(_wood->getPhysicsBody());
		woodFadeOut();
		GameOverScene* gameoverscene = GameOverScene::create();
		Director::getInstance()->replaceScene(gameoverscene);
		
	}
}

void GameLayer::woodFadeOut() {
	FadeOut* animation = FadeOut::create(1.5);
	CallFunc* woodRemove = CallFunc::create(CC_CALLBACK_0(GameLayer::removeWood, this));
	_wood->runAction(Sequence::createWithTwoActions(animation, woodRemove));
}

void GameLayer::removeWood() {
	this->removeChild(_wood);
}

void GameLayer::createBarriers() {
	for (int i = 0; i < 2; i++) {
		Sprite* barrier_up = Sprite::createWithSpriteFrameName("up.png");
		Sprite* barrier_down = Sprite::createWithSpriteFrameName("down.png");
		int barHeight = getHeight();
		Node *barrier_1 = Node::create();
		barrier_down->setPosition(Point(0, 460));
		barrier_1->addChild(barrier_up);
		barrier_1->addChild(barrier_down);
		barrier_1->setAnchorPoint(Point(0, 0));
		barrier_1->setPosition(380+i*420, 380-barHeight);
		auto body = PhysicsBody::create();
		auto shapeDown = PhysicsShapeBox::create(barrier_down->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Point(0, 460));
		auto shapeUp = PhysicsShapeBox::create(barrier_up->getContentSize());
		body->addShape(shapeDown);
		body->addShape(shapeUp);
		body->setContactTestBitmask(1);
		body->setDynamic(false);
		barrier_1->setPhysicsBody(body);
		barrier_1->setTag(100);
		addChild(barrier_1, -2);
		barriers.pushBack(barrier_1);
	}

}

int GameLayer::getHeight() {
	int barHeight = 0;
	while (barHeight < 50) barHeight = rand() % 250;
	return barHeight;
}

void GameLayer::score(float dt) {

}
