/*
 * OutputFactory.cpp
 *
 *  Created on: 21.09.2016
 *      Author: grgarno
 */

#include "OutputFactory.h"

Output_Factory::Output_Factory() {
	// No initialization necessary

}

Output_Factory::~Output_Factory() {
	// No destruction needed at this level
}

Output* Output_Factory::Create_Output(std::string args) {
	double frame_rate = parse_arg(args, "frame_rate:");
	int width = parse_arg(args, "width:");
	int height = parse_arg(args, "height:");
	int x = parse_arg(args, "x:");
	int y = parse_arg(args, "y:");
	int card_number = parse_arg(args, "card_number:");
	std::string card_name = "";
	parse_arg(args, "card_name:", false, &card_name);


	if ((args.find("desktop")) != std::string::npos) {//use HTML Output
		return Create_Desktop_Output(frame_rate, width, height, x, y);
	} else if ((args.find("decklink")) != std::string::npos) {//use HTML Output
		return Create_Decklink_Output(frame_rate, width, height, card_number, card_name);
	} else if ((args.find("HTML")) != std::string::npos) {//use HTML Output
		HTMLOutput* output_return = new HTMLOutput();
		output_return->x = x;
		output_return->y = y;
		output_return->width = width;
		output_return->height = height;
		output_return->Frame_Rate = frame_rate;

		return output_return;
	} else {
		return nullptr;
	}
}

double Output_Factory::parse_arg(std::string arg, std::string param, bool is_double, std::string* return_string){ //is double to true when needing to return a double,
	std::string temp_string = "";
		std::size_t found;

		found = arg.find(param);
		if (found != std::string::npos) {
				temp_string = arg.substr(found, arg.length() - found);
				temp_string = temp_string.substr(temp_string.find_first_of(":") + 1, temp_string.find_first_of(",") - 1);
				if(return_string){
					return_string = &temp_string;
					return 0;
				}
				if(is_double){
					return std::stoi(temp_string);
				}else{
					return std::stod(temp_string);
				}
		}
		return 0; //default error handling
}


