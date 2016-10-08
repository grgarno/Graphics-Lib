/*
 * ImageWindows.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_IMAGEWINDOWS_H_
#define WINDOWS_IMAGEWINDOWS_H_

#include "../Image.h"

class Image_Windows: public Image{
public:
	Image_Windows();
	~Image_Windows();
	uint32_t** Refresh_Frame_Buffer();
	std::string Get_Name();
};

#endif /* WINDOWS_IMAGEWINDOWS_H_ */
