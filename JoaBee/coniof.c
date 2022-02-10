#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void textcolor (int iColor) {

    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);

    bufferInfo.wAttributes &= 0x00F0;

    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();

    while (goal > clock());
}
void gotoxy(int x, int y){

    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
