/*
 *  CompanyLayer.h
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 *  
 */

#ifndef __MS5_LAYER_H__
#define __MS5_LAYER_H__

#include "cocos2d.h"

class MS5Layer : public cocos2d::CCLayerColor
{
	typedef struct tagPointInfo
	{
		int X;
		int Y;
		bool bPop;
	}PointInfo;
public:
	MS5Layer();
	virtual ~MS5Layer();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	// implement the "static node()" method manually
	LAYER_NODE_FUNC(MS5Layer);

	void hidePopupPanel();
	void showNotePanel(int nTag, int nData, float fX=0.0f, float fY=0.0f);

protected:
	void colorMenuCallback(CCObject* pSender);
	void specMenuCallback(CCObject* pSender);

protected:
	virtual void updateColor();
	void initColorMenu();
	void initPopupPanel();

private:
	bool m_bPopupPanel;
	PointInfo m_arPointInfo[8];
};

#endif // __MS5_LAYER_H__
