/*
 * ImageMac.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef MAC_IMAGEMAC_H_
#define MAC_IMAGEMAC_H_
#include "../Image.h"
#include <SDL.h>
#include <SDL_image.h>


class Image_Mac: public Image {
protected:
	SDL_Surface* dummySurface;
public:
	Image_Mac();
	~Image_Mac();
	uint32_t** Refresh_Frame_Buffer();
	std::string Get_Name();
};

#endif /* MAC_IMAGEMAC_H_ */
