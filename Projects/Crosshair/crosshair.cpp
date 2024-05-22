#include <Windows.h>

int main()
{
    // Get the handle of the desktop window
    HWND desktop = GetDesktopWindow();

    // Get the dimensions of the screen
    RECT desktopRect;
    GetWindowRect(desktop, &desktopRect);

    // Calculate the center of the screen
    int screenWidth = desktopRect.right - desktopRect.left;
    int screenHeight = desktopRect.bottom - desktopRect.top;
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    // Create a crosshair at the center of the screen
    HDC hdc = GetDC(desktop);
    SelectObject(hdc, GetStockObject(WHITE_PEN));
    MoveToEx(hdc, centerX - 50, centerY, NULL);
    LineTo(hdc, centerX + 50, centerY);
    MoveToEx(hdc, centerX, centerY - 50, NULL);
    LineTo(hdc, centerX, centerY + 50);
    ReleaseDC(desktop, hdc);

    return 0;
}