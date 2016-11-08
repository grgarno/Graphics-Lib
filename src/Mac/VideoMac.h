/*
 * VideoMac.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef MAC_VIDEOMAC_H_
#define MAC_VIDEOMAC_H_
#include "../Video.h"
class Video_Mac: public Video {
public:
	Video_Mac();
	~Video_Mac();
	uint32_t** Refresh_Frame_Buffer();
	void Play();
	void Pause();
	void Stop();
	long Get_Elapsed_Time_Milliseconds();
	void Set_Elapsed_Time_Milliseconds(long New_Time);
	std::string Get_Name();
};

#endif /* MAC_VIDEOMAC_H_ */
