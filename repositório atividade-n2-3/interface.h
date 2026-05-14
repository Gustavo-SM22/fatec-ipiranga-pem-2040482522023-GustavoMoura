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

/*Evita que o arquivo de interface
 seja incluído mais de uma vez */
#ifndef INTERFACE_H
#define INTERFACE_H

/*função responsável pela interface/menu do programa*/
void interface();

/* Função para ler um número inteiro usando ponteiro */
void scan(int *n);

/* Finaliza a diretiva de proteção */
#endif
