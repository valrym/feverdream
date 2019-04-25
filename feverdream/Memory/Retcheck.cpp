#include "Retcheck.h"

//This bypass was made by eternal (if I recall correctly), I think this still works.
DWORD Ret(DWORD addr)
{
	BYTE* BYTEADDR = (BYTE *)addr;

	do {
		BYTEADDR += 0x10;
	} while (!(BYTEADDR[0] == 0x55 && BYTEADDR[1] == 0x8B && BYTEADDR[2] == 0xEC));

	DWORD FUNC = BYTEADDR - (BYTE*)addr;

	PVOID VOID_FUNC = VirtualAlloc(NULL, FUNC, 0x1000 | 0x2000, 0x40);
	if (VOID_FUNC == NULL)
		return addr;

	memcpy(VOID_FUNC, (BYTE*)addr, FUNC);

	DWORD pos = (DWORD)VOID_FUNC;
	BOOL valid = false;
	do {
		if (*(BYTE*)pos == 0x72 && *(BYTE*)(pos + 0x2) == 0xA1 && *(BYTE*)(pos + 0x7) == 0x8B)
		{
			memcpy((void*)pos, "\xEB", 1);

			DWORD DWORD_FUNC = (DWORD)VOID_FUNC;
			do
			{
				if (*(BYTE*)DWORD_FUNC == 0xE8)
				{
					DWORD DWORD_FUNC2 = addr + (DWORD_FUNC - (DWORD)VOID_FUNC);

					DWORD DWORD_FUNC3 = (DWORD_FUNC2 + *(DWORD*)(DWORD_FUNC2 + 1)) + 5;

					if (DWORD_FUNC3 % 16 == 0)
					{
						DWORD Reb_Addr = DWORD_FUNC3 - DWORD_FUNC - 5;
						*(DWORD*)(DWORD_FUNC + 1) = Reb_Addr;
					}
					DWORD_FUNC += 5;
				}
				else
					DWORD_FUNC += 1;
			} while (DWORD_FUNC - (DWORD)VOID_FUNC < FUNC);

			valid = true;
		}
		pos += 1;

	} while (pos < (DWORD)VOID_FUNC + FUNC);

	if (!valid)
	{
		VirtualFree(VOID_FUNC, FUNC, MEM_RELEASE);
		return addr;
	}

	return (DWORD)VOID_FUNC;
}