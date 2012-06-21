/*
 *  CompanyScene.h
 *  QATDemo
 *
 *  Created by chenyf on 4/3/12.
 *  Copyright 2012 lexong. All rights reserved.
 *  main scene
 *
 */

#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

enum PAGETYPE {
	PAGE_NONE = -1,
	PAGE_COMPANY = 0,
	
	PAGE_PRODUCT_MS5,
	PAGE_PRODUCT_RP5,
	PAGE_PRODUCT_AMPLIFIER,
	PAGE_PRODUCT_CRYSTAL520,
	PAGE_PRODUCT_CRYSTAL820,

	PAGE_EVALUATION_SIXMOON,
	PAGE_EVALUATION_HIFI,
};
enum TAG_NUM {
	TAG_SIGNICON = 90,
	TAG_ARROW,
	TAG_POINT,
	//TAG_POINT2,
	//TAG_POINT3,
	TAG_NOTE0,
	TAG_NOTE1,
	TAG_NOTE2,
	TAG_NOTE3,
	TAG_NOTE4,
	TAG_NOTE5,
	TAG_NOTE6,
	TAG_NOTE7,
	TAG_SPEC,
	TAG_COLOR,
	TAG_ROTATE360,
	
	TAG_IPAD,
	TAG_IPAD_BIG,

	TAG_PRODUCT_SUB_MENU = 200,
	TAG_EVALUATION_SUB_MENU,
};

class MainScene : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
	void changePage(PAGETYPE newPage);
	void hideMenu();
	
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
	
	// implement the "static node()" method manually
	LAYER_NODE_FUNC(MainScene);

protected:
	void initMainMenu();
	void initProductSubMenu();
	void initEvaluationSubMenu();
	void initSignIcon();
	void updateMenuSelected(int nIndex);

protected:
	// a selector callback
	void companyMenuCallback(CCObject* pSender);
	void productMenuCallback(CCObject* pSender);
	void evaluationMenuCallback(CCObject* pSender);

	void MS5SubMenuCallback(CCObject* pSender);
	void RP5SubMenuCallback(CCObject* pSender);
	void amplifierSubMenuCallback(CCObject* pSender);
	void crystal520SubMenuCallback(CCObject* pSender);
	void crystal820SubMenuCallback(CCObject* pSender);

	void HifiSubMenuCallback(CCObject* pSender);
	void SixmoonSubMenuCallback(CCObject* pSender);

	void fadeoutCallback(CCNode* pSender);
	
private:
	PAGETYPE  m_CurPageType;
	cocos2d::CCMenuItemSprite *m_pMainMenu[3];
	
};

#endif // __MAIN_SCENE_H__
