#ifndef _BGLAYER_
#define _BGLAYER_

#include "cocos2d.h"

USING_NS_CC;

class BgLayer : public Layer {
public:

	BgLayer();

	~BgLayer();

	virtual bool init();

	CREATE_FUNC(BgLayer);
};

#endif