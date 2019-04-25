#pragma once
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <functional>

/*
Filename:   AddCommand.h
Author:     valrym
Date:       28/5/18
*/

class Command {
		public:
			std::string name;
			std::function<void(std::vector<std::string>)> function;
			std::string description;
			std::string alias;
};

extern std::vector<Command> commands;

void AddCommands();