#include "HandleInput.h"
#include "..\CommandHandlers\AddCommand.h"

/*
Filename:   HandleInput.cpp
Author:     valrym
Date:       16/8/18
*/
 
namespace fd::input {
	int ComputeInput(std::vector<std::string> input) {
		for (int i = 0; i < commands.size(); i++) {
			if (commands.at(i).name == input.at(0).c_str() || commands.at(i).alias == input.at(0).c_str()) {
				try {
					commands.at(i).function(input);
				}
				catch (...) {
					printf("\n[EXCEPTION]: Default Exception (can't handle params or wrong syntax.)");
				}
				return 1;
			}
			else {}
		}
	}
}
