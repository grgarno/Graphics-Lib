/*
 * LinuxGraphicObjectFactory.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_LINUXGRAPHICOBJECTFACTORY_H_
#define LINUX_LINUXGRAPHICOBJECTFACTORY_H_
#include "../GraphicObjectFactory.h"
class Linux_Graphic_Object_Factory: public Graphic_Object_Factory {
public:
	Linux_Graphic_Object_Factory();
	~Linux_Graphic_Object_Factory();
	virtual Text* Create_Text(std::string Text, std::string Font, int Size);
	virtual Video* Create_Video();
	virtual Image* Create_Image();
	virtual Solid* Create_Solid();
	virtual std::string Get_Name();
};

#endif /* LINUX_LINUXGRAPHICOBJECTFACTORY_H_ */
