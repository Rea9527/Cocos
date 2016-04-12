#ifndef _WELCOME_SCENE_H_
#define _WELCOME_SCENE_H_

#include "welcomeLayer.h"
#include "cocos2d.h"

class WelcomeScene : public Scene {
public:


	WelcomeScene();

	~WelcomeScene();

	virtual bool init();

	CREATE_FUNC(WelcomeScene);

};

#endif