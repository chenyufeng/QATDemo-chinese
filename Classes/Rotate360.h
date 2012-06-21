#ifndef _ROTATE_360_H_
#define _ROTATE_360_H_

#include "cocos2d.h"

using namespace cocos2d;

typedef struct tagPointPos
{
	int nPosX[8];
	int nPosY[8];
}PointPos;

class Rotate360 : public CCNode, public CCTargetedTouchDelegate
{
	typedef enum tagRotateState 
	{
		kStateGrabbed,
		kStateUngrabbed
	} RotateState; 
#define TAG_MACHINE   1000
#define TAG_SHADOW	  1001
public:
	Rotate360(void);
	virtual ~Rotate360(void);

	virtual void onEnter();
	virtual void onExit();
	bool containsTouchLocation(CCTouch* touch);
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);

	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	static Rotate360* rotate();
	bool init();

	void updateColor(int nColor);

protected:
	void addFadeInOutEffect();
	void removeFadeInOutEffect();
	void updateAngle();
	void updatePoint(int nPage);
	void hideAllPanel();

	void showPointAndArrow();
	void hidePointAndArrow();

	void pointMenuCallback(CCObject* pSender);

private:
	float	m_fRotateAngle;
	float	m_fLastRotateAngle;
	CGFloat previousTouch;
	CCPoint firstPoint;

	RotateState m_state;
	PointPos	m_PointPos[60];
	CCMenuItemSprite* m_pPoint[8];
	int		m_nPage;
	bool	m_bCanRotate;
	
};

#endif // _ROTATE_360_H_
