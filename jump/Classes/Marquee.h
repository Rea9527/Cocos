#include "cocos2d.h"

USING_NS_CC;

class Marquee : public Node {

public:

	CREATE_FUNC(Marquee);

	bool init();

	void show(const std::string& text);

public:
	const std::string& getFont() const { return _font; }
	void setFont(std::string& font) { _font = font; }
	float getFontSize() const { return _fontSize; }
	void setFontSize(float fontSize) { _fontSize = fontSize; }
	const Rect& getShowRect() const { return _showRect; }
	void setShowRect(Rect& showRect) { _showRect = showRect; }

protected:
	Marquee() : _font(""), _fontSize(15), _showRect(Rect(0, 0, 200, 30)) {}
	~Marquee() {}

private:
	std::string _font;

	float _fontSize;

	Rect _showRect;

	Label* _label;

};