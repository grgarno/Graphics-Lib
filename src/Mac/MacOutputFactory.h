/*
 * MacOutputFactory.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef MAC_MACOUTPUTFACTORY_H_
#define MAC_MACOUTPUTFACTORY_H_
#ifndef _OUTPUTFACTORY_INCLUDED // is it already included?
#define _OUTPUTFACTORY_INCLUDED // define this so we know it's included
#include "../OutputFactory.h"
#endif

#ifndef _DESKTOPOUTPUTMAC_INCLUDED // is it already included?
#define _DESKTOPOUTPUTMAC_INCLUDED // define this so we know it's included
#include "DesktopOutputMac.h"
#endif

#ifndef _DECKLINKOUTPUTMAC_INCLUDED // is it already included?
#define _DECKLINKOUTPUTMAC_INCLUDED // define this so we know it's included
#include "DecklinkOutputMac.h"
#endif



class Mac_Output_Factory: public Output_Factory {
public:
	Mac_Output_Factory();
	~Mac_Output_Factory();
	Desktop_Output* Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y);
		Decklink_Output* Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name);

};

#endif /* MAC_MACOUTPUTFACTORY_H_ */
