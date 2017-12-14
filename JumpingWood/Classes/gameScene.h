#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "gameLayer.h"
#include "bgLayer.h"
#include "statusLayer.h"
#include "pauseLayer.h"

USING_NS_CC;



class GameScene : public Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	GameScene();

	~GameScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	CREATE_FUNC(GameScene);



};

#endif // __HELLOWORLD_SCENE_H__
