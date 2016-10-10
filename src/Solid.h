/*
 * Solid.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef SOLID_H_
#define SOLID_H_

#include "GraphicObject.h"
/**
 * Class representing a solid object. Note that this class is not an abstract class, because it doesn't need to be!
 */
class Solid: public Graphic_Object {
public:
	Solid();
	~Solid();
	std::string Get_Name();
	uint32_t** Refresh_Frame_Buffer();
};

#endif /* SOLID_H_ */
