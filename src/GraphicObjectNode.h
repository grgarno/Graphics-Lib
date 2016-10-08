/*
 * GraphicObjectNode.h
 *
 *  Created on: 03.10.2016
 *      Author: grgarno
 */

#ifndef GRAPHICOBJECTNODE_H_
#define GRAPHICOBJECTNODE_H_
#include "GraphicObject.h"
class Graphic_Object_Node {
public:
	Graphic_Object_Node();
	~Graphic_Object_Node();

	Graphic_Object* Object;
	int Layer_ID;
	Graphic_Object_Node* next;
	Graphic_Object_Node* previous;

};

#endif /* GRAPHICOBJECTNODE_H_ */
