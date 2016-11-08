/*
 * DesktopOutputMac.cpp
 *
 *  Created on: 23.09.2016
 *      Author: grgarno
 */

#include "DesktopOutputMac.h"


Desktop_Output_Mac::Desktop_Output_Mac() {

	// TODO Auto-generated constructor stub

}

Desktop_Output_Mac::~Desktop_Output_Mac() {
	// TODO Auto-generated destructor stub
	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);

	 SDL_Quit();

}

void Desktop_Output_Mac::Begin_Output() {

	std::thread t(&Desktop_Output_Mac::renderLoop, this);
	t.detach();
	outputting = true;

}

void Desktop_Output_Mac::renderLoop() {
	double milli_timeout_per_frame = 1000 / Frame_Rate;
	long timeout;
	double elapsed_millisecs;
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow("SDL Tutorial", x, y, width, height,
			SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_BORDERLESS
					| SDL_WINDOW_SHOWN);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	} else {

		windowSurface = SDL_CreateRGBSurface(0, width, height, 32, 0xFF << 16,
				0xFF << 8, 0xFF, 0xFF << 24);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);

		texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
				SDL_TEXTUREACCESS_STATIC, width, height);
		uint8_t red = 128;
		uint8_t green = 0;
		uint8_t blue = 200;
		uint8_t alpha = 255;
		dest.h = height;
		dest.w = width;
		dest.x = 0;
		dest.y = 0;
		int size = (height * width);
		pixels = new uint32_t*[height];
		for (int i = 0; i < height; ++i) {
			pixels[i] = new uint32_t[width];
		}

		uint32_t color = (alpha << 24) + (red << 16) + (green << 8) + blue;
		for (int county = 0; county < height; county++) {
			for (int countx = 0; countx < width; countx++) {
				pixels[county][countx] = color;
			}
		}


		SDL_UpdateWindowSurface(window);
		SDL_ShowWindow(window);

		while (outputting) {
			clock_t begin = clock();
			refresh();

			clock_t end = clock();
			elapsed_millisecs = 1000 * (double(end - begin) / CLOCKS_PER_SEC);

			timeout = (long) (milli_timeout_per_frame - elapsed_millisecs);
			std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
		}



	}

}

void Desktop_Output_Mac::refresh() {
	Compose_Pixels();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	for (int drawY = 0; drawY < height; drawY++) {
		for (int drawX = 0; drawX < width; drawX++) {
			SDL_SetRenderDrawColor(renderer,
					(pixels[drawY][drawX] & 0x000000ff),
					(pixels[drawY][drawX] & 0x0000ff00) >> 8,
					(pixels[drawY][drawX] & 0x00ff0000) >> 16,
					(pixels[drawY][drawX] & 0xff000000) >> 24);
			SDL_RenderDrawPoint(renderer, drawX, drawY);

		}
	}

	SDL_RenderPresent(renderer);
}

void Desktop_Output_Mac::Stop_Output() {
	outputting = false;

}

uint32_t** Desktop_Output_Mac::Get_Preview_Image() {
	return nullptr;
}

