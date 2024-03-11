#include <windows.h>

/*
* Achei essa implementacao interessante, verificar de onde saiu
* Referencia:
* https://pt.stackoverflow.com/a/469069
*/

int cls()
{   // limpa a tela no windows, do jeito oficial
    CONSOLE_SCREEN_BUFFER_INFO      info;
    HANDLE      H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD       origem = { 0,0 };
    int         total;
    if (H == INVALID_HANDLE_VALUE) return -1;
    GetConsoleScreenBufferInfo(H, &info);
    int r = FillConsoleOutputCharacter(H, (TCHAR)' ',
        info.dwSize.X * info.dwSize.Y,
        origem, &total);
    int s = FillConsoleOutputAttribute(
        H, info.wAttributes,
        info.dwSize.X * info.dwSize.Y,
        origem, &total);
    SetConsoleCursorPosition(H, origem);
    return 0;
};  // end cls()