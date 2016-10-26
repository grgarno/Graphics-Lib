//============================================================================
// Name        : GraphicsObject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "GraphicObjectFactory.h"
#include "Windows/WindowsGraphicObjectFactory.h"
#include "Mac/MacGraphicObjectFactory.h"
#include "Linux/LinuxGraphicObjectFactory.h"
#include "OutputFactory.h"
#include "Windows/WindowsOutputFactory.h"
#include "Mac/MacOutputFactory.h"
#include "Linux/LinuxOutputFactory.h"
#include "Text.h"
#include "Video.h"
#include "Image.h"
#include "Solid.h"

using namespace std;
int os = 0;
/**
 * This file serves as a test file, and served as the platform for which the presentation in class was presented from.
 */
Graphic_Object_Factory* getFactory(int os) {
	switch (os) {
	case 0: //windows, defined in pre-processing
		return (new Windows_Graphic_Object_Factory());
		break;
	case 1: //mac, defined in pre-processing
		return (new Mac_Graphic_Object_Factory());
		break;
	case 2: //linux, defined in pre-processing
		return (new Linux_Graphic_Object_Factory());
		break;
	default: //OS not supported

		exit(1);
		break;
	}
}

Output_Factory* getOutputFactory(int os){
	switch (os) {
	case 0: //windows, defined in pre-processing
		return (new Windows_Output_Factory());
		break;
	case 1: //mac, defined in pre-processing
		return (new Mac_Output_Factory());
		break;
	case 2: //linux, defined in pre-processing
		return (new Linux_Output_Factory());
		break;
	default: //OS not supported

		exit(1);
		break;
	}
}
int main() {
	cout << "Enter a number for the operating system" << endl;
	int input;
	cin >> input;
	cin.ignore();
	Graphic_Object_Factory* Factory = getFactory(input);
	Output_Factory* OutputF = getOutputFactory(input);
	//create output
	Output* out = OutputF->Create_Desktop_Output(29.97, 1280, 720, 500,0);
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
	Text* Text_Object = Factory->Create_Text("Hello World", "/Library/Fonts/Microsoft/Century Gothic", 233);
	Text_Object->x = 500;
	Text_Object->y = 500;
	//TODO Add text object to output

	out->Add_Graphic_Object(Solid_Other, 30);
	out->Add_Graphic_Object(Solid_Third, 25);

	out->Add_Graphic_Object(Solid_Black, 20);

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

