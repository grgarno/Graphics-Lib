/*
 * Output.cpp
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#include "Output.h"

Output::Output() {
	//set defaults
	Frame_Rate = 29.97;
	width = 1920;
	height = 1080;
	opacity = 1.0;

}

Output::~Output() {
	// TODO Auto-generated destructor stub
}

void Output::Add_Graphic_Object(Graphic_Object* Object_To_Render, int LayerID) {

	if (!head) {

		head = new Graphic_Object_Node;

		head->next = nullptr;

		head->Object = Object_To_Render;
		head->Layer_ID = LayerID;

	} else if (head->Layer_ID > LayerID) { //define new head

		head->previous = new Graphic_Object_Node;
		head->next = head;
		head->previous->previous = nullptr;
		head = head->previous;
		head->Object = Object_To_Render;
		head->Layer_ID = LayerID;
	} else {
		Graphic_Object_Node* current_node = head;
		Graphic_Object_Node* new_object = new Graphic_Object_Node;
		new_object->Object = Object_To_Render;
		new_object->Layer_ID = LayerID;
		Graphic_Object_Node* next_node = nullptr;
		while (current_node->next != nullptr) { //find the place in the lili to insert the object, either at the end, or where the layer ID is larger


			if(LayerID > current_node->Layer_ID) {
				break;
			}
			current_node = current_node->next;

		}
		if(current_node->next != nullptr){
			next_node = current_node->next->next;
		}

		//insert to the list
		//new_object->previous = current_node;
		current_node->next = new_object;
		new_object->next = next_node;
//		if (next_node != nullptr) {
//			next_node->previous = new_object;
//		}

	}

	//set the properties

}

void Output::Remove_Graphic_Object(Graphic_Object* Object_To_Remove) {
	Graphic_Object_Node* current_node = head;
	Graphic_Object_Node* previous_node;
	Graphic_Object_Node* next_node;
	while (current_node->Object != Object_To_Remove) {
		if (current_node->next == nullptr) {
			break;
		} else {
			previous_node = current_node;
			current_node = current_node->next;
		}
	}
	if (current_node->next) {
		previous_node->next = current_node->next;
	}
	//next_node = current_node->next;
	/*
	 if (previous_node && next_node) {
	 previous_node->next = next_node;
	 next_node->previous = previous_node;
	 } else if (previous_node) {
	 previous_node->next = nullptr;
	 } else if(next_node != nullptr) {
	 next_node->previous = nullptr;
	 }
	 */
	//delete (current_node); //TODO! Where does a graphic object get deleted!!
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
		uint8_t denom;

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
					 * Alpha formula: output_color = ((color_over * alpha_over) + (color_under * alpha_under * (1 - alpha_over)))/ (alpha_over + (alpha_under * (1 - alpha over)))

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

					denom = (alpha_over + (alpha_under * (1 - alpha_over)));
					if (denom == 0) {
						pixels[objy][objx] = (0 << 24) + (0 << 16) + (0 << 8)
								+ 0;
					} else {

//						pixels[objy][objx] = ((int) ((alpha_over + alpha_under)
//								* opacity) << 24)
//								+ ((((red_over * alpha_over)
//										+ (red_under * alpha_under
//												* (1 - alpha_over))) / denom)
//										<< 16)
//								+ ((((green_over * alpha_over)
//										+ (green_under * alpha_under
//												* (1 - alpha_over))) / denom)
//										<< 8)
//								+ ((((blue_over * alpha_over)
//										+ (blue_under * alpha_under
//												* (1 - alpha_over))) / denom)); //composit red
						pixels[objy][objx] = (255 << 24) + (red_over << 16) + (green_over <<8) + blue_over;



					}

					// std::cout<<pixels[count]<<std::endl;

					//					if(count_pixels > max_pixels){
					//						break;
					//					}

				}

			}

			current_node = current_node->next;
		}
	}
}

