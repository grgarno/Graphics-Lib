/*
 * GraphicObjectNode.cpp
 *
 *  Created on: 03.10.2016
 *      Author: grgarno
 */

#include "GraphicObjectNode.h"

Graphic_Object_Node::Graphic_Object_Node() {
	// No construction needed

}

Graphic_Object_Node::~Graphic_Object_Node() {
	delete[] Object; //deletes the object //TODO Should this be deleted here? what if the client wants to add the object to another output?
}

