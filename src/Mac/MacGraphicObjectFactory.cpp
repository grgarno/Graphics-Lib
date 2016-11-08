/*
 * MacGraphicObjectFactory.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "MacGraphicObjectFactory.h"
#include "TextMac.h"
#include "VideoMac.h"
#include "ImageMac.h"
#include "../Solid.h"




Mac_Graphic_Object_Factory::Mac_Graphic_Object_Factory() {
	// TODO Auto-generated constructor stub

}

Mac_Graphic_Object_Factory::~Mac_Graphic_Object_Factory() {
	// TODO Auto-generated destructor stub
}
Text* Mac_Graphic_Object_Factory::Create_Text(std::string Text, std::string Font, int Size){
	Text_Mac* return_text = new Text_Mac();
	Set_Up_Text(return_text, Text, Font, Size);
	return return_text;

}
Video* Mac_Graphic_Object_Factory::Create_Video(){
	return new Video_Mac();
}
Image* Mac_Graphic_Object_Factory::Create_Image(){
	return new Image_Mac();
}
Solid* Mac_Graphic_Object_Factory::Create_Solid(){
	return new Solid();
}


std::string Mac_Graphic_Object_Factory::Get_Name(){
	return "Mac Factory";
}
