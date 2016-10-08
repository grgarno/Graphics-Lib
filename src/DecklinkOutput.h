/*
 * DecklinkOutput.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef DECKLINKOUTPUT_H_
#define DECKLINKOUTPUT_H_

#include "Output.h"


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
