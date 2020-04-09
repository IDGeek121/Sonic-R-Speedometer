#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <cmath>
#include <string>

#include "SonicRModLoader.h"

#define BUFFER 32
#define X_OFFSET 256
#define Y_OFFSET 0


/* Prints numbers for floats as HUD */
void float_string_to_text(char* buffer)
{
    //PrintDebug("float_string_to_text(%s)\n", buffer);
    int i = 0;
    int currentPos = 0;
    while (i < BUFFER && buffer[i] != 0x0)
    {
        //PrintDebug("Detected char \"%c\"\n", buffer[i]);
            switch (buffer[i])
            {
            case 0x2E:
                D3D_Render2DObject(X_OFFSET + currentPos + 4, Y_OFFSET, 10.0f, 8, 32, TPageIcon01, 83, 136, 3, 16, 0xFFE0E0E0);
                currentPos += 16;
                break;
            default:
                if (buffer[i] >= 0x30 && buffer[i] <= 0x39)
                {
                    int num = buffer[i] - 0x30;
                    int tPageOffset = num * 8;
                    D3D_Render2DObject(X_OFFSET + currentPos, Y_OFFSET, 10.0f, 16, 32, TPageIcon01, tPageOffset, 136, 8, 15, 0xFFE0E0E0);
                    currentPos += 16;
                }
                break;
            }
        i++;
    }
}

extern "C"
{
    __declspec(dllexport) ModInfo SonicRModInfo = { ModLoaderVer };
    __declspec(dllexport) void __cdecl OnFrame()
    {
        char buffer[BUFFER];
        if (InGame == 4)
        {
            double speed = sqrt(pow((double)Players[0].XSpeed, 2.0) + /* pow((double)Players[0].YSpeed, 2.0) + */ pow((double)Players[0].ZSpeed, 2.0));
            snprintf(buffer, (size_t)BUFFER, "%011.4f", speed);
            float_string_to_text(buffer);
            //PrintDebug("\tSpeed: %f", speed);
        }
        //PrintDebug("\r");
    }
}