#include "gameOverScene.h"


GameOverScene::GameOverScene() {}

GameOverScene::~GameOverScene() {}


bool GameOverScene::init() {

	if (!Scene::init()) return false;

	GameOverLayer* gameoverlayer = GameOverLayer::create();
	this->addChild(gameoverlayer);

	return true;
}