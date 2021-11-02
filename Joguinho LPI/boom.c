#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "boom.h"
#include "funcoesEspecificas.h"

extern int xt, yt, yalvo;

void boom()//printa uma animação para o boom
{
    gotoxy(xt-4,yalvo-1);
        printf("  /-\\");
    gotoxy(xt-4,yalvo);
        printf("  \\-/");

    usleep(200000);

    gotoxy(xt-3,yalvo-1);
        printf(" /\\-/\\");
    gotoxy(xt-3,yalvo);
        printf("<BOOM!>");
        if(yalvo+1 < 24){
            gotoxy(xt-3,yalvo+1);
                printf(" \\/-\\/");
        }
    usleep(200000);

    gotoxy(xt-3,yalvo-1);
        printf("      ");
    gotoxy(xt-3,yalvo);
        printf("       ");
        if(yalvo+1 < 24){
            gotoxy(xt-3,yalvo+1);
                printf("       ");
        }
    gotoxy(xt-4,yalvo-1);
        printf("  /-\\");
    gotoxy(xt-4,yalvo);
        printf("  \\-/");

    usleep(200000);

    gotoxy(xt-3,yalvo-1);
        printf("      ");
    gotoxy(xt-3,yalvo);
        printf("       ");
        if(yalvo+1 < 23){
            gotoxy(xt-3,yalvo+1);
                printf("       ");
            gotoxy(xt-3,yalvo+2);
                printf("       ");
        }
}
