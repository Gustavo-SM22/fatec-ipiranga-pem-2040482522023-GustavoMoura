/*----------------------------------------------------------*
 *                      FATEC Ipiranga                       *
 * Disciplina: Programacao Estruturada e Modular             *
 *          Prof. Verissimo                                  *
 *-----------------------------------------------------------*
 * Nome: Gustavo Silva De Moura - RA:2040482522023           *
 * Objetivo: Busca em profundidade - Versao interativa       *
 * Codigo Interativo - Conversao de recursivo para iterativo *
 * Data - 24/04/2026                                         *
 *-----------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0
#define MAX_PILHA 200   

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

typedef struct {
    int index;         
    int nivel;          
    int filho_atual;    
    int pai_idx;        
} FramePilha;

Pasta drive[MAX_PASTAS];

void processarHierarquiaIterativo(int raiz, int limite_profundidade) {
    FramePilha pilha[MAX_PILHA];
    int topo = -1;

    topo++;
    pilha[topo].index       = raiz;
    pilha[topo].nivel       = 0;
    pilha[topo].filho_atual = 0;
    pilha[topo].pai_idx     = -1;

    drive[raiz].tamanho_total = drive[raiz].tamanho_proprio;

    while (topo >= 0) {
        FramePilha *frame = &pilha[topo];
        Pasta *pasta = &drive[frame->index];

        if (frame->nivel > limite_profundidade) {
            topo--;
            continue;
        }

        if (frame->filho_atual < pasta->qtd_sub) {
            int filho_idx = pasta->subpastas_indices[frame->filho_atual];
            frame->filho_atual++; 

            drive[filho_idx].tamanho_total = drive[filho_idx].tamanho_proprio;

            topo++;
            pilha[topo].index       = filho_idx;
            pilha[topo].nivel       = frame->nivel + 1;
            pilha[topo].filho_atual = 0;
            pilha[topo].pai_idx     = frame->index;

        } else {

            for (int i = 0; i < frame->nivel; i++) printf("  ");

            printf("|-- %s [%.2f GB]", pasta->nome, pasta->tamanho_total);

            if (pasta->tamanho_total > LIMITE_ALERTA) {
                printf(" [!] ALERTA: GARGALO DETECTADO");
            }
            printf("\n");

            if (frame->pai_idx != -1) {
                drive[frame->pai_idx].tamanho_total += pasta->tamanho_total;
            }

            topo--; 
        }
    }
}

int main() {
    strcpy(drive[0].nome, "RAIZ");
    drive[0].tamanho_proprio = 10.0f;
    drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1;
    drive[0].subpastas_indices[1] = 2;

    strcpy(drive[1].nome, "Projetos_TI");
    drive[1].tamanho_proprio = 50.0f;
    drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3;

    strcpy(drive[2].nome, "Backups_Antigos");
    drive[2].tamanho_proprio = 350.0f;
    drive[2].qtd_sub = 0;

    strcpy(drive[3].nome, "Videos_Aulas");
    drive[3].tamanho_proprio = 280.0f;
    drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE (ITERATIVO) ---\n");

    clock_t t;
    t = clock();

    processarHierarquiaIterativo(0, limite);
    
    t = clock() - t;
    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;

    printf("--------------------------------------------------------\n");
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("Ciclos de clock: %ld\n", (long)t);

    return 0;
}
