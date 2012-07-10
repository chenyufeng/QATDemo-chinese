/*
 *  CompanyLayer.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "HifiLayer.h"
#include "MainScene.h"
#include "MovableSelector.h"
#include "ScrollableNode.h"
#include "GlobalConfig.h"

USING_NS_CC;

HifiLayer::HifiLayer()
{
}
HifiLayer::~HifiLayer()
{

}
// on "init" you need to initialize your instance
bool HifiLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
	{
		return false;
	}
	
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hifiworld/hifiworld.plist", "hifiworld/hifiworld.png");

	CCSprite* pSprite = NULL;
	CCNode* pView = CCNode::node();
	this->addChild(pView);
	pView->setContentSize(CCSizeMake(size.width, size.height-71));
	pView->setPosition(CCPointZero);
	m_pImageNode = ScrollableNode::node();
	pView->addChild(m_pImageNode);
	
	m_tBeginPos = CCPointZero;
	CCSize contentSize(0, 0);
	char szTemp[256];
	int nLastHalfY = 0;
	int nCurY = size.height;
	for(int row=1; row<=3; row++)
	{
		int nCurX = 0;
		int nLastHalfX = 0;
		for(int line=1; line<=4; line++)
		{
			sprintf(szTemp, "hifiworld/hifiworld_%d_%d.png", row, line);
			pSprite = CCSprite::spriteWithFile(szTemp);
			if(row == 1)
				contentSize.width = contentSize.width + pSprite->getContentSize().width;
			if(line == 1)
			{
				contentSize.height = contentSize.height + pSprite->getContentSize().height;
				nCurY = nCurY - nLastHalfY - pSprite->getContentSize().height/2;
				nLastHalfY = pSprite->getContentSize().height/2;
			}
			nCurX = nCurX + nLastHalfX + pSprite->getContentSize().width/2;
#if (VERSION_LANGUAGE == VERSION_CHINESE)
			if(line == 3)
				nCurX -= 27;
#elif (VERSION_LANGUAGE == VERSION_ENGLISH)
		
#endif
			
			nLastHalfX = pSprite->getContentSize().width/2;
			pSprite->setPosition( ccp(nCurX, nCurY) );
			m_pImageNode->addChild(pSprite);
			pSprite->getTexture()->setAliasTexParameters();
		}
	}
#if (VERSION_LANGUAGE == VERSION_CHINESE)
	contentSize.width -= 27;
#elif (VERSION_LANGUAGE == VERSION_ENGLISH)
	
#endif
	m_pImageNode->setContentSize(contentSize);
	m_pImageNode->setPosition(m_tBeginPos);

	pSprite = CCSprite::spriteWithSpriteFrameName("evaluation_HIFIWorld_smallpage.png");
	pSprite->setPosition( ccp(926, 136) );
	this->addChild(pSprite);
	
	MovableSelector* pSelector = MovableSelector::selectorWithSpriteFrameName("HIFIworld_selectbox.png");
	//pSprite->setPosition( ccp(885, 164) );
	pSelector->setType(kTypeNone);
	float fScaleRateX = (pSprite->getContentSize().width-pSelector->getContentSize().width) / (contentSize.width-1024);
	float fScaleRateY = (pSprite->getContentSize().height-pSelector->getContentSize().height) / (contentSize.height-697);
	pSelector->setScaleRate(fScaleRateX, fScaleRateY);
	pSelector->setTag(1000);
	m_pSelector = pSelector;
	pSelector->addScaleRateDelegate(this);
	pSelector->setPosition( ccp(pSelector->getContentSize().width/2-1, pSprite->getContentSize().height-pSelector->getContentSize().height/2) );
	pSprite->addChild(pSelector, 1);

	return true;
}

void HifiLayer::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCLayerColor::onEnter();
}
void HifiLayer::onExit()
{
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCLayerColor::onExit();
	CCDirector::sharedDirector()->purgeCachedData();
}

void HifiLayer::updateColor(void)
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

bool HifiLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) 
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

void HifiLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) 
{
	CCPoint touchLocation = pTouch->locationInView( pTouch->view() );	
	touchLocation = CCDirector::sharedDirector()->convertToGL( touchLocation );
	float nMoveX = touchLocation.x - m_tBeginPos.x;
	float nMoveY = touchLocation.y - m_tBeginPos.y;

	CCPoint curPos  = m_pImageNode->getPosition();
	CCPoint nextPos = ccp(curPos.x+nMoveX, curPos.y + nMoveY);
	
	if (nextPos.x > 0.0f)
	{
		nextPos.x = 0.0f;
	}
	else if (nextPos.x < (m_pImageNode->getParent()->getContentSize().width - m_pImageNode->getContentSize().width))
	{
		nextPos.x = m_pImageNode->getParent()->getContentSize().width - m_pImageNode->getContentSize().width;
	}
	if (nextPos.y < 0.0f)
	{
		nextPos.y = 0.0f;
	}
	else if (nextPos.y > (m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height))
	{
		nextPos.y = m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height;
	}

	updatePos(nextPos);
	m_tBeginPos = touchLocation;
}

void HifiLayer::updatePos(CCPoint pos)
{
	m_pImageNode->setPosition(pos);
	MovableSelector* pSelector = dynamic_cast<MovableSelector*>(m_pSelector);
	if(pSelector)
		pSelector->ccUpdateScalePos(pos);
}

void HifiLayer::ccUpdateScalePos(CCPoint targetPoint)
{
	if (targetPoint.y < 0.0f)
	{
		targetPoint.y = 0.0f;
	}
	else if (targetPoint.y > (m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height))
	{
		targetPoint.y = m_pImageNode->getContentSize().height - m_pImageNode->getParent()->getContentSize().height;
	}
	if (targetPoint.x > 0.0f)
	{
		targetPoint.x = 0.0f;
	}
	else if (targetPoint.x < (m_pImageNode->getParent()->getContentSize().width - m_pImageNode->getContentSize().width))
	{
		targetPoint.x = m_pImageNode->getParent()->getContentSize().width - m_pImageNode->getContentSize().width;
	}
	m_pImageNode->setPosition(targetPoint);
}
