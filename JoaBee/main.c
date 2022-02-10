#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "menu.h"
#include "ranking.h"

int main()
{
    system("MODE con: cols=125 lines=35");
    rRanking();
    menu();

    return 0;
}
