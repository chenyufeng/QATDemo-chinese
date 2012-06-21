/*
 *  CompanyLayer.h
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 *  
 */

#ifndef __SIXMOON_LAYER_H__
#define __SIXMOON_LAYER_H__

#include "cocos2d.h"
#include "UpdateScalePosDelegate.h"

class SixmoonLayer : public cocos2d::CCLayerColor, public UpdateScalePosDelegate
{
public:
	SixmoonLayer();
	virtual ~SixmoonLayer();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init(); 
	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	virtual void ccUpdateScalePos(cocos2d::CCPoint targetPos);

	// implement the "static node()" method manually
	LAYER_NODE_FUNC(SixmoonLayer);

protected:
	virtual void updateColor();
	void updatePos(cocos2d::CCPoint pos);

	cocos2d::CCNode* m_pImageNode;
	cocos2d::CCPoint m_tBeginPos;
	float			 m_fScaleRateY;
	cocos2d::CCNode* m_pSelector;
};

#endif // __SIXMOON_LAYER_H__
