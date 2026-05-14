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
/*
 * decToBin: Converte decimal para binário usando a pilha de chamadas
 * recursivas para exibir os bits na ordem correta (do mais significativo
 * para o menos significativo).
 */
void decToBin(int n) {
    if (n < 0) {
        printf("-");
        decToBin(-n);
        return;
    }
    if (n == 0) {
        return;
    }
    decToBin(n / 2);        /* processa os bits mais significativos primeiro */
    printf("%d", n % 2);    /* imprime o bit atual ao retornar da recursão */
}

/*
 * potencia: Calcula base^exp de forma recursiva.
 * Caso base: qualquer número elevado a 0 é 1.
 */
int potencia(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * potencia(base, exp - 1);
}

/*
 * somaDigitos: Soma todos os algarismos de n.
 * Trabalha com valor absoluto para suportar negativos.
 * Caso base: número de um só dígito retorna ele mesmo.
 */
int somaDigitos(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        return n;
    }
    return (n % 10) + somaDigitos(n / 10);
}

