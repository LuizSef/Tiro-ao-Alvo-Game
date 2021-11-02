#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "alvos.h"
#include "funcoesEspecificas.h"

int yalvo;
extern int dificuldade;

void layout() //printa a borda no jogo
{
    int i, j;
    char matriz [4][10] = {
        {"  ______  "},
        {" /      \\ "},
        {"|  O  O  |"},
        {" \\__ww__/ "},
};
    
    for (i = 0; i < 120; i++)
    {

        printf("#");
    }
    for (i = 1; i < 24; i++)
    {
        printf("#");
        for (j = 1; j < 119; j++)
        {
            printf(" ");
        }
        printf("#");
    }
    for (i = 0; i < 49; i++)
    {
        printf("#");
    }
    printf("\\\\ A \\\\|| S ||// D //");
    for (i = 0; i < 50; i++)
    {
        printf("#");
    }
    gotoxy(55,25);

    gotoxy(2,28);
        printf("pontos: ");
    gotoxy(100,28);
        printf("dificuldade: %d", dificuldade - 48);
    gotoxy(100,26);
        printf("alvos: ");
    for(i=0; i<4; i++)
    {
        gotoxy(54,25+i);
        for(j=0; j<10; j++)
        {
            printf("%c", matriz[i][j]);
        }
        
    }
}

void parabola(int x)//calcula um y a partir do x crescente na funcão do jogo
{
    int ox, oy;
    ox = x-1;
    oy = 25 - round(-0.005*ox*ox + 0.6*ox);
    if(ox> 1 && oy<=24 && oy>=2 && ox<119)
    {
        gotoxy(ox,oy);
        printf(" ");
    }
    yalvo = 25 - round(-0.005*x*x + 0.6*x);
    if(x<119 && yalvo<=24 && yalvo>=2 && ox<119)
    {
        gotoxy(x,yalvo);
        printf("@");
    }
}
void sen(int x)//usa uma função seno pra calcular o y
{
    int ox, oy;
    ox = x-1;
    oy = 14 - 9*sin(0.15*ox);
    if(ox> 1 && oy<=24 && oy>=2 && ox<119)
    {
        gotoxy(ox,oy);
        printf(" ");
    }
    yalvo = 14 - 9*sin(0.15*x);
    if(x<119 && yalvo<=24 && yalvo>=2 && ox<119)
    {
        gotoxy(x,yalvo);
        printf("$");
    }
}
void mare(int x)//usa uma função módulo do seno pra calcular o y
{
    int ox, oy;
    ox = x-1;
    oy = 18 - abs((int)(9*sin(0.15*ox)));
    if(ox> 1 && oy<=24 && oy>=2 && ox<119)
    {
        gotoxy(ox,oy);
        printf(" ");
    }
    yalvo = 18 - abs((int)(9*sin(0.15*x)));
    if(x<119 && yalvo<=24 && yalvo>=2 && ox<119)
    {
        gotoxy(x,yalvo);
        printf("%%");
    }
}
void cus(int x)//usa uma função cosseno pra calcular o y
{
    int ox, oy;
    ox = x-1;
    oy = 14 - 9*cos(0.15*ox);
    if(ox> 1 && oy<=24 && oy>=2 && ox<119)
    {
        gotoxy(ox,oy);
        printf(" ");
    }
    yalvo = 14 - 9*cos(0.15*x);
    if(x<119 && yalvo<=24 && yalvo>=2 && ox<119)
    {
        gotoxy(x,yalvo);
        printf("C");
    }
}
