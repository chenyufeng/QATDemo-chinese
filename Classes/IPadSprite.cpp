/*
 *  IPadSprite.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/28/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "IPadSprite.h"
#include "MainScene.h"
#include "MS5Layer.h"
#include "ScaleSprite.h"

IPadSprite::IPadSprite(void)
{
}

IPadSprite::~IPadSprite(void)
{
}

IPadSprite* IPadSprite::IPadSpriteWithFile(const char *pszFileName)
{
	IPadSprite* pSelector = new IPadSprite();
	pSelector->initWithFile( pszFileName );
	pSelector->autorelease();
	
	return pSelector;
}

IPadSprite* IPadSprite::IPadSpriteWithSpriteFrameName(const char *pszFileName)
{
	IPadSprite* pSelector = new IPadSprite();
	pSelector->initWithSpriteFrameName( pszFileName );
	pSelector->autorelease();
	
	return pSelector;
}

void IPadSprite::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void IPadSprite::onExit()
{
	this->stopAllActions();
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}	

bool IPadSprite::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	if(!(this->getIsVisible()))
		return false;
	CCSize s = this->getContentSize();
	CCRect rc = CCRectMake(-s.width / 2, 0, s.width, s.height/2);
	if(!CCRect::CCRectContainsPoint(rc, convertTouchToNodeSpaceAR(touch)))
		return false;
	return true;
}

void IPadSprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCNode* pNode = this->getParent();
	CCNode* pNode1 = this;
	while(pNode->getParent() != NULL)
	{
		pNode1 = pNode;
		pNode = pNode->getParent();
	}
	MainScene* pScene = dynamic_cast<MainScene*>(pNode1);
	if(pScene)
	{
		pScene->hideMenu();
	}
	
	MS5Layer* pLayer = dynamic_cast<MS5Layer*>(this->getParent());
	if(pLayer)
		pLayer->hidePopupPanel();
		
	this->setIsVisible(false);
	pNode = this->getParent();
	pNode = pNode->getParent();
	
	if(pNode->getChildByTag(TAG_IPAD_BIG) == NULL)
	{
		ScaleSprite* pSprite = ScaleSprite::scaleSpriteWithFile("ipad_big.png");
		pSprite->setTag(TAG_IPAD_BIG);
		pSprite->setScale(0.24f);
		pSprite->setPosition( ccp(855, 420) );
		pNode->addChild(pSprite, 2);
		pSprite->startScale();
	}
} 

void IPadSprite::touchDelegateRetain()
{
	this->retain();
}

void IPadSprite::touchDelegateRelease()
{
	this->release();
}