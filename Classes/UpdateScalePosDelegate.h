#ifndef __UPDATE_SCALEPOS_DELEGATE_H__
#define __UPDATE_SCALEPOS_DELEGATE_H__

#include "cocos2d.h"

class UpdateScalePosDelegate
 {
 public:
 	virtual void ccUpdateScalePos(cocos2d::CCPoint targetPos) {CC_UNUSED_PARAM(targetPos);}
 
 };

#endif // __UPDATE_SCALEPOS_DELEGATE_H__
