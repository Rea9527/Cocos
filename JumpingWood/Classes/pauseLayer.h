#pragma once

#ifndef _PAUSE_LAYER_H_
#define _PAUSE_LAYER_H

#include "cocos2d.h"
#include "ui\CocosGUI.h"

using namespace cocos2d::ui;
USING_NS_CC;

class PauseLayer : public LayerColor {
public:

	PauseLayer();

	~PauseLayer();

	virtual bool init();

	CREATE_FUNC(PauseLayer);
};

#endif
