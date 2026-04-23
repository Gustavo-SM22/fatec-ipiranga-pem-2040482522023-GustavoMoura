 /*
 * ------------------------------------------------------------
 *  Nome: Gustavo Silva De Moura - RA:2040482522023
 *  Fatec Ipiranga - Ads Vespertino - Dia 17/04/2025
 *  Atividade: Semana 08 - Gestao de Carga em Logistica
 *             (Ponteiros e Vetores).
 *             Sistema de calibracao de pesos de pacotes para
 *             uma transportadora digital. Utiliza ponteiros
 *             para manipulacao direta de memoria.
 * 
 * ------------------------------------------------------------
 */

#include <stdio.h>

#define TAMANHO 10     
#define CORRECAO 0.95f  
#define LIMITE   1.10f  

void processarCarga(float *ptr_vetor, int n);

void exibirVetor(float *ptr_vetor, int n, const char *titulo) { 
    printf("\n--- %s ---\n", titulo);
    for (int i = 0; i < n; i++) {
       
        printf("  Pacote [%02d]: %.2f kg\n", i + 1, *(ptr_vetor + i));
    }
}

void processarCarga(float *ptr_vetor, int n) { 
    float soma  = 0.0f;
    float media = 0.0f;
    float limiteSuperior;
    int   correcoesAplicadas = 0;

    for (int i = 0; i < n; i++) {
        soma += *(ptr_vetor + i);   
    }
    media = soma / n;
    limiteSuperior = media * LIMITE;

    printf("\n  Media do lote          : %.2f kg", media);
    printf("\n  Limite superior (+10%%) : %.2f kg\n", limiteSuperior);

    printf("\n  Verifição de excedentes\n");

    for (int i = 0; i < n; i++) {
        float *p = ptr_vetor + i;   

        if (*p > limiteSuperior) {
            printf("  [!] Pacote [%02d]: %.2f kg excede o limite"
                   " -> corrigido para ", i + 1, *p);

            *p = *p * CORRECAO;     

            printf("%.2f kg\n", *p);
            correcoesAplicadas++;
        }
    }

    if (correcoesAplicadas == 0) {
        printf("  Nenhum pacote excedeu o limite. Sem correcoes.\n");
    } else {
        printf("\n  Total de correcoes aplicadas: %d\n", correcoesAplicadas);
    }
}

int main(void) {
    
    float pesos[TAMANHO] = {
        12.5f, 30.0f, 8.0f, 27.3f, 15.0f,
        33.1f, 10.4f, 28.9f, 9.7f, 22.0f
    };

    printf("  SISTEMA DE GESTAO DE CARGA - LOGISTICA\n");

    exibirVetor(pesos, TAMANHO, "PESOS ANTES DO PROCESSAMENTO");

    processarCarga(pesos, TAMANHO);

    exibirVetor(pesos, TAMANHO, "PESOS APOS O PROCESSAMENTO");

    printf("  Processamento concluido.\n");

    return 0;
}
