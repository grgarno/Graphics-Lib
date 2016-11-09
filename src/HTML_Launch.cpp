/*
 * HTML_Launch.cpp
 *
 *  Created on: 07.11.2016
 *      Author: grgarno
 */

#ifndef _IOSTREAM_INCLUDED // is it already included?
#define _IOSTREAM_INCLUDED // define this so we know it's included
#include <iostream>
#endif

#ifdef _WIN32 //include if on windows.
#ifndef _WINDOWSGRAPHICOBJECTFACTORY_INCLUDED // is it already included?
#define _WINDOWSGRAPHICOBJECTFACTORY_INCLUDED // define this so we know it's included
#include "Windows/WindowsGraphicObjectFactory.h"
#endif

#ifndef _WINDOWSOUTPUTFACTORY_INCLUDED // is it already included?
#define _WINDOWSOUTPUTFACTORY_INCLUDED // define this so we know it's included
#include "Windows/WindowsOutputFactory.h"
#endif
#endif

#ifdef __MACH__ //include if on mac
#ifndef _MACGRAPHICOBJECTFACTORY_INCLUDED // is it already included?
#define _MACGRAPHICOBJECTFACTORY_INCLUDED // define this so we know it's included
#include "Mac/MacGraphicObjectFactory.h"
#endif

#ifndef _MACOUTPUTFACTORY_INCLUDED // is it already included?
#define _MACOUTPUTFACTORY_INCLUDED // define this so we know it's included
#include "Mac/MacOutputFactory.h"
#endif
#endif


#ifdef __linux__//include if on linux
#ifndef _LINUXGRAPHICOBJECTFACTORY_INCLUDED // is it already included?
#define _LINUXGRAPHICOBJECTFACTORY_INCLUDED // define this so we know it's included
#include "Linux/LinuxGraphicObjectFactory.h"
#endif

#ifndef _LINUXOUTPUTFACTORY_INCLUDED // is it already included?
#define _LINUXOUTPUTFACTORY_INCLUDED // define this so we know it's included
#include "Linux/LinuxOutputFactory.h"
#endif
#endif





#ifndef _OUTPUTFACTORY_INCLUDED // is it already included?
#define _OUTPUTFACTORY_INCLUDED // define this so we know it's included
#include "OutputFactory.h"
#endif

#ifndef _GRAPHICOBJECTFACTORY_INCLUDED // is it already included?
#define _GRAPHICOBJECTFACTORY_INCLUDED // define this so we know it's included
#include "GraphicObjectFactory.h"
#endif

#ifndef _GRAPHICOBJECTFACTORY_INCLUDED // is it already included?
#define _GRAPHICOBJECTFACTORY_INCLUDED // define this so we know it's included
#include "GraphicObjectFactory.h"
#endif



#ifndef _TEXT_INCLUDED // is it already included?
#define _TEXT_INCLUDED // define this so we know it's included
#include "Text.h"
#endif
#ifndef _VIDEO_INCLUDED // is it already included?
#define _VIDEO_INCLUDED // define this so we know it's included
#include "Video.h"
#endif
#ifndef _IMAGE_INCLUDED // is it already included?
#define _IMAGE_INCLUDED // define this so we know it's included
#include "Image.h"
#endif
#ifndef _SOLID_INCLUDED // is it already included?
#define _SOLID_INCLUDED // define this so we know it's included
#include "Solid.h"
#endif





using namespace std;

/**
 * This file serves as a test file, and served as the platform for which the presentation in class was presented from.
 */
Graphic_Object_Factory* getFactory() {
#ifdef _WIN32
   return (new Windows_Graphic_Object_Factory());
#endif

#ifdef __MACH__
		return (new Mac_Graphic_Object_Factory());
#endif


#ifdef __linux__
		return (new Linux_Graphic_Object_Factory());
#endif

		//cannot compile on other platforms.

}

Output_Factory* getOutputFactory(){
#ifdef _WIN32
   return (new Windows_Output_Factory());
#endif

#ifdef __MACH__
   return (new Mac_Output_Factory());
#endif


#ifdef __linux__
		return (new Linux_Output_Factory());
#endif



}

int main() {

	Graphic_Object_Factory* Factory = getFactory();
	Output_Factory* OutputF = getOutputFactory();
	//create output
	Output* out = OutputF->Create_Output("HTML, width:720, height:480, frame_rate:29.97");
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

