#ifndef _GAMEOVER_SCENE_H_
#define _GAMEOVER_SCENE_H_

#include "gameScene.h"
#include "gameLayer.h"
#include "gameoverLayer.h"

class GameOverScene : public Scene {
public:
	GameOverScene();

	~GameOverScene();

	virtual bool init();

	CREATE_FUNC(GameOverScene);
};
#endif