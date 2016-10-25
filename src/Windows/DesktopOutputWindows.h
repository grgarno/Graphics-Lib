/*
 * DesktopOutputWindows.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_DESKTOPOUTPUTWINDOWS_H_
#define WINDOWS_DESKTOPOUTPUTWINDOWS_H_
#include "../DesktopOutput.h"
class Desktop_Output_Windows: public Desktop_Output {
public:
	Desktop_Output_Windows();
	~Desktop_Output_Windows();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();
};

#endif /* WINDOWS_DESKTOPOUTPUTWINDOWS_H_ */
