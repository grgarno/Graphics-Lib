/*
 * TextLinux.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "TextLinux.h"

Text_Linux::Text_Linux() {
	// TODO Auto-generated constructor stub

}

Text_Linux::~Text_Linux() {
	// TODO Auto-generated destructor stub
}

uint32_t** Text_Linux::Refresh_Frame_Buffer(){
	return Frame_Buffer;
}

std::string Text_Linux::Get_Name(){
	return "Linux Text";
}
