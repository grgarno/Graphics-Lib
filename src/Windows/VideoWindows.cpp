/*
 * VideoWindows.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "VideoWindows.h"

Video_Windows::Video_Windows() {
	// TODO Auto-generated constructor stub

}

Video_Windows::~Video_Windows() {
	// TODO Auto-generated destructor stub
}

uint32_t** Video_Windows::Refresh_Frame_Buffer(){
	return Video_Windows::Frame_Buffer;
}

std::string Video_Windows::Get_Name(){
	return "Windows Video";
}

void Video_Windows::Play(){

}

void Video_Windows::Pause(){

}
void Video_Windows::Stop(){

}
long Video_Windows::Get_Elapsed_Time_Milliseconds(){
	return 0.0;
}
void Video_Windows::Set_Elapsed_Time_Milliseconds(long New_Time){

}
