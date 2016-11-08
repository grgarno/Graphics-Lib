/*
 * DecklinkOutput.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef DECKLINKOUTPUT_H_
#define DECKLINKOUTPUT_H_

#ifndef _OUTPUT_INCLUDED // is it already included?
#define _OUTPUT_INCLUDED // define this so we know it's included
#include "Output.h"
#endif



/**
 * An abstract output representing a decklink output. This output gets created in each platform factory, and is dependent on which platform is running.
 */
class Decklink_Output: public Output {
public:
	std::string Card_Name;
	int Card_Number;
	Decklink_Output();
	virtual ~Decklink_Output();
	virtual void Begin_Output() = 0;
	virtual void Stop_Output() = 0;
	virtual uint32_t** Get_Preview_Image() = 0;
};

#endif /* DECKLINKOUTPUT_H_ */
