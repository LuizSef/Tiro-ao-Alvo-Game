#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

#include "ranking.h"
#include "menu.h"
#include "funcoesEspecificas.h"

extern int pontos, nivel;
char nomeatual[20];

FILE *salvar;

void salvamento();
void recall();

struct jogadores
{
    char nome[20];
    int nivel;
    int pontuacao;

} todosJogadores[11];

int i,j;

void rankingZerado()
{
    for(i=0; i<10; i++)
    {
        strcpy(todosJogadores[i].nome,"Desconhecido");
        todosJogadores[i].nivel = 0;
        todosJogadores[i].pontuacao = 0;
    }
}
void dadosJogador()
{
    gotoxy(50,13);
    printf("DIGITE SEU NOME: ");
    gets(nomeatual);
    strcpy(todosJogadores[10].nome, nomeatual);
    todosJogadores[10].nivel = nivel;
    todosJogadores[10].pontuacao = pontos;

}

void ordem()
{
    int temp;//variavel auxiliar para ordenar a pontuacao
    char auxnome[20];//variavel auxiliar para ordernar os nomes junto com a pontuacao
    for(i=0; i<11; i++)
    {

        for(j=0; j<11; j++)
        {

            if(todosJogadores[i].pontuacao>todosJogadores[j].pontuacao)
            {
                temp = todosJogadores[j].pontuacao;
                todosJogadores[j].pontuacao = todosJogadores[i].pontuacao;
                todosJogadores[i].pontuacao = temp;
                temp = todosJogadores[j].nivel;
                todosJogadores[j].nivel = todosJogadores[i].nivel;
                todosJogadores[i].nivel = temp;
                strcpy(auxnome,todosJogadores[j].nome);
                strcpy(todosJogadores[j].nome,todosJogadores[i].nome);
                strcpy(todosJogadores[i].nome,auxnome);
            }
        }
    }
    strcpy(todosJogadores[10].nome,"Desconhecido");
    todosJogadores[10].pontuacao = 0;
}

void mostrarRanking()
{
    gotoxy(50,9);
    printf("NOME |\t DIFICULDADE |\t PONTOS");
    for(i=0; i<10; i++)
    {
        gotoxy(50,10+i);
        printf("%s |\t\t %d |\t %d", todosJogadores[i].nome, todosJogadores[i].nivel, todosJogadores[i].pontuacao);
    }
}

void recall()
{
    salvar = fopen("ranking.txt","rb");
    for(i=0; i<10; i++)
    {
        fread(&todosJogadores[i],sizeof(struct jogadores),1,salvar);
    }
    fclose(salvar);
}

void salvamento()
{
    salvar = fopen("ranking.txt","wb");

    for(i=0; i<11; i++)
    {
        fwrite(&todosJogadores[i],sizeof(struct jogadores),1,salvar);
    }
}
