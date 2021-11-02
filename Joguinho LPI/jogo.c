#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "jogo.h"
#include "alvos.h"
#include "tiro.h"
#include "boom.h"
#include "funcoesEspecificas.h"

extern int yalvo, limy, yt, ang, dificuldade, xt;
int pontos, tempo;
void jogo()
{
    int x, a;
    char tiro;
    limy = 1;
    tempo =0;
    pontos = 0;
    srand(time(NULL));
    layout();

    do
    {
        a = rand()%4;
        x = 2;
        do
        {
            switch (a)
            {
            case 0:
                sen(x);
                break;
            case 1:
                cus(x);
                break;
            case 2:
                parabola(x);
                break;
            case 3:
                mare(x);
                break;
            }
            x++;
            if(kbhit() && limy == 1)
            {
                tiro = getch();
                if(tiro=='a'||tiro=='s'||tiro=='d')
                {
                    yt = 22;
                    ang = 0;
                }
            }
            atirar(tiro);
            usleep(65000/(((dificuldade-48)/2)+0.75));
            if(abs(xt-x)<=1 && abs(yt-yalvo)<=1)
            {
                boom();
                x = 121;
                yt = 1;
                pontos+=5;
                gotoxy(10,28);
                printf("%d",pontos);
            }
            gotoxy(107,26);
            printf("   ");
            gotoxy(107,26);
            printf("%d",20-tempo);
        }
        while(x<121);
        tempo++;
    }
    while(tempo<20);

}
