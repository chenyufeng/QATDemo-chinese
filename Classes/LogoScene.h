/*
 *  LogoScene.h
 *  QATDemo
 *
 *  Created by chenyf on 4/3/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 *  Logo scene: stop 2s, fadeout 0.5s
 */
 
 
#ifndef __LOGO_SCENE_H__
#define __LOGO_SCENE_H__

#include "cocos2d.h"	

class LogoScene : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  
	
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
	
	void changeToMain(cocos2d::ccTime time);
	
	// implement the "static node()" method manually
	LAYER_NODE_FUNC(LogoScene);
};

#endif // __LOGO_SCENE_H__
