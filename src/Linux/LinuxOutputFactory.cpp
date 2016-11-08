/*
 * LinuxOutputFactory.cpp
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#include "LinuxOutputFactory.h"

Linux_Output_Factory::Linux_Output_Factory() {
	// TODO Auto-generated constructor stub

}

Linux_Output_Factory::~Linux_Output_Factory() {
	// TODO Auto-generated destructor stub
}

Desktop_Output* Linux_Output_Factory::Create_Desktop_Output(double Frame_Rate, int width, int height, int x, int y){
	return new Desktop_Output_Linux();
}
Decklink_Output* Linux_Output_Factory::Create_Decklink_Output(double Frame_Rate, int width, int height, int Card_Number, std::string Card_Name){
	return new Decklink_Output_Linux();
}
Output* Linux_Output_Factory::Create_Output(std::string args){
	return nullptr;
}
