//============================================================================
// Name        : GraphicsObject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/**
#include <iostream>
#include "GraphicObjectFactory.h"

#include "Mac/MacGraphicObjectFactory.h"

#include "OutputFactory.h"

#include "Mac/MacOutputFactory.h"

#include "Text.h"
#include "Video.h"
#include "Image.h"
#include "Solid.h"

using namespace std;
int os = 0;
/**
 * This file serves as a test file, and served as the platform for which the presentation in class was presented from.
 *//**
Graphic_Object_Factory* getFactory(int os) {

		return (new Mac_Graphic_Object_Factory());

}

Output_Factory* getOutputFactory(int os){

		return (new Mac_Output_Factory());

}

int main() {

	Graphic_Object_Factory* Factory = getFactory(0);
	Output_Factory* OutputF = getOutputFactory(0);
	//create output
	Output* out = OutputF->Create_Desktop_Output(29.97, 1280, 720, 100,0);
	//start output
	out->Begin_Output();




	//new solid
	Solid* Solid_Black = Factory->Create_Solid();
	Solid_Black->Background_Color_R  = 255;
	Solid_Black->Background_Color_G = 255;
	Solid_Black->Background_Color_B = 255;
	Solid_Black->Background_Color_A  = 128;
	Solid_Black->x = 200;
	Solid_Black->y = 200;
	Solid_Black->width = 200;
	Solid_Black->height = 200;
	//new solid
	Solid* Solid_Other = Factory->Create_Solid();
	Solid_Other->Background_Color_R  = 255;
	Solid_Other->Background_Color_G = 255;
	Solid_Other->Background_Color_B = 255;
	Solid_Other->Background_Color_A  = 128;
	Solid_Other->x = 50;
	Solid_Other->y = 50;
	Solid_Other->width = 200;
	Solid_Other->height = 200;
	//new solid
	Solid* Solid_Third = Factory->Create_Solid();
	Solid_Third->Background_Color_R  = 255;
	Solid_Third->Background_Color_G = 255;
	Solid_Third->Background_Color_B = 255;
	Solid_Third->Background_Color_A  = 128;
	Solid_Third->x = 200;
	Solid_Third->y = 100;
	Solid_Third->width = 200;
	Solid_Third->height = 200;


	//new text object
	Text* Text_Object = Factory->Create_Text("The quick brown fox jumps over the lazy dog.\n1234567890\nThe brown fox is quick and jumps alot.", "/Library/Fonts/Microsoft/Century Gothic", 53);
	Text_Object->x = 50;
	Text_Object->y = 50;
	Text_Object->Text_Color_A = 255;
	Text_Object->Text_Color_B = 0;
	Text_Object->Text_Color_G = 255;
	Text_Object->Text_Color_R = 255;
	Text_Object->align = Text::Horizontal_Align::right;

	//TODO Add text object to output


	out->Add_Graphic_Object(Solid_Other, 30);
	out->Add_Graphic_Object(Solid_Third, 25);

	out->Add_Graphic_Object(Solid_Black, 20);
	out->Add_Graphic_Object(Text_Object, 50);
	std::string line_input = "";
	std::string input = "";
	while(line_input.compare("`") != 0){
		std::getline(cin, line_input);
		input = input + line_input;
		if(line_input.compare("=") == 0){
			Text_Object->Set_Text_Content(input + '\n');
			input = "";
		}
	}
	//loop through presentation slides. They are images stored at the following filepath.
	for(int count = 1; count <=2; count++){
		Image* Image_New = Factory->Create_Image();
		Image_New->Source_File = "/Users/grgarno/Desktop/Dropbox/CSCI 426/assignment2gfx/images/Assignment2.pptxSlide" + std::to_string(count) + ".jpg";
		Image_New->Opacity = 0.5;
		out->Add_Graphic_Object(Image_New, 1);
		system("read");
		out->Remove_Graphic_Object(Image_New, true);

	}


	out->Stop_Output();

	return 0;
}
*/
