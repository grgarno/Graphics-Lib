/*
 * ImageWindows.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "ImageWindows.h"

Image_Windows::Image_Windows() {
	// TODO Auto-generated constructor stub

}

Image_Windows::~Image_Windows() {
	// TODO Auto-generated destructor stub
}

uint32_t** Image_Windows::Refresh_Frame_Buffer(){
	return Frame_Buffer;
}

std::string Image_Windows::Get_Name(){
	return "Windows Image";
}
