/*
 * OutputFactory.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef OUTPUTFACTORY_H_
#define OUTPUTFACTORY_H_
#ifndef _STDIO_INCLUDED // is it already included?
#define _STDIO_INCLUDED // define this so we know it's included
#include <stdio.h>
#endif

#ifndef _DESKTOPOUTPUT_INCLUDED // is it already included?
#define _DESKTOPOUTPUT_INCLUDED // define this so we know it's included
#include "DesktopOutput.h"
#endif

#ifndef _DECKLINKOUTPUT_INCLUDED // is it already included?
#define _DECKLINKOUTPUT_INCLUDED // define this so we know it's included
#include "DecklinkOutput.h"
#endif

#ifndef _HTMLOUTPUT_INCLUDED // is it already included?
#define _HTMLOUTPUT_INCLUDED // define this so we know it's included
#include "HTMLOutput.h"
#endif

/**
 * Factory for creating various kinds of outputs
 */
class Output_Factory {
private:
	double parse_arg(std::string arg, std::string param, bool is_double = true, std::string* return_string = nullptr);
public:
	Output_Factory();
	virtual ~Output_Factory();
	Output* Create_Output(std::string args);
	virtual Desktop_Output* Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y) = 0;
	virtual Decklink_Output* Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name) = 0;
};

#endif /* OUTPUTFACTORY_H_ */
