/*
 * VideoMac.cpp
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#include "VideoMac.h"

Video_Mac::Video_Mac() {
	// TODO Auto-generated constructor stub

}

Video_Mac::~Video_Mac() {
	// TODO Auto-generated destructor stub
}
uint32_t** Video_Mac::Refresh_Frame_Buffer(){
	return Frame_Buffer;
}
std::string Video_Mac::Get_Name(){
	return "Mac Video";
}
void Video_Mac::Play(){

}

void Video_Mac::Pause(){

}
void Video_Mac::Stop(){

}
long Video_Mac::Get_Elapsed_Time_Milliseconds(){
	return 0.0;
}
void Video_Mac::Set_Elapsed_Time_Milliseconds(long New_Time){

}
