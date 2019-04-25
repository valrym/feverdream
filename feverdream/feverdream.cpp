#include "MicrosoftGenerated\stdafx.h"
#include "feverdream.h"

BOOL __stdcall DllMain(HINSTANCE, DWORD Reason, LPVOID)
{
	if (Reason == DLL_PROCESS_ATTACH)
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)fd::Load, NULL, NULL, NULL);
	return TRUE;
}