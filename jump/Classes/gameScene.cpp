#include "gameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

GameScene::GameScene() {}

GameScene::~GameScene() {}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::initWithPhysics() )
    {
        return false;
    }

	this->getPhysicsWorld()->setGravity(Vec2(0, -300));
	//this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	auto bgLayer = BgLayer::create();
	if (bgLayer) addChild(bgLayer);

	auto gameLayer = GameLayer::create();
	gameLayer->setTag(10);
	if (gameLayer) {
		gameLayer->setPhyWorld(this->getPhysicsWorld());
		addChild(gameLayer);
	}

	auto statusLayer = StatusLayer::create();
	if (statusLayer) addChild(statusLayer, 2, 20);


    return true;
}


