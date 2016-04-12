#include "Marquee.h"



bool Marquee::init() {

	auto stencil = Sprite::create();
	stencil->setTextureRect(_showRect);
	stencil->setColor(Color3B::BLUE);
	_label = Label::createWithSystemFont("", _font, _fontSize);
	_label->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	_label->setAlignment(TextHAlignment::LEFT);

	auto clippingNode = ClippingNode::create(stencil);
	clippingNode->setInverted(false);
	clippingNode->addChild(_label);
	addChild(clippingNode);

	return true;
}

void Marquee::show(const std::string& text) {
	
	_label->setString(text);
	_label->setPosition(Vec2(100, _label->getContentSize().height / 2));
	_label->setTextColor(Color4B::BLACK);

	auto sequ = Sequence::create(MoveBy::create(6.0f, Vec2(-_label->getContentSize().width-30, 0)), Hide::create(), nullptr);
	_label->runAction(sequ);
}