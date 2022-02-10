#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "carro.h"
#include "coniof.h"
#include "ranking.h"
void manual(){

        char j;

        textcolor(11);

        gotoxy(50,15);
        printf("CONTROLS:");

        gotoxy(50,16);
        printf("'W'/'S' TO GO UP/DOWN IN THE MENU");

        gotoxy(50,17);
        printf("'D' TO SELECT");

        gotoxy(50,18);
        printf("'S' TO SHOOT");

        gotoxy(50,19);
        printf("'SPACE' TO JUMP");

        gotoxy(0,34);
        printf("PRESS R  TO GO BACK");

      while(1)
    {
        if(kbhit())
        {
            j=getch();
            if(j=='r'||j=='R')
            {
                menu();
            }
        }
    }
}
void menu()
{
    char opcao;

    int y = 15,yAntigo;

    char enter = 255;

    system("cls");

    textcolor(14);

gotoxy(24,5);
printf("         ___                              _______                                     ");
gotoxy(24,6);
printf("        |   |    ______     _______      |  ___  |     _______     _______            ");
gotoxy(24,7);
printf("        |   |   |  __  |   |  ___  |     | |___| |    |  _____|   |  _____|           ");
gotoxy(24,8);
printf("        |   |   | |  | |   | |___| |     |  ____<     | |_____    | |_____            ");
gotoxy(24,9);
printf("   __   |   |   | |  | |   |  ___  |     | |    | |   | |_____|   | |_____|           ");
gotoxy(24,10);
printf("  |  |__|   |   | |__| |   | |   | |     | |____| |   | |_____    | |_____            ");
gotoxy(24,11);
printf("  |_________|   |______|   |_|   |_|     |________|   |_______|   |_______|           ");



    do
    {

        textcolor(15);

        gotoxy(62,15);
        printf("Jogar");

        gotoxy(62,16);
        printf("Ranking");

        gotoxy(62,17);
        printf("Manual");

        gotoxy(62,18);
        printf("Sair\n %c",enter);

        yAntigo = y;        //troca de valores da seta

        gotoxy(60,y);
        printf("->");

        opcao = getch();     //formação das opçoes

        switch(opcao)
        {

        case 'w':
        case 'W':

            y--;

            break;

        case 's':
        case 'S':

            y++;

            break;

        case 'd':
        case 'D':

            switch(y)
            {

            case 15:
                system("cls");

                walk();

                opcao='j';

                break;
            case 16:

                system("cls");

                iRanking();

                opcao='j';

                break;

            case 17:

                system("cls");

                manual();

                opcao='j';

                break;

            case 18:

                return NULL;
            }
        }

        y == 19? y = 15 : y; //prisao da seta
        y == 14? y = 18 : y;

        gotoxy(60,yAntigo); //apagar a seta
        printf("  ");

    }
    while (opcao!='d' && opcao!='D');
}
