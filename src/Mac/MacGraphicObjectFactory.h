/*
 * MacGraphicObjectFactory.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef MAC_MACGRAPHICOBJECTFACTORY_H_
#define MAC_MACGRAPHICOBJECTFACTORY_H_
#ifndef _GRAPHICOBJECTFACTORY_INCLUDED // is it already included?
#define _GRAPHICOBJECTFACTORY_INCLUDED // define this so we know it's included
#include "../GraphicObjectFactory.h"
#endif



class Mac_Graphic_Object_Factory: public Graphic_Object_Factory {
public:
	Mac_Graphic_Object_Factory();
	~Mac_Graphic_Object_Factory();
	Text* Create_Text(std::string Text, std::string Font, int Size);
	Video* Create_Video();
	Image* Create_Image();
	Solid* Create_Solid();
	std::string Get_Name();
};

#endif /* MAC_MACGRAPHICOBJECTFACTORY_H_ */
