/*
 * DecklinkOutputWindows.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_DECKLINKOUTPUTWINDOWS_H_
#define WINDOWS_DECKLINKOUTPUTWINDOWS_H_
#include "../DecklinkOutput.h"
class Decklink_Output_Windows: public Decklink_Output {
public:
	Decklink_Output_Windows();
	~Decklink_Output_Windows();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();
};

#endif /* WINDOWS_DECKLINKOUTPUTWINDOWS_H_ */
