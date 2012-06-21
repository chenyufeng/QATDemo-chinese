#ifndef _SCROLLABLE_NODE_H_
#define _SCROLLABLE_NODE_H_

#include "cocos2d.h"

using namespace cocos2d;

class ScrollableNode : public CCNode
{
public:
	ScrollableNode(void);
	virtual ~ScrollableNode(void);

	static ScrollableNode* node();
	/** recursive method that visit its children and draw them */
	virtual void visit(void);
	
private:
	CCSize m_viewSize;

};

#endif // _SCROLLABLE_NODE_H_
