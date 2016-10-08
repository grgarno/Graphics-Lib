/*
 * DecklinkOutputLinux.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_DECKLINKOUTPUTLINUX_H_
#define LINUX_DECKLINKOUTPUTLINUX_H_
#include "../DecklinkOutput.h"
class Decklink_Output_Linux: public Decklink_Output {
public:
	Decklink_Output_Linux();
	~Decklink_Output_Linux();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();
};

#endif /* LINUX_DECKLINKOUTPUTLINUX_H_ */
