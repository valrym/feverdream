#include "Retcheck.h"

#define ida_grab(address) (address - 0x400000 + (DWORD)GetModuleHandle(NULL)) //We could indeed put this somewhere else but... /shrug

extern int lua_state;

int GlobalState(DWORD* Instance, int Index);

typedef void(__stdcall* getfieldFn)(int, int, const char*);
void getglobal(const char* K);
void getfield(int IDX, const char* K);

typedef int(__cdecl* callFn)(int, int, int); //Who uses pcall anyways? Lol...
int call(int ARGS, int RESULTS);

typedef int(__cdecl* newthreadFn)(int);
int newthread(int LUASTATE);