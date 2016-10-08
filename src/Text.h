/*
 * Text.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "GraphicObject.h"
#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H


class Text: public Graphic_Object {
protected:
	FT_Library* library;
	FT_Face face;
	FT_Error error;
	std::vector<FT_GlyphSlot> *Rendered_Glyph_Array;
public:
	std::string Text_Content;
	std::string Font;
	int Font_Size;
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
