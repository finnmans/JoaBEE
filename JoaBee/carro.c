#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "coniof.h"
#include "mapa.h"
#include "frames.h"


int pulo(int x,int y)//o pulo//
{
    static int jump=0;//variavel usada como contador, o valor dela permanece quando a função é finalizada//

    int yold;//armazena a posição anterior de uma linha da string//
    int h=10;//altura do pulo//

    if(jump<h/2)//subida//
    {
        jump++;

        yold=y+1;//armazena a posição anterior das rodas//

        y--;//altera o valor de Y//

        gotoxy(x,yold);
        printf("          ");//apaga a string das rodas do carro an posição anterior//

    }

    else if(jump>=h/2 && jump<=h)//descida//
    {
        jump++;

        yold=y;//armazena a posição anterior da cabeça//

        y++;//altera o valor de Y//

        gotoxy(x,yold);
        printf("          ");//apaga a string da cabeça do carro an posição anterior//

        if(jump==h)//reseta jump quando =6//
            jump=0;
    }

    //gotoxy(20,0);
    // printf("y   %d    jump %d ",y,jump);// imprime valores na tela, usado somente para testes//

    return y;//retorna o novo valor de Y//
}
void bullet(axy carro,axy *bala, int colisao)
{
    static int Ctiro=0;

    int xcarro,xold;//usado em funcões que, por algum motivo, não funcionam direito quando colocam uma operação//

    axy tiro; //area do tiro

    tiro=*bala; //area do tiro direcionada a bala

    xcarro=carro.x2-2; //x da cabeça do carro

        if(xcarro == tiro.x1)
        {
        tiro.x1=xcarro+1; //tiro saindo do carro

        xold=tiro.x1-1;

        tiro.y1=carro.y1;

        gotoxy(xold,tiro.y1); //garante a espera pela recarga
        printf(" ");

        tiro.y2=tiro.y1;

        Ctiro++; //movimento do tiro
        }

            else if(xcarro < tiro.x1 && Ctiro < 40)
            {
        Ctiro++; //faz o tiro ir ate tal ponto

        xold=tiro.x1-1; //reprint do tiro na possição correta

        tiro.x1++; //movimento do tiro

        gotoxy(tiro.x1-1,tiro.y1); //apaga o tiro
        printf(" ");
            }

    if(tiro.x1==40 || colisao>=128)
    {
        gotoxy(tiro.x1,tiro.y1); //hitbox do tiro e final dele
        printf("   ");

        Ctiro=0; //reseta o tiro

        tiro.x1=xcarro; //volta o tiro pra cabeça do carro
    }

    tiro.x2=tiro.x1+2; //volta o tiro pra cabeça do carro

    *bala = tiro; //troca de valor

    // gotoxy(20,3);
    //  printf("xcarro   %d    tiro.x1 %d ",xcarro,tiro.x1);// imprime valores na tela, usado somente para testes// (TESTE)

    // gotoxy(20,4);
    // printf("Ctiro   %d    colisao %d ",Ctiro,colisao); (TESTE)

}
void walk()//carro andando//
{
    int y=30;//Y do carro e cordenadas de outros objetos//
    //int M;//contadores usado em funções e animações e variveis usadas para verificar certos fatos//
    int ponto=0;

    const int yfloor=33,xcarro=1;//o valor do X do carro e do Y do chao//

    char j;//armazena comaandos//

    unsigned char b=0, colisao=0;//b->verifica se tem um buraco abaixo do carro|colisao->verifica se o tiro acertou algum alvo

    axy carro,tiro;//cordenadas e area do carro e de outros objetos//

    carro.x1=xcarro;
    carro.x2=xcarro+9;

    tiro.x1=8;

    do //loop do jogo
    {
        carro.y2=y+1; //rodas
        carro.y1=y;   //cabeça

        if(b==255)
            death(ponto,3); //vitoria

        if(tiro.x1!=8) //chamada do tiro
            bullet(carro,&tiro,colisao);

        car(carro,tiro); //movimento do carro

        if(b%2==1)
        {
            b--;

        }

        b=mapa(yfloor,b);

        Sleep(50);

        if(y<30)
            y=pulo(xcarro,y);//chama a função do pulo//

        if(kbhit())//detecta o comando//
        {
            j=getch();//armazena o comando//

           /* if(ponto % 2500 == 0)      //chamada do JoaBee
            {

                switch (ponto)
                {

                case 2500:

                    joabee(18,20);

                    break;

                case 5000:

                    joabee(49,15);

                    break;

                case 7500:

                    joabee(80,15);

                    break;

                case 10000:

                    joabee(111,20);

                    break;
                }

            } */


            switch(j)//caso possivel realisa a função desejada//
            {
            case ' '://comando para iniciar a função pulo//

                if(y==30)

                    y=pulo(xcarro,y);

                j='m';//troca o valr de j para o de um comando inexistente//

                break;

            case 's':
            case 'S'://

                bullet(carro,&tiro,colisao);

                j='m';

                break;
            }
        }

        if(b>=100 && carro.y2==31) //hitbox do carro
        {

            death(ponto,4);

            ponto=0;

            break;
        }

        ponto+=10; //contador da pontuação

        gotoxy(20,5);
        printf("SCORE:%d ",ponto);// imprime valores na tela, usado somente para testes//
    }
    while(1);
}
