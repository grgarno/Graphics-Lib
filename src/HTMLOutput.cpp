/*
 * HTMLOutput.cpp
 *
 *  Created on: 07.11.2016
 *      Author: grgarno
 */

#include "HTMLOutput.h"


HTMLOutput::HTMLOutput() {

	// TODO Auto-generated constructor stub

}

HTMLOutput::~HTMLOutput() {
	// TODO Auto-generated destructor stub
	delete[] pixels;


}

void HTMLOutput::Begin_Output() {

	std::thread t(&HTMLOutput::renderLoop, this);
	t.detach();
	outputting = true;

}

void HTMLOutput::renderLoop() {
	double milli_timeout_per_frame = 1000 / Frame_Rate;
	long timeout;
	double elapsed_millisecs;

	uint8_t red = 128;
	uint8_t green = 0;
	uint8_t blue = 200;
	uint8_t alpha = 255;
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
	//open socket.
	while (outputting) {
		clock_t begin = clock();
		refresh();

		clock_t end = clock();
		elapsed_millisecs = 1000 * (double(end - begin) / CLOCKS_PER_SEC);

		timeout = (long) (milli_timeout_per_frame - elapsed_millisecs);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
	}

}

void HTMLOutput::refresh() {
	Compose_Pixels();
	//TODO push pixels here...
	for (int drawY = 0; drawY < height; drawY++) {
		for (int drawX = 0; drawX < width; drawX++) {

		}
	}

}

void HTMLOutput::Stop_Output() {
	outputting = false;

}

uint32_t** HTMLOutput::Get_Preview_Image() {
	return pixels;
}
