/*
 * VideoLinux.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "VideoLinux.h"

Video_Linux::Video_Linux() {
	// TODO Auto-generated constructor stub

}

Video_Linux::~Video_Linux() {
	// TODO Auto-generated destructor stub
}
uint32_t** Video_Linux::Refresh_Frame_Buffer(){
	return Frame_Buffer;
}

std::string Video_Linux::Get_Name(){
	return "Linux Video";
}

void Video_Linux::Play(){

}

void Video_Linux::Pause(){

}
void Video_Linux::Stop(){

}
long Video_Linux::Get_Elapsed_Time_Milliseconds(){
	return 0.0;
}
void Video_Linux::Set_Elapsed_Time_Milliseconds(long New_Time){

}
