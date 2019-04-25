#include "ConsoleFuncs.h"
/*
    Filename:   fdConsoleExec.cpp
    Author:     valrym
    Date:       23/2/18
    Purpose:    Define functions for "fdConsoleExec.h"
*/

#define exception() printf("Error: Console exception. Handled.");

namespace fd::console {

    std::string Input(){
        std::string ret;	
	    std::getline(std::cin, ret);
	    return ret;
    }

    std::vector<std::string> Split(std::string sem){
        std::vector<std::string> elems;
	    std::stringstream strsem(sem);
	    std::istream_iterator<std::string> begin(strsem);
	    std::istream_iterator<std::string> end;
	    std::vector<std::string> splitstring(begin, end);
	    return splitstring;
    }

    void Free_Console(){
        int *ad = (int*)GetProcAddress(GetModuleHandle("kernel32.dll"), "FreeConsole");
	    DWORD adw;
	    VirtualProtect(ad, 1, PAGE_EXECUTE_READWRITE, &adw);
	    *ad = 0xC3;
	    VirtualProtect(ad, 1, adw, &adw);
    }
    
    void ConsoleInitialize(){
        AllocConsole();
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
    }

	void color(const char * text, int clr, HANDLE hC) {
		SetConsoleTextAttribute(hC, clr);
		printf(text);
	}

	void resetcolor(HANDLE hC) {
		SetConsoleTextAttribute(hC, 15);
	}
}
