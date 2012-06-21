/*
 *  LogoScene.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/3/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "LogoScene.h"
#include "MainScene.h"

USING_NS_CC;

CCScene* LogoScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	LogoScene *layer = LogoScene::node();
	
	// add layer as a child to scene
	scene->addChild(layer);
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LogoScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	
	
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::spriteWithFile("logo.png");
	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
	
	this->schedule(schedule_selector(LogoScene::changeToMain), 1);
	return true;
}

void LogoScene::changeToMain(cocos2d::ccTime time)
{
	this->unschedule(schedule_selector(LogoScene::changeToMain));
	
	CCDirector *pDirector = CCDirector::sharedDirector();
	// create a scene. it's an autorelease object
	CCScene *pScene = MainScene::scene();
	CCTransitionFade* pFade = CCTransitionFade::transitionWithDuration(0.5, pScene, ccBLACK);
	// run
	pDirector->replaceScene(pFade);
}
