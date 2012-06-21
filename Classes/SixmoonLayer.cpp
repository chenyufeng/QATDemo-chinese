/*
 *  CompanyLayer.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "SixmoonLayer.h"
#include "MainScene.h"
#include "MovableSelector.h"
#include "ScrollableNode.h"
#include "GlobalConfig.h"

USING_NS_CC;

SixmoonLayer::SixmoonLayer()
	:m_fScaleRateY(1.0)
{
}
SixmoonLayer::~SixmoonLayer()
{
}

// on "init" you need to initialize your instance
bool SixmoonLayer::init()
{
	CCDirector::sharedDirector()->purgeCachedData();
	CCTextureCache::sharedTextureCache()->removeUnusedTextures();

	//////////////////////////////
	// 1. super init first
	if ( !CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
	{
		return false;
	}
	
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("sixmoon/sixmoon.plist", "sixmoon/sixmoon.png");

	CCSprite* pSprite = NULL;
	CCNode* pView = CCNode::node();
	this->addChild(pView);
	pView->setContentSize(CCSizeMake(size.width, size.height-71));
	pView->setPosition(CCPointZero);
	m_pImageNode = ScrollableNode::node();
	pView->addChild(m_pImageNode);
	
#if (VERSION_LANGUAGE == VERSION_CHINESE)
	int nImageCount = 15;
#elif (VERSION_LANGUAGE == VERSION_ENGLISH)
	int nImageCount = 18;
#endif

	m_tBeginPos = CCPointZero;
	CCSize contentSize(0, 0);
	char szTemp[256];
	int nCurY = size.height;
	int nLastHalf = 0;
	for(int i=1; i<=nImageCount; i++)
	{
		sprintf(szTemp, "sixmoon/sixmoons_%d.png", i);
		pSprite = CCSprite::spriteWithFile(szTemp);
		if(pSprite->getContentSize().width > contentSize.width)
			contentSize.width = pSprite->getContentSize().width;
		contentSize.height = contentSize.height + pSprite->getContentSize().height;
		nCurY = nCurY - nLastHalf - pSprite->getContentSize().height/2;
		nLastHalf = pSprite->getContentSize().height/2;
		pSprite->setPosition( ccp(size.width/2, nCurY) );
		m_pImageNode->addChild(pSprite);
		pSprite->getTexture()->setAliasTexParameters();
	}
	m_pImageNode->setContentSize(contentSize);
	m_pImageNode->setPosition(m_tBeginPos);

	pSprite = CCSprite::spriteWithSpriteFrameName("evaluation_SixMoons_smallpage.png");
	pSprite->setPosition( ccp(974, 380) );
	this->addChild(pSprite, 1);
	MovableSelector* pSelector = MovableSelector::selectorWithSpriteFrameName("SixMoons_selectbox.png");
	pSelector->setType(kTypeVertical);
	m_fScaleRateY = (pSprite->getContentSize().height-pSelector->getContentSize().height) / (contentSize.height-697);
	pSelector->setScaleRate(1.0, m_fScaleRateY);
	pSelector->setTag(1000);
	m_pSelector = pSelector;
	pSelector->addScaleRateDelegate(this);
	pSelector->setPosition( ccp(pSelector->getContentSize().width/2-1, pSprite->getContentSize().height-pSelector->getContentSize().height/2) );
	pSprite->addChild(pSelector, 1);
	
	return true;
}

void SixmoonLayer::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCLayerColor::onEnter();
}
void SixmoonLayer::onExit()
{
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCLayerColor::onExit();
	CCDirector::sharedDirector()->purgeCachedData();
}

void SixmoonLayer::updateColor(void)
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

bool SixmoonLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) 
{
	MainScene* pScene = dynamic_cast<MainScene*>(this->getParent());
	if(pScene)
	{
		pScene->hideMenu();
	}
	m_tBeginPos = pTouch->locationInView( pTouch->view() );	
	m_tBeginPos = CCDirector::sharedDirector()->convertToGL( m_tBeginPos );
	return true;
}

void SixmoonLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) 
{
	CCPoint touchLocation = pTouch->locationInView( pTouch->view() );	
	touchLocation = CCDirector::sharedDirector()->convertToGL( touchLocation );
	float nMoveY = touchLocation.y - m_tBeginPos.y;

	CCPoint curPos  = m_pImageNode->getPosition();
	CCPoint nextPos = ccp(curPos.x, curPos.y + nMoveY);
	
	if (nextPos.y < 0.0f)
	{
		updatePos(CCPointZero);
		return;
	}
	else if (nextPos.y > (m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height))
	{
		updatePos(ccp(0, (m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height)));
		return;
	}

	updatePos(nextPos);
	m_tBeginPos = touchLocation;
}

void SixmoonLayer::updatePos(CCPoint pos)
{
	m_pImageNode->setPosition(pos);
	MovableSelector* pSelector = dynamic_cast<MovableSelector*>(m_pSelector);
	if(pSelector)
		pSelector->ccUpdateScalePos(pos);
}

void SixmoonLayer::ccUpdateScalePos(CCPoint targetPoint)
{
	targetPoint.x = m_pImageNode->getPosition().x;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	if (targetPoint.y < 0.0f)
	{
		targetPoint = CCPointZero;
	}
	else if (targetPoint.y > (m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height))
	{
		targetPoint = ccp(0, (m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height));
	}
	m_pImageNode->setPosition(targetPoint);
}
