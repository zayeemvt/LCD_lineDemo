#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"

// Initialization function for graphics
void initializeGraphics(Graphics_Context* g_sContext_p) {
    // Initialize the LCD
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    // Initialize context
    Graphics_initContext(g_sContext_p, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);

    // Set colors and fonts
    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
    Graphics_setBackgroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
    Graphics_setFont(g_sContext_p, &g_sFontCmss12);

    // Clear the screen
    Graphics_clearDisplay(g_sContext_p);
}

int main(void)
{
    // Stop watchdog timer
    MAP_WDT_A_holdTimer();

    // Initializations
    Graphics_Context g_sContext; // Create context
    initializeGraphics(&g_sContext);

    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_drawString(&g_sContext, (int8_t*) "Horizontal", -1, 15, 10, true);
    Graphics_drawString(&g_sContext, (int8_t*) "Line", -1, 27, 20, true);
    Graphics_drawLineH(&g_sContext, 80, 110, 20);

    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_BLUE);
    Graphics_drawString(&g_sContext, (int8_t*) "Vertical", -1, 15, 55, true);
    Graphics_drawString(&g_sContext, (int8_t*) "Line", -1, 25, 65, true);
    Graphics_drawLineV(&g_sContext, 95, 50, 80);

    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_YELLOW);
    Graphics_drawString(&g_sContext, (int8_t*) "Diagonal", -1, 15, 90, true);
    Graphics_drawString(&g_sContext, (int8_t*) "Lines", -1, 22, 100, false);
    Graphics_drawLine(&g_sContext, 63, 90, 88, 115);
    Graphics_drawLine(&g_sContext, 98, 115, 123, 90);

    while(1);
}
