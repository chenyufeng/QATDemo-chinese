/*
 *  MainScene.cpp
 *  QATDemo
 *
 *  Created by chenyf on 4/3/12.
 *  Copyright 2012 lexong. All rights reserved.
 *
 */

#include "MainScene.h"
#include "CompanyLayer.h"
#include "MS5Layer.h"
#include "RP5Layer.h"
#include "AmplifierLayer.h"
#include "Crystal520Layer.h"
#include "Crystal820Layer.h"
#include "SixmoonLayer.h"
#include "HifiLayer.h"

USING_NS_CC;

CCScene* MainScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	MainScene *layer = MainScene::node();
	
	// add layer as a child to scene
	scene->addChild(layer);
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	initMainMenu();
	initProductSubMenu();
	initEvaluationSubMenu();
	initSignIcon();

	m_CurPageType = PAGE_NONE;
	changePage(PAGE_PRODUCT_MS5);
	
	return true;
}

void MainScene::initMainMenu()
{
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainmenu.plist", "mainmenu.png");

	CCSprite* pSprite = CCSprite::spriteWithSpriteFrameName("menu_bar.png");
	pSprite->setPosition( ccp(size.width/2, pSprite->getContentSize().height/2) );
	this->addChild(pSprite, 2);

	CCSprite* pNormal = CCSprite::spriteWithSpriteFrameName("company_menu_normal.png");
	CCSprite* pSelect = CCSprite::spriteWithSpriteFrameName("company_menu_select.png");
	m_pMainMenu[0] = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::companyMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("product_menu_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("product_menu_select.png");
	m_pMainMenu[1] = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::productMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("evaluation_menu_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("evaluation_menu_select.png");
	m_pMainMenu[2] = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::evaluationMenuCallback));
	
	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::menuWithItems(m_pMainMenu[0], m_pMainMenu[1], m_pMainMenu[2], NULL);
#if (VERSION_LANGUAGE == VERSION_CHINESE)
	pMenu->setPosition( ccp(size.width/2, (pSprite->getContentSize().height-pNormal->getContentSize().height-4) + pNormal->getContentSize().height/2) );
#elif (VERSION_LANGUAGE == VERSION_ENGLISH)
	pMenu->setPosition( ccp(size.width/2, pSprite->getContentSize().height/2) );
#endif	
	pMenu->alignItemsHorizontallyWithPadding(124);
	this->addChild(pMenu, 2);
}

void MainScene::initProductSubMenu()
{
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("product_menu.plist", "product_menu.png");

	CCSprite* pNormal = CCSprite::spriteWithSpriteFrameName("product_menu_music_server_normal.png");
	CCSprite* pSelect = CCSprite::spriteWithSpriteFrameName("product_menu_music_server_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	//CCMenuItemImage *pItem1 = CCMenuItemImage::itemFromNormalImage("product_menu_music server_normal.png", "product_menu_music server_select.png", "product_menu_music server_normal.png", this, menu_selector(MainScene::MS5SubMenuCallback));
	CCMenuItemSprite *pItem1 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::MS5SubMenuCallback));
	//CCMenuItemImage *pItem2 = CCMenuItemImage::itemFromNormalImage("product_menu_amplifier_normal.png", "product_menu_amplifier_select.png", "product_menu_amplifier_normal.png", this, menu_selector(MainScene::amplifierSubMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("product_menu_amplifier_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("product_menu_amplifier_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	CCMenuItemSprite *pItem2 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::amplifierSubMenuCallback));
	//CCMenuItemImage *pItem3 = CCMenuItemImage::itemFromNormalImage("product_menu_RP5_normal.png", "product_menu_RP5_select.png", "product_menu_RP5_normal.png", this, menu_selector(MainScene::RP5SubMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("product_menu_RP5_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("product_menu_RP5_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	CCMenuItemSprite *pItem3 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::RP5SubMenuCallback));
	//CCMenuItemImage *pItem4 = CCMenuItemImage::itemFromNormalImage("product_menu_crystal520_normal.png", "product_menu_crystal520_select.png", "product_menu_crystal520_normal.png", this, menu_selector(MainScene::crystal520SubMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("product_menu_crystal520_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("product_menu_crystal520_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	CCMenuItemSprite *pItem4 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::crystal520SubMenuCallback));
	//CCMenuItemImage *pItem5 = CCMenuItemImage::itemFromNormalImage("product_menu_crystal820_normal.png", "product_menu_crystal820_select.png", "product_menu_crystal820_normal.png", this, menu_selector(MainScene::crystal820SubMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("product_menu_crystal820_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("product_menu_crystal820_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	CCMenuItemSprite *pItem5 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::crystal820SubMenuCallback));
	
	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::menuWithItems(pItem1, pItem3, pItem2, pItem4, pItem5, NULL);
	pMenu->setPosition( ccp(size.width/2, 238) );
	pMenu->alignItemsVerticallyWithPadding(0.0f);
	pMenu->setTag(TAG_PRODUCT_SUB_MENU);
	pMenu->setIsVisible(false);
	this->addChild(pMenu, 1);
}

void MainScene::initEvaluationSubMenu()
{
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("evaluation_menu.plist", "evaluation_menu.png");
	
	CCSprite* pNormal = CCSprite::spriteWithSpriteFrameName("evaluation_menu_SixMoons_normal.png");
	CCSprite* pSelect = CCSprite::spriteWithSpriteFrameName("evaluation_menu_SixMoons_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	CCMenuItemSprite *pItem1 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::SixmoonSubMenuCallback));
	pNormal = CCSprite::spriteWithSpriteFrameName("evaluation_menu_HI-FIWorld_normal.png");
	pSelect = CCSprite::spriteWithSpriteFrameName("evaluation_menu_HI-FIWorld_select.png");
	pNormal->getTexture()->setAliasTexParameters();
	pSelect->getTexture()->setAliasTexParameters();
	//CCMenuItemImage *pItem2 = CCMenuItemImage::itemFromNormalImage("evaluation_menu_HI-FIWorld_normal.png", "evaluation_menu_HI-FIWorld_select.png", "evaluation_menu_HI-FIWorld_normal.png", this, menu_selector(MainScene::HifiSubMenuCallback));
	CCMenuItemSprite *pItem2 = CCMenuItemSprite::itemFromNormalSprite(pNormal, pSelect, NULL, this, menu_selector(MainScene::HifiSubMenuCallback));
	
	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::menuWithItems(pItem1, pItem2, NULL);
	pMenu->setPosition( ccp(size.width-250, 118));
	pMenu->alignItemsVerticallyWithPadding(-1.0f);
	pMenu->setTag(TAG_EVALUATION_SUB_MENU);
	pMenu->setIsVisible(false);
	this->addChild(pMenu, 1);
}

void MainScene::initSignIcon()
{
	CCSprite* pSignIcon = CCSprite::spriteWithSpriteFrameName("signicon.png");
	pSignIcon->setPosition(ccp(0, 0));
	pSignIcon->setTag(TAG_SIGNICON);
	this->addChild(pSignIcon, 2);
}

void MainScene::changePage(PAGETYPE newPage)
{
	int nIndex = 0;
	switch(newPage)
	{
	case PAGE_COMPANY:
		nIndex = 0;
		break;
	case PAGE_PRODUCT_MS5:
	case PAGE_PRODUCT_RP5:
	case PAGE_PRODUCT_AMPLIFIER:
	case PAGE_PRODUCT_CRYSTAL820:
	case PAGE_PRODUCT_CRYSTAL520:
		nIndex = 1;
		break;
	case PAGE_EVALUATION_HIFI:
	case PAGE_EVALUATION_SIXMOON:
		nIndex = 2;
		break;
	}
	updateMenuSelected(nIndex);
	if(newPage == m_CurPageType)
		return;

	if(m_CurPageType != PAGE_NONE)
	{
		//CCFadeOut* pAction = CCFadeOut::actionWithDuration(0.5);
		//CCCallFuncN *pFunc = CCCallFuncN::actionWithTarget(this, callfuncN_selector(MainScene::fadeoutCallback));

		//CCSequence* pSequence = CCSequence::actionOneTwo(pAction, pFunc);
		CCNode* pLayer = this->getChildByTag(m_CurPageType+10);
		if(pLayer)
		{
			pLayer->stopAllActions();
			//pLayer->runAction(pSequence);
			this->removeChild(pLayer, true);
		}
	}
		
	m_CurPageType = newPage;

	CCLayer* pLayer = NULL;
	//CCAction* pAction = CCFadeIn::actionWithDuration(0.5);
	switch(m_CurPageType)
	{
	case PAGE_COMPANY:
		pLayer = CompanyLayer::node();
		break;
	case PAGE_PRODUCT_MS5:
		pLayer = MS5Layer::node();
		break;
	case PAGE_PRODUCT_RP5:
		pLayer = RP5Layer::node();
		break;
	case PAGE_PRODUCT_AMPLIFIER:
		pLayer = AmplifierLayer::node();
		break;
	case PAGE_PRODUCT_CRYSTAL820:
		pLayer = Crystal820Layer::node();
		break;
	case PAGE_PRODUCT_CRYSTAL520:
		pLayer = Crystal520Layer::node();
		break;
	case PAGE_EVALUATION_HIFI:
		pLayer = HifiLayer::node();
		break;
	case PAGE_EVALUATION_SIXMOON:
		pLayer = SixmoonLayer::node();
		break;
	}
	if(!pLayer)
		return;
	pLayer->setTag(m_CurPageType+10);
	//pLayer->runAction(pAction);
	this->addChild(pLayer, 0);
}

void MainScene::companyMenuCallback(CCObject* pSender)
{
	changePage(PAGE_COMPANY);
	hideMenu();
}

void MainScene::productMenuCallback(CCObject* pSender)
{
	this->getChildByTag(TAG_PRODUCT_SUB_MENU)->setIsVisible(true);
	this->getChildByTag(TAG_EVALUATION_SUB_MENU)->setIsVisible(false);
}

void MainScene::evaluationMenuCallback(CCObject* pSender)
{
	this->getChildByTag(TAG_PRODUCT_SUB_MENU)->setIsVisible(false);
	this->getChildByTag(TAG_EVALUATION_SUB_MENU)->setIsVisible(true);
}

void MainScene::MS5SubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_PRODUCT_MS5);
	hideMenu();
}

void MainScene::RP5SubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_PRODUCT_RP5);
	hideMenu();
}
void MainScene::amplifierSubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_PRODUCT_AMPLIFIER);
	hideMenu();
}
void MainScene::crystal520SubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_PRODUCT_CRYSTAL520);
	hideMenu();
}
void MainScene::crystal820SubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_PRODUCT_CRYSTAL820);
	hideMenu();
}

void MainScene::HifiSubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_EVALUATION_HIFI);
	hideMenu();
}

void MainScene::SixmoonSubMenuCallback(CCObject* pSender)
{
	changePage(PAGE_EVALUATION_SIXMOON);
	hideMenu();
}
void MainScene::fadeoutCallback(CCNode* pSender)
{
	pSender->stopAllActions();
	this->removeChild(pSender, true);
}

void MainScene::updateMenuSelected(int nIndex)
{
	for(int i=0; i<3; i++)
	{
		if(i == nIndex)
			m_pMainMenu[i]->selected();
		else
			m_pMainMenu[i]->unselected();
	}
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	switch(nIndex)
	{
	case 0:
		this->getChildByTag(TAG_SIGNICON)->setPosition(ccp(250, 10));
		break;
	case 1:
		this->getChildByTag(TAG_SIGNICON)->setPosition(ccp(size.width/2, 10));
		break;
	case 2:
		this->getChildByTag(TAG_SIGNICON)->setPosition(ccp(size.width-250, 10));
		break;
	}
}

void MainScene::hideMenu()
{
	this->getChildByTag(TAG_PRODUCT_SUB_MENU)->setIsVisible(false);
	this->getChildByTag(TAG_EVALUATION_SUB_MENU)->setIsVisible(false);
	int nIndex = 0;
	switch(m_CurPageType)
	{
	case PAGE_COMPANY:
		nIndex = 0;
		break;
	case PAGE_PRODUCT_MS5:
	case PAGE_PRODUCT_RP5:
	case PAGE_PRODUCT_AMPLIFIER:
	case PAGE_PRODUCT_CRYSTAL820:
	case PAGE_PRODUCT_CRYSTAL520:
		nIndex = 1;
		break;
	case PAGE_EVALUATION_HIFI:
	case PAGE_EVALUATION_SIXMOON:
		nIndex = 2;
		break;
	default:
		return;
	}
	updateMenuSelected(nIndex);
}
