#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "carro.h"
#include "coniof.h"
#include "mapa.h"
#include "menu.h"
#include "ranking.h"

/*void joabee(byte xBee,byte yBee) //JoaBee q n ta pegando ;-;
{
    static int C=2;

    short HighWing;
    short LowWing;

    HighWing = yBee - 1;
    LowWing = yBee + 1;

    do{


            switch(C)
            {

            case 0:
            case 2:

                gotoxy(xBee,HighWing);
                printf("      ");

                textcolor(rand()%16);

                gotoxy(xBee,yBee);
                printf("-- 0 --");

                gotoxy(xBee,LowWing);
                printf("      ");

                C++;

                break;

            case 1:

                textcolor(rand()%16);

                gotoxy(xBee,HighWing);
                printf(" \\   /");

                gotoxy(xBee,yBee);
                printf("   O   ");

                C++;

                break;

            case 3:

                C=0;

                textcolor(rand()%16);

                gotoxy(xBee,yBee);
                printf("   O   ");

                gotoxy(xBee,LowWing);
                printf(" /   \\");

                break;
            }

            Sleep(80);



    }
    while(1);
}*/
void car(axy carro,axy tiro) //função q faz o carro rodar
{
    static int C=0;

    gotoxy(carro.x1,carro.y1);

    //textcolor((rand() % 16 != 0));

    textcolor(2);

    if(tiro.x1!=8)
    {

        printf(" [----]   ");

        gotoxy(tiro.x1,tiro.y1);
        printf("=D");
    }

    else
        printf(" [----]=D");

    gotoxy(carro.x1,carro.y2);

    textcolor(10);

    switch(C)//Define em qual frame da animacao da roda sera exibido(case 0= frame 1, case 3= frame 4)//
    {
    case 0:

        printf("<->--<->   ");
        C++;

        break;

    case 1:

        printf("<\\>--<\\>   ");
        C++;

        break;

    case 2:
        printf("<|>--<|>   ");
        C++;

        break;

    case 3:

        printf("</>--</>   ");
        C=0;//reseta o contador usado nos frames//

        break;
    }

}
void death (int pontuacao,char c) //tela de game over
{
    jogador player;

    char name[9];

    byte i;

    mapa(0,'t');

    system("cls");
    while(1)
    {
        textcolor(c);
        gotoxy(58,16);
        printf("------------");

        gotoxy(58,17);
        textcolor(c);

        switch(c)
        {

        case 4:

            printf("|YOU   DIED|");

            break;

        case 3:
            printf("|YOU    WIN|");

            break;
        }

        gotoxy(58,18);
        textcolor(c);
        printf("------------");

        textcolor(11);

        gotoxy(50,19);
        printf("NAME OF THE MEMORABLE PILOT:");

        /*  joabee(5,20);
           joabee(30,25);
            joabee(35,10);
             joabee(110,16);
              joabee(80,13);
               joabee(60,14);
                joabee(100,28); */

        gotoxy(59,20);
        gets(name);

        break;
    }
    for(i=0; i<9; i++)
    {
        if(name[i]==' ')
            name[i]='0';
    }

    player.pontos=pontuacao;

    textcolor(15);
    strcpy(player.name,name);

    vRanking(player);

    sRanking();

    menu();
}

