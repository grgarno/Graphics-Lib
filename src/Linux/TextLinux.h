/*
 * TextLinux.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_TEXTLINUX_H_
#define LINUX_TEXTLINUX_H_
#include "../Text.h"
class Text_Linux: public Text {
public:
	Text_Linux();
	~Text_Linux();
	virtual uint32_t** Refresh_Frame_Buffer();
	virtual std::string Get_Name();
};

#endif /* LINUX_TEXTLINUX_H_ */
