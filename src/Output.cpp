/*
 * Output.cpp
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#include "Output.h"
/**
 * Implementation of non-abstract elements of an output
 */
Output::Output() {
	//set defaults
	Frame_Rate = 29.97;
	width = 1920;
	height = 1080;
	opacity = 1.0;
	pixels = nullptr;

}

Output::~Output() {
	delete pixels;
}

/**
 * Adds a graphic object to this output. Uses a linked list.
 */
void Output::Add_Graphic_Object(Graphic_Object* Object_To_Render, int LayerID) {
	Graphic_Object_Node* new_object = new Graphic_Object_Node;
	new_object->Object = Object_To_Render;
	new_object->Layer_ID = LayerID;
	if (!head) {

		head = new_object;

		head->next = nullptr;
		head->previous = nullptr;

	} else if (head->Layer_ID > LayerID) { //define new head
		new_object->next = head;
		new_object->previous = nullptr;
		head->previous = new_object;
		head = new_object;

	} else {
		Graphic_Object_Node* current_node = head;
		Graphic_Object_Node* last_node = nullptr;

		while (current_node->Layer_ID <= LayerID) { //find the place in the lili to insert the object, either at the end, or where the layer ID is larger
			last_node = current_node;

			current_node = current_node->next;
			if (current_node == nullptr) {
				break;
			}

		}

		last_node->next = new_object;
		new_object->previous = last_node;
		new_object->next = current_node;
		if (current_node != nullptr) {
			current_node->previous = new_object;
		}

	}

}

/**
 * Removes a graphic object from this output.
 */
void Output::Remove_Graphic_Object(Graphic_Object* Object_To_Remove,
		bool Dispose_Object) {
	Graphic_Object_Node* current_node = head;
	Graphic_Object_Node* previous_node = nullptr;

	while (true) {
		if (current_node->Object == Object_To_Remove) {
			if (previous_node == nullptr) { //delete head
				head = current_node->next;
			} else {
				previous_node->next = current_node->next;
				if (current_node->next != nullptr) {
					current_node->next->previous = previous_node;
				}

			}
			if (Dispose_Object) {
				delete current_node->Object; //prevent memory leak
			}

			delete current_node;
			break;
		}

		previous_node = current_node;

		current_node = current_node->next;

		if (current_node == nullptr) {
			break;
		}
	}

}

/**
 * Loop through linked list of graphic objects, determine the entire composite
 */
void Output::Compose_Pixels() {

	if (head && pixels) {

		Graphic_Object_Node* current_node = head;

		Graphic_Object* object;

		uint8_t alpha_over;
		uint8_t red_over;
		uint8_t green_over;
		uint8_t blue_over;
		uint8_t alpha_under;
		uint8_t red_under;
		uint8_t green_under;
		uint8_t blue_under;
		double alpha_norm = 0.0;

		uint32_t red_out;
		uint32_t green_out;
		uint32_t blue_out;
		uint32_t alpha_out;

		//td::fill_n(*pixels, (width*height*4), 0);

		for (int resety = 0; resety < height; resety++) {
			for (int resetx = 0; resetx < width; resetx++) {

				pixels[resety][resetx] = 0x00000000;

			}
		}
		while (current_node) { //write composition
			object = current_node->Object;
			if (object->valid == false) {
				object->Refresh_Frame_Buffer();
			}
			for (int objy = object->y; objy < (object->height + object->y);
					objy++) {
				for (int objx = object->x; objx < (object->width + object->x);
						objx++) {

					/**
					 * Taken from: http://www.codeguru.com/cpp/cpp/algorithms/general/article.php/c15989/Tip-An-Optimized-Formula-for-Alpha-Blending-Pixels.htm
					 * Optomized Alpha formula: out = ((source * alpha) + (destination * (255 - alpha)))>>8. (Alpha is destination alpha)
					 *
					 * Alpha out = alpha dest + alpha source

					 */

					if (objy >= height || objx >= width) {
						continue;
					}
					red_under = (pixels[objy][objx] & 0x000000ff);
					green_under = (pixels[objy][objx] & 0x0000ff00) >> 8;
					blue_under = (pixels[objy][objx] & 0x00ff0000) >> 16;
					alpha_under = (pixels[objy][objx] & 0xff000000) >> 24;
					red_over = (object->Frame_Buffer[objy - object->y][objx
							- object->x] & 0x000000ff);
					green_over = (object->Frame_Buffer[objy - object->y][objx
							- object->x] & 0x0000ff00) >> 8;
					blue_over = (object->Frame_Buffer[objy - object->y][objx
							- object->x] & 0x00ff0000) >> 16;
					alpha_over = ((object->Frame_Buffer[objy - object->y][objx
							- object->x] & 0xff000000) >> 24) * object->Opacity; //calculate source opacity here


					alpha_norm = ((double) alpha_over / 255.0);
					if(alpha_over + alpha_under > 255){//stuff happens here

					}else{

					}

					red_out = red_over * alpha_norm
							+ red_under * (1.0 - alpha_norm); //
					green_out = green_over * alpha_norm
							+ green_under * (1.0 - alpha_norm); //
					blue_out = blue_over * alpha_norm
							+ blue_under * (1.0 - alpha_norm); //
					alpha_out = alpha_over + alpha_under; //TODO I should not be forty!
					pixels[objy][objx] = (alpha_out << 24) + (red_out << 16)
							+ (green_out << 8) + blue_out;


				}

			}

			current_node = current_node->next;
		}
	}
}

