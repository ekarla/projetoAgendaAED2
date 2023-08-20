#ifndef _AGENDADOR_H
#define _AGENDADOR_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct no
{
    int dia, mes, ano, hora, min;
    char descricao[140];
    char prioridade[6];
    struct no *prox;    
}Evento;
typedef struct fila{
    Evento *prim;
    Evento *fim;
    int tamanho;
}Fila;

void criar_agenda(Fila *fila);
void agendar_evento(Fila *fila,int dia, int mes, int ano, int hora, int min, char descricao[], char prioridade[]);
Evento* concluir_evento(Fila *fila);
void immprimir_fila(Fila *fila);
int quantificar_evento(Fila *fila);
Evento* proximo_evento(Fila *fila);
Evento* buscar_evento(Fila *fila, int dia, int mes, int ano, int hora, int min);
void alterar_evento(Fila *fila, int dia, int mes, int ano, int hora, int min, int novo_dia, int novo_mes, int novo_ano, int novo_hora, int novo_min, char novo_descricao[]);
Evento* cancelar_evento(Fila *fila, int dia, int mes, int ano, int hora, int min);
void agendar_evento_ordenado(Fila *fila,int dia, int mes, int ano, int hora, int min, char descricao[], char prioridade[]);

#endif