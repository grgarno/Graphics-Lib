/*
 * ImageLinux.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_IMAGELINUX_H_
#define LINUX_IMAGELINUX_H_
#include "../Image.h"
class Image_Linux: public Image {
public:
	Image_Linux();
	~Image_Linux();
	virtual uint32_t** Refresh_Frame_Buffer();
	virtual std::string Get_Name();
};

#endif /* LINUX_IMAGELINUX_H_ */
