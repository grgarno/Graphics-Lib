/*
 * VideoLinux.h
 *
 *  Created on: 11.09.2016
 *      Author: grgarno
 */

#ifndef LINUX_VIDEOLINUX_H_
#define LINUX_VIDEOLINUX_H_
#include "../Video.h"
class Video_Linux: public Video {
public:
	Video_Linux();
	~Video_Linux();
	virtual uint32_t** Refresh_Frame_Buffer();
	virtual void Play();
	virtual void Pause();
	virtual void Stop();
	virtual long Get_Elapsed_Time_Milliseconds();
	virtual void Set_Elapsed_Time_Milliseconds(long New_Time);
	virtual std::string Get_Name();
};

#endif /* LINUX_VIDEOLINUX_H_ */
