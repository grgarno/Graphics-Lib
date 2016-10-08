/*
 * Video.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include "GraphicObject.h"
#include <string>

class Video: public Graphic_Object {
protected:
	std::string Source_File;

public:
	Video();
	virtual ~Video();

};

#endif /* VIDEO_H_ */
