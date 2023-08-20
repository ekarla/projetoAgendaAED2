/*
Projeto Agenda com Prioridade
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/agendador.h"


void criar_agenda(Fila *fila){
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}
void agendar_evento(Fila *fila,int dia, int mes, int ano, int hora, int min, char descricao[], char prioridade[]){

    Evento *aux, *novo=malloc(sizeof(Evento));
    if(novo){
        novo->dia=dia;
        novo->mes=mes;
        novo->ano=ano;
        novo->hora=hora;
        novo->min=min;
        strcpy(novo->descricao,descricao);
        strcpy(novo->prioridade,prioridade);
        novo->prox=NULL;
        if(fila->prim == NULL){
            fila->prim = novo;
            fila->fim = novo;
            
        }  
        else{
            fila->fim->prox = novo;
            fila->fim = novo;           
        }
        fila->tamanho++;
    }
    else
        printf("\nErro ao alocar memoria.\n");
}



Evento* proximo_evento(Fila *fila){
    Evento *proximo = NULL;
    if(fila->prim){
        proximo = fila->prim;
    } 
    return proximo;
}

Evento* concluir_evento(Fila *fila){
    Evento *remover = NULL;
    if(fila->prim){
        remover = fila->prim;
        fila->prim = remover->prox;
        fila->tamanho--;
    }    
    return remover;
}

Evento* cancelar_evento(Fila *fila, int dia, int mes, int ano, int hora, int min){
    Evento *aux, *remover = NULL;
    if(fila->prim){
        if(fila->prim->dia == dia && fila->prim->mes == mes && fila->prim->ano == ano && fila->prim->hora == hora && fila->prim->min == min)
        remover = fila->prim;
        fila->prim = remover->prox;
        fila->tamanho--;
    }
    else{
        aux = fila->prim;
        while (aux->prox)
        {
            if(aux->prox->dia == dia && aux->prox->mes == mes && aux->prox->ano == ano && aux->prox->hora == hora && aux->prox->min == min)
                remover = aux->prox;
                aux->prox = remover->prox;
                fila->tamanho--;
            aux = aux->prox;
        }        
    }  
    return remover;
}

void alterar_evento(Fila *fila, int dia, int mes, int ano, int hora, int min, int novo_dia, int novo_mes, int novo_ano, int novo_hora, int novo_min, char novo_descricao[]){
    Evento *aux = NULL;
    aux = buscar_evento(fila, dia, mes, ano, hora, min);
    if(aux)
        aux->dia = novo_dia;
        aux->mes = novo_mes;
        aux->ano = novo_ano;
        aux->hora = novo_hora;
        aux->min = novo_min;
        strcpy(aux->descricao, novo_descricao);
        printf("Evento alterado!");
}

void immprimir_fila(Fila *fila){
    Evento *aux = fila->prim;
    while (aux)
    {
        printf("Evento: %02d/%02d/%d %02d:%02d %s %s\n", aux->dia, aux->mes, aux->ano, aux->hora, aux->min,aux->descricao, aux->prioridade);
        aux = aux->prox;
    }   
}

Evento* buscar_evento(Fila *fila, int dia, int mes, int ano, int hora, int min){
    Evento *aux, *no = NULL;
    aux = fila->prim;
    while (aux)
    {
        if(aux->dia == dia && aux->mes == mes && aux->ano == ano && aux->hora == hora && aux->min == min)
            no = aux;
        aux = aux->prox;
    }
    return no;
}



int quantificar_evento(Fila *fila){
    return fila->tamanho;
}

