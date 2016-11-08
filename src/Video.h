/*
 * Video.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef VIDEO_H_
#define VIDEO_H_
#ifndef _GRAPHICOBJECT_INCLUDED // is it already included?
#define _GRAPHICOBJECT_INCLUDED // define this so we know it's included
#include "GraphicObject.h"
#endif

#ifndef _STRING_INCLUDED // is it already included?
#define _STRING_INCLUDED // define this so we know it's included
#include <string>
#endif


/**
 * Abstract class representing a video object
 */
class Video: public Graphic_Object {
protected:
	std::string Source_File;

public:
	Video();
	virtual ~Video();

};

#endif /* VIDEO_H_ */
