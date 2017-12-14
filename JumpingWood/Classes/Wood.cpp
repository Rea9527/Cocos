#include "Wood.h"


Wood::Wood() {

}

Wood::~Wood() {

}

bool Wood::init() {

		return true;


}

Wood* Wood::wood = NULL;

Wood* Wood::getInstance() {
	if (wood == NULL) {
		wood = new Wood();
		if (!wood->init()) {
			delete(wood);
			wood = NULL;
		}
	}
	return wood;
}

bool Wood::createWood() {
	if (Sprite::initWithSpriteFrameName("Float.png")) {
		return true;
	}
	else {
		return false;
	}
}

void Wood::die() {
	delete(wood);
	wood = NULL;
}