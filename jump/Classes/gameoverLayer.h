#ifndef _GAMEOVER_LAYER_H_
#define _GAMEOVER_LAYER_H_

#include "welcomeScene.h"
#include "statusLayer.h"

class GameOverLayer : public LayerColor {
public:

	GameOverLayer();

	GameOverLayer(int score);

	~GameOverLayer();

	virtual bool init();

	CREATE_FUNC(GameOverLayer);

private:

	int finalScore;
};

#endif