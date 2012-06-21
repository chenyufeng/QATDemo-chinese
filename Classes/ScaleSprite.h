#ifndef _SCALE_SPRITE_H_
#define _SCALE_SPRITE_H_

#include "cocos2d.h"

using namespace cocos2d;

class ScaleSprite : public CCSprite, public CCTargetedTouchDelegate
{
public:
	ScaleSprite(void);
	virtual ~ScaleSprite(void);

	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	//virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	static ScaleSprite* scaleSpriteWithFile(const char *pszFileName);
	static ScaleSprite* scaleSpriteWithSpriteFrameName(const char *pszFileName);
	
	void startScale();
	
protected:
	void fullscreenCallback(CCNode* pSender);
	void playFinishedCallback(CCNode* pSender);

private:
	bool m_bScaling;
};

#endif // _SCALE_SPRITE_H_
