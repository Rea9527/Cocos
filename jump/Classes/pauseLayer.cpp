#include "pauseLayer.h"


PauseLayer::PauseLayer() {}

PauseLayer::~PauseLayer() {}


bool PauseLayer::init() {
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0))) return false;

	Button* continueBtn = Button::create("restart.png");
	addChild(continueBtn);

	return true;
}