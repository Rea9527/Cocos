#ifndef _WOOD_H_
#define _WOOD_H_

#include "cocos2d.h"

USING_NS_CC;

class Wood : public Sprite {
public:

	Wood();

	~Wood();

	virtual bool init();

	static Wood* getInstance();

	bool createWood();

	static void die();

private:

	static Wood* wood;
	//Wood* wood;
};

#endif