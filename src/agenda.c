#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/agendador.h"

int main(){
    Evento *evento;
    Fila fila ;
    int dia, mes, ano, hora, min,opcao;
    int novo_dia, novo_mes, novo_ano, novo_hora, novo_min;
    char novo_descricao[140];
    char descricao[140];
    char prioridade[6];

    criar_agenda(&fila);
    printf("XXXXXXXXXXXXXXXXX PROJETO AGENDA - AED2 2023 XXXXXXXXXXXXXXXXXX ");
    printf("\n 1 - AGENDAR ");
    printf("\n 2 - QUANTIFICAR ");
    printf("\n 3 - EVENTO EMINENTE ");
    printf("\n 4 - ALTERAR ");
    printf("\n 5 - CANCELAR ");
    printf("\n 6 - CONCLUIR ");
    printf("\n -1 - SAIR \n");
    do{
        
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            scanf("%d/%d/%d",&dia,&mes,&ano);
            scanf("%d:%d",&hora,&min);
            scanf("%s", descricao);
            scanf("%s", prioridade);
            agendar_evento_ordenado(&fila, dia, mes, ano, hora, min,descricao,prioridade);
            break;
        case 2:
            printf("%d\n", quantificar_evento(&fila));
            break;
        case 3:
            evento = proximo_evento(&fila);
            if(evento){
                printf("Evento: %02d/%02d/%d %02d:%02d %s %s\n", evento->dia, evento->mes, evento->ano, evento->hora, evento->min,evento->descricao, evento->prioridade);               
            }
            break;
        case 4:
            scanf("%d/%d/%d",&dia,&mes,&ano);
            scanf("%d:%d",&hora,&min);
            scanf("%d/%d/%d",&novo_dia,&novo_mes,&novo_ano);
            scanf("%d:%d",&novo_hora,&novo_min);
            scanf("%s", novo_descricao);
            alterar_evento(&fila, dia, mes,ano, hora, min, novo_dia, novo_mes, novo_ano, novo_hora, novo_min, novo_descricao);
            break;
        case 5:
            scanf("%d/%d/%d",&dia,&mes,&ano);
            scanf("%d:%d",&hora,&min);
            evento = cancelar_evento(&fila, dia, mes, ano, hora, min);
            if(evento){
              printf("Evento: %02d/%02d/%d %02d:%02d %s %s\n", evento->dia, evento->mes, evento->ano, evento->hora, evento->min,evento->descricao, evento->prioridade);
              free(evento);
            }
            else
                printf("Evento não existe!!") ;
            break;
        case 6:
            evento = concluir_evento(&fila);
            if(evento){
                printf("Evento: %02d/%02d/%d %02d:%02d %s %s\n", evento->dia, evento->mes, evento->ano, evento->hora, evento->min,evento->descricao, evento->prioridade);
                free(evento);
            }
            break;
        case 7:
            immprimir_fila(&fila);
            break;
        }
    }while (opcao != -1);

    return 0;    

}

