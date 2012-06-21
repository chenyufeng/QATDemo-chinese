/*
 *  CompanyLayer.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "RP5Layer.h"
#include "MainScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool RP5Layer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayerColor::init() )
	{
		return false;
	}
	
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	CCSprite* pSprite = CCSprite::spriteWithFile("MS5_background.png");
	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
	this->addChild(pSprite);
	
	// add "HelloWorld" splash screen"
	pSprite = CCSprite::spriteWithFile("RP5.png");
	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
	// add the sprite as a child to this layer
	this->addChild(pSprite);
	 
	return true;
}

void RP5Layer::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCLayerColor::onEnter();
}
void RP5Layer::onExit()
{
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCLayerColor::onExit();
	CCDirector::sharedDirector()->purgeCachedData();
}

void RP5Layer::updateColor(void)
{
	CCLayerColor::updateColor();
	if(m_pChildren && m_pChildren->count() > 0)
	{
        CCObject* child;
        CCARRAY_FOREACH(m_pChildren, child)
        {
            CCNode* pNode = (CCNode*) child;
			CCRGBAProtocol *pRGBAProtocol = dynamic_cast<CCRGBAProtocol*>(pNode);
			if (pRGBAProtocol)
			{
				pRGBAProtocol->setOpacity(m_cOpacity);
			}
		}
	}
}

bool RP5Layer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) 
{
	MainScene* pScene = dynamic_cast<MainScene*>(this->getParent());
	if(pScene)
	{
		pScene->hideMenu();
	}
	return true;
}
