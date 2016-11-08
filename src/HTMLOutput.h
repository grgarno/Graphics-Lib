/*
 * HTMLOutput.h
 *
 *  Created on: 07.11.2016
 *      Author: grgarno
 */

#ifndef SRC_HTMLOUTPUT_H_
#define SRC_HTMLOUTPUT_H_
#ifndef _OUTPUT_INCLUDED // is it already included?
#define _OUTPUT_INCLUDED // define this so we know it's included
#include "Output.h"
#endif


class HTMLOutput: public Output {
private:
	void renderLoop();
	bool outputting = false;
public:
	int x;
	int y;//x, y
	std::string stream_port;
	HTMLOutput();
	~HTMLOutput();
	void Begin_Output();
	void Stop_Output();
	uint32_t** Get_Preview_Image();
	void refresh();
};

#endif /* SRC_HTMLOUTPUT_H_ */
