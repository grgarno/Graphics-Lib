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
	Output* out = OutputF->Create_Desktop_Output(29.97, 1280, 720, 1440,0);
	//start output
	out->Begin_Output();




	//new solid
	Solid* Solid_Black = Factory->Create_Solid();
	Solid_Black->Background_Color_R  = 255;
	Solid_Black->Background_Color_G = 255;
	Solid_Black->Background_Color_B = 0;
	Solid_Black->Background_Color_A  = 128;
	Solid_Black->x = 200;
	Solid_Black->y = 200;
	Solid_Black->width = 200;
	Solid_Black->height = 200;
	//new solid
	Solid* Solid_Other = Factory->Create_Solid();
	Solid_Other->Background_Color_R  = 255;
	Solid_Other->Background_Color_G = 0;
	Solid_Other->Background_Color_B = 0;
	Solid_Other->Background_Color_A  = 128;
	Solid_Other->x = 50;
	Solid_Other->y = 50;
	Solid_Other->width = 200;
	Solid_Other->height = 200;
	//loop through presentation slides. They are images stored at the following filepath.
	for(int count = 1; count <=10; count++){
		Image* Image_New = Factory->Create_Image();
		Image_New->Source_File = "/Users/grgarno/Desktop/Dropbox/CSCI 426/assignment2gfx/images/Assignment2.pptxSlide" + std::to_string(count) + ".jpg";
		out->Add_Graphic_Object(Image_New, count);
		system("read");
		//out->Remove_Graphic_Object(Image_New);

	}


	out->Stop_Output();

	return 0;
}

