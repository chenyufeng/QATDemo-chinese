#include "MovableSelector.h"

MovableSelector::MovableSelector(void)
	: m_state(kStateUngrabbed)
	, m_type(kTypeNone)
	, m_fScaleRateX(1.0)
	, m_fScaleRateY(1.0)
	, m_pScaleRateDelegate(NULL)
{
}

MovableSelector::~MovableSelector(void)
{
}

MovableSelector* MovableSelector::selectorWithFile(const char *pszFileName)
{
	MovableSelector* pSelector = new MovableSelector();
	pSelector->initWithFile( pszFileName );
	pSelector->autorelease();

	return pSelector;
}

MovableSelector* MovableSelector::selectorWithSpriteFrameName(const char *pszFileName)
{
	MovableSelector* pSelector = new MovableSelector();
	pSelector->initWithSpriteFrameName( pszFileName );
	pSelector->autorelease();

	return pSelector;
}

bool MovableSelector::initWithFile(const char *pszFileName)
{
	if( CCSprite::initWithFile(pszFileName) ) 
	{
		m_state = kStateUngrabbed;
		m_type = kTypeNone;
	}

	return true;
}

bool MovableSelector::initWithSpriteFrameName(const char *pszFileName)
{
	if( CCSprite::initWithSpriteFrameName(pszFileName) ) 
	{
		m_state = kStateUngrabbed;
		m_type = kTypeNone;
	}

	return true;
}

CCRect MovableSelector::rect()
{
	CCSize s = this->getContentSize();
	return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}

void MovableSelector::onEnter()
{
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void MovableSelector::onExit()
{
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}	

bool MovableSelector::containsTouchLocation(CCTouch* touch)
{
	return CCRect::CCRectContainsPoint(rect(), convertTouchToNodeSpaceAR(touch));
}

bool MovableSelector::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	if (m_state != kStateUngrabbed) 
		return false;
	if ( !containsTouchLocation(touch) ) 
		return false;

	m_state = kStateGrabbed;
	return true;
}

void MovableSelector::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	// If it weren't for the TouchDispatcher, you would need to keep a reference
	// to the touch from touchBegan and check that the current touch is the same
	// as that one.
	// Actually, it would be even more complicated since in the Cocos dispatcher
	// you get CCSets instead of 1 UITouch, so you'd need to loop through the set
	// in each touchXXX method.

	CCAssert(m_state == kStateGrabbed, L"MovableSelector - Unexpected state!");	

	CCPoint touchPoint = touch->locationInView( touch->view() );
	touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );
	CCPoint targetPoint = this->getParent()->convertToNodeSpace(touchPoint);
	CCPoint maxPoint, minPoint;
	maxPoint.x = this->getParent()->getContentSize().width - this->getContentSize().width/2;
	maxPoint.y = this->getParent()->getContentSize().height - this->getContentSize().height/2;
	minPoint.x = this->getContentSize().width/2;
	minPoint.y = this->getContentSize().height/2;

	switch(m_type)
	{
	case kTypeNone:
		targetPoint.x = clampf(targetPoint.x, minPoint.x, maxPoint.x); 
		targetPoint.y = clampf(targetPoint.y, minPoint.y, maxPoint.y); 
		setPosition( CCPointMake(targetPoint.x, targetPoint.y) );
		break;
	case kTypeHorizon:
		targetPoint.x = clampf(targetPoint.x, minPoint.x, maxPoint.x); 
		setPosition( CCPointMake(targetPoint.x, getPosition().y) );
		break;
	case kTypeVertical:
		targetPoint.y = clampf(targetPoint.y, minPoint.y, maxPoint.y); 
		setPosition( CCPointMake(getPosition().x, targetPoint.y) );
		break;
	};
	if(m_pScaleRateDelegate)
	{
		targetPoint = getPosition();
		switch(m_type)
		{
		case kTypeNone:
			targetPoint.x = minPoint.x - targetPoint.x;
			targetPoint.x = targetPoint.x / m_fScaleRateX;
			targetPoint.y = maxPoint.y - targetPoint.y;
			targetPoint.y = targetPoint.y / m_fScaleRateY; 
			break;
		case kTypeHorizon:
			targetPoint.x = minPoint.x - targetPoint.x;
			targetPoint.x = targetPoint.x / m_fScaleRateX;
			break;
		case kTypeVertical:
			targetPoint.y = maxPoint.y - targetPoint.y;
			targetPoint.y = targetPoint.y / m_fScaleRateY;
			break;
		};
		m_pScaleRateDelegate->ccUpdateScalePos(targetPoint);
	}
}

void MovableSelector::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCAssert(m_state == kStateGrabbed, L"MovableSelector - Unexpected state!");	

	m_state = kStateUngrabbed;
} 

void MovableSelector::touchDelegateRetain()
{
	this->retain();
}

void MovableSelector::touchDelegateRelease()
{
	this->release();
}

void MovableSelector::ccUpdateScalePos(CCPoint targetPoint)
{
	CCPoint maxPoint, minPoint;
	maxPoint.x = this->getParent()->getContentSize().width - this->getContentSize().width/2;
	maxPoint.y = this->getParent()->getContentSize().height - this->getContentSize().height/2;
	minPoint.x = this->getContentSize().width/2;
	minPoint.y = this->getContentSize().height/2;

	switch(m_type)
	{
	case kTypeNone:
		targetPoint.x = -targetPoint.x * m_fScaleRateX + minPoint.x;
		targetPoint.x = clampf(targetPoint.x, minPoint.x, maxPoint.x); 
		targetPoint.y = maxPoint.y - targetPoint.y * m_fScaleRateY;
		targetPoint.y = clampf(targetPoint.y, minPoint.y, maxPoint.y); 
		setPosition( CCPointMake(targetPoint.x, targetPoint.y) );
		break;
	case kTypeHorizon:
		targetPoint.x = -targetPoint.x * m_fScaleRateX + minPoint.x;
		targetPoint.x = clampf(targetPoint.x, minPoint.x, maxPoint.x); 
		setPosition( CCPointMake(targetPoint.x, getPosition().y) );
		break;
	case kTypeVertical:
		targetPoint.y = maxPoint.y - targetPoint.y * m_fScaleRateY;
		targetPoint.y = clampf(targetPoint.y, minPoint.y, maxPoint.y); 
		setPosition( CCPointMake(getPosition().x, targetPoint.y) );
		break;
	};
}
