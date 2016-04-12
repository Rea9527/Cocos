#ifndef _STATUSLAYER_H_
#define _STATUSLAYER_H_


#include "Marquee.h"
#include "ui\CocosGUI.h"
#include "pauseLayer.h"

using namespace ui;
//#include "cocostudio/CocoStudio.h"
//
//using namespace cocostudio::timeline;


class StatusLayer : public Layer {

public:

	StatusLayer();

	~StatusLayer();

	virtual bool init();

	CREATE_FUNC(StatusLayer);

	void addScore();

	int getScore();

private:

	Marquee* marquee;

	int _currentPoint;

	Label* _countDownLabel;

};

#endif