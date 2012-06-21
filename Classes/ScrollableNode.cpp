#include "ScrollableNode.h"

ScrollableNode::ScrollableNode(void)
{
	m_viewSize.width = 1024;
	m_viewSize.height = 697;
}

ScrollableNode::~ScrollableNode(void)
{
}

ScrollableNode* ScrollableNode::node()
{
	ScrollableNode* pSelector = new ScrollableNode();
	pSelector->autorelease();

	return pSelector;
}

void ScrollableNode::visit(void)
{
	glEnable(GL_SCISSOR_TEST);
	glScissor(0, 71, m_viewSize.width, m_viewSize.height);//x, y, w, h   

	CCNode::visit();
	glDisable(GL_SCISSOR_TEST);
}
