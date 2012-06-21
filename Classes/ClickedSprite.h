#ifndef _CLICKED_SPRITE_H_
#define _CLICKED_SPRITE_H_

#include "cocos2d.h"

using namespace cocos2d;

class ClickedSprite : public CCSprite, public CCTargetedTouchDelegate
{
public:
	ClickedSprite(void);
	virtual ~ClickedSprite(void);

	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	//virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	static ClickedSprite* clickedSpriteWithFile(const char *pszFileName);
	bool initWithFile(const char *pszFileName);

private:
	
};

#endif // _CLICKED_SPRITE_H_
