#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "tiro.h"
#include "funcoesEspecificas.h"

int limy, yt, ang, oxt, xt;
void atirar(char tiro)
{
    switch(tiro)
    {
    case 'a':
        if(yt>=2)
        {
            xt = 50 + ang;
            oxt = xt+1;
            gotoxy(xt,yt);
            printf("O");
            ang--;
        }
        if(yt==1)
        {
            gotoxy(oxt - 1,2);
            printf(" ");
        }
        break;
    case 's':
        if(yt>=2)
        {
            xt = 59;
            oxt = xt;
            gotoxy(xt,yt);
            printf("O");
        }
        break;
    case 'd':
        if(yt>=2)
        {
            xt = 67 + ang;
            oxt = xt -1;
            gotoxy(xt,yt);
            printf("O");
            ang++;
        }
        if(yt==1)
        {
            gotoxy(oxt+1,yt + 1);
            printf(" ");
        }
        break;
    default:
        break;
    }
    if(yt>=1)
    {
        gotoxy(oxt,yt + 1);
        printf(" ");
        limy = yt;
    }
    yt--;
}
