/*
 * DecklinkOutputMac.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#ifndef MAC_DECKLINKOUTPUTMAC_H_
#define MAC_DECKLINKOUTPUTMAC_H_
#include "../DecklinkOutput.h"
class Decklink_Output_Mac: public Decklink_Output {
public:
	Decklink_Output_Mac();
	~Decklink_Output_Mac();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();

};

#endif /* MAC_DECKLINKOUTPUTMAC_H_ */
