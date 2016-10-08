/*
 * MacOutputFactory.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef MAC_MACOUTPUTFACTORY_H_
#define MAC_MACOUTPUTFACTORY_H_
#include "../OutputFactory.h"
#include "DesktopOutputMac.h"
#include "DecklinkOutputMac.h"

class Mac_Output_Factory: public Output_Factory {
public:
	Mac_Output_Factory();
	~Mac_Output_Factory();
	Desktop_Output* Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y);
		Decklink_Output* Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name);
		Output* Create_Output(std::string args);
};

#endif /* MAC_MACOUTPUTFACTORY_H_ */
