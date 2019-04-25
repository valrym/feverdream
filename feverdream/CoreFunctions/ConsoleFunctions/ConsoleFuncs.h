#define _CRT_SECURE_NO_WARNINGS
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

/*
    Filename:   fdConsoleExec.h
    Author:     valrym
    Date:       23/2/18
    Purpose:    Define namespace for "fdConsoleExec.cpp"
*/


namespace fd::console {
    std::string Input();
    std::vector<std::string> Split(std::string sem);
    void Free_Console();
    void ConsoleInitialize();
	void color(const char * text, int clr, HANDLE hC);
	void resetcolor(HANDLE hC);
}