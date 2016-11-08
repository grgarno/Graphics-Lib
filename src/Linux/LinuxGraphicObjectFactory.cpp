/*
 * LinuxGraphicObjectFactory.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "LinuxGraphicObjectFactory.h"
#include "TextLinux.h"
#include "VideoLinux.h"
#include "ImageLinux.h"
#include "../Solid.h"

Linux_Graphic_Object_Factory::Linux_Graphic_Object_Factory() {
	// TODO Auto-generated constructor stub

}

Linux_Graphic_Object_Factory::~Linux_Graphic_Object_Factory() {
	// TODO Auto-generated destructor stub
}
Text* Linux_Graphic_Object_Factory::Create_Text(std::string Text, std::string Font, int Size){
	Text_Linux* return_text = new Text_Linux();
	Set_Up_Text(return_text, Text, Font, Size);
	return return_text;
}
Video* Linux_Graphic_Object_Factory::Create_Video(){
	return new Video_Linux();
}
Image* Linux_Graphic_Object_Factory::Create_Image(){
	return new Image_Linux();
}
Solid* Linux_Graphic_Object_Factory::Create_Solid(){
	return new Solid();
}


std::string Linux_Graphic_Object_Factory::Get_Name(){
	return "Linux Factory";
}
