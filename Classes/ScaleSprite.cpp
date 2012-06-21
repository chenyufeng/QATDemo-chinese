#include "ScaleSprite.h"
#include "MS5Layer.h"
#include "MainScene.h"
#include "CCVideoUtils.h"

ScaleSprite::ScaleSprite(void)
	: m_bScaling(false)
{
}

ScaleSprite::~ScaleSprite(void)
{
}

ScaleSprite* ScaleSprite::scaleSpriteWithFile(const char *pszFileName)
{
	ScaleSprite* pSelector = new ScaleSprite();
	pSelector->initWithFile( pszFileName );
	pSelector->autorelease();

	return pSelector;
}

ScaleSprite* ScaleSprite::scaleSpriteWithSpriteFrameName(const char *pszFileName)
{
	ScaleSprite* pSelector = new ScaleSprite();
	pSelector->initWithSpriteFrameName(pszFileName);
	pSelector->autorelease();

	return pSelector;
}

void ScaleSprite::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, kCCMenuTouchPriority, true);
	CCSprite::onEnter();
}

void ScaleSprite::onExit()
{
	this->stopAllActions();
	m_bScaling = false;
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}	

bool ScaleSprite::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCRect s = this->boundingBox();
	//CCRect rc = CCRectMake(-s.size.width / 2, -s.size.height / 2, s.size.width, s.size.height);
	//CCPoint pt = convertTouchToNodeSpaceAR(touch);
	CCPoint point = touch->locationInView(touch->view());
	point = CCDirector::sharedDirector()->convertToGL(point);
	if(!CCRect::CCRectContainsPoint(s, point))
		return false;

	CCNode* pNode = this->getParent();
	MS5Layer* pLayer = dynamic_cast<MS5Layer*>(pNode);
	if(pLayer)
		pLayer->hidePopupPanel();
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

	return true;
}

void ScaleSprite::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	
} 

void ScaleSprite::touchDelegateRetain()
{
	this->retain();
}

void ScaleSprite::touchDelegateRelease()
{
	this->release();
}

void ScaleSprite::startScale()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	this->stopAllActions();
	if(!m_bScaling)
	{
		//CCActionInterval* scaleIn = CCScaleTo::actionWithDuration(1.0f, size.width/this->boundingBox().size.width, size.height/this->boundingBox().size.height);
		CCActionInterval* scaleIn = CCScaleTo::actionWithDuration(0.5f, 1.0f);
		CCActionInterval* moveIn = CCMoveTo::actionWithDuration(0.5f, ccp(size.width/2, size.height/2));
		CCCallFuncN *pFunc = CCCallFuncN::actionWithTarget(this, callfuncN_selector(ScaleSprite::fullscreenCallback));
		CCSequence* pSequence = CCSequence::actionOneTwo(CCSpawn::actionOneTwo(scaleIn, moveIn), pFunc);
		
		this->runAction(CCEaseIn::actionWithAction(pSequence, 0.5f));
		m_bScaling = true;
	}
	else
	{
		CCActionInterval* scaleIn = CCScaleTo::actionWithDuration(0.5f, 0.24f);
		CCActionInterval* moveIn = CCMoveTo::actionWithDuration(0.5f, ccp(855, 420));
		this->runAction(CCEaseOut::actionWithAction(CCSpawn::actionOneTwo(scaleIn, moveIn), 0.5f));
		m_bScaling = false;
	}
}

void ScaleSprite::fullscreenCallback(CCNode* pSender)
{
	CCNode* pParent = this->getParent();
	pParent = pParent->getChildByTag(PAGE_PRODUCT_MS5+10);
	CCNode* pPad = pParent->getChildByTag(TAG_IPAD);
	if(pPad)
		pPad->setIsVisible(true);
	this->stopAllActions();
	
	// play video
	CCVideoUtils::playVideo("video.mp4", true, false, this, callfuncN_selector(ScaleSprite::playFinishedCallback), NULL);
}

void ScaleSprite::playFinishedCallback(CCNode* pSender)
{
	this->removeFromParentAndCleanup(true);
	
	CCVideoUtils::purgeCCVideoUtils();
}
