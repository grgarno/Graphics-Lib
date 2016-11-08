/*
 * ImageLinux.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "ImageLinux.h"

Image_Linux::Image_Linux() {
	// TODO Auto-generated constructor stub

}

Image_Linux::~Image_Linux() {
	// TODO Auto-generated destructor stub
}

uint32_t** Image_Linux::Refresh_Frame_Buffer(){
	return Frame_Buffer;
}

std::string Image_Linux::Get_Name(){
	return "Linux Image";
}
