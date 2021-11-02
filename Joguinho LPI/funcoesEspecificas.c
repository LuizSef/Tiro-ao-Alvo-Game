#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "funcoesEspecificas.h"

//CRIA A FUNCAO GOTOXY DA "CONIO.H"
void gotoxy(int xt, int yt)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        xt,yt
    });
}
