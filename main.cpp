#include "ExternalWriting.h"

int main() {

    // Thanks void https://www.youtube.com/watch?v=zzMGDS4ZyZ
    
    bool on = false;
    DWORD processID = GetProcessByName("GeometryDash.exe");

    if (!processID) {
        printf("Could not find Geometry Dash");
    }

    HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processID);
    auto base = GetModuleBaseAddress(processID, "GeometryDash.exe");

    
    std::vector<BYTE> onbytes = { 0xEB, 0x23, 0x90, 0x90, 0x90, 0x90 };
    std::vector<BYTE> offbytes = { 0x0F, 0x85, 0x8F, 0x07, 0x00, 0x00 };

    std::cout << "2.2 Noclip by CJ_Link :3\n" << std::endl;
    std::cout << "Press enter to toggle noclip" << std::endl;
    
    while (true) {

        getchar();

        if (on) {
            WPM(pHandle, (LPVOID*)(base + 0x2E0AE5), offbytes);
            std::cout << "NoClip off" << std::endl;
            on = false;
        }
        else {
            WPM(pHandle, (LPVOID*)(base + 0x2E0AE5), onbytes);
            std::cout << "NoClip on" << std::endl;
            on = true;
        }
    }

    return 0;
}
