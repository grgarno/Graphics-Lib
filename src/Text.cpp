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
	Text_Color_R = 0;
	Text_Color_G = 0;
	Text_Color_B = 0;
	Text_Color_A = 255;
	align = left;

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
	} else if (error) {
		std::cout << "There was an error creating the font" << std::endl;
		return nullptr;
	}
	return &face;

}
/**
 * Set the text of this object.
 */
void Text::Set_Text_Content(std::string Text) {
	this->Text_Content = Text;
	valid = false;

}
/**
 * Set the font size of this text
 */
void Text::Set_Font_Size(int Pixel_Height) {
	this->Font_Size = Pixel_Height;
	error = FT_Set_Char_Size(face, 0, (Pixel_Height * 64), 72, 72);
	this->Return_Height = Pixel_Height;
}
/**
 * Set the font color for this object.
 */
void Text::Set_Font_Color(int* Color_RGBA) {
	this->Text_Color_RGBA = Color_RGBA;
}
/**
 * Set the outline size for this object. //TODO not implemented
 */
void Text::Set_Outline_Size(int Pixel_Outline) {

}
/**
 * Set the outline color for this text object //TODO not implemented
 */
void Text::Set_Outline_Color(int* Color_RGBA) {

}
/**
 * Set the shadow size for this text object //TODO not implemented //TODO Refactor so the spelling is right!
 */
void Text::Set_Shaddow_Size(int Pixel_Height) {

}
/**
 * Set the shadow bounds for this object //TODO not implemented //TODO Refactor so the spelling is right!
 */
void Text::Set_Shaddow_Bounds(int* Shaddow_Bounds) {
	//Must Be in the text bounds to show

}
/**
 * Set the shadow color for this object //TODO not implemented //TODO Refactor so the spelling is right!
 */
void Text::Set_Shaddow_Color(int* Color_RGBA) {

}
/**
 * Render the text to the frame buffer //TODO clean p sparkles
 */
uint32_t** Text::Refresh_Frame_Buffer() {
	valid = false;
	if (Frame_Buffer != nullptr) {	//get rid of old frame buffer
		for (int i = 0; i < height; ++i) {
			delete Frame_Buffer[i];
		}
		delete Frame_Buffer;
	}

	if (Text_Content.empty()) {

		width = 2;
		height = 2;
		Frame_Buffer = new uint32_t*[height];
		for (int i = 0; i < height; ++i) {
			Frame_Buffer[i] = new uint32_t[width];
			for (int j = 0; j < width; ++j) {
				Frame_Buffer[i][j] = 0;
			}
		}
		valid = true;
		return Frame_Buffer;
	}

	int Glyph_Index;

	std::vector<int>* widths = new std::vector<int>(0);
	int temp_width = 0;
	int biggest_width = 0;

	for (int count = 0; count < Text_Content.size(); count++) {

		Glyph_Index = FT_Get_Char_Index(face, Text_Content.at(count));

		error = FT_Load_Glyph(face, Glyph_Index, FT_LOAD_DEFAULT);
		//TODO error handling!
		if (error) {
			std::cout << "There was an error creating the glyph" << std::endl;
		}
		error = false;
		error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
		if (error) {
			std::cout << "There was an error rendering the glyph" << std::endl;
		}
		temp_width = temp_width + face->glyph->metrics.horiAdvance / 64;
		if (temp_width > biggest_width) {
			biggest_width = temp_width;

		}

		if (count == (Text_Content.size() - 1)
				|| Text_Content.at(count) == '\n') {
			height = height + Return_Height;
			widths->push_back(temp_width);

			temp_width = 0;
		}

	}
	width = biggest_width;
	//always add an extra line of space at the end to render hanging characters...
	height = height + Return_Height;
	//std::cout << "X " << width << "    Y " << height << std::endl;

	Frame_Buffer = new uint32_t*[height];
	for (int i = 0; i < height; ++i) {
		Frame_Buffer[i] = new uint32_t[width];
		for (int j = 0; j < width; ++j) {
			Frame_Buffer[i][j] = 0;
		}
	}

	uint32_t color = (Text_Color_A << 24) + (Text_Color_R << 16)
			+ (Text_Color_G << 8) + Text_Color_B;
	int tempX = biggest_width - widths->at(0);
	int tempY = 0;
	int line_count = 0;

	for (int count = 0; count < Text_Content.size(); count++) {
		Glyph_Index = FT_Get_Char_Index(face, Text_Content.at(count));

		error = FT_Load_Glyph(face, Glyph_Index, FT_LOAD_DEFAULT);

		if (error) {
			std::cout << "There was an error creating the glyph" << std::endl;
		}
		error = false;
		error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
		if (error) {
			std::cout << "There was an error rendering the glyph" << std::endl;
		}
		FT_Bitmap* bitmap = &(face->glyph)->bitmap;

		//tempX = tempX + *(&(face->glyph)->metrics.horiBearingX);
		//tempY = tempY + (*(&(face->glyph)->metrics.height) - *(&(face->glyph)->metrics.horiBearingY));
		int max_x = tempX + bitmap->width;

		int y_offset = (Return_Height - face->glyph->metrics.horiBearingY / 64);
		int max_y = tempY + Return_Height;

		if (Text_Content.at(count) != '\n') {

			for (int county = tempY + y_offset;
					county
							< tempY + y_offset
									+ (face->glyph->metrics.height / 64);
					county++) {
				for (int countx = tempX; countx < max_x; countx++) {

					color = ((int) ((double) ((bitmap->buffer[(county
							- (tempY + y_offset)) * bitmap->pitch
							+ (countx - tempX)])) * Opacity) << 24)
							+ (Text_Color_R << 16) + (Text_Color_G << 8)
							+ Text_Color_B;
					Frame_Buffer[county][countx] = color;//TODO make the letters right!
				}
			}
		}

		tempX = tempX + (face->glyph->metrics.horiAdvance) / 64;
		if (Text_Content.at(count) == '\n') {
			tempY = max_y;
			std::cout << count << std::endl;
			line_count++;
			if (line_count < widths->size()) {
				switch (align) {
				case left:
					tempX = 0;
					break;
				case center:
					tempX = (biggest_width / 2) - (widths->at(line_count) / 2);
					break;
				case right:
					tempX = biggest_width - widths->at(line_count);
					break;
				case justify:
					tempX = 0; //TODO: Fix Justify
					break;
				default:
					tempX = 0;
					break;
				}

			} else {
				tempX = 0;
			}
		}

	}
	valid = true;

	return Frame_Buffer; //do nothing.

}
