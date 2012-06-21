#include "ColorMachinePanel.h"

ColorMachinePanel::ColorMachinePanel(void)
{
}

ColorMachinePanel::~ColorMachinePanel(void)
{
}

ColorMachinePanel* ColorMachinePanel::panelWithFile(const char *pszFileName)
{
	ColorMachinePanel* pPanel = new ColorMachinePanel();
	if(pPanel->initWithFile(pszFileName))
	{
		pPanel->autorelease();
		return pPanel;
	}

	return NULL;
}

bool ColorMachinePanel::initWithFile(const char *pszFileName)
{
	if( CCSprite::initWithFile(pszFileName) ) 
	{
		m_color = ColorGold;
		CCSprite* pSprite = CCSprite::spriteWithFile("machine/machine_gold.png");
		pSprite->setTag(Color_Image);
		pSprite->setPosition(ccp(pSprite->getContentSize().width/2, pSprite->getContentSize().height/2));
		this->addChild(pSprite);
	}

	return true;
}

void ColorMachinePanel::setColor(MachineColor color)
{
	if(color == m_color)
		return;
	m_color = color;
	CCTexture2D * texture = NULL;
	switch(m_color)
	{
		case ColorSilver:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_silver.png");
			break;
		case ColorGold:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_gold.png");
			break;
		case ColorRed:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_red.png");
			break;
		case ColorDarkRed:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_darkred.png");
			break;
		case ColorGreen:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_green.png");
			break;
		case ColorBlue:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_blue.png");
			break;
		case ColorBlack:
			texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_black.png");
			break;
	}
	CCSprite* pSprite = dynamic_cast<CCSprite*>(this->getChildByTag(Color_Image));
	if(pSprite)
		pSprite->setTexture(texture);
}
