#ifndef _COLOR_MACHINE_PANEL_H_
#define _COLOR_MACHINE_PANEL_H_

#include "cocos2d.h"

using namespace cocos2d; 

#define Color_Image 200
class ColorMachinePanel : public CCSprite
{
public:
	typedef enum tagMachineColor 
	{
		ColorSilver,
		ColorGold,
		ColorRed,
		ColorDarkRed,
		ColorGreen,
		ColorBlue,
		ColorBlack
	} MachineColor; 

	ColorMachinePanel(void);
	virtual ~ColorMachinePanel(void);

	static ColorMachinePanel* panelWithFile(const char *pszFileName);
	bool initWithFile(const char *pszFileName);
	void setColor(MachineColor color);

private:
	MachineColor	m_color;
};

#endif // _COLOR_MACHINE_PANEL_H_
