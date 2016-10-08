/*
 * LinuxOutputFactory.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_LINUXOUTPUTFACTORY_H_
#define LINUX_LINUXOUTPUTFACTORY_H_
#include "../OutputFactory.h"
#include "DesktopOutputLinux.h"
#include "DecklinkOutputLinux.h"
class Linux_Output_Factory: public Output_Factory {
public:
	Linux_Output_Factory();
	~Linux_Output_Factory();
	Desktop_Output* Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y);
	Decklink_Output* Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name);
	Output* Create_Output(std::string args);
};

#endif /* LINUX_LINUXOUTPUTFACTORY_H_ */
