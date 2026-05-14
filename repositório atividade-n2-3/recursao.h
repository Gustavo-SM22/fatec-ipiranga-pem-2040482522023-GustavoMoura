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
#ifndef RECURSAO_H
#define RECURSAO_H

/* Converte um número decimal para binário (exibição via pilha recursiva) */
void decToBin(int n);

/* Calcula a potência de um número (exp >= 0) */
int potencia(int base, int exp);

/* Soma todos os algarismos de um número inteiro (ex: 123 = 6) */
int somaDigitos(int n);

#endif
