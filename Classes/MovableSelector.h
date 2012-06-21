#ifndef _MOVABLE_SELECTOR_H_
#define _MOVABLE_SELECTOR_H_

#include "cocos2d.h"
#include "UpdateScalePosDelegate.h"

using namespace cocos2d;

typedef enum tagSelectorState 
{
	kStateGrabbed,
	kStateUngrabbed
} SelectorState; 
typedef enum tagSelectorType 
{
	kTypeNone,
	kTypeHorizon,
	kTypeVertical
} SelectorType; 

class MovableSelector : public CCSprite, public CCTargetedTouchDelegate, public UpdateScalePosDelegate
{
public:
	MovableSelector(void);
	virtual ~MovableSelector(void);

	CCRect rect();
	virtual void onEnter();
	virtual void onExit();
	bool containsTouchLocation(CCTouch* touch);
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	virtual void ccUpdateScalePos(CCPoint targetPos);

	static MovableSelector* selectorWithFile(const char *pszFileName);
	static MovableSelector* selectorWithSpriteFrameName(const char *pszFileName);
	
	bool initWithFile(const char *pszFileName);
	bool initWithSpriteFrameName(const char *pszFileName);
	void setType(SelectorType type) { m_type = type; }
	void setScaleRate(float fX, float fY) { m_fScaleRateX=fX; m_fScaleRateY=fY; }
	void addScaleRateDelegate(UpdateScalePosDelegate* pDelegate) { m_pScaleRateDelegate = pDelegate; }

private:
	SelectorState		m_state;
	SelectorType		m_type;
	float				m_fScaleRateX, m_fScaleRateY;
	UpdateScalePosDelegate* m_pScaleRateDelegate;
};

#endif // _MOVABLE_SELECTOR_H_
