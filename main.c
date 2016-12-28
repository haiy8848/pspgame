/*
 * My PSP Game.
 *
 * Learn how to development games for PSP platform.
 *
 * Based on the sample codes provided in the pspsdk, it seems the os running on psp uses
 * the 'callback' mechnism to coordinate user application and kernel. As a result, we
 * should setup the start and exit callback functions to initialize and cleanup the game
 * environment respectively.
 */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"

/* Define the module info section */
PSP_MODULE_INFO("MYPSPGAME", 0, 1, 1);

/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

/* Define printf, just to make typing easier */
#define printf  pspDebugScreenPrintf

void dump_threadstatus(void);

int main(void)
{
    SceCtrlData pad;

    setupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    while(running()){
        // set location of the debug screen
        pspDebugScreenSetXY(0, 2);

        // read current controller status
        sceCtrlReadBufferPositive(&pad, 1);
        // display controller information
        printf("Analog X = %d ", pad.Lx);
        printf("Analog Y = %d \n", pad.Ly);

        if (pad.Buttons != 0){
            if (pad.Buttons & PSP_CTRL_SQUARE){
                printf("Square pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_TRIANGLE){
                printf("Triangle pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_CIRCLE){
                printf("Cicle pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_CROSS){
                printf("Cross pressed \n");
            }

            if (pad.Buttons & PSP_CTRL_UP){
                printf("Up pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_DOWN){
                printf("Down pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_LEFT){
                printf("Left pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_RIGHT){
                printf("Right pressed \n");
            }

            if (pad.Buttons & PSP_CTRL_START){
                printf("Start pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_SELECT){
                printf("Select pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_LTRIGGER){
                printf("L-trigger pressed \n");
            }
            if (pad.Buttons & PSP_CTRL_RTRIGGER){
                printf("R-trigger pressed \n");
            }
        }
    }

    sceKernelExitGame();
    return 0;
}
