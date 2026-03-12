/**-------------------------------------------*
* -Nome: Gustavo Silva De Moura - RA:2040482522023
  -Fatec Ipiranga - Ads Vespertino 
  -Atividade PEM - Aula 4 - Dia 02/03/2025
  -Objetivo: Produção de um algoritmo em liguagem de programação
  estruturada, aplicando conceitos de manipulação de matrizes
  multidimensionais, estruturas de repetição, condicionais 
  e controle de fluxo. Para isso deve implementar um simulador do 
  jogo da velha para 2 jogadores (X e O)*           
  *-------------------------------------------*/

#include <stdio.h>// biblioteca para entrada e saída de dados

#define TAM 3 // Define o tamanho do tabuleiro

char tabuleiro[TAM][TAM]; // matriz para representar o tabuleiro
char jogador = 'X'; // variável para indicar o jogador atual
int vencedor = 0;// variável para indicar se há um vencedor
int jogadas = 0;// variável para contar o número de jogadas

void inicializarTabuleiro() {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';// inicializa cada posição do tabuleiro com um espaço em branco, indicando que está vazia
        }
    }
} // função para inicializar o tabuleiro com espaços em branco

void mostrarTabuleiro() {
    printf("\n");

    for(int i = 0; i < TAM; i++) {// percorre cada linha do tabuleiro

        printf(" %c | %c | %c ", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        // exibe o estado atual do tabuleiro, mostrando os símbolos dos jogadores nas posições correspondentes
        if(i < TAM-1)
            printf("\n---+---+---\n");// exibe uma linha de separação entre as linhas do tabuleiro, exceto após a última linha
    }

    printf("\n\n");
}// função para mostrar o estado atual do tabuleiro

int verificarVitoria() {// função para verificar se o jogador atual venceu o jogo

    // linhas
    for(int i = 0; i < TAM; i++) {
        if(tabuleiro[i][0] == jogador &&
           tabuleiro[i][1] == jogador &&
           tabuleiro[i][2] == jogador)
            return 1;
    } // verifica se o jogador atual venceu por completar uma linha

    // colunas
    for(int j = 0; j < TAM; j++) {
        if(tabuleiro[0][j] == jogador &&
           tabuleiro[1][j] == jogador &&
           tabuleiro[2][j] == jogador)
            return 1;
    } // verifica se o jogador atual venceu por completar uma coluna

    // diagonal principal
    if(tabuleiro[0][0] == jogador &&
       tabuleiro[1][1] == jogador &&
       tabuleiro[2][2] == jogador)
        return 1; // verifica se o jogador atual venceu por completar a diagonal principal

    // diagonal secundaria
    if(tabuleiro[0][2] == jogador &&
       tabuleiro[1][1] == jogador &&
       tabuleiro[2][0] == jogador)
        return 1; // verifica se o jogador atual venceu por completar a diagonal secundária

    return 0;
}

void trocarJogador() {
    if(jogador == 'X')
        jogador = 'O';
    else
        jogador = 'X';
}// função para alternar entre os jogadores X e O

int main() {

    int linha, coluna; // variáveis para armazenar a linha e coluna escolhidas pelo jogador

    inicializarTabuleiro();// chama a função para inicializar o tabuleiro antes de começar o jogo

    while(!vencedor && jogadas < 9) {// loop principal do jogo, onde os jogadores fazem suas jogadas até que haja um vencedor ou o tabuleiro esteja cheio

        mostrarTabuleiro(); // mostra o estado atual do tabuleiro antes de cada jogada

        printf("Jogador %c\n", jogador);
        printf("Digite linha (0-2): ");
        scanf("%d", &linha); // solicita ao jogador que digite a linha onde deseja jogar

        printf("Digite coluna (0-2): ");
        scanf("%d", &coluna); // solicita ao jogador que digite a coluna onde deseja jogar

        if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Posicao invalida!\n");
            continue;// verifica se a posição digitada é válida (entre 0 e 2 para linha e coluna)
        }

        if(tabuleiro[linha][coluna] != ' ') {
            printf("Posicao ocupada! Tente novamente.\n");
            continue; // verifica se a posição escolhida já está ocupada por outro jogador,
        }             // caso esteja, solicita que o jogador tente novamente

        tabuleiro[linha][coluna] = jogador;
        jogadas++;// registra a jogada do jogador atual no tabuleiro e incrementa o contador de jogadas

        if(verificarVitoria()) {// verifica se o jogador atual venceu após fazer sua jogada
            vencedor = 1;
        } else {
            trocarJogador();// se não houver vencedor, alterna para o próximo jogador
        }
    }

    mostrarTabuleiro();

    if(vencedor) {
        printf("O jogador %c venceu!\n", jogador);// exibe a mensagem de vitória para o jogador vencedor
    } else {
        printf("O jogo terminou em empate!\n");// se não houver vencedor e o número de jogadas atingir 9, o jogo termina em empate
    }

    return 0;// encerra o programa
}