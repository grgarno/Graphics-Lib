/*
 * WindowsGraphicObjectFactory.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "WindowsGraphicObjectFactory.h"
#include "TextWindows.h"
#include "VideoWindows.h"
#include "ImageWindows.h"
#include "../Solid.h"


Windows_Graphic_Object_Factory::Windows_Graphic_Object_Factory() {
	// TODO Auto-generated constructor stub

}

Windows_Graphic_Object_Factory::~Windows_Graphic_Object_Factory() {
	// TODO Auto-generated destructor stub
}
Text* Windows_Graphic_Object_Factory::Create_Text(std::string Text, std::string Font, int Size){
	Text_Windows* return_text = new Text_Windows();
	Set_Up_Text(return_text, Text, Font, Size);
	return return_text;
}
Video* Windows_Graphic_Object_Factory::Create_Video(){
	return new Video_Windows();
}
Image* Windows_Graphic_Object_Factory::Create_Image(){
	return new Image_Windows();
}
Solid* Windows_Graphic_Object_Factory::Create_Solid(){
	return new Solid();
}


std::string Windows_Graphic_Object_Factory::Get_Name(){
	return "Windows Factory";
}

