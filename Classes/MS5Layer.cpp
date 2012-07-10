/*
 *  CompanyLayer.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/4/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "MS5Layer.h"
#include "MainScene.h"
#include "ColorMachinePanel.h"
#include "Rotate360.h"
#include "IPadSprite.h"
#include "ClickedSprite.h"

USING_NS_CC;

MS5Layer::MS5Layer()
{
	m_arPointInfo[0].bPop = true;
	m_arPointInfo[0].X = 0;
	m_arPointInfo[0].Y = -116;
	m_arPointInfo[1].bPop = false;
	m_arPointInfo[1].X = 0;
	m_arPointInfo[1].Y = 0;
	m_arPointInfo[2].bPop = true;
	m_arPointInfo[2].X = 0;
	m_arPointInfo[2].Y = 114;
	m_arPointInfo[3].bPop = true;
	m_arPointInfo[3].X = 0;
	m_arPointInfo[3].Y = 102;
	m_arPointInfo[4].bPop = true;
	m_arPointInfo[4].X = 0;
	m_arPointInfo[4].Y = -116;
	m_arPointInfo[5].bPop = false;
	m_arPointInfo[5].X = 0;
	m_arPointInfo[5].Y = 0;
	m_arPointInfo[6].bPop = false;
	m_arPointInfo[6].X = 0;
	m_arPointInfo[6].Y = 0;
	m_arPointInfo[7].bPop = false;
	m_arPointInfo[7].X = 0;
	m_arPointInfo[7].Y = 0;
}
MS5Layer::~MS5Layer()
{
	CCDirector::sharedDirector()->purgeCachedData();
}

// on "init" you need to initialize your instance
bool MS5Layer::init()
{
	CCDirector::sharedDirector()->purgeCachedData();
	//////////////////////////////
	// 1. super init first
	if ( !CCLayerColor::init() )
	{
		return false;
	}
	
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ipad.plist", "ipad.png");

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::spriteWithFile("MS5_background.png");
	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );
	// add the sprite as a child to this layer
	this->addChild(pSprite);

	Rotate360* pRotate360 = Rotate360::rotate();
	pRotate360->setTag(TAG_ROTATE360);
	this->addChild(pRotate360);

	pSprite = IPadSprite::IPadSpriteWithSpriteFrameName("ipad_bk.png");
	pSprite->setPosition( ccp(size.width-182, 310) );
	pSprite->setTag(TAG_IPAD);
	this->addChild(pSprite, 2);

	initColorMenu();
	m_bPopupPanel = false;
	//initPopupPanel();
	
	return true;
}

void MS5Layer::onEnter()
{
	//CCDirector::sharedDirector()->setProjection(kCCDirectorProjection3D);
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCLayerColor::onEnter();
}
void MS5Layer::onExit()
{
	//CCDirector::sharedDirector()->setProjection(kCCDirectorProjection2D);
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCLayerColor::onExit();
	CCDirector::sharedDirector()->purgeCachedData();
}

void MS5Layer::updateColor(void)
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

void MS5Layer::initColorMenu()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("color_button.plist", "color_button.png");

	int nTag = ColorMachinePanel::ColorSilver;
	CCSprite *pNormal = NULL;
	const char* szColor[7] = {"silver.png","gold.png","red.png","darkred.png","green.png","blue.png","black.png" };
	CCMenuItemSprite *pColorSprite[7];
	for(int i=0; i<7; i++)
	{
		pNormal = CCSprite::spriteWithSpriteFrameName(szColor[i]);
		pColorSprite[i] = CCMenuItemSprite::itemFromNormalSprite(pNormal, NULL, NULL, this, menu_selector(MS5Layer::colorMenuCallback));
		pColorSprite[i]->setTag(nTag++);
	}

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::menuWithItems(pColorSprite[0], pColorSprite[1], pColorSprite[2], pColorSprite[3], pColorSprite[4], pColorSprite[5], pColorSprite[6], NULL);
	pMenu->setPosition( ccp(200, 106) );
	pMenu->alignItemsHorizontallyWithPadding(8);
	this->addChild(pMenu, 1);

	CCSprite* pSprite = CCSprite::spriteWithSpriteFrameName("color.png");
	pSprite->setPosition( ccp(431, 103) );
	this->addChild(pSprite);

	pSprite = CCSprite::spriteWithSpriteFrameName("MS5_text.png");
	pSprite->setPosition( ccp(204, 624) );
	this->addChild(pSprite);

	pNormal = CCSprite::spriteWithSpriteFrameName("specbutton.png");
	CCMenuItemSprite* pPoint = CCMenuItemSprite::itemFromNormalSprite(pNormal, NULL, NULL, this, menu_selector(MS5Layer::specMenuCallback));
	pPoint->setPosition( ccp(938, 106) );
	pMenu = CCMenu::menuWithItems(pPoint, NULL);
	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);
}

void MS5Layer::initPopupPanel()
{
	m_bPopupPanel = false;
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	//CCSprite* pSub = NULL;
	CCSprite* pSprite = NULL;
	// point panel
	char szPath[256];
	int nTag = TAG_NOTE0;
	for(int i=0; i<8; i++)
	{
		sprintf(szPath, "pop_point%d.png", i+1);
		pSprite = ClickedSprite::clickedSpriteWithFile(szPath);
		if(m_arPointInfo[i].bPop)
			pSprite->setPosition( ccp(m_arPointInfo[i].X, m_arPointInfo[i].Y) );
		else
			pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
		pSprite->setTag(nTag++);
		pSprite->setIsVisible(false);
		this->addChild(pSprite, 2);
	}
	
	//pop_point1.png 3 
	//pop_point4.png
	//pop_point5.png
	/*CCSprite* pSprite = CCSprite::spriteWithFile("pop_point3.png");
	pSprite->setPosition( ccp(265, 655) );
	pSprite->setTag(TAG_NOTE);
	pSprite->setIsVisible(false);
	this->addChild(pSprite, 2);

	pSprite = CCSprite::spriteWithFile("note_1.png");
	pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
	pSprite->setTag(TAG_NOTE1);
	pSprite->setIsVisible(false);
	this->addChild(pSprite, 2);
	pSprite = CCSprite::spriteWithFile("pop_point8.png");
	pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
	pSprite->setTag(TAG_NOTE2);
	pSprite->setIsVisible(false);
	this->addChild(pSprite, 2);

	pSprite = CCSprite::spriteWithFile("note_3.png");
	pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
	pSprite->setTag(TAG_NOTE3);
	pSprite->setIsVisible(false);
	this->addChild(pSprite, 2);
	CCSprite* pSub = CCSprite::spriteWithFile("ultra.png");
	pSub->setPosition( ccp(300, 245) );
	pSprite->addChild(pSub);

	pSprite = CCSprite::spriteWithFile("pop_point6.png");
	pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
	pSprite->setTag(TAG_NOTE4);
	pSprite->setIsVisible(false);
	this->addChild(pSprite, 2);
	pSub = CCSprite::spriteWithFile("unique.png");
	pSub->setPosition( ccp(300, 245) );
	pSprite->addChild(pSub);*/

	// color panel
	/*ColorMachinePanel* pPanel = ColorMachinePanel::panelWithFile("color_variation.png");
	pPanel->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
	pPanel->setTag(TAG_COLOR);
	pPanel->setIsVisible(false);
	this->addChild(pPanel, 2);
	*/
	// spec panel
	pSprite = ClickedSprite::clickedSpriteWithFile("specpage.png");
	pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
	pSprite->setTag(TAG_SPEC);
	pSprite->setIsVisible(false);
	this->addChild(pSprite, 2);
}

void MS5Layer::hidePopupPanel()
{
	m_bPopupPanel = false;
	int nTag = TAG_NOTE0;
	for(int i=0; i<10; i++)
	{
		CCNode* pNode = this->getChildByTag(nTag++);
		if(pNode)
		{
			pNode->setIsVisible(false);
			this->removeChild(pNode, true);
		}
	}
}

void MS5Layer::colorMenuCallback(CCObject* pSender)
{
	CCNode* pSenderNode = dynamic_cast<CCNode*>(pSender);
	if(!pSenderNode)
		return;
	//Rotate360* pNode = dynamic_cast<Rotate360*>(this->getChildByTag(TAG_ROTATE360));
	//if(pNode)
	//	pNode->updateColor(pSenderNode->getTag());
	showNotePanel(TAG_COLOR, pSenderNode->getTag());
}

void MS5Layer::showNotePanel(int nTag, int nData, float fX/*=0.0f*/, float fY/*=0.0f*/)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	MainScene* pScene = dynamic_cast<MainScene*>(this->getParent());
	if(pScene)
	{
		pScene->hideMenu();
	}
	if(nTag == TAG_COLOR)
	{
		/*ColorMachinePanel* pNode = dynamic_cast<ColorMachinePanel*>(this->getChildByTag(TAG_COLOR));
		if(pNode && pNode->getIsVisible())
		{
			pNode->setColor(static_cast<ColorMachinePanel::MachineColor>(nData));
			return;
		}*/
		CCSprite* pNode = dynamic_cast<CCSprite*>(this->getChildByTag(TAG_COLOR));
		if(pNode && pNode->getIsVisible())
		{
			const char* szPath[7] = {"machine/machine_silver.png", "machine/machine_gold.png", "machine/machine_red.png", "machine/machine_darkred.png", "machine/machine_green.png", "machine/machine_blue.png", "machine/machine_black.png"};
			CCTexture2D *pTexture=CCTextureCache::sharedTextureCache()->addImage(szPath[nData]);
			if(pTexture)
				pNode->setTexture(pTexture);
			pNode->setIsVisible(true);
			return;
		}
	}
	if(m_bPopupPanel)
	{
		hidePopupPanel();
		return;
	}
	CCNode* pNode = this->getChildByTag(nTag);
	if(pNode)
	{
		pNode->setIsVisible(true);
		m_bPopupPanel = true;
		return;
	}
	if(nTag >= TAG_NOTE0 && nTag <= TAG_NOTE7)
	{
		char szPath[256];
		int i = nTag-TAG_NOTE0;
		sprintf(szPath, "pop_point%d.png", i+1);
		CCSprite* pSprite = ClickedSprite::clickedSpriteWithFile(szPath);
		if(m_arPointInfo[i].bPop)
			pSprite->setPosition( ccp(fX, fY + m_arPointInfo[i].Y) );
		else
			pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
		pSprite->setTag(nTag);
		pSprite->setIsVisible(true);
		this->addChild(pSprite, 2);	
	}
	else if(nTag == TAG_COLOR)
	{
		const char* szPath[7] = {"machine/machine_silver.png", "machine/machine_gold.png", "machine/machine_red.png", "machine/machine_darkred.png", "machine/machine_green.png", "machine/machine_blue.png", "machine/machine_black.png"};
		//ColorMachinePanel* pPanel = ColorMachinePanel::panelWithFile("color_variation.png");
		CCSprite* pPanel = ClickedSprite::clickedSpriteWithFile(szPath[nData]);
		pPanel->setPosition( ccp(368, 358) );
		//pPanel->setColor(static_cast<ColorMachinePanel::MachineColor>(nData));
		pPanel->setTag(nTag);
		pPanel->setIsVisible(true);
		this->addChild(pPanel, 2);
	}
	else if(nTag == TAG_SPEC)
	{
		// spec panel
		CCSprite* pSprite = ClickedSprite::clickedSpriteWithFile("specpage.png");
		pSprite->setPosition( ccp(size.width/2, (size.height-71)/2+71) );
		pSprite->setTag(nTag);
		pSprite->setIsVisible(true);
		this->addChild(pSprite, 2);
	}
	else
		return;
	m_bPopupPanel = true;
}

void MS5Layer::specMenuCallback(CCObject* pSender)
{
	showNotePanel(TAG_SPEC, 0);
}

bool MS5Layer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) 
{
	MainScene* pScene = dynamic_cast<MainScene*>(this->getParent());
	if(pScene)
	{
		pScene->hideMenu();
	}
	hidePopupPanel();
	return true;
}

