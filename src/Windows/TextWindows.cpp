/*
 * TextWindows.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "TextWindows.h"

Text_Windows::Text_Windows() {
	// TODO Auto-generated constructor stub

}

Text_Windows::~Text_Windows() {
	// TODO Auto-generated destructor stub
}
uint32_t** Text_Windows::Refresh_Frame_Buffer(){
	return Text_Windows::Frame_Buffer;
}
std::string Text_Windows::Get_Name(){
	return "Windows Text";
}

