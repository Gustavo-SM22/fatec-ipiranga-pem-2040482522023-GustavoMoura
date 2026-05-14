/*-----------------------------------------------------------*
 *                      FATEC Ipiranga                       *
 * Disciplina: Programacao Estruturada e Modular             *
 *          Prof. Verissimo                                  *
 *-----------------------------------------------------------*
 * Nome: Gustavo Silva De Moura - RA:2040482522023           *
 * Objetivo: Explorar a Modularização através da criação de  *
 * bibliotecas personalizadas (arquivos .h e .c ) e a        *
 * aplicação de Recursividade para a resolução de            *
 * problemas matemáticos,garantindo a separação entre        *
 * lógica de processamento e interface de usuário.           *
 *                                                           *
 * Data - 08/05/2026                                         *
 *-----------------------------------------------------------*/
#include <stdio.h>
#include "recursao.h"
#include "interface.h"

/* Função responsável por exibir o menu
e chamar as funções escolhidas pelo usuário*/
void interface(){

    /* Variável que armazena a escolha do usuário */
    int escolha;

    /* Loop para repetir o menu enquanto a opção for inválida */
    do {

        /* Exibe o menu de opções */
        printf("escolha umas dessas funcoes:\n\n1-converter para binario(ex 10: 1010)\n2-fazer potencia de 2 numeros(ex 10, 2: 100)\n3-somar digitos(ex: 123 = 6)\n\n");

        /* Lê a opção escolhida */
        scan(&escolha);

    /* Estrutura de decisão para cada opção */
    switch(escolha){

        /* Opção 1: converter decimal para binário */
        case 1:{

            /* Variável para armazenar o número digitado */
            int numeroBinario;

            /* Solicita o número ao usuário */
            printf("escolha um numero para ser convertido para binario: ");

            /* Lê o número */
            scan(&numeroBinario);

            /* Exibe mensagem de resultado */
            printf("o resultado do numero %d em binario e: ", numeroBinario);

            /* Chama a função de conversão */
            decToBin(numeroBinario);

            break;
        }

        /* Opção 2: calcular potência */
        case 2:{

            /* Variáveis para base e expoente */
            int n, expoente;

            /* Solicita os valores ao usuário */
            printf("escolha respectivamente um numero e um expoente: ");

            /* Lê a base */
            scan(&n);

            /* Lê o expoente */
            scan(&expoente);

            /* Exibe o resultado da potência */
            printf("o numero %d elevado a %d e igual a: %d",
                   n, expoente, potencia(n,expoente));

            break;
        }

        /* Opção 3: somar os dígitos de um número */
        case 3:{

            /* Variável para armazenar o número */
            int numeroSoma;

            /* Solicita o número ao usuário */
            printf("escolha um numero para os digitos serem somados: ");

            /* Lê o número */
            scan(&numeroSoma);

            /* Exibe o resultado da soma dos dígitos */
            printf("a soma do numero dado e igual a: %d",
                   somaDigitos(numeroSoma));

            break;
        }

        /* Caso o usuário digite uma opção inválida */
        default:

            /* Exibe mensagem de erro e repete o menu */
            printf("escolha um valor valido!\n\n");

            break;
    }

    /* Repete enquanto a opção for inválida (fora de 1, 2 ou 3) */
    } while (escolha < 1 || escolha > 3);

    return;
}

 /* Função para ler um número inteiro usando ponteiro */
void scan(int *n){

    /* Lê um valor inteiro e armazena
       no endereço apontado por n */
    scanf("%d", n);

    return;
}
