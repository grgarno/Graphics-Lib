/*
 * Output.h
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "GraphicObject.h"
#include "GraphicObjectNode.h"
/**
 * Class representing an abstract output
 */
class Output {


protected:

	Graphic_Object_Node* head;
	uint32_t ** pixels;
public:
	int width;
	int height;
	double Frame_Rate;
	double opacity;
	Output();
	virtual ~Output();
	/**
	 * Adds an item to the output
	 */
	void Add_Graphic_Object(Graphic_Object* Object_To_Render, int LayerID);
	/**
	 * Removes an item from the output.
	 */
	void Remove_Graphic_Object(Graphic_Object* Object_To_Remmove, bool Dispose_Object);
	/**
	 * Compose the pixels from all the graphic objects added
	 */
	void Compose_Pixels();

	virtual void Begin_Output() = 0;
	virtual void Stop_Output() = 0;
	/**
	 * Returns a COPY of the memory on this output, used for previews or some transitions.
	 * //TODO Change the name to something that makes more sense.
	 */
	virtual uint32_t** Get_Preview_Image() = 0;
};

#endif /* OUTPUT_H_ */
