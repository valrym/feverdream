#include "Lua C.h"

int lua_state;

int GlobalState(DWORD* Instance, int Index)
{
	return Instance[14 * Index + 41] - (DWORD)&Instance[14 * Index + 41];
	//THIS CAN BREAK, How2Update: Search "Unable to create a new thread for", xref, psuedocode and locate something that looks like v52 = v39[14 * v51 + 41] - (_DWORD)&v39[14 * v51 + 41];
}

getfieldFn getfield_scan = (getfieldFn)ida_grab(0x779CC0); //Signature breaks often, search up _LOADED and xref, 2 sub_ below should be it
getfieldFn getfield_ret = (getfieldFn)Ret((DWORD)getfield_scan);
void getfield(int IDX, const char* K)
{
	return getfield_ret(lua_state, IDX, K);
}
void getglobal(const char* K)
{
	return getfield(-10002, K); //LUA_GLOBALSINDEX == -10002
}

callFn call_scan = (callFn)ida_grab(0x7796D0); //Signature is 55 8B EC 8B 4D 0C 57 8B 7D 08 FF 75 10 (as of 2018-10-29)
callFn call_ret = (callFn)Ret((DWORD)call_scan);
int call(int ARGS, int RESULTS)
{
	return call_ret(lua_state, ARGS, RESULTS);
}

newthreadFn newthread_scan = (newthreadFn)ida_grab(0x77A770); //Signature is 55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 64 89 25 ?? ?? ?? ?? 51 56 8B 75 08 8D 46 0C (as of 2018-10-29)
newthreadFn newthread_ret = (newthreadFn)Ret((DWORD)newthread_scan);
int newthread(int LUASTATE)
{
	return newthread_ret(LUASTATE);
}
