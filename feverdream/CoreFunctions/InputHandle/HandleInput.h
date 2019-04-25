#pragma once
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include "..\CommandHandlers\AddCommand.h"
/*
Filename:   HandleInput.h
Author:     valrym
Date:       28/5/18
*/

namespace fd::input {
	int ComputeInput(std::vector<std::string> args);
	}
