/*
 * DesktopOutputMac.h
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */



#ifndef MAC_DESKTOPOUTPUTMAC_H_
#define MAC_DESKTOPOUTPUTMAC_H_
#include "../DesktopOutput.h"
#include <iostream>
#include <pthread.h>
#include <SDL.h>
#include <thread>
#include <ctime>



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
