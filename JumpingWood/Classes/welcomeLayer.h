#ifndef _WELCOMELAYER_H_
#define _WELCOMELAYER_H_


#include "gameScene.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;
USING_NS_CC;

class WelcomeLayer : public Layer {
public:

	WelcomeLayer();

	~WelcomeLayer();

	virtual bool init();

	CREATE_FUNC(WelcomeLayer);


private:

	Size visibleSize;

	Point origin;
};

#endif