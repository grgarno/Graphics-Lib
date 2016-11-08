/*
 * Text.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef TEXT_H_
#define TEXT_H_

#ifndef _GRAPHICOBJECT_INCLUDED // is it already included?
#define _GRAPHICOBJECT_INCLUDED // define this so we know it's included
#include "GraphicObject.h"
#endif

#ifndef _STRING_INCLUDED // is it already included?
#define _STRING_INCLUDED // define this so we know it's included
#include <string>
#endif

#ifndef _FT2BUILD_INCLUDED // is it already included?
#define _FT2BUILD_INCLUDED // define this so we know it's included
#include <ft2build.h>
#endif

#ifndef _VECTOR_INCLUDED // is it already included?
#define _VECTOR_INCLUDED // define this so we know it's included
#include <vector>
#endif



#ifndef _FT_FREETYPE_H_INCLUDED // is it already included?
#define _FT_FREETYPE_H_INCLUDED // define this so we know it's included
#include FT_FREETYPE_H
#endif





/**
 * Abstract class representing a text object
 */
class Text: public Graphic_Object {
protected:
	FT_Library* library;
	FT_Face face;
	FT_Error error;

public:
	std::string Text_Content;
	std::string Font;
	int Font_Size;
	int Return_Height;
	enum Horizontal_Align {left=0, center=1, right=2, justify=3}; //ENUM Type-- TODO: Put them all in a common class resource
	Horizontal_Align align;
	uint8_t Text_Color_R;
	uint8_t Text_Color_G;
	uint8_t Text_Color_B;
	uint8_t Text_Color_A;
	int* Text_Color_RGBA;
	int Outline_Size;
	int* Outline_Color_RGBA;
	int Shaddow_Size;
	int* Shaddow_Bounds;
	int* Shaddow_Color_RGBA;
	Text();
	virtual ~Text();

	void Set_Library(FT_Library* new_lib);
	FT_Face* Set_Font_Face(std::string Path_To_Font);
	void Set_Text_Content(std::string Text);
	void Set_Font_Size(int Pixel_Height);
	void Set_Font_Color(int* Color_RGBA);
	void Set_Outline_Size(int Pixel_Outline);
	void Set_Outline_Color(int* Color_RGBA);
	void Set_Shaddow_Size(int Pixel_Height);
	void Set_Shaddow_Bounds(int* Shaddow_Bounds); //Must Be in the text bounds to show
	void Set_Shaddow_Color(int* Color_RGBA);
	uint32_t** Refresh_Frame_Buffer();

};

#endif /* TEXT_H_ */
