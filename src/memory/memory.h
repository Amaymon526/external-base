#ifndef MEMORY_H
#define MEMORY_H

#include <Windows.h>

DWORD GetProcessIdByName(const char* processName);

bool ReadMemory(HANDLE hProcess, uintptr_t lpBaseAddress, void* lpBuffer, SIZE_T nSize);

bool WriteMemory(HANDLE hProcess, uintptr_t lpBaseAddress, void* lpBuffer, SIZE_T nSize);

#endif
