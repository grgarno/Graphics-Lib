/*
 * TextWindows.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_TEXTWINDOWS_H_
#define WINDOWS_TEXTWINDOWS_H_
#include "../Text.h"
class Text_Windows: public Text {
public:
	Text_Windows();
	~Text_Windows();
	uint32_t** Refresh_Frame_Buffer();
	std::string Get_Name();
};

#endif /* WINDOWS_TEXTWINDOWS_H_ */
