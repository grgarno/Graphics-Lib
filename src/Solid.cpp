/*
 * Solid.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "Solid.h"

Solid::Solid() {
	// TODO Auto-generated constructor stub

}

Solid::~Solid() {
	// TODO Auto-generated destructor stub
}
std::string Solid::Get_Name() {
	return "Generic Solid";
}
/**
 * Refresh
 */
uint32_t** Solid::Refresh_Frame_Buffer() {
	valid = false;
	if (Frame_Buffer == nullptr) {
		Frame_Buffer = new uint32_t*[height];
		for (int i = 0; i < height; ++i) {
			Frame_Buffer[i] = new uint32_t[width];
		}

	}
	uint32_t color = (Background_Color_A << 24) + (Background_Color_R << 16) + (Background_Color_G << 8) + Background_Color_B;
	for (int county = 0; county < height; county++) {
		for (int countx = 0; countx < width; countx++) {
			Frame_Buffer[county][countx] = color;
		}
	}

	valid = true;
	return Frame_Buffer;
}
