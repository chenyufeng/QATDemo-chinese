#include "ClickedSprite.h"
#include "MainScene.h"
#include "MS5Layer.h"

ClickedSprite::ClickedSprite(void)
{
}

ClickedSprite::~ClickedSprite(void)
{
}

ClickedSprite* ClickedSprite::clickedSpriteWithFile(const char *pszFileName)
{
	ClickedSprite* pSelector = new ClickedSprite();
	pSelector->initWithFile( pszFileName );
	pSelector->autorelease();

	return pSelector;
}

bool ClickedSprite::initWithFile(const char *pszFileName)
{
	if( CCSprite::initWithFile(pszFileName) ) 
	{

	}

	return true;
}

void ClickedSprite::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void ClickedSprite::onExit()
{
	this->stopAllActions();
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}	

bool ClickedSprite::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	if(!(this->getIsVisible()))
		return false;
	CCSize s = this->getContentSize();
	CCRect rc = CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
	if(!CCRect::CCRectContainsPoint(rc, convertTouchToNodeSpaceAR(touch)))
		return false;
	return true;
}

void ClickedSprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
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
} 

void ClickedSprite::touchDelegateRetain()
{
	this->retain();
}

void ClickedSprite::touchDelegateRelease()
{
	this->release();
}
