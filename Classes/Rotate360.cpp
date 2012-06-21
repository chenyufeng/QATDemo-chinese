#include "Rotate360.h"
#include "MS5Layer.h"
#include "MainScene.h"
#include "ColorMachinePanel.h"

Rotate360::Rotate360(void)
	: m_fRotateAngle(0.0f)
	, m_fLastRotateAngle(0.0f)
	, m_state(kStateUngrabbed)
	, m_nPage(0)
	, m_bCanRotate(true)
{
	//m_PointPos[60].nPosX[0]=int(98*2.82f);m_PointPos[60].nPosY[0]=768-(46*2.82f); m_PointPos[60].nPosX[1]=0;m_PointPos[60].nPosY[1]=0;
	//m_PointPos[60].nPosX[2]=int(124*2.82f);m_PointPos[60].nPosY[2]=768-(126*2.82f); m_PointPos[60].nPosX[3]=0;m_PointPos[60].nPosY[3]=0;
	//m_PointPos[60].nPosX[4]=0;m_PointPos[60].nPosY[4]=0; m_PointPos[59].nPosX[5]=int(76*2.82f);m_PointPos[60].nPosY[5]=768-(130*2.82f);
	//m_PointPos[60].nPosX[6]=int(120*2.82f);m_PointPos[60].nPosY[6]=768-(208*2.82f); m_PointPos[60].nPosX[7]=0;m_PointPos[60].nPosY[7]=0;
	
	m_PointPos[59].nPosX[0]=int(98*2.82f);m_PointPos[59].nPosY[0]=768-(46*2.82f); m_PointPos[59].nPosX[1]=0;m_PointPos[59].nPosY[1]=0;
	m_PointPos[59].nPosX[2]=int(124*2.82f);m_PointPos[59].nPosY[2]=768-(126*2.82f); m_PointPos[59].nPosX[3]=0;m_PointPos[59].nPosY[3]=0;
	m_PointPos[59].nPosX[4]=0;m_PointPos[59].nPosY[4]=0; m_PointPos[59].nPosX[5]=int(76*2.82f);m_PointPos[59].nPosY[5]=768-(130*2.82f);
	m_PointPos[59].nPosX[6]=int(120*2.82f);m_PointPos[59].nPosY[6]=768-(208*2.82f); m_PointPos[59].nPosX[7]=0;m_PointPos[59].nPosY[7]=0;

	m_PointPos[58].nPosX[0]=int(98*2.82f);m_PointPos[58].nPosY[0]=768-(46*2.82f); m_PointPos[58].nPosX[1]=0;m_PointPos[58].nPosY[1]=0;
	m_PointPos[58].nPosX[2]=int(124*2.82f);m_PointPos[58].nPosY[2]=768-(126*2.82f); m_PointPos[58].nPosX[3]=0;m_PointPos[58].nPosY[3]=0;
	m_PointPos[58].nPosX[4]=0;m_PointPos[58].nPosY[4]=0; m_PointPos[58].nPosX[5]=int(76*2.82f);m_PointPos[58].nPosY[5]=768-(130*2.82f);
	m_PointPos[58].nPosX[6]=int(120*2.82f);m_PointPos[58].nPosY[6]=768-(208*2.82f); m_PointPos[58].nPosX[7]=0;m_PointPos[58].nPosY[7]=0;

	m_PointPos[57].nPosX[0]=int(98*2.82f);m_PointPos[57].nPosY[0]=768-(40*2.82f); m_PointPos[57].nPosX[1]=0;m_PointPos[57].nPosY[1]=0;
	m_PointPos[57].nPosX[2]=int(124*2.82f);m_PointPos[57].nPosY[2]=768-(102*2.82f); m_PointPos[57].nPosX[3]=0;m_PointPos[57].nPosY[3]=0;
	m_PointPos[57].nPosX[4]=0;m_PointPos[57].nPosY[4]=0; m_PointPos[57].nPosX[5]=int(76*2.82f);m_PointPos[57].nPosY[5]=768-(120*2.82f);
	m_PointPos[57].nPosX[6]=int(120*2.82f);m_PointPos[57].nPosY[6]=768-(196*2.82f); m_PointPos[57].nPosX[7]=0;m_PointPos[57].nPosY[7]=0;

	m_PointPos[56].nPosX[0]=int(96*2.82f);m_PointPos[56].nPosY[0]=768-(40*2.82f); m_PointPos[56].nPosX[1]=0;m_PointPos[56].nPosY[1]=0;
	m_PointPos[56].nPosX[2]=int(124*2.82f);m_PointPos[56].nPosY[2]=768-(96*2.82f); m_PointPos[56].nPosX[3]=0;m_PointPos[56].nPosY[3]=0;
	m_PointPos[56].nPosX[4]=0;m_PointPos[56].nPosY[4]=0; m_PointPos[56].nPosX[5]=int(76*2.82f);m_PointPos[56].nPosY[5]=768-(120*2.82f);
	m_PointPos[56].nPosX[6]=int(120*2.82f);m_PointPos[56].nPosY[6]=768-(196*2.82f); m_PointPos[56].nPosX[7]=0;m_PointPos[56].nPosY[7]=0; 


	m_PointPos[55].nPosX[0]=int(96*2.82f);m_PointPos[55].nPosY[0]=768-(40*2.82f); m_PointPos[55].nPosX[1]=0;m_PointPos[55].nPosY[1]=0;
	m_PointPos[55].nPosX[2]=int(124*2.82f);m_PointPos[55].nPosY[2]=768-(88*2.82f); m_PointPos[55].nPosX[3]=0;m_PointPos[55].nPosY[3]=0;
	m_PointPos[55].nPosX[4]=0;m_PointPos[55].nPosY[4]=0; m_PointPos[55].nPosX[5]=int(76*2.82f);m_PointPos[55].nPosY[5]=768-(120*2.82f);
	m_PointPos[55].nPosX[6]=int(124*2.82f);m_PointPos[55].nPosY[6]=768-(180*2.82f); m_PointPos[55].nPosX[7]=0;m_PointPos[55].nPosY[7]=0; 

	m_PointPos[54].nPosX[0]=int(96*2.82f);m_PointPos[54].nPosY[0]=768-(40*2.82f); m_PointPos[54].nPosX[1]=0;m_PointPos[54].nPosY[1]=0;
	m_PointPos[54].nPosX[2]=int(122*2.82f);m_PointPos[54].nPosY[2]=768-(80*2.82f); m_PointPos[54].nPosX[3]=0;m_PointPos[54].nPosY[3]=0;
	m_PointPos[54].nPosX[4]=0;m_PointPos[54].nPosY[4]=0; m_PointPos[54].nPosX[5]=int(76*2.82f);m_PointPos[54].nPosY[5]=768-(120*2.82f);
	m_PointPos[54].nPosX[6]=int(126*2.82f);m_PointPos[54].nPosY[6]=768-(174*2.82f); m_PointPos[54].nPosX[7]=0;m_PointPos[54].nPosY[7]=0; 

	m_PointPos[53].nPosX[0]=int(96*2.82f);m_PointPos[53].nPosY[0]=768-(40*2.82f); m_PointPos[53].nPosX[1]=0;m_PointPos[53].nPosY[1]=0;
	m_PointPos[53].nPosX[2]=int(122*2.82f);m_PointPos[53].nPosY[2]=768-(80*2.82f); m_PointPos[53].nPosX[3]=0;m_PointPos[53].nPosY[3]=0;
	m_PointPos[53].nPosX[4]=0;m_PointPos[53].nPosY[4]=0; m_PointPos[53].nPosX[5]=int(76*2.82f);m_PointPos[53].nPosY[5]=768-(120*2.82f);
	m_PointPos[53].nPosX[6]=int(126*2.82f);m_PointPos[53].nPosY[6]=768-(174*2.82f); m_PointPos[53].nPosX[7]=0;m_PointPos[53].nPosY[7]=0; 

	m_PointPos[52].nPosX[0]=0;m_PointPos[52].nPosY[0]=0; m_PointPos[52].nPosX[1]=0;m_PointPos[52].nPosY[1]=0;
	m_PointPos[52].nPosX[2]=0;m_PointPos[52].nPosY[2]=0; m_PointPos[52].nPosX[3]=0;m_PointPos[52].nPosY[3]=0;
	m_PointPos[52].nPosX[4]=0;m_PointPos[52].nPosY[4]=0; m_PointPos[52].nPosX[5]=int(76*2.82f);m_PointPos[52].nPosY[5]=768-(120*2.82f);
	m_PointPos[52].nPosX[6]=int(130*2.82f);m_PointPos[52].nPosY[6]=768-(160*2.82f); m_PointPos[52].nPosX[7]=0;m_PointPos[52].nPosY[7]=0; 

	m_PointPos[51].nPosX[0]=0;m_PointPos[51].nPosY[0]=0; m_PointPos[51].nPosX[1]=0;m_PointPos[51].nPosY[1]=0;
	m_PointPos[51].nPosX[2]=0;m_PointPos[51].nPosY[2]=0; m_PointPos[51].nPosX[3]=0;m_PointPos[51].nPosY[3]=0;
	m_PointPos[51].nPosX[4]=0;m_PointPos[51].nPosY[4]=0; m_PointPos[51].nPosX[5]=int(76*2.82f);m_PointPos[51].nPosY[5]=768-(120*2.82f);
	m_PointPos[51].nPosX[6]=int(130*2.82f);m_PointPos[51].nPosY[6]=768-(146*2.82f); m_PointPos[51].nPosX[7]=0;m_PointPos[51].nPosY[7]=0; 

	m_PointPos[50].nPosX[0]=0;m_PointPos[50].nPosY[0]=0; m_PointPos[50].nPosX[1]=0;m_PointPos[50].nPosY[1]=0;
	m_PointPos[50].nPosX[2]=0;m_PointPos[50].nPosY[2]=0; m_PointPos[50].nPosX[3]=0;m_PointPos[50].nPosY[3]=0;
	m_PointPos[50].nPosX[4]=0;m_PointPos[50].nPosY[4]=0; m_PointPos[50].nPosX[5]=int(76*2.82f);m_PointPos[50].nPosY[5]=768-(120*2.82f);
	m_PointPos[50].nPosX[6]=int(130*2.82f);m_PointPos[50].nPosY[6]=768-(132*2.82f); m_PointPos[50].nPosX[7]=0;m_PointPos[50].nPosY[7]=0; 

	m_PointPos[49].nPosX[0]=0;m_PointPos[49].nPosY[0]=0; m_PointPos[49].nPosX[1]=0;m_PointPos[49].nPosY[1]=0;
	m_PointPos[49].nPosX[2]=0;m_PointPos[49].nPosY[2]=0; m_PointPos[49].nPosX[3]=0;m_PointPos[49].nPosY[3]=0;
	m_PointPos[49].nPosX[4]=0;m_PointPos[49].nPosY[4]=0; m_PointPos[49].nPosX[5]=int(76*2.82f);m_PointPos[49].nPosY[5]=768-(120*2.82f);
	m_PointPos[49].nPosX[6]=int(130*2.82f);m_PointPos[49].nPosY[6]=768-(130*2.82f); m_PointPos[49].nPosX[7]=0;m_PointPos[49].nPosY[7]=0; 

	m_PointPos[48].nPosX[0]=0;m_PointPos[48].nPosY[0]=0; m_PointPos[48].nPosX[1]=0;m_PointPos[48].nPosY[1]=0;
	m_PointPos[48].nPosX[2]=0;m_PointPos[48].nPosY[2]=0; m_PointPos[48].nPosX[3]=0;m_PointPos[48].nPosY[3]=0;
	m_PointPos[48].nPosX[4]=0;m_PointPos[48].nPosY[4]=0; m_PointPos[48].nPosX[5]=int(76*2.82f);m_PointPos[48].nPosY[5]=768-(120*2.82f);
	m_PointPos[48].nPosX[6]=int(130*2.82f);m_PointPos[48].nPosY[6]=768-(120*2.82f); m_PointPos[48].nPosX[7]=0;m_PointPos[48].nPosY[7]=0; 

	m_PointPos[47].nPosX[0]=0;m_PointPos[47].nPosY[0]=0; m_PointPos[47].nPosX[1]=0;m_PointPos[47].nPosY[1]=0;
	m_PointPos[47].nPosX[2]=0;m_PointPos[47].nPosY[2]=0; m_PointPos[47].nPosX[3]=0;m_PointPos[47].nPosY[3]=0;
	m_PointPos[47].nPosX[4]=0;m_PointPos[47].nPosY[4]=0; m_PointPos[47].nPosX[5]=int(76*2.82f);m_PointPos[47].nPosY[5]=768-(120*2.82f);
	m_PointPos[47].nPosX[6]=int(130*2.82f);m_PointPos[47].nPosY[6]=768-(106*2.82f); m_PointPos[47].nPosX[7]=0;m_PointPos[47].nPosY[7]=0; 

	m_PointPos[46].nPosX[0]=0;m_PointPos[46].nPosY[0]=0; m_PointPos[46].nPosX[1]=0;m_PointPos[46].nPosY[1]=0;
	m_PointPos[46].nPosX[2]=0;m_PointPos[46].nPosY[2]=0; m_PointPos[46].nPosX[3]=0;m_PointPos[46].nPosY[3]=0;
	m_PointPos[46].nPosX[4]=0;m_PointPos[46].nPosY[4]=0; m_PointPos[46].nPosX[5]=int(76*2.82f);m_PointPos[46].nPosY[5]=768-(120*2.82f);
	m_PointPos[46].nPosX[6]=int(130*2.82f);m_PointPos[46].nPosY[6]=768-(90*2.82f); m_PointPos[46].nPosX[7]=0;m_PointPos[46].nPosY[7]=0; 

	m_PointPos[45].nPosX[0]=0;m_PointPos[45].nPosY[0]=0; m_PointPos[45].nPosX[1]=0;m_PointPos[45].nPosY[1]=0;
	m_PointPos[45].nPosX[2]=0;m_PointPos[45].nPosY[2]=0; m_PointPos[45].nPosX[3]=0;m_PointPos[45].nPosY[3]=0;
	m_PointPos[45].nPosX[4]=0;m_PointPos[45].nPosY[4]=0; m_PointPos[45].nPosX[5]=int(76*2.82f);m_PointPos[45].nPosY[5]=768-(120*2.82f);
	m_PointPos[45].nPosX[6]=int(130*2.82f);m_PointPos[45].nPosY[6]=768-(90*2.82f); m_PointPos[45].nPosX[7]=0;m_PointPos[45].nPosY[7]=0; 

	m_PointPos[44].nPosX[0]=0;m_PointPos[44].nPosY[0]=0; m_PointPos[44].nPosX[1]=0;m_PointPos[44].nPosY[1]=0;
	m_PointPos[44].nPosX[2]=0;m_PointPos[44].nPosY[2]=0; m_PointPos[44].nPosX[3]=0;m_PointPos[44].nPosY[3]=0;
	m_PointPos[44].nPosX[4]=0;m_PointPos[44].nPosY[4]=0; m_PointPos[44].nPosX[5]=int(76*2.82f);m_PointPos[44].nPosY[5]=768-(120*2.82f);
	m_PointPos[44].nPosX[6]=int(130*2.82f);m_PointPos[44].nPosY[6]=768-(90*2.82f); m_PointPos[44].nPosX[7]=0;m_PointPos[44].nPosY[7]=0; 


	m_PointPos[43].nPosX[0]=0;m_PointPos[43].nPosY[0]=0; m_PointPos[43].nPosX[1]=0;m_PointPos[43].nPosY[1]=0;
	m_PointPos[43].nPosX[2]=0;m_PointPos[43].nPosY[2]=0; m_PointPos[43].nPosX[3]=int(144*2.82f);m_PointPos[43].nPosY[3]=768-(170*2.82f);
	m_PointPos[43].nPosX[4]=int(124*2.82f);m_PointPos[43].nPosY[4]=768-(158*2.82f); m_PointPos[43].nPosX[5]=int(76*2.82f);m_PointPos[43].nPosY[5]=768-(120*2.82f);
	m_PointPos[43].nPosX[6]=int(120*2.82f);m_PointPos[43].nPosY[6]=768-(70*2.82f); m_PointPos[43].nPosX[7]=int(138*2.82f);m_PointPos[43].nPosY[7]=768-(170*2.82f); 


	m_PointPos[42].nPosX[0]=0;m_PointPos[42].nPosY[0]=0; m_PointPos[42].nPosX[1]=0;m_PointPos[42].nPosY[1]=0;
	m_PointPos[42].nPosX[2]=0;m_PointPos[42].nPosY[2]=0; m_PointPos[42].nPosX[3]=int(144*2.82f);m_PointPos[42].nPosY[3]=768-(164*2.82f);
	m_PointPos[42].nPosX[4]=int(124*2.82f);m_PointPos[42].nPosY[4]=768-(150*2.82f); m_PointPos[42].nPosX[5]=int(76*2.82f);m_PointPos[42].nPosY[5]=768-(120*2.82f);
	m_PointPos[42].nPosX[6]=int(124*2.82f);m_PointPos[42].nPosY[6]=768-(70*2.82f); m_PointPos[42].nPosX[7]=int(136*2.82f);m_PointPos[42].nPosY[7]=768-(164*2.82f); 


	m_PointPos[41].nPosX[0]=0;m_PointPos[41].nPosY[0]=0; m_PointPos[41].nPosX[1]=0;m_PointPos[41].nPosY[1]=0;
	m_PointPos[41].nPosX[2]=0;m_PointPos[41].nPosY[2]=0; m_PointPos[41].nPosX[3]=int(146*2.82f);m_PointPos[41].nPosY[3]=768-(158*2.82f);
	m_PointPos[41].nPosX[4]=int(126*2.82f);m_PointPos[41].nPosY[4]=768-(140*2.82f); m_PointPos[41].nPosX[5]=int(76*2.82f);m_PointPos[41].nPosY[5]=768-(120*2.82f);
	m_PointPos[41].nPosX[6]=int(120*2.82f);m_PointPos[41].nPosY[6]=768-(60*2.82f); m_PointPos[41].nPosX[7]=int(132*2.82f);m_PointPos[41].nPosY[7]=768-(158*2.82f); 


	m_PointPos[40].nPosX[0]=0;m_PointPos[40].nPosY[0]=0; m_PointPos[40].nPosX[1]=0;m_PointPos[40].nPosY[1]=0;
	m_PointPos[40].nPosX[2]=0;m_PointPos[40].nPosY[2]=0; m_PointPos[40].nPosX[3]=int(146*2.82f);m_PointPos[40].nPosY[3]=768-(152*2.82f);
	m_PointPos[40].nPosX[4]=int(126*2.82f);m_PointPos[40].nPosY[4]=768-(134*2.82f); m_PointPos[40].nPosX[5]=int(76*2.82f);m_PointPos[40].nPosY[5]=768-(120*2.82f);
	m_PointPos[40].nPosX[6]=int(120*2.82f);m_PointPos[40].nPosY[6]=768-(60*2.82f); m_PointPos[40].nPosX[7]=int(136*2.82f);m_PointPos[40].nPosY[7]=768-(152*2.82f); 


	m_PointPos[39].nPosX[0]=0;m_PointPos[39].nPosY[0]=0; m_PointPos[39].nPosX[1]=0;m_PointPos[39].nPosY[1]=0;
	m_PointPos[39].nPosX[2]=0;m_PointPos[39].nPosY[2]=0; m_PointPos[39].nPosX[3]=int(148*2.82f);m_PointPos[39].nPosY[3]=768-(146*2.82f);
	m_PointPos[39].nPosX[4]=int(126*2.82f);m_PointPos[39].nPosY[4]=768-(124*2.82f); m_PointPos[39].nPosX[5]=int(76*2.82f);m_PointPos[39].nPosY[5]=768-(120*2.82f);
	m_PointPos[39].nPosX[6]=int(120*2.82f);m_PointPos[39].nPosY[6]=768-(58*2.82f); m_PointPos[39].nPosX[7]=int(138*2.82f);m_PointPos[39].nPosY[7]=768-(146*2.82f); 

	m_PointPos[38].nPosX[0]=0;m_PointPos[38].nPosY[0]=0; m_PointPos[38].nPosX[1]=0;m_PointPos[38].nPosY[1]=0;
	m_PointPos[38].nPosX[2]=0;m_PointPos[38].nPosY[2]=0; m_PointPos[38].nPosX[3]=int(148*2.82f);m_PointPos[38].nPosY[3]=768-(140*2.82f);
	m_PointPos[38].nPosX[4]=int(122*2.82f);m_PointPos[38].nPosY[4]=768-(116*2.82f); m_PointPos[38].nPosX[5]=int(76*2.82f);m_PointPos[38].nPosY[5]=768-(120*2.82f);
	m_PointPos[38].nPosX[6]=int(118*2.82f);m_PointPos[38].nPosY[6]=768-(50*2.82f); m_PointPos[38].nPosX[7]=int(138*2.82f);m_PointPos[38].nPosY[7]=768-(140*2.82f); 

	m_PointPos[37].nPosX[0]=0;m_PointPos[37].nPosY[0]=0; m_PointPos[37].nPosX[1]=0;m_PointPos[37].nPosY[1]=0;
	m_PointPos[37].nPosX[2]=0;m_PointPos[37].nPosY[2]=0; m_PointPos[37].nPosX[3]=int(148*2.82f);m_PointPos[37].nPosY[3]=768-(134*2.82f);
	m_PointPos[37].nPosX[4]=int(124*2.82f);m_PointPos[37].nPosY[4]=768-(106*2.82f); m_PointPos[37].nPosX[5]=int(76*2.82f);m_PointPos[37].nPosY[5]=768-(120*2.82f);
	m_PointPos[37].nPosX[6]=int(118*2.82f);m_PointPos[37].nPosY[6]=768-(50*2.82f); m_PointPos[37].nPosX[7]=int(138*2.82f);m_PointPos[37].nPosY[7]=768-(134*2.82f); 

	m_PointPos[36].nPosX[0]=0;m_PointPos[36].nPosY[0]=0; m_PointPos[36].nPosX[1]=0;m_PointPos[36].nPosY[1]=0;
	m_PointPos[36].nPosX[2]=0;m_PointPos[36].nPosY[2]=0; m_PointPos[36].nPosX[3]=int(148*2.82f);m_PointPos[36].nPosY[3]=768-(128*2.82f);
	m_PointPos[36].nPosX[4]=int(124*2.82f);m_PointPos[36].nPosY[4]=768-(100*2.82f); m_PointPos[36].nPosX[5]=int(76*2.82f);m_PointPos[36].nPosY[5]=768-(120*2.82f);
	m_PointPos[36].nPosX[6]=int(118*2.82f);m_PointPos[36].nPosY[6]=768-(50*2.82f); m_PointPos[36].nPosX[7]=int(138*2.82f);m_PointPos[36].nPosY[7]=768-(128*2.82f); 

	m_PointPos[35].nPosX[0]=0;m_PointPos[35].nPosY[0]=0; m_PointPos[35].nPosX[1]=0;m_PointPos[35].nPosY[1]=0;
	m_PointPos[35].nPosX[2]=0;m_PointPos[35].nPosY[2]=0; m_PointPos[35].nPosX[3]=int(148*2.82f);m_PointPos[35].nPosY[3]=768-(120*2.82f);
	m_PointPos[35].nPosX[4]=int(120*2.82f);m_PointPos[35].nPosY[4]=768-(90*2.82f); m_PointPos[35].nPosX[5]=int(76*2.82f);m_PointPos[35].nPosY[5]=768-(130*2.82f);
	m_PointPos[35].nPosX[6]=0;m_PointPos[35].nPosY[6]=0; m_PointPos[35].nPosX[7]=int(138*2.82f);m_PointPos[35].nPosY[7]=768-(120*2.82f); 

	m_PointPos[34].nPosX[0]=0;m_PointPos[34].nPosY[0]=0; m_PointPos[34].nPosX[1]=0;m_PointPos[34].nPosY[1]=0;
	m_PointPos[34].nPosX[2]=0;m_PointPos[34].nPosY[2]=0; m_PointPos[34].nPosX[3]=int(148*2.82f);m_PointPos[34].nPosY[3]=768-(114*2.82f);
	m_PointPos[34].nPosX[4]=int(120*2.82f);m_PointPos[34].nPosY[4]=768-(84*2.82f); m_PointPos[34].nPosX[5]=int(76*2.82f);m_PointPos[34].nPosY[5]=768-(130*2.82f);
	m_PointPos[34].nPosX[6]=0;m_PointPos[34].nPosY[6]=0; m_PointPos[34].nPosX[7]=int(138*2.82f);m_PointPos[34].nPosY[7]=768-(114*2.82f); 

	m_PointPos[33].nPosX[0]=0;m_PointPos[33].nPosY[0]=0; m_PointPos[33].nPosX[1]=0;m_PointPos[33].nPosY[1]=0;
	m_PointPos[33].nPosX[2]=0;m_PointPos[33].nPosY[2]=0; m_PointPos[33].nPosX[3]=int(148*2.82f);m_PointPos[33].nPosY[3]=768-(108*2.82f);
	m_PointPos[33].nPosX[4]=int(120*2.82f);m_PointPos[33].nPosY[4]=768-(78*2.82f); m_PointPos[33].nPosX[5]=int(76*2.82f);m_PointPos[33].nPosY[5]=768-(130*2.82f);
	m_PointPos[33].nPosX[6]=0;m_PointPos[33].nPosY[6]=0; m_PointPos[33].nPosX[7]=int(138*2.82f);m_PointPos[33].nPosY[7]=768-(108*2.82f); 

	m_PointPos[32].nPosX[0]=0;m_PointPos[32].nPosY[0]=0; m_PointPos[32].nPosX[1]=0;m_PointPos[32].nPosY[1]=0;
	m_PointPos[32].nPosX[2]=0;m_PointPos[32].nPosY[2]=0; m_PointPos[32].nPosX[3]=int(146*2.82f);m_PointPos[32].nPosY[3]=768-(102*2.82f);
	m_PointPos[32].nPosX[4]=int(120*2.82f);m_PointPos[32].nPosY[4]=768-(72*2.82f); m_PointPos[32].nPosX[5]=int(76*2.82f);m_PointPos[32].nPosY[5]=768-(130*2.82f);
	m_PointPos[32].nPosX[6]=0;m_PointPos[32].nPosY[6]=0; m_PointPos[32].nPosX[7]=int(138*2.82f);m_PointPos[32].nPosY[7]=768-(102*2.82f); 

	m_PointPos[31].nPosX[0]=0;m_PointPos[31].nPosY[0]=0; m_PointPos[31].nPosX[1]=0;m_PointPos[31].nPosY[1]=0;
	m_PointPos[31].nPosX[2]=0;m_PointPos[31].nPosY[2]=0; m_PointPos[31].nPosX[3]=int(146*2.82f);m_PointPos[31].nPosY[3]=768-(96*2.82f);
	m_PointPos[31].nPosX[4]=int(118*2.82f);m_PointPos[31].nPosY[4]=768-(68*2.82f); m_PointPos[31].nPosX[5]=int(76*2.82f);m_PointPos[31].nPosY[5]=768-(130*2.82f);
	m_PointPos[31].nPosX[6]=0;m_PointPos[31].nPosY[6]=0; m_PointPos[31].nPosX[7]=int(136*2.82f);m_PointPos[31].nPosY[7]=768-(96*2.82f); 

	m_PointPos[30].nPosX[0]=0;m_PointPos[30].nPosY[0]=0; m_PointPos[30].nPosX[1]=0;m_PointPos[30].nPosY[1]=0;
	m_PointPos[30].nPosX[2]=0;m_PointPos[30].nPosY[2]=0; m_PointPos[30].nPosX[3]=int(146*2.82f);m_PointPos[30].nPosY[3]=768-(92*2.82f);
	m_PointPos[30].nPosX[4]=int(116*2.82f);m_PointPos[30].nPosY[4]=768-(62*2.82f); m_PointPos[30].nPosX[5]=int(76*2.82f);m_PointPos[30].nPosY[5]=768-(130*2.82f);
	m_PointPos[30].nPosX[6]=0;m_PointPos[30].nPosY[6]=0; m_PointPos[30].nPosX[7]=int(134*2.82f);m_PointPos[30].nPosY[7]=768-(92*2.82f); 

	m_PointPos[29].nPosX[0]=0;m_PointPos[29].nPosY[0]=0; m_PointPos[29].nPosX[1]=0;m_PointPos[29].nPosY[1]=0;
	m_PointPos[29].nPosX[2]=0;m_PointPos[29].nPosY[2]=0; m_PointPos[29].nPosX[3]=int(146*2.82f);m_PointPos[29].nPosY[3]=768-(88*2.82f);
	m_PointPos[29].nPosX[4]=int(116*2.82f);m_PointPos[29].nPosY[4]=768-(60*2.82f); m_PointPos[29].nPosX[5]=int(76*2.82f);m_PointPos[29].nPosY[5]=768-(130*2.82f);
	m_PointPos[29].nPosX[6]=0;m_PointPos[29].nPosY[6]=0; m_PointPos[29].nPosX[7]=int(132*2.82f);m_PointPos[29].nPosY[7]=768-(88*2.82f); 

	m_PointPos[28].nPosX[0]=0;m_PointPos[28].nPosY[0]=0; m_PointPos[28].nPosX[1]=0;m_PointPos[28].nPosY[1]=0;
	m_PointPos[28].nPosX[2]=0;m_PointPos[28].nPosY[2]=0; m_PointPos[28].nPosX[3]=int(144*2.82f);m_PointPos[28].nPosY[3]=768-(84*2.82f);
	m_PointPos[28].nPosX[4]=int(114*2.82f);m_PointPos[28].nPosY[4]=768-(58*2.82f); m_PointPos[28].nPosX[5]=int(76*2.82f);m_PointPos[28].nPosY[5]=768-(130*2.82f);
	m_PointPos[28].nPosX[6]=0;m_PointPos[28].nPosY[6]=0; m_PointPos[28].nPosX[7]=int(132*2.82f);m_PointPos[28].nPosY[7]=768-(84*2.82f); 


	m_PointPos[27].nPosX[0]=0;m_PointPos[27].nPosY[0]=0; m_PointPos[27].nPosX[1]=0;m_PointPos[27].nPosY[1]=0;
	m_PointPos[27].nPosX[2]=0;m_PointPos[27].nPosY[2]=0; m_PointPos[27].nPosX[3]=int(142*2.82f);m_PointPos[27].nPosY[3]=768-(80*2.82f);
	m_PointPos[27].nPosX[4]=int(112*2.82f);m_PointPos[27].nPosY[4]=768-(54*2.82f); m_PointPos[27].nPosX[5]=int(74*2.82f);m_PointPos[27].nPosY[5]=768-(130*2.82f);
	m_PointPos[27].nPosX[6]=int(120*2.82f);m_PointPos[27].nPosY[6]=768-(210*2.82f); m_PointPos[27].nPosX[7]=int(132*2.82f);m_PointPos[27].nPosY[7]=768-(80*2.82f); 

	m_PointPos[26].nPosX[0]=0;m_PointPos[26].nPosY[0]=0; m_PointPos[26].nPosX[1]=0;m_PointPos[26].nPosY[1]=0;
	m_PointPos[26].nPosX[2]=0;m_PointPos[26].nPosY[2]=0; m_PointPos[26].nPosX[3]=int(140*2.82f);m_PointPos[26].nPosY[3]=768-(76*2.82f);
	m_PointPos[26].nPosX[4]=int(110*2.82f);m_PointPos[26].nPosY[4]=768-(54*2.82f); m_PointPos[26].nPosX[5]=int(74*2.82f);m_PointPos[26].nPosY[5]=768-(130*2.82f);
	m_PointPos[26].nPosX[6]=int(120*2.82f);m_PointPos[26].nPosY[6]=768-(210*2.82f); m_PointPos[26].nPosX[7]=int(130*2.82f);m_PointPos[26].nPosY[7]=768-(76*2.82f); 

	m_PointPos[25].nPosX[0]=0;m_PointPos[25].nPosY[0]=0; m_PointPos[25].nPosX[1]=0;m_PointPos[25].nPosY[1]=0;
	m_PointPos[25].nPosX[2]=0;m_PointPos[25].nPosY[2]=0; m_PointPos[25].nPosX[3]=int(140*2.82f);m_PointPos[25].nPosY[3]=768-(74*2.82f);
	m_PointPos[25].nPosX[4]=int(110*2.82f);m_PointPos[25].nPosY[4]=768-(52*2.82f); m_PointPos[25].nPosX[5]=int(74*2.82f);m_PointPos[25].nPosY[5]=768-(130*2.82f);
	m_PointPos[25].nPosX[6]=int(120*2.82f);m_PointPos[25].nPosY[6]=768-(210*2.82f); m_PointPos[25].nPosX[7]=int(130*2.82f);m_PointPos[25].nPosY[7]=768-(74*2.82f); 

	m_PointPos[24].nPosX[0]=0;m_PointPos[24].nPosY[0]=0; m_PointPos[24].nPosX[1]=0;m_PointPos[24].nPosY[1]=0;
	m_PointPos[24].nPosX[2]=0;m_PointPos[24].nPosY[2]=0; m_PointPos[24].nPosX[3]=int(140*2.82f);m_PointPos[24].nPosY[3]=768-(72*2.82f);
	m_PointPos[24].nPosX[4]=int(108*2.82f);m_PointPos[24].nPosY[4]=768-(52*2.82f); m_PointPos[24].nPosX[5]=int(74*2.82f);m_PointPos[24].nPosY[5]=768-(130*2.82f);
	m_PointPos[24].nPosX[6]=int(120*2.82f);m_PointPos[24].nPosY[6]=768-(200*2.82f); m_PointPos[24].nPosX[7]=int(128*2.82f);m_PointPos[24].nPosY[7]=768-(72*2.82f); 

	m_PointPos[23].nPosX[0]=0;m_PointPos[23].nPosY[0]=0; m_PointPos[23].nPosX[1]=0;m_PointPos[23].nPosY[1]=0;
	m_PointPos[23].nPosX[2]=0;m_PointPos[23].nPosY[2]=0; m_PointPos[23].nPosX[3]=int(140*2.82f);m_PointPos[23].nPosY[3]=768-(72*2.82f);
	m_PointPos[23].nPosX[4]=int(108*2.82f);m_PointPos[23].nPosY[4]=768-(56*2.82f); m_PointPos[23].nPosX[5]=int(74*2.82f);m_PointPos[23].nPosY[5]=768-(130*2.82f);
	m_PointPos[23].nPosX[6]=int(120*2.82f);m_PointPos[23].nPosY[6]=768-(194*2.82f); m_PointPos[23].nPosX[7]=int(128*2.82f);m_PointPos[23].nPosY[7]=768-(72*2.82f); 

	m_PointPos[22].nPosX[0]=0;m_PointPos[22].nPosY[0]=0; m_PointPos[22].nPosX[1]=0;m_PointPos[22].nPosY[1]=0;
	m_PointPos[22].nPosX[2]=0;m_PointPos[22].nPosY[2]=0; m_PointPos[22].nPosX[3]=0;m_PointPos[22].nPosY[3]=0;
	m_PointPos[22].nPosX[4]=0;m_PointPos[22].nPosY[4]=0; m_PointPos[22].nPosX[5]=int(74*2.82f);m_PointPos[22].nPosY[5]=768-(130*2.82f);
	m_PointPos[22].nPosX[6]=int(124*2.82f);m_PointPos[22].nPosY[6]=768-(190*2.82f); m_PointPos[22].nPosX[7]=0;m_PointPos[22].nPosY[7]=0; 

	m_PointPos[21].nPosX[0]=0;m_PointPos[21].nPosY[0]=0; m_PointPos[21].nPosX[1]=0;m_PointPos[21].nPosY[1]=0;
	m_PointPos[21].nPosX[2]=0;m_PointPos[21].nPosY[2]=0; m_PointPos[21].nPosX[3]=0;m_PointPos[21].nPosY[3]=0;
	m_PointPos[21].nPosX[4]=0;m_PointPos[21].nPosY[4]=0; m_PointPos[21].nPosX[5]=int(72*2.82f);m_PointPos[21].nPosY[5]=768-(140*2.82f);
	m_PointPos[21].nPosX[6]=int(130*2.82f);m_PointPos[21].nPosY[6]=768-(180*2.82f); m_PointPos[21].nPosX[7]=0;m_PointPos[21].nPosY[7]=0; 

	m_PointPos[20].nPosX[0]=0;m_PointPos[20].nPosY[0]=0; m_PointPos[20].nPosX[1]=0;m_PointPos[20].nPosY[1]=0;
	m_PointPos[20].nPosX[2]=0;m_PointPos[20].nPosY[2]=0; m_PointPos[20].nPosX[3]=0;m_PointPos[20].nPosY[3]=0;
	m_PointPos[20].nPosX[4]=0;m_PointPos[20].nPosY[4]=0; m_PointPos[20].nPosX[5]=int(72*2.82f);m_PointPos[20].nPosY[5]=768-(140*2.82f);
	m_PointPos[20].nPosX[6]=int(130*2.82f);m_PointPos[20].nPosY[6]=768-(180*2.82f); m_PointPos[20].nPosX[7]=0;m_PointPos[20].nPosY[7]=0; 

	m_PointPos[19].nPosX[0]=0;m_PointPos[19].nPosY[0]=0; m_PointPos[19].nPosX[1]=0;m_PointPos[19].nPosY[1]=0;
	m_PointPos[19].nPosX[2]=0;m_PointPos[19].nPosY[2]=0; m_PointPos[19].nPosX[3]=0;m_PointPos[19].nPosY[3]=0;
	m_PointPos[19].nPosX[4]=0;m_PointPos[19].nPosY[4]=0; m_PointPos[19].nPosX[5]=int(72*2.82f);m_PointPos[19].nPosY[5]=768-(140*2.82f);
	m_PointPos[19].nPosX[6]=int(130*2.82f);m_PointPos[19].nPosY[6]=768-(170*2.82f); m_PointPos[19].nPosX[7]=0;m_PointPos[19].nPosY[7]=0; 

	m_PointPos[18].nPosX[0]=0;m_PointPos[18].nPosY[0]=0; m_PointPos[18].nPosX[1]=0;m_PointPos[18].nPosY[1]=0;
	m_PointPos[18].nPosX[2]=0;m_PointPos[18].nPosY[2]=0; m_PointPos[18].nPosX[3]=0;m_PointPos[18].nPosY[3]=0;
	m_PointPos[18].nPosX[4]=0;m_PointPos[18].nPosY[4]=0; m_PointPos[18].nPosX[5]=int(72*2.82f);m_PointPos[18].nPosY[5]=768-(140*2.82f);
	m_PointPos[18].nPosX[6]=int(130*2.82f);m_PointPos[18].nPosY[6]=768-(154*2.82f); m_PointPos[18].nPosX[7]=0;m_PointPos[18].nPosY[7]=0; 

	m_PointPos[17].nPosX[0]=0;m_PointPos[17].nPosY[0]=0; m_PointPos[17].nPosX[1]=0;m_PointPos[17].nPosY[1]=0;
	m_PointPos[17].nPosX[2]=0;m_PointPos[17].nPosY[2]=0; m_PointPos[17].nPosX[3]=0;m_PointPos[17].nPosY[3]=0;
	m_PointPos[17].nPosX[4]=0;m_PointPos[17].nPosY[4]=0; m_PointPos[17].nPosX[5]=int(72*2.82f);m_PointPos[17].nPosY[5]=768-(140*2.82f);
	m_PointPos[17].nPosX[6]=int(130*2.82f);m_PointPos[17].nPosY[6]=768-(154*2.82f); m_PointPos[17].nPosX[7]=0;m_PointPos[17].nPosY[7]=0; 

	m_PointPos[16].nPosX[0]=0;m_PointPos[16].nPosY[0]=0; m_PointPos[16].nPosX[1]=0;m_PointPos[16].nPosY[1]=0;
	m_PointPos[16].nPosX[2]=0;m_PointPos[16].nPosY[2]=0; m_PointPos[16].nPosX[3]=0;m_PointPos[16].nPosY[3]=0;
	m_PointPos[16].nPosX[4]=0;m_PointPos[16].nPosY[4]=0; m_PointPos[16].nPosX[5]=int(76*2.82f);m_PointPos[16].nPosY[5]=768-(140*2.82f);
	m_PointPos[16].nPosX[6]=int(130*2.82f);m_PointPos[16].nPosY[6]=768-(140*2.82f); m_PointPos[16].nPosX[7]=0;m_PointPos[16].nPosY[7]=0; 

	m_PointPos[15].nPosX[0]=0;m_PointPos[15].nPosY[0]=0; m_PointPos[15].nPosX[1]=0;m_PointPos[15].nPosY[1]=0;
	m_PointPos[15].nPosX[2]=0;m_PointPos[15].nPosY[2]=0; m_PointPos[15].nPosX[3]=0;m_PointPos[15].nPosY[3]=0;
	m_PointPos[15].nPosX[4]=0;m_PointPos[15].nPosY[4]=0; m_PointPos[15].nPosX[5]=int(76*2.82f);m_PointPos[15].nPosY[5]=768-(140*2.82f);
	m_PointPos[15].nPosX[6]=int(130*2.82f);m_PointPos[15].nPosY[6]=768-(140*2.82f); m_PointPos[15].nPosX[7]=0;m_PointPos[15].nPosY[7]=0; 

	m_PointPos[14].nPosX[0]=0;m_PointPos[14].nPosY[0]=0; m_PointPos[14].nPosX[1]=0;m_PointPos[14].nPosY[1]=0;
	m_PointPos[14].nPosX[2]=0;m_PointPos[14].nPosY[2]=0; m_PointPos[14].nPosX[3]=0;m_PointPos[14].nPosY[3]=0;
	m_PointPos[14].nPosX[4]=0;m_PointPos[14].nPosY[4]=0; m_PointPos[14].nPosX[5]=int(76*2.82f);m_PointPos[14].nPosY[5]=768-(140*2.82f);
	m_PointPos[14].nPosX[6]=int(128*2.82f);m_PointPos[14].nPosY[6]=768-(122*2.82f); m_PointPos[14].nPosX[7]=0;m_PointPos[14].nPosY[7]=0; 

	m_PointPos[13].nPosX[0]=0;m_PointPos[13].nPosY[0]=0; m_PointPos[13].nPosX[1]=0;m_PointPos[13].nPosY[1]=0;
	m_PointPos[13].nPosX[2]=0;m_PointPos[13].nPosY[2]=0; m_PointPos[13].nPosX[3]=0;m_PointPos[13].nPosY[3]=0;
	m_PointPos[13].nPosX[4]=0;m_PointPos[13].nPosY[4]=0; m_PointPos[13].nPosX[5]=int(76*2.82f);m_PointPos[13].nPosY[5]=768-(140*2.82f);
	m_PointPos[13].nPosX[6]=int(128*2.82f);m_PointPos[13].nPosY[6]=768-(122*2.82f); m_PointPos[13].nPosX[7]=0;m_PointPos[13].nPosY[7]=0; 

	m_PointPos[12].nPosX[0]=0;m_PointPos[12].nPosY[0]=0; m_PointPos[12].nPosX[1]=0;m_PointPos[12].nPosY[1]=0;
	m_PointPos[12].nPosX[2]=0;m_PointPos[12].nPosY[2]=0; m_PointPos[12].nPosX[3]=0;m_PointPos[12].nPosY[3]=0;
	m_PointPos[12].nPosX[4]=0;m_PointPos[12].nPosY[4]=0; m_PointPos[12].nPosX[5]=int(76*2.82f);m_PointPos[12].nPosY[5]=768-(134*2.82f);
	m_PointPos[12].nPosX[6]=int(128*2.82f);m_PointPos[12].nPosY[6]=768-(108*2.82f); m_PointPos[12].nPosX[7]=0;m_PointPos[12].nPosY[7]=0; 

	m_PointPos[11].nPosX[0]=0;m_PointPos[11].nPosY[0]=0; m_PointPos[11].nPosX[1]=0;m_PointPos[11].nPosY[1]=0;
	m_PointPos[11].nPosX[2]=0;m_PointPos[11].nPosY[2]=0; m_PointPos[11].nPosX[3]=0;m_PointPos[11].nPosY[3]=0;
	m_PointPos[11].nPosX[4]=0;m_PointPos[11].nPosY[4]=0; m_PointPos[11].nPosX[5]=int(76*2.82f);m_PointPos[11].nPosY[5]=768-(134*2.82f);
	m_PointPos[11].nPosX[6]=int(128*2.82f);m_PointPos[11].nPosY[6]=768-(108*2.82f); m_PointPos[11].nPosX[7]=0;m_PointPos[11].nPosY[7]=0; 

	m_PointPos[10].nPosX[0]=int(108*2.82f);m_PointPos[10].nPosY[0]=768-(172*2.82f); m_PointPos[10].nPosX[1]=0;m_PointPos[10].nPosY[1]=0;
	m_PointPos[10].nPosX[2]=int(110*2.82f);m_PointPos[10].nPosY[2]=768-(218*2.82f); m_PointPos[10].nPosX[3]=0;m_PointPos[10].nPosY[3]=0;
	m_PointPos[10].nPosX[4]=0;m_PointPos[10].nPosY[4]=0; m_PointPos[10].nPosX[5]=int(76*2.82f);m_PointPos[10].nPosY[5]=768-(140*2.82f);
	m_PointPos[10].nPosX[6]=int(128*2.82f);m_PointPos[10].nPosY[6]=768-(90*2.82f); m_PointPos[10].nPosX[7]=0;m_PointPos[10].nPosY[7]=0; 

	m_PointPos[9].nPosX[0]=int(108*2.82f);m_PointPos[9].nPosY[0]=768-(160*2.82f); m_PointPos[9].nPosX[1]=0;m_PointPos[9].nPosY[1]=0;
	m_PointPos[9].nPosX[2]=int(114*2.82f);m_PointPos[9].nPosY[2]=768-(218*2.82f); m_PointPos[9].nPosX[3]=0;m_PointPos[9].nPosY[3]=0;
	m_PointPos[9].nPosX[4]=0;m_PointPos[9].nPosY[4]=0; m_PointPos[9].nPosX[5]=int(76*2.82f);m_PointPos[9].nPosY[5]=768-(140*2.82f);
	m_PointPos[9].nPosX[6]=int(120*2.82f);m_PointPos[9].nPosY[6]=768-(90*2.82f); m_PointPos[9].nPosX[7]=0;m_PointPos[9].nPosY[7]=0; 

	m_PointPos[8].nPosX[0]=int(110*2.82f);m_PointPos[8].nPosY[0]=768-(152*2.82f); m_PointPos[8].nPosX[1]=0;m_PointPos[8].nPosY[1]=0;
	m_PointPos[8].nPosX[2]=int(114*2.82f);m_PointPos[8].nPosY[2]=768-(218*2.82f); m_PointPos[8].nPosX[3]=0;m_PointPos[8].nPosY[3]=0;
	m_PointPos[8].nPosX[4]=0;m_PointPos[8].nPosY[4]=0; m_PointPos[8].nPosX[5]=int(76*2.82f);m_PointPos[8].nPosY[5]=768-(140*2.82f);
	m_PointPos[8].nPosX[6]=int(126*2.82f);m_PointPos[8].nPosY[6]=768-(80*2.82f); m_PointPos[8].nPosX[7]=0;m_PointPos[8].nPosY[7]=0; 

	m_PointPos[7].nPosX[0]=int(110*2.82f);m_PointPos[7].nPosY[0]=768-(140*2.82f); m_PointPos[7].nPosX[1]=0;m_PointPos[7].nPosY[1]=0;
	m_PointPos[7].nPosX[2]=int(116*2.82f);m_PointPos[7].nPosY[2]=768-(210*2.82f); m_PointPos[7].nPosX[3]=0;m_PointPos[7].nPosY[3]=0;
	m_PointPos[7].nPosX[4]=0;m_PointPos[7].nPosY[4]=0; m_PointPos[7].nPosX[5]=int(76*2.82f);m_PointPos[7].nPosY[5]=768-(140*2.82f);
	m_PointPos[7].nPosX[6]=int(120*2.82f);m_PointPos[7].nPosY[6]=768-(70*2.82f); m_PointPos[7].nPosX[7]=0;m_PointPos[7].nPosY[7]=0; 

	m_PointPos[6].nPosX[0]=int(110*2.82f);m_PointPos[6].nPosY[0]=768-(130*2.82f); m_PointPos[6].nPosX[1]=0;m_PointPos[6].nPosY[1]=0;
	m_PointPos[6].nPosX[2]=int(118*2.82f);m_PointPos[6].nPosY[2]=768-(210*2.82f); m_PointPos[6].nPosX[3]=0;m_PointPos[6].nPosY[3]=0;
	m_PointPos[6].nPosX[4]=0;m_PointPos[6].nPosY[4]=0; m_PointPos[6].nPosX[5]=int(76*2.82f);m_PointPos[6].nPosY[5]=768-(140*2.82f);
	m_PointPos[6].nPosX[6]=int(120*2.82f);m_PointPos[6].nPosY[6]=768-(70*2.82f); m_PointPos[6].nPosX[7]=0;m_PointPos[6].nPosY[7]=0; 

	m_PointPos[5].nPosX[0]=int(106*2.82f);m_PointPos[5].nPosY[0]=768-(120*2.82f); m_PointPos[5].nPosX[1]=0;m_PointPos[5].nPosY[1]=0;
	m_PointPos[5].nPosX[2]=int(120*2.82f);m_PointPos[5].nPosY[2]=768-(210*2.82f); m_PointPos[5].nPosX[3]=0;m_PointPos[5].nPosY[3]=0;
	m_PointPos[5].nPosX[4]=0;m_PointPos[5].nPosY[4]=0; m_PointPos[5].nPosX[5]=int(76*2.82f);m_PointPos[5].nPosY[5]=768-(140*2.82f);
	m_PointPos[5].nPosX[6]=int(120*2.82f);m_PointPos[5].nPosY[6]=768-(60*2.82f); m_PointPos[5].nPosX[7]=0;m_PointPos[5].nPosY[7]=0; 

	m_PointPos[4].nPosX[0]=int(108*2.82f);m_PointPos[4].nPosY[0]=768-(108*2.82f); m_PointPos[4].nPosX[1]=0;m_PointPos[4].nPosY[1]=0;
	m_PointPos[4].nPosX[2]=int(120*2.82f);m_PointPos[4].nPosY[2]=768-(202*2.82f); m_PointPos[4].nPosX[3]=0;m_PointPos[4].nPosY[3]=0;
	m_PointPos[4].nPosX[4]=0;m_PointPos[4].nPosY[4]=0; m_PointPos[4].nPosX[5]=int(76*2.82f);m_PointPos[4].nPosY[5]=768-(140*2.82f);
	m_PointPos[4].nPosX[6]=int(120*2.82f);m_PointPos[4].nPosY[6]=768-(60*2.82f); m_PointPos[4].nPosX[7]=0;m_PointPos[4].nPosY[7]=0; 

	m_PointPos[3].nPosX[0]=int(108*2.82f);m_PointPos[3].nPosY[0]=768-(100*2.82f); m_PointPos[3].nPosX[1]=0;m_PointPos[3].nPosY[1]=0;
	m_PointPos[3].nPosX[2]=int(122*2.82f);m_PointPos[3].nPosY[2]=768-(198*2.82f); m_PointPos[3].nPosX[3]=0;m_PointPos[3].nPosY[3]=0;
	m_PointPos[3].nPosX[4]=0;m_PointPos[3].nPosY[4]=0; m_PointPos[3].nPosX[5]=int(76*2.82f);m_PointPos[3].nPosY[5]=768-(140*2.82f);
	m_PointPos[3].nPosX[6]=0;m_PointPos[3].nPosY[6]=0; m_PointPos[3].nPosX[7]=0;m_PointPos[3].nPosY[7]=0; 

	m_PointPos[2].nPosX[0]=int(108*2.82f);m_PointPos[2].nPosY[0]=768-(90*2.82f); m_PointPos[2].nPosX[1]=0;m_PointPos[2].nPosY[1]=0;
	m_PointPos[2].nPosX[2]=int(122*2.82f);m_PointPos[2].nPosY[2]=768-(188*2.82f); m_PointPos[2].nPosX[3]=0;m_PointPos[2].nPosY[3]=0;
	m_PointPos[2].nPosX[4]=0;m_PointPos[2].nPosY[4]=0; m_PointPos[2].nPosX[5]=int(76*2.82f);m_PointPos[2].nPosY[5]=768-(130*2.82f);
	m_PointPos[2].nPosX[6]=0;m_PointPos[2].nPosY[6]=0; m_PointPos[2].nPosX[7]=0;m_PointPos[2].nPosY[7]=0; 

	m_PointPos[1].nPosX[0]=int(108*2.82f);m_PointPos[1].nPosY[0]=768-(82*2.82f); m_PointPos[1].nPosX[1]=0;m_PointPos[1].nPosY[1]=0;
	m_PointPos[1].nPosX[2]=int(122*2.82f);m_PointPos[1].nPosY[2]=768-(180*2.82f); m_PointPos[1].nPosX[3]=0;m_PointPos[1].nPosY[3]=0;
	m_PointPos[1].nPosX[4]=0;m_PointPos[1].nPosY[4]=0; m_PointPos[1].nPosX[5]=int(76*2.82f);m_PointPos[1].nPosY[5]=768-(130*2.82f);
	m_PointPos[1].nPosX[6]=0;m_PointPos[1].nPosY[6]=0; m_PointPos[1].nPosX[7]=0;m_PointPos[1].nPosY[7]=0; 

	m_PointPos[0].nPosX[0]=int(108*2.82f);m_PointPos[0].nPosY[0]=768-(76*2.82f); m_PointPos[0].nPosX[1]=0;m_PointPos[0].nPosY[1]=0;
	m_PointPos[0].nPosX[2]=int(124*2.82f);m_PointPos[0].nPosY[2]=768-(172*2.82f); m_PointPos[0].nPosX[3]=0;m_PointPos[0].nPosY[3]=0;
	m_PointPos[0].nPosX[4]=0;m_PointPos[0].nPosY[4]=0; m_PointPos[0].nPosX[5]=int(76*2.82f);m_PointPos[0].nPosY[5]=768-(130*2.82f);
	m_PointPos[0].nPosX[6]=0;m_PointPos[0].nPosY[6]=0; m_PointPos[0].nPosX[7]=0;m_PointPos[0].nPosY[7]=0; 

	for(int i=0; i<60; i++)
	{
		for(int j=0; j<8; j++)
		{
			if(m_PointPos[i].nPosX[j] != 0)
			{
				int nTemp = m_PointPos[i].nPosX[j];
				m_PointPos[i].nPosX[j] = -(m_PointPos[i].nPosY[j]-768);
				m_PointPos[i].nPosY[j] = 728 - nTemp;
			}
		}
	}
}

Rotate360::~Rotate360(void)
{
}

Rotate360* Rotate360::rotate()
{
	Rotate360* pSelector = new Rotate360();
	pSelector->init(  );
	pSelector->autorelease();

	return pSelector;
}

bool Rotate360::init()
{
	m_state = kStateUngrabbed;

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	/*CCSprite* pSprite = CCSprite::spriteWithFile("shape/01.png");
	pSprite->setTag(TAG_SHADOW);
	pSprite->setPosition( ccp(pSprite->getContentSize().width/2+53, size.height-(pSprite->getContentSize().height/2+373)) );
	this->addChild(pSprite, 1);*/
	
	CCSprite* pSprite = CCSprite::spriteWithSpriteFrameName("arrow.png");
	pSprite->setPosition( ccp(377, 296) );
	pSprite->setTag(TAG_ARROW);
	this->addChild(pSprite, 1);

	pSprite = CCSprite::spriteWithFile("machine/machine_01.png");
	pSprite->setTag(TAG_MACHINE);
	//pSprite->setPosition( ccp(pSprite->getContentSize().width/2+112, size.height-(pSprite->getContentSize().height/2+197)) );
	pSprite->setPosition( ccp(pSprite->getContentSize().width/2+42, size.height-(pSprite->getContentSize().height/2+219)) );
	this->addChild(pSprite, 1);

	for(int i=0, nTag=0; i<8; i++)
	{
		pSprite = CCSprite::spriteWithSpriteFrameName("point.png");
		m_pPoint[i] = CCMenuItemSprite::itemFromNormalSprite(pSprite, NULL, NULL, this, menu_selector(Rotate360::pointMenuCallback));
		m_pPoint[i]->setTag(nTag++);
		m_pPoint[i]->setPosition( ccp(0, 0) );
	}
	
	CCMenu* pMenu = CCMenu::menuWithItems(m_pPoint[0], m_pPoint[2], m_pPoint[3], m_pPoint[4], m_pPoint[5],m_pPoint[6], m_pPoint[7], m_pPoint[8],NULL);
	pMenu->setTag(TAG_POINT);
	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);
	
	char szPath[256];
	for(int i=1; i<=60; )
	{
		sprintf(szPath, "machine/machine_%02d.png", i);
		CCTextureCache::sharedTextureCache()->addImage(szPath);
		//sprintf(szPath, "shape/%02d.png", i);
		//CCTextureCache::sharedTextureCache()->addImage(szPath);
		i += 2;
	}

	m_fRotateAngle = 30.0f;
	m_fLastRotateAngle = 30.0f;
	m_bCanRotate = true;
	updateAngle();
	return true;
}

void Rotate360::onEnter()
{
	addFadeInOutEffect();
	CCTouchDispatcher::sharedDispatcher()->addTargetedDelegate(this, 0, true);
	CCNode::onEnter();
}

void Rotate360::onExit()
{
	removeFadeInOutEffect();
	CCTouchDispatcher::sharedDispatcher()->removeDelegate(this);
	CCNode::onExit();
}	

bool Rotate360::containsTouchLocation(CCTouch* touch)
{
	CCSprite* pMachine = dynamic_cast<CCSprite*>(this->getChildByTag(TAG_MACHINE));
	if(!pMachine)
		return false;
	CCSize s = pMachine->getContentSize();
	return CCRect::CCRectContainsPoint(CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height), pMachine->convertTouchToNodeSpaceAR(touch));
}

bool Rotate360::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	if(!m_bCanRotate)
		return false;
	if (m_state != kStateUngrabbed) 
		return false;
	if ( !containsTouchLocation(touch) ) 
		return false;

	firstPoint = touch->locationInView( touch->view() );
	firstPoint = CCDirector::sharedDirector()->convertToGL( firstPoint );
//	CCPoint firstVector = ccpSub(firstPoint, this->getChildByTag(TAG_MACHINE)->getPosition());   
//	CGFloat firstRotateAngle = ccpToAngle(firstVector);            
//	CGFloat previousTouch = CC_RADIANS_TO_DEGREES(firstRotateAngle); 

	m_state = kStateGrabbed;
	hideAllPanel();
	//removeFadeInOutEffect();
	hidePointAndArrow();
	return true;
}

void Rotate360::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	// If it weren't for the TouchDispatcher, you would need to keep a reference
	// to the touch from touchBegan and check that the current touch is the same
	// as that one.
	// Actually, it would be even more complicated since in the Cocos dispatcher
	// you get CCSets instead of 1 UITouch, so you'd need to loop through the set
	// in each touchXXX method.

	CCAssert(m_state == kStateGrabbed, L"Rotate360 - Unexpected state!");	

	CCPoint touchPoint = touch->locationInView( touch->view() );
	touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );
	//CCPoint firstPoint = touch->previousLocationInView( touch->view() );
	//firstPoint = CCDirector::sharedDirector()->convertToGL( firstPoint );

	//CCPoint firstVector = ccpSub(firstPoint, this->getChildByTag(TAG_MACHINE)->getPosition());   
	//CGFloat firstRotateAngle = ccpToAngle(firstVector);            
	//CGFloat previousTouch = CC_RADIANS_TO_DEGREES(firstRotateAngle); 
	//CCPoint vector = ccpSub(touchPoint, this->getChildByTag(TAG_MACHINE)->getPosition());            
	//CGFloat rotateAngle = ccpToAngle(vector);           
	//CGFloat currentTouch = CC_RADIANS_TO_DEGREES(rotateAngle); 
	//m_fRotateAngle = m_fLastRotateAngle + (currentTouch - previousTouch);
	m_fRotateAngle = m_fLastRotateAngle + (touchPoint.x - firstPoint.x)/662.0f*180;
	//CCLog("angle=%f\n", m_fRotateAngle);
	while(m_fRotateAngle<0.0f)
		m_fRotateAngle += 360.0f;
	m_fRotateAngle = fmod(m_fRotateAngle, 360.0f); 
	
	updateAngle();
}

void Rotate360::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCAssert(m_state == kStateGrabbed, L"Rotate360 - Unexpected state!");	

	m_fLastRotateAngle = m_fRotateAngle;
	m_state = kStateUngrabbed;
	//addFadeInOutEffect();
	showPointAndArrow();
} 

void Rotate360::touchDelegateRetain()
{
	this->retain();
}

void Rotate360::touchDelegateRelease()
{
	this->release();
}

void Rotate360::addFadeInOutEffect()
{
	int nTag = TAG_ARROW;
	for(int i=0; i<2; i++)
	{
		CCFadeOut* pFadeOut = CCFadeOut::actionWithDuration(1);
		CCFadeIn* pFadeIn = CCFadeIn::actionWithDuration(1);
		CCSequence* pSequence = CCSequence::actionOneTwo(pFadeOut, pFadeIn);
		CCRepeatForever* pForever = CCRepeatForever::actionWithAction(pSequence);
		CCNode* pNode = this->getChildByTag(nTag++);
		if(pNode)
		{
			pNode->stopAllActions();
			pNode->runAction(pForever);
		}
	}
}

void Rotate360::removeFadeInOutEffect()
{
	int nTag = TAG_ARROW;
	for(int i=0; i<2; i++)
	{
		CCNode* pNode = this->getChildByTag(nTag++);
		if(pNode)
		{
			pNode->stopAllActions();
		}
	}
}

void Rotate360::showPointAndArrow()
{
	int nTag = TAG_POINT;
	for(int i=0; i<1; i++)
	{
		CCNode* pNode = this->getChildByTag(nTag++);
		if(pNode)
		{
			pNode->setIsVisible(true);
		}
	}
}
void Rotate360::hidePointAndArrow()
{
	int nTag = TAG_POINT;
	for(int i=0; i<1; i++)
	{
		CCNode* pNode = this->getChildByTag(nTag++);
		if(pNode)
		{
			pNode->setIsVisible(false);
		}
	}
}

void Rotate360::updateAngle()
{
	char szPath[256];
	int nIndex =(m_fRotateAngle/6.0f);
	nIndex += 1;
	/*float fStart = 0.0f;
	float fEnd = 6.0f;
	for(int i=1; i<=60; i++)
	{
		if(m_fRotateAngle >=fStart && m_fRotateAngle <fEnd)
		{
			nIndex = i;
			break;
		}
		fStart += 6.0f;
		fEnd += 6.0f;
	}*/
	
	int nImage = nIndex;//(nIndex-1)/5*5+1;
	if(nImage%2==0)
		nImage = nImage-1;
	/*int nImage = 1; 
	if(nIndex>=1 && nIndex <10)
		nImage = 1;
	else if(nIndex>=10 && nIndex<19)
		nImage = 10;
	else if(nIndex>=19 && nIndex<28)
		nImage = 19;
	else if(nIndex>=28 && nIndex<37)
		nImage = 28;
	else if(nIndex>=37 && nIndex<46)
		nImage = 37;
	else if(nIndex>=46 && nIndex<55)
		nImage = 46;
	else if(nIndex>=55 && nIndex<64)
		nImage = 55;*/
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite* pMachine = dynamic_cast<CCSprite*>(this->getChildByTag(TAG_MACHINE));
	if(pMachine)
	{
		sprintf(szPath, "machine/machine_%02d.png", nImage);
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey(szPath);
		if(!texture)
			texture = CCTextureCache::sharedTextureCache()->addImage(szPath);
		pMachine->setTexture(texture);
		//pMachine->setPosition( ccp(pMachine->getContentSize().width/2+m_arMachinePos[nIndex-1][0], size.height-(pMachine->getContentSize().height/2+m_arMachinePos[nIndex-1][1])) );
		//pMachine->setPosition( ccp(pMachine->getContentSize().width/2+42, size.height-(pMachine->getContentSize().height/2+179)) );
	}
	/*CCSprite* pShadow = dynamic_cast<CCSprite*>(this->getChildByTag(TAG_SHADOW));
	if(pShadow)
	{
		sprintf(szPath, "shape/%02d.png", nImage);
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey(szPath);
		if(!texture)
			texture = CCTextureCache::sharedTextureCache()->addImage(szPath);
		pShadow->setTexture(texture);
		//pShadow->setPosition( ccp(pShadow->getContentSize().width/2+53, size.height-(pShadow->getContentSize().height/2+373)) );
	}*/
	updatePoint(nIndex);
	//CCDirector::sharedDirector()->purgeCachedData();
}

void Rotate360::hideAllPanel()
{
	// get root node
	CCNode* pNode = this->getParent();
	MS5Layer* pLayer = dynamic_cast<MS5Layer*>(pNode);
	if(pLayer)
		pLayer->hidePopupPanel();
	CCNode* pNode1 = this;
	while(pNode->getParent() != NULL)
	{
		pNode1 = pNode;
		pNode = pNode->getParent();
	}
	MainScene* pScene = dynamic_cast<MainScene*>(pNode1);
	if(pScene)
	{
		pScene->hideMenu();
	}
}

void Rotate360::pointMenuCallback(CCObject* pSender)
{
	CCNode* pSendNode = dynamic_cast<CCNode*>(pSender);
	if(!pSendNode)
		return;
	CCNode* pNode = this->getParent();
	MS5Layer* pLayer = dynamic_cast<MS5Layer*>(pNode);
	if(pLayer)
		pLayer->showNotePanel(TAG_NOTE0 + pSendNode->getTag(), 0, m_PointPos[m_nPage].nPosX[pSendNode->getTag()], m_PointPos[m_nPage].nPosY[pSendNode->getTag()]);
}

void Rotate360::updatePoint(int nPage)
{
	m_nPage = nPage-1;
	for(int i=0; i<8; i++)
	{
		if(i==1)
			continue;
		if(m_PointPos[m_nPage].nPosX[i] == 0)
		{
			m_pPoint[i]->setIsEnabled(false);
			m_pPoint[i]->setIsVisible(false);
		}
		else
		{
			m_pPoint[i]->setIsEnabled(true);
			m_pPoint[i]->setIsVisible(true);
			m_pPoint[i]->setPosition(ccp(m_PointPos[m_nPage].nPosX[i], m_PointPos[m_nPage].nPosY[i]));
		}
	}
}

void Rotate360::updateColor(int nColor)
{
	CCSprite* pMachine = dynamic_cast<CCSprite*>(this->getChildByTag(TAG_MACHINE));
	switch((ColorMachinePanel::MachineColor)nColor)
	{
	case ColorMachinePanel::ColorSilver:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = true;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_06.png");
			pMachine->setTexture(texture);
		}
		break;
	case ColorMachinePanel::ColorGold:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = false;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_gold.png");
			pMachine->setTexture(texture);
		}
		break;
	case ColorMachinePanel::ColorRed:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = false;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_red.png");
			pMachine->setTexture(texture);
		}
		break;
	case ColorMachinePanel::ColorDarkRed:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = false;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_darkred.png");
			pMachine->setTexture(texture);
		}
		break;
	case ColorMachinePanel::ColorGreen:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = false;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_green.png");
			pMachine->setTexture(texture);
		}
		break;
	case ColorMachinePanel::ColorBlue:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = false;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_blue.png");
			pMachine->setTexture(texture);
		}
		break;
	case ColorMachinePanel::ColorBlack:
		m_fRotateAngle = 30.0f;
		m_bCanRotate = false;
		if(pMachine)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("machine/machine_black.png");
			pMachine->setTexture(texture);
		}
		break;
	}
	
	CCSprite* pShadow = dynamic_cast<CCSprite*>(this->getChildByTag(TAG_SHADOW));
	if(pShadow)
	{
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("shape/06.png");
		pShadow->setTexture(texture);
	}
	updatePoint(6);
	CCDirector::sharedDirector()->purgeCachedData();
}