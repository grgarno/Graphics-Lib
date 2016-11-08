/*
 * DesktopOutputMac.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#ifndef MAC_DESKTOPOUTPUTMAC_H_
#define MAC_DESKTOPOUTPUTMAC_H_
#ifndef _DESKTOPOUTPUT_INCLUDED // is it already included?
#define _DESKTOPOUTPUT_INCLUDED // define this so we know it's included
#include "../DesktopOutput.h"
#endif

#ifndef _SDL_INCLUDED // is it already included?
#define _SDL_INCLUDED // define this so we know it's included
#include <SDL.h>
#endif

class Desktop_Output_Mac: public Desktop_Output {
private:

	SDL_Window* window;
	SDL_Surface* windowSurface;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

//	uint8_t * oldPixels;
//	int oldPitch;
	void renderLoop();
	bool outputting = false;
	SDL_Rect dest;

public:
	Desktop_Output_Mac();
	~Desktop_Output_Mac();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();
	void refresh();
};

#endif /* MAC_DESKTOPOUTPUTMAC_H_ */
