#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "coniof.h"
#include "ranking.h"//usado por causa de um struct presente nesse arquivo
#include "menu.h"

jogador playersalvos[N];

void rRanking()
{
    int i;

    FILE *ranking = fopen("ranking.txt", "r+");

    for(i = 0; i < N; i++)
    {
        fread(&playersalvos[i],sizeof(jogador),1,ranking);
    }

    fclose(ranking);
}
void sRanking()
{
    int i;

    FILE *ranking = fopen("ranking.txt", "w+");

    for(i = 0; i < N; i++)
    {
        fwrite(&playersalvos[i],sizeof(jogador),1,ranking);
    }

    fclose(ranking);
    rRanking();
}
void iRanking()
{

    byte MsMs,i;

    char j;


    rRanking();

    textcolor(12);

    gotoxy(50,14);
    printf("NICKNAME");

    gotoxy(62,14);
    printf("SCORE");

    gotoxy(48,12);
    printf("===========================");
    gotoxy(48,13);
    printf("|                         |");
    gotoxy(48,14);
    printf("| NICKNAME         SCORE  |");
    gotoxy(48,15);
    printf("|                         |");
    gotoxy(48,16);
    printf("|                         |");
    gotoxy(48,17);
    printf("|                         |");
    gotoxy(48,18);
    printf("|                         |");
    gotoxy(48,19);
    printf("|                         |");
    gotoxy(48,20);
    printf("|                         |");
    gotoxy(48,21);
    printf("|                         |");
    gotoxy(48,22);
    printf("|                         |");
    gotoxy(48,23);
    printf("|                         |");
    gotoxy(48,24);
    printf("|                         |");
    gotoxy(48,25);
    printf("|                         |");
    gotoxy(48,26);
    printf("|                         |");
    gotoxy(48,27);
    printf("|                         |");
    gotoxy(48,28);
    printf("|                         |");
    gotoxy(48,29);
    printf("===========================");

    for(i=1; i <= N; i++)
    {

        MsMs = i + 15;
        gotoxy(50,MsMs);
        puts(playersalvos[i].name);

        gotoxy(68,MsMs);
        printf("%d",playersalvos[i].pontos);
    }
    gotoxy(0,34);
    printf("PRESS R TO GO BACK");

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

void vRanking(jogador player)
{
    int i,j;

    rRanking();

    for(i = 0; i < N; i++)
    {
        if(player.pontos >= playersalvos[i].pontos )
        {

            for(j = N-1; j > i; j--)
            {
                playersalvos[j] = playersalvos[j-1];
            }

            playersalvos[i] = player;

            break;
        }
    }
}
