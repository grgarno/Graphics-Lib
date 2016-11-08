/*
 * Image.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#ifndef _GRAPHICOBJECT_INCLUDED // is it already included?
#define _GRAPHICOBJECT_INCLUDED // define this so we know it's included
#include "GraphicObject.h"
#endif

#ifndef _STRING_INCLUDED // is it already included?
#define _STRING_INCLUDED // define this so we know it's included
#include <string>
#endif
/**
 * Graphic object representing an image
 */
class Image: public Graphic_Object {
protected:


public:
	std::string Source_File;
	Image();
	virtual ~Image();

};

#endif /* IMAGE_H_ */
