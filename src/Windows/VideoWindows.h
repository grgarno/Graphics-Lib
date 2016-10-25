/*
 * VideoWindows.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef WINDOWS_VIDEOWINDOWS_H_
#define WINDOWS_VIDEOWINDOWS_H_
#include "../Video.h"
class Video_Windows: public Video {
public:
	Video_Windows();
	~Video_Windows();
	uint32_t** Refresh_Frame_Buffer();
	void Play();
	void Pause();
	void Stop();
	long Get_Elapsed_Time_Milliseconds();
	void Set_Elapsed_Time_Milliseconds(long New_Time);
	std::string Get_Name();

};

#endif /* WINDOWS_VIDEOWINDOWS_H_ */
