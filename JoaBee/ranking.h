#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED
#define N 10

struct joga_dor
{
    char name[9];//nome escolhido pelo jogador//

    unsigned int pontos;//total de pontos//
    //unsigned int m;total de monstros assassinados pelo jogador//
};

typedef struct joga_dor jogador;

void menu();

void rRanking();

void sRanking();

void iRanking();

void vRanking(jogador player);


#endif // RANKING_H_INCLUDED
