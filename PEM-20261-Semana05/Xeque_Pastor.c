/**-------------------------------------------*
* -Nome: Gustavo Silva De Moura - RA:2040482522023
  -Fatec Ipiranga - Ads Vespertino 
  -Atividade PEM - Aula 5 - Dia 13/03/2025
  -Objetivo: O objetivo desta atividade prática de modularização de uma solução software.
   Adicionalmente objetiva consolidar a manipulação de matrizes multidimensionais*           
  *-------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define TAM 8 //Define o Tamanho do tabuleiro de xadrez (8x8) em 8

//Função para pausar o programa e esperar o usuário pressionar ENTER para avançar para a próxima jogada
void avancar() {
    printf("\nPressione ENTER para Avançar para próxima jogada.");
    getchar();
}

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAM][TAM][4]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            strcpy(tabuleiro[i][j], "...");// Inicializa todas as posições do tabuleiro com "..." para indicar que estão vazias
        }
    }

    /*Peças brancas
    PB = Peão Branco, TB = Torre Branca, CB = Cavalo Branco, BB = Bispo Branco, DB = Dama Branca, RB = Rei Branco*/
    strcpy(tabuleiro[6][0], "PB1"); strcpy(tabuleiro[6][1], "PB2");//Inicializa os peões brancos na linha 6 e colunas de 0 a 7
    strcpy(tabuleiro[6][2], "PB3"); strcpy(tabuleiro[6][3], "PB4");
    strcpy(tabuleiro[6][4], "PB5"); strcpy(tabuleiro[6][5], "PB6");
    strcpy(tabuleiro[6][6], "PB7"); strcpy(tabuleiro[6][7], "PB8");

    strcpy(tabuleiro[7][0], "TB1"); strcpy(tabuleiro[7][7], "TB8");//Inicializa as torres brancas nas colunas 0 e 7 da linha 7
    strcpy(tabuleiro[7][1], "CB2"); strcpy(tabuleiro[7][6], "CB7");//Inicializa os cavalos brancos nas colunas 1 e 6 da linha 7
    strcpy(tabuleiro[7][2], "BB3"); strcpy(tabuleiro[7][5], "BB6");//Inicializa os bispos brancos nas colunas 2 e 5 da linha 7
    strcpy(tabuleiro[7][3], "DB4");//Inicializa a dama branca na coluna 3 da linha 7
    strcpy(tabuleiro[7][4], "RB5");//Inicializa o rei branco na coluna 4 da linha 7

    /*Peças pretas
     PP = Peão Preto, TP = Torre Preta, CP = Cavalo Preto, BP = Bispo Preto, DP = Dama Preta, RP = Rei Preto*/
    strcpy(tabuleiro[1][0], "PP1"); strcpy(tabuleiro[1][1], "PP2");
    strcpy(tabuleiro[1][2], "PP3"); strcpy(tabuleiro[1][3], "PP4");
    strcpy(tabuleiro[1][4], "PP5"); strcpy(tabuleiro[1][5], "PP6");
    strcpy(tabuleiro[1][6], "PP7"); strcpy(tabuleiro[1][7], "PP8");//Inicializa os peões pretos na linha 1 e colunas de 0 a 7

    strcpy(tabuleiro[0][0], "TP1"); strcpy(tabuleiro[0][7], "TP8");//Inicializa as torres pretas nas colunas 0 e 7 da linha 0
    strcpy(tabuleiro[0][1], "CP2"); strcpy(tabuleiro[0][6], "CP7");//Inicializa os cavalos pretos nas colunas 1 e 6 da linha 0
    strcpy(tabuleiro[0][2], "BP3"); strcpy(tabuleiro[0][5], "BP6");//Inicializa os bispos pretos nas colunas 2 e 5 da linha 0
    strcpy(tabuleiro[0][3], "DP4");//Inicializa a dama preta na coluna 3 da linha 0
    strcpy(tabuleiro[0][4], "RP5");//Inicializa o rei preto na coluna 4 da linha 0
}

// Função para mostrar o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAM][TAM][4]) {
    printf("\n   A   B   C   D   E   F   G   H\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAM; j++) {
            printf("%s ", tabuleiro[i][j]);
        }// Imprime o conteúdo de cada posição do tabuleiro, mostrando as peças ou "..." para posições vazias
        printf("\n");
    }
}

// Função para mover as peça
void mover(char tabuleiro[TAM][TAM][4], int oi, int oj, int di, int dj) {
    strcpy(tabuleiro[di][dj], tabuleiro[oi][oj]);
    strcpy(tabuleiro[oi][oj], "...");// Move a peça da posição original (oi, oj) para a posição de destino (di, dj) e marca a posição original como vazia ("...")
}

//Função da jogada 1
void jogada1(char tabuleiro[TAM][TAM][4]) {
    printf("\n=== Jogada 1 ===\n");

    printf("=== Brancas: PB5 de e2 para e4 ===\n");
    mover(tabuleiro, 6, 4, 4, 4);// Mover o peão branco de e2 para e4

    printf("=== Pretas: PP5 de e7 para e5 ===\n");
    mover(tabuleiro, 1, 4, 3, 4);// Mover o peão preto de e7 para e5

    mostrarTabuleiro(tabuleiro);
    avancar();
}

// Função da jogada 2
void jogada2(char tabuleiro[TAM][TAM][4]) {
    printf("\n=== Jogada 2 ===\n");

    printf("=== Brancas: BB6 de f1 para c4 ===\n");
    mover(tabuleiro, 7, 5, 4, 2);// Mover o bispo branco de f1 para c4

    printf("=== Pretas: CP2 de b8 para c6 ===\n");
    mover(tabuleiro, 0, 1, 2, 2);// Mover o cavalo preto de b8 para c6

    mostrarTabuleiro(tabuleiro);
    avancar();
}

// Função da jogada 3
void jogada3(char tabuleiro[TAM][TAM][4]) {
    printf("\n=== Jogada 3 ===\n");

    printf("=== Brancas: DB4 de d1 para h5 ===\n");
    mover(tabuleiro, 7, 3, 3, 7);// Mover a dama branca de d1 para h5

    printf("=== Pretas: CP7 de g8 para f6 ===\n");
    mover(tabuleiro, 0, 6, 2, 5);// Mover o cavalo preto de g8 para f6

    mostrarTabuleiro(tabuleiro);
    avancar();
}

//Função da jogada 4
void jogada4(char tabuleiro[TAM][TAM][4]) {
    printf("\n=== Jogada 4 (XEQUE-MATE) ===\n");

    printf("=== Brancas: Capturam Peao PP6 em f7 e (xeque-mate) ===\n");
    mover(tabuleiro, 3, 7, 1, 5);// Mover a dama branca de h5 para f7, capturando o peão preto e dando xeque-mate

    mostrarTabuleiro(tabuleiro);
    avancar();
}

int main() {
    char tabuleiro[TAM][TAM][4];// Tabuleiro de xadrez representado como uma matriz 3D (8x8x4) para armazenar as peças

    inicializarTabuleiro(tabuleiro);// Inicializar o tabuleiro com as peças nas posições iniciais
    mostrarTabuleiro(tabuleiro);// Mostrar o tabuleiro inicial

    avancar();

    jogada1(tabuleiro);// Executar a jogada 1
    jogada2(tabuleiro);// Executar a jogada 2
    jogada3(tabuleiro);// Executar a jogada 3
    jogada4(tabuleiro);// Executar a jogada 4 (xeque-mate)

    return 0;
}