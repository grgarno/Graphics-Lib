/*
 * GraphicObject.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "GraphicObject.h"


Graphic_Object::Graphic_Object(){

	Opacity = 1.0;
	Maintain_Aspect_Ratio = true;
	Background_Color_R = 0;
	Background_Color_G = 0;
	Background_Color_B = 0;
	Background_Color_A = 0;
	width = 0;
	height = 0;
	x = 0;
	y = 0;
	valid = false;
	Frame_Buffer = nullptr;

}

Graphic_Object::~Graphic_Object(){

}
