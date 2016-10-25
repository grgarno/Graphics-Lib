/*
 * WindowsGraphicObjectFactory.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_WINDOWSGRAPHICOBJECTFACTORY_H_
#define WINDOWS_WINDOWSGRAPHICOBJECTFACTORY_H_

#include "../GraphicObjectFactory.h"

class Windows_Graphic_Object_Factory: public Graphic_Object_Factory {
public:
	Windows_Graphic_Object_Factory();
	~Windows_Graphic_Object_Factory();
	Text* Create_Text(std::string Text, std::string Font, int Size);
	Video* Create_Video();
	Image* Create_Image();
	Solid* Create_Solid();
	std::string Get_Name();
};

#endif /* WINDOWS_WINDOWSGRAPHICOBJECTFACTORY_H_ */
