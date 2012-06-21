/*
 *  IPadSprite.h
 *  QATDemo
 *
 *  Created by chenyf on 4/28/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#ifndef _IPAD_SPRITE_H_
#define _IPAD_SPRITE_H_

#include "cocos2d.h"

using namespace cocos2d;

class IPadSprite : public CCSprite, public CCTargetedTouchDelegate
{
public:
	IPadSprite(void);
	virtual ~IPadSprite(void);
	
	virtual void onEnter();
	virtual void onExit();
	
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();
	
	static IPadSprite* IPadSpriteWithFile(const char *pszFileName);
	static IPadSprite* IPadSpriteWithSpriteFrameName(const char *pszFileName);
	
private:
	
};

#endif // _IPAD_SPRITE_H_
