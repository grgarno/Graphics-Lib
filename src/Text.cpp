/*
 * Text.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "Text.h"

Text::Text() {
	// TODO Finish constructor
	//Text = "";
	Font = "";
	Font_Size = 12;
	//Text_Color_RGBA = {0,0,0,0};
	Outline_Size = 4;
	//Outline_Color_RGBA = {0,0,0,0};
	Shaddow_Size = 3;
	//Shaddow_Bounds = {0,0,200,200};
	//Shaddow_Color_RGBA = {0,0,0,0};

}

Text::~Text() {
	// TODO Create proper destructor
}

/**
 * Set the library for this text object
 */
void Text::Set_Library(FT_Library* new_lib) {
	library = new_lib;
}

/**
 * Set the font for this text object.
 */
FT_Face* Text::Set_Font_Face(std::string Path_To_Font) {
	error = FT_New_Face(*library, Path_To_Font.c_str(), 0, &face);
	if (error == FT_Err_Unknown_File_Format) {
		std::cout << "The font file could not be found" << std::endl;
		return nullptr;
	} else if(error) {
		std::cout<<"There was an error creating the font"<<std::endl;
		return nullptr;
	}
	return &face;

}
/**
 * Set the text of this object.
 */
void Text::Set_Text_Content(std::string Text){
	this->Text_Content = Text;
	char const *Simple_String = Text.c_str();
	int Glyph_Index;
	width = 0;
	height = 0;


	Rendered_Glyph_Array.reserve(Text.length());
	for(int i = 0; i < Text.length(); i++){
		Glyph_Index = FT_Get_Char_Index(face, Simple_String[i]);

		error = FT_Load_Glyph(face, Glyph_Index, FT_LOAD_DEFAULT);
		//TODO error handling!
		if(error){
			std::cout<<"There was an error creating the glyph"<<std::endl;
		}
		error = false;
		error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
		if(error){
			std::cout<<"There was an error rendering the glyph"<<std::endl;
		}
		Rendered_Glyph_Array.push_back(face->glyph);

		width = width + face->glyph->bitmap.width;
		//if(height < face->glyph->bitmap.rows){
		//	height = face->glyph->bitmap.rows);

		//}


	}

}
/**
 * Set the font size of this text
 */
void Text::Set_Font_Size(int Pixel_Height){
 this->Font_Size = Pixel_Height;
 error = FT_Set_Char_Size(face, 0, (Pixel_Height * 64), 300, 300);
}
/**
 * Set the font color for this object.
 */
void Text::Set_Font_Color(int* Color_RGBA){
 this->Text_Color_RGBA = Color_RGBA;
}
/**
 * Set the outline size for this object. //TODO not implemented
 */
void Text::Set_Outline_Size(int Pixel_Outline){

}
/**
 * Set the outline color for this text object //TODO not implemented
 */
void Text::Set_Outline_Color(int* Color_RGBA){

}
/**
 * Set the shadow size for this text object //TODO not implemented //TODO Refactor so the spelling is right!
 */
void Text::Set_Shaddow_Size(int Pixel_Height){

}
/**
 * Set the shadow bounds for this object //TODO not implemented //TODO Refactor so the spelling is right!
 */
void Text::Set_Shaddow_Bounds(int* Shaddow_Bounds){
	//Must Be in the text bounds to show

}
/**
 * Set the shadow color for this object //TODO not implemented //TODO Refactor so the spelling is right!
 */
void Text::Set_Shaddow_Color(int* Color_RGBA){

}
/**
 * Render the text to the frame buffer //TODO revise implementation.
 */
uint32_t** Text::Refresh_Frame_Buffer(){
	/*
	unsigned char image[height][width];
	int tempX = x;
	int tempY = y;
	for(int count = 0; count < Rendered_Glyph_Array->size(); count++){
		FT_Bitmap* bitmap = ((FT_GlyphSlot)Rendered_Glyph_Array->at(count))->bitmap;
		 FT_Int  i, j, p, q;
		 FT_Int  x_max = tempX + bitmap->width;
		 FT_Int  y_max = tempY + bitmap->rows;


		  for ( i = tempX, p = 0; i < x_max; i++, p++ )
		  {
		    for ( j = tempY, q = 0; j < y_max; j++, q++ )
		    {
		      if ( i < 0 || j < 0 || i >= width || j >= height )
		        continue;

		      image[j][i] |= bitmap->buffer[q * bitmap->width + p];
		    }
		  }
		  tempX = tempX+ x_max;
	}
	*/

	return Frame_Buffer; //do nothing.
}
