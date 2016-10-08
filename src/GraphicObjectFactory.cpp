/*
 * GraphicObjectFactory.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "GraphicObjectFactory.h"

Graphic_Object_Factory::Graphic_Object_Factory() {
	// TODO Auto-generated constructor stub
	int error = FT_Init_FreeType(&library);
	if(error){
		std::cout<<"Error Creating FreeType library"<<std::endl;
	}

}

Graphic_Object_Factory::~Graphic_Object_Factory() {
	// TODO Auto-generated destructor stub
}

Text* Graphic_Object_Factory::Set_Up_Text(Text* Text_To_Set_Up, std::string Text, std::string Font, int size){
	Text_To_Set_Up->Set_Library(&library);
	Text_To_Set_Up->Set_Font_Face(Font);
	Text_To_Set_Up->Set_Font_Size(size);
	Text_To_Set_Up->Set_Text_Content(Text);
	return Text_To_Set_Up;
}

