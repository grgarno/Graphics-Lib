/*
 * GraphicObjectFactory.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "GraphicObjectFactory.h"
/**
 * Concrete methods of the abstract Graphic Object Factory.
 */
Graphic_Object_Factory::Graphic_Object_Factory() {

	int error = FT_Init_FreeType(&library); //initialize the text library.
	if(error){
		std::cout<<"Error Creating FreeType library"<<std::endl;
	}

}

Graphic_Object_Factory::~Graphic_Object_Factory() {
	// no member pointers, all member variables get deleted upon deconstruct
}

/**
 * Utility method, used in any concrete method to set up freetype. The way that freetype is rendered could be different depending on the platform, but the initialization should be constant between platforms.
 */
Text* Graphic_Object_Factory::Set_Up_Text(Text* Text_To_Set_Up, std::string Text, std::string Font, int size){
	Text_To_Set_Up->Set_Library(&library);

	Text_To_Set_Up->Set_Font_Face(Font);
	Text_To_Set_Up->Set_Font_Size(size);

	Text_To_Set_Up->Set_Text_Content(Text);

	return Text_To_Set_Up;
}

