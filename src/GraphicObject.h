/*
 * GraphicObject.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef GRAPHICOBJECT_H_
#define GRAPHICOBJECT_H_
#include <iostream>
#include <vector>
#import <string>

/**
 * An abstract representation of a graphics object used in each output to render to the screen, and by the client to control the object.
 * Includes the attributes that every graphic object should have.
 */
class Graphic_Object {

public:
	int width;
	int height;
	int x;
	int y;
	uint8_t Background_Color_R;
	uint8_t Background_Color_G;
	uint8_t Background_Color_B;
	uint8_t Background_Color_A;
	double Opacity;
	bool Maintain_Aspect_Ratio;
	bool valid;
	uint32_t** Frame_Buffer;
	Graphic_Object();
	virtual ~Graphic_Object();
	virtual std::string Get_Name() = 0;
	virtual uint32_t** Refresh_Frame_Buffer() = 0;

};

#endif /* GRAPHICOBJECT_H_ */
