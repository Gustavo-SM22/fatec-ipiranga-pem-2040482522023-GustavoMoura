/*----------------------------------------------------------*
 *                      FATEC Ipiranga                       *
 * Disciplina: Programacao Estruturada e Modular             *
 *          Prof. Verissimo                                  *
 *-----------------------------------------------------------*
 * Nome: Gustavo Silva De Moura - RA:2040482522023           *
 * Objetivo: Busca em profundidade (Recursiva) com Ponteiros *
 * Codigo Ponteiros - Refatoracao com uso de ponteiros       *
 * Data - 24/04/2026                                         *
 *-----------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

float processarHierarquia(Pasta *drive_ptr, int index, int nivel_atual, int limite_profundidade) {
    if (index == -1 || nivel_atual > limite_profundidade) {
        return 0.0f;
    }

    Pasta *pasta_atual = &drive_ptr[index];

    pasta_atual->tamanho_total = pasta_atual->tamanho_proprio;

    for (int i = 0; i < pasta_atual->qtd_sub; i++) {
        int filho_idx = pasta_atual->subpastas_indices[i];
        pasta_atual->tamanho_total += processarHierarquia(drive_ptr, filho_idx, nivel_atual + 1, limite_profundidade);
    }

    for (int i = 0; i < nivel_atual; i++) printf("  ");

    printf("|-- %s [%.2f GB]", pasta_atual->nome, pasta_atual->tamanho_total);

    if (pasta_atual->tamanho_total > LIMITE_ALERTA) {
        printf(" [!] ALERTA: GARGALO DETECTADO");
    }
    printf("\n");

    return pasta_atual->tamanho_total;
}

int main() {
    Pasta *drive_ptr = drive;

    Pasta *p;

    p = &drive_ptr[0];
    strcpy(p->nome, "RAIZ");
    p->tamanho_proprio = 10.0f;
    p->qtd_sub = 2;
    p->subpastas_indices[0] = 1;
    p->subpastas_indices[1] = 2;

    p = &drive_ptr[1];
    strcpy(p->nome, "Projetos_TI");
    p->tamanho_proprio = 50.0f;
    p->qtd_sub = 1;
    p->subpastas_indices[0] = 3;

    p = &drive_ptr[2];
    strcpy(p->nome, "Backups_Antigos");
    p->tamanho_proprio = 350.0f;
    p->qtd_sub = 0;

    p = &drive_ptr[3];
    strcpy(p->nome, "Videos_Aulas");
    p->tamanho_proprio = 280.0f;
    p->qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE (COM PONTEIROS) ---\n");

    clock_t t;
    t = clock();

    processarHierarquia(drive_ptr, 0, 0, limite);

    t = clock() - t;
    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;

    printf("-----------------------------------------------------------\n");
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("Ciclos de clock: %ld\n", (long)t);

    return 0;
}
