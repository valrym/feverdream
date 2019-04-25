#include "AddCommand.h"
#include <chrono>
#include <thread>

namespace CommandFunctions {
	void Test(std::vector<std::string> vars) {
		printf("Hello, world!\n");
	};
	void cmds(std::vector<std::string> vars) {
		printf("\n| commands |\n");
		for (int i = 0; i < commands.size(); i++)
		{
			std::cout << commands.at(i).name + " | " + commands.at(i).description  << std::endl;
		}
		printf("| -------- |\n");
	};
}

void AddCommands() {
	commands.push_back( Command {
		"world", 
		CommandFunctions::Test, 
		"prints \"hello world!\" for testing purposes",
		"helloworld"
		} );
	commands.push_back( Command {
		"cmds", 
		CommandFunctions::cmds, 
		"displays lists of commands with descriptions",
		"commands"
		} );

}

std::vector<Command> commands;
