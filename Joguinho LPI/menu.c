#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#include "funcoesEspecificas.h"
#include "menu.h"
#include "jogo.h"
#include "ranking.h"

extern int pontos;

void menu();
int dificuldade, nivel;

void molduracapa()
{
    int i, y, x;
    y = 29;
    recall();
    for(i=0; i<30; i++)  //Coluna da esquerda. Movimento de baixo para cima
    {
        gotoxy(0, y);
        printf("#");
        y--;
        usleep(4500); //Usleep apenas estetico
    }

    x=1;
    for(i=0; i<119; i++)  //Linha da superior. Movimento esquerda direita
    {
        gotoxy(x, 0);
        printf("#");
        x++;
        usleep(1250);
    }

    y=1;
    for(i=0; i<28; i++)  //Coluna da direita. Movimento de cima para baixo
    {

        gotoxy(119, y);
        printf("#");
        y++;
        usleep(4500);
    }

    x = 118;

    for(i=0; i<118; i++)   //Linha inferior. Movimento da direita para esquerda
    {
        gotoxy(x, 29);
        printf("#");
        x--;
        usleep(1250);
    }
}

void conteudocapa()
{

    int i, j;
    char matriz [6][6] = {
        {"  ^   "},
        {" /|\\ "},
        {"/_|_\\"},
        {"  |   "},
        {"  ^   "}
    };
    dificuldade=49;
    gotoxy(58, 8);
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%c", matriz[i][j]);
            usleep(1250);
        }
        gotoxy(58,9+i);
    }

    char matriz2 [5][13] = {
        {" ___________ "},
        {"|  T I R O  |"},
        {"|    A O    |"},
        {"|  A L V O  |"},
        {"|___________|"}
    };


    gotoxy(54,13);
    for(i=0; i<5; i++)
    {
        for(j=0; j<13; j++)
        {
            printf("%c", matriz2[i][j]);
            usleep(1250);
        }
        gotoxy(54,14+i);
    }

    gotoxy(44,21);
    printf("Aperte qualquer tecla para continuar");

    char powered[102] = "P O W E R E D  B Y: GUSTAVO POROCA, MARIA FERNANDA RODRIGUES, FRANCIELE FRANCA, LUIZ FELIPE ESPINDOLA";
    gotoxy(9, 28);
    for(i=0; i<102; i++)
    {
        printf("%c", powered[i]);
        usleep(1250);
    }
    getch();
    system("cls");
}

void moldurageral()
{
    int i, y, x;
    y=30;
    for(i=0; i<30; i++)
    {

        gotoxy(0,y);
        printf("#");
        y--;
    }

    x = 1;

    for(i=0; i<118; i++)
    {
        gotoxy(x, 1);
        printf("#");
        x++;
    }

    y = 1;

    for(i=0; i<30; i++)
    {

        gotoxy(119, y);
        printf("#");
        y++;
    }

    x = 119;

    for(i=0; i<118; i++)
    {
        gotoxy(x, 30);
        printf("#");
        x--;
    }
}

void invalido()
{
    moldurageral();
    gotoxy(28, 15);
    printf("* O P C A O  I N V A L I D A, T E N T E  N O V A M E N T E*");
    sleep(2);
    system("cls");
}

void incremento()
{
    moldurageral();
    gotoxy(27, 15);
    printf("* A  D I F I C U L D A D E  S E R A  I N C R E M E N T A D A *");
    gotoxy(47, 16);
    printf("* N O  J O G O *");
    sleep(2);
    system("cls");
}

void fechamento()
{
    moldurageral();
    int i;

    char obrigado[60] = "* O B R I G A D O  P O R  J O G A R  O  N O S S O  J O G O *";
    gotoxy(28,15);
    for(i=0; i<60; i++)
    {
        printf("%c", obrigado[i]);
        usleep(1250);
    }

    char powered[102] = "P O W E R E D  B Y: GUSTAVO POROCA, MARIA FERNANDA RODRIGUES, FRANCIELE FRANCA, LUIZ FELIPE ESPINDOLA";
    gotoxy(9,28);
    for(i=0; i<102; i++)
    {
        printf("%c", powered[i]);
        usleep(1250);
    }
    sleep(2);
}

void configuracoes()
{
    moldurageral();

    int i, j;

    char matriz3 [6][48]= {{" ______________________________________________ "},
        {"| E S C O L H A  U M A  D I F I C U L D A D E: |"},
        {"| 1- F A C I L                                 |"},
        {"| 2- M E D I O                                 |"},
        {"| 3- D I F I C I L                             |"},
        {"|______________________________________________|"}
    };

    gotoxy(40, 10);
    for(i=0; i<6; i++)
    {
        for(j=0; j<48; j++)
        {
            printf("%c", matriz3[i][j]);
        }
        gotoxy(40, 11+i);
    }

    dificuldade = getch();
    system("cls");

    switch(dificuldade - 48)
    {
    case 1:
        incremento();
        menu();
        break;
    case 2:
        incremento();
        menu();
        break;
    case 3:
        incremento();
        menu();
        break;
    default:
        invalido();
        menu();
        break;
    }

}

void menu()
{
    moldurageral();

    int i, j, opcao;

    char matriz3 [7][36]= {{" __________________________________ "},
        {"| E S C O L H A  U M A  O P C A O: |"},
        {"| 1- J O G A R                     |"},
        {"| 2- R A N K I N G                 |"},
        {"| 3- C O N F I G U R A C O E S     |"},
        {"| 4- S A I R                       |"},
        {"|__________________________________|"}
    };

    gotoxy(40, 10);
    for(i=0; i<7; i++)
    {
        for(j=0; j<36; j++)
        {
            printf("%c", matriz3[i][j]);
        }
        gotoxy(40, 11+i);
    }
    opcao = getch();

    switch(opcao)
    {
    case '1':
        system("cls");
        jogo();
        nivel = dificuldade - 48;
        dadosJogador();
        ordem();
        salvamento();
        system("cls");
        menu();
        break;
    case '2':
        system("cls");
        moldurageral();
        mostrarRanking();
        getch();
        system("cls");
        menu();
        break;
    case '3':
        system("cls");
        configuracoes();
        system("cls");
        break;
    case '4':
        system("cls");
        fechamento();
        exit(0);
        break;
    default:
        system("cls");
        invalido();
        system("cls");
        menu();
        break;
    }
}

