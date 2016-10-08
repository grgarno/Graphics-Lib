/*
 * ImageMac.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "ImageMac.h"

Image_Mac::Image_Mac() {
	// TODO Auto-generated constructor stub
	Source_File = "";
	dummySurface = nullptr;
	valid = false;

}

Image_Mac::~Image_Mac() {
	// TODO Auto-generated destructor stub
}

uint32_t** Image_Mac::Refresh_Frame_Buffer() {

	valid = false;

	if (Source_File == "") {
		return Frame_Buffer;
	}
	if (!dummySurface) {
		int imgFlags = IMG_INIT_JPG;
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			printf("SDL_image could not initialize! SDL_image Error: %s\n",
			IMG_GetError());
			return nullptr;
		} else {
			//Get window surface
			dummySurface = IMG_Load(Source_File.c_str());
		}


	}

uint32_t* pixels = (uint32_t *) dummySurface->pixels;
	width = dummySurface->w;
	height = dummySurface->h;
	if (Frame_Buffer == nullptr) {
		Frame_Buffer = new uint32_t*[height];
		for (int i = 0; i < height; ++i) {
			Frame_Buffer[i] = new uint32_t[width];
		}

	}
	std::cout<<width<<"   "<<height<<std::endl;
	for (int county = 0; county < height; county++) {

		for (int countx = 0; countx < width; countx++) {
			Frame_Buffer[county][countx] = pixels[(county * width) + countx];
		}
	}

	valid = true;

	return Frame_Buffer;
}

std::string Image_Mac::Get_Name() {
	return "Mac Image";
}

