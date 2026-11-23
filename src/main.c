#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

PSP_MODULE_INFO("Pou PSP", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void)
{
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    while (1)
    {
        SceCtrlData pad;
        sceCtrlReadBufferPositive(&pad, 1);

        pspDebugScreenClear();
        pspDebugScreenSetXY(10, 5);

        pspDebugScreenPrintf("POU PSP");

        pspDebugScreenSetXY(10, 8);
        pspDebugScreenPrintf("Virtual Pet Project");

        pspDebugScreenSetXY(10, 11);
        pspDebugScreenPrintf("X      : Feed");

        pspDebugScreenSetXY(10, 12);
        pspDebugScreenPrintf("O      : Clean");

        pspDebugScreenSetXY(10, 13);
        pspDebugScreenPrintf("SQUARE : Play");

        pspDebugScreenSetXY(10, 15);
        pspDebugScreenPrintf("START  : Exit");

        if (pad.Buttons & PSP_CTRL_START)
            break;

        sceKernelDelayThread(100000);
    }

    sceKernelExitGame();
    return 0;
}
