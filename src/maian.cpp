#include <Windows.h>
#include <iostream>
#include <thread>
#include "memory.h"
#include "memory/memory.h"
#include "offsets/Offsets.h"

using namespace std;

int main() {
    const char* processName = "game.exe";

    DWORD pid = GetProcessIdByName(processName);
    if (pid == 0) {
        cerr << processName << "' not found!" << endl;
        return -1;
    }

    HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, pid);
    if (hProcess == nullptr) {
        cerr << "OpenProcess faild. Error: " << GetLastError() << endl;
        return -1;
    }

    uintptr_t moduleBase = 0x400000;

    uintptr_t ammoAddress = AMMO_OFFSET;
    uintptr_t hpAddress = moduleBase + HP_OFFSET;

    int maxAmmo = 20;
    int ammo = 0, hp = 0;
    while (true) {
        if (ammo < maxAmmo) {
            if (!WriteMemory(hProcess, ammoAddress, &maxAmmo, sizeof(int))) {
                cerr << "Cant Write memory. Error: " << GetLastError() << endl;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(250)); //dont fuck with your cpu
    }

    CloseHandle(hProcess);
    return 0;
}
