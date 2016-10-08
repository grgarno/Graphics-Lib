/*
 * MacOutputFactory.cpp
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#include "MacOutputFactory.h"


Mac_Output_Factory::Mac_Output_Factory() {
	// TODO Auto-generated constructor stub

}

Mac_Output_Factory::~Mac_Output_Factory() {
	// TODO Auto-generated destructor stub
}

Desktop_Output* Mac_Output_Factory::Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y){

	Desktop_Output* ret = (Desktop_Output*) new Desktop_Output_Mac();
	ret->Frame_Rate = Frame_Rate;
	ret->x = x;
	ret->y = y;
	ret->width = width;
	ret->height = height;



	return ret;
}

Decklink_Output* Mac_Output_Factory::Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name){
	return new Decklink_Output_Mac();
}

Output* Mac_Output_Factory::Create_Output(std::string args){
	return nullptr;
}
