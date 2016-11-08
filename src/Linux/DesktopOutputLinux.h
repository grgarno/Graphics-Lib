/*
 * DesktopOutputLinux.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_DESKTOPOUTPUTLINUX_H_
#define LINUX_DESKTOPOUTPUTLINUX_H_
#include "../DesktopOutput.h"
class Desktop_Output_Linux: public Desktop_Output {
public:
	Desktop_Output_Linux();
	~Desktop_Output_Linux();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();
};

#endif /* LINUX_DESKTOPOUTPUTLINUX_H_ */
