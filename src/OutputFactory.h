/*
 * OutputFactory.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef OUTPUTFACTORY_H_
#define OUTPUTFACTORY_H_

#include "DesktopOutput.h"
#include "DecklinkOutput.h"

class Output_Factory {
public:
	Output_Factory();
	virtual ~Output_Factory();
	virtual Output* Create_Output(std::string args) = 0;
	virtual Desktop_Output* Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y) = 0;
	virtual Decklink_Output* Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name) = 0;
};

#endif /* OUTPUTFACTORY_H_ */
