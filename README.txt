   ___                                __                                      
 /'___\                              /\ \                                     
/\ \__/   __   __  __     __   _ __  \_\ \  _ __    __     __      ___ ___    
\ \ ,__\/'__`\/\ \/\ \  /'__`\/\`'__\/'_` \/\`'__\/'__`\ /'__`\  /' __` __`\  
 \ \ \_/\  __/\ \ \_/ |/\  __/\ \ \//\ \L\ \ \ \//\  __//\ \L\.\_/\ \/\ \/\ \ 
  \ \_\\ \____\\ \___/ \ \____\\ \_\\ \___,_\ \_\\ \____\ \__/.\_\ \_\ \_\ \_\
   \/_/ \/____/ \/__/   \/____/ \/_/ \/__,_ /\/_/ \/____/\/__/\/_/\/_/\/_/\/_/
    
    		Welcome to feverdream, a superior ROBLOX cheat base.
Feverdream has been in development since February 2nd, 2018, by Bork Gang and affiliates.

This README.txt underlines how to correctly add commands and what to do afterwords.
You currently have to add your own memory functions (ex. sigscanning and memchangers.)

[How to add commands]
* First, you go to "AddCommand.h" in Feverdream>CoreFunctions>CommandHandlers.
* You add the function for commands inside of the namespace "CommandFunctions" as follows:

namespace CommandFunctions {
	void Test(std::vector<std::string> vars) {
		printf("Hello, world!\n");
	};
};

* (NOTE: since the variable string is a vector of words input into the console, it supports multi-argument commands natively.)
* (		 you can do this by accessing vars.at(1).c_str() or above 1 to access the second word or above input.				 )

* You then can add the function into the function "AddCommands" by inserting the command into the commands vector by doing the following:

void AddCommands() {
	commands.push_back( Command {
		"world", 
		CommandFunctions::Test, 
		"prints \"hello world!\" for testing purposes",
		"helloworld"
		} );
}

* The command class works as follows: 

class Command {
		public:
			std::string name;
			std::function<void(std::vector<std::string>)> function;
			std::string description;
			std::string alias;
};

* Name, obviously is the name, and function is fairly simple to understand too.
* Description is used inside the native "cmds" command in order to explain what the purpose of the function is.
* Alias is a second name, namely for commands needing shortened names or longer names.

* Adding commands is easy to do, and as long as you have your own CLua base headders, you can add it to Feverdream>Memory
* and include it inside of "AddCommand.h" and get to work.

* Good luck with this framework, fuck pay to cheats. Shits lame.

* zach#5099 | https://discord.gg/PXSDEKf | github.com/valrym