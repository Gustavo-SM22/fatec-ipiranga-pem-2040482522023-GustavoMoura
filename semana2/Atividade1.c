// Nome: Gustavo Silva De Moura - RA:2040482522023
// Fatec Ipiranga - Ads Vespertino 
// Atividade PEM - Aula 2 - Dia 20/02/2025
// Criar um programa que calcular quantas palavras possui determinada frase.

#include <stdio.h>
#include <string.h>

int main () {
    char frase[200];
    int i = 0, palavras = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    while (frase[i] != '\0') {

        if ((frase[i] != ' ' && frase[i] != '\n') &&
            (i == 0 || frase[i-1] == ' ')) {
            palavras++;
        }

        i++;
    }

    printf("A frase possui %d palavras.\n", palavras);

    return 0;
}