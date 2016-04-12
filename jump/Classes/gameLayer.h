#ifndef _GAMELAYER_
#define _GAMELAYER_

#include "cocos2d.h"
#include "bgLayer.h"
#include "statusLayer.h"
#include "gameOverScene.h"

USING_NS_CC;

typedef enum _game_status {
	GAME_STATUS_READY = 1,
	GAME_STATUS_START,
	GAME_STATUS_OVER
} GameStatus;

class GameLayer : public Layer {
public:
	GameLayer();

	~GameLayer();

	virtual bool init();

	CREATE_FUNC(GameLayer);

	void setPhyWorld(PhysicsWorld* world) { this->_world = world; }

	bool onTouchBegan();

	bool onContactBegin(PhysicsContact& contact);
	void onContactSeperate(PhysicsContact& contact);

	void shiftLand(float dt);

	void gameOver();

	void createBarriers();

	int getHeight();

	void woodFadeOut();

	void removeWood();

	void score(float dt);

private:

	GameStatus gameStatus;

	PhysicsWorld* _world;

	Sprite* _wood;

	Sprite* edge;

	Node* groundLine;

	Sprite* test;

	Sprite* ground_1;
	Sprite* ground_2;
	Sprite* decorator_1;
	Sprite* decorator_2;

	Vector<Node *> barriers;
};

#endif