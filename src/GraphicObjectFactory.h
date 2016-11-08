/*
 * GraphicObjectFactory.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef GRAPHICOBJECTFACTORY_H_
#define GRAPHICOBJECTFACTORY_H_

#ifndef _IOSTREAM_INCLUDED // is it already included?
#define _IOSTREAM_INCLUDED // define this so we know it's included
#include <iostream>
#endif

#ifndef _TEXT_INCLUDED // is it already included?
#define _TEXT_INCLUDED // define this so we know it's included
#include "Text.h"
#endif

#ifndef _VIDEO_INCLUDED // is it already included?
#define _VIDEO_INCLUDED // define this so we know it's included
#include "Video.h"
#endif

#ifndef _IMAGE_INCLUDED // is it already included?
#define _IMAGE_INCLUDED // define this so we know it's included
#include "Image.h"
#endif

#ifndef _SOLID_INCLUDED // is it already included?
#define _SOLID_INCLUDED // define this so we know it's included
#include "Solid.h"
#endif






/**
 * A factory to create graphic objects.
 */
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
