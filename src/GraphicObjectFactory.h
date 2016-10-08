/*
 * GraphicObjectFactory.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef GRAPHICOBJECTFACTORY_H_
#define GRAPHICOBJECTFACTORY_H_

#include <iostream>
#include "Text.h"
#include "Video.h"
#include "Image.h"
#include "Solid.h"


class Graphic_Object_Factory {
protected:
	Text* Set_Up_Text(Text* Text_To_Set_Up, std::string Text, std::string Font, int Size);
public:
	FT_Library library;
	Graphic_Object_Factory();
	virtual ~Graphic_Object_Factory();
	virtual Text* Create_Text(std::string Text, std::string Font, int Size) = 0;
	virtual Video* Create_Video() = 0;
	virtual Image* Create_Image() = 0;
	virtual Solid* Create_Solid() = 0;
};

#endif /* GRAPHICOBJECTFACTORY_H_ */
