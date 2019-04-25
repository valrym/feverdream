#pragma once
#include <windows.h>
#include <iostream>
#include <tchar.h> 
#include "CoreFunctions\ConsoleFunctions\ConsoleFuncs.h"
#include "CoreFunctions\InputHandle\HandleInput.h"

/*
Filename:   feverdream.h
Author:     valrym & bork gang
Date:       28/5/18
Purpose:    The start of feverdream.
Note:		I started this project on 23/2/18.
			Any date mentioned in this info header is the last time "Intialize" was updated.
			Anything else is finished the day that it's authored.
			-valrym
*/

namespace fd {

    inline void Load( ) {

		fd::console::Free_Console();
		fd::console::ConsoleInitialize();

		HANDLE HandleDefine;
		HandleDefine = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTitle("feverdream superior base");
		fd::console::color("$ ", 2, HandleDefine);
		fd::console::color("feverdream, a superior cheat base", 5, HandleDefine);
		fd::console::color(" $", 2, HandleDefine);
		fd::console::resetcolor(HandleDefine);
		fd::console::color( "\nloading feverdream, please be patient.", 5, HandleDefine); Sleep(1000); printf("."); Sleep(1000); printf(".");

		AddCommands();
		do { 
			printf("\n>");
			fd::input::ComputeInput(
				fd::console::Split(fd::console::Input())
			); 
		 } while (true);
	}

}