/*
 * Image.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "GraphicObject.h"
#include <string>

class Image: public Graphic_Object {
protected:


public:
	std::string Source_File;
	Image();
	virtual ~Image();

};

#endif /* IMAGE_H_ */
