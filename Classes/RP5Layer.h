/*
 *  CompanyLayer.h
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 *  
 */

#ifndef __RP5_LAYER_H__
#define __RP5_LAYER_H__

#include "cocos2d.h"

class RP5Layer : public cocos2d::CCLayerColor
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	// implement the "static node()" method manually
	LAYER_NODE_FUNC(RP5Layer);

protected:
	virtual void updateColor();
};

#endif // __RP5_LAYER_H__
