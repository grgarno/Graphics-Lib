/*
 * DesktopOutput.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef DESKTOPOUTPUT_H_
#define DESKTOPOUTPUT_H_

#include "Output.h"

class Desktop_Output: public Output {
public:
	int x;
	int y;//x, y
	Desktop_Output();
	virtual ~Desktop_Output();
	virtual void Begin_Output() = 0;
	virtual void Stop_Output() = 0;
	virtual uint32_t** Get_Preview_Image() = 0;
};

#endif /* DESKTOPOUTPUT_H_ */
