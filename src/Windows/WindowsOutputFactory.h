/*
 * WindowsOutputFactory.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_WINDOWSOUTPUTFACTORY_H_
#define WINDOWS_WINDOWSOUTPUTFACTORY_H_

#include "../OutputFactory.h"
#include "DesktopOutputWindows.h"
#include "DecklinkOutputWindows.h"
class Windows_Output_Factory: public Output_Factory {
public:
	Windows_Output_Factory();
	~Windows_Output_Factory();
	Output* Create_Output(std::string args);
	Desktop_Output* Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y);
	Decklink_Output* Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name);
};

#endif /* WINDOWS_WINDOWSOUTPUTFACTORY_H_ */
