/**-------------------------------------------*
* -Nome: Gustavo Silva De Moura - RA:2040482522023
  -Fatec Ipiranga - Ads Vespertino 
  -Atividade PEM - Aula 3 - Dia 27/02/2025
  -Objetivo: Desenvolva um programa de cadastro de produtos utilizando a linguagem C. O programa
deve gerenciar um array de nomes de produtos (strings).*           
  *-------------------------------------------*/
#include <stdio.h>
#include <string.h>

struct Produto{
    int idProduto;
    char nomeProduto[50];
};

int main() {
    struct Produto listaProduto[10]; // agora é vetor de struct
    int total = 0;
    int opcao, id, i, posicao;

    do {
        printf("\n----- MENU CRUD ------\n");
        printf("1 - Inclusao\n");
        printf("2 - Consulta\n");
        printf("3 - Alteracao\n");
        printf("4 - Exclusao\n");
        printf("5 - Listar todos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if(total < 10) {
                    printf("Digite o ID do produto: ");
                    scanf("%d", &listaProduto[total].idProduto);

                    printf("Digite o nome do produto: ");
                    scanf(" %[^\n]", listaProduto[total].nomeProduto);

                    total++;
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("Lista cheia!\n");
                }
                break;

            case 2:
                printf("Digite o ID para consultar: ");
                scanf("%d", &id);
                posicao = -1;

                for(i = 0; i < total; i++) {
                    if(listaProduto[i].idProduto == id) {
                        posicao = i;
                        break;
                    }
                }

                if(posicao != -1)
                    printf("Produto encontrado: ID: %d | Nome: %s\n",
                           listaProduto[posicao].idProduto,
                           listaProduto[posicao].nomeProduto);
                else
                    printf("Produto nao encontrado.\n");
                break;

            case 3:
                printf("Digite o ID para alterar: ");
                scanf("%d", &id);
                posicao = -1;

                for(i = 0; i < total; i++) {
                    if(listaProduto[i].idProduto == id) {
                        posicao = i;
                        break;
                    }
                }

                if(posicao != -1) {
                    printf("Digite o novo ID: ");
                    scanf("%d", &listaProduto[posicao].idProduto);

                    printf("Digite o novo nome: ");
                    scanf(" %[^\n]", listaProduto[posicao].nomeProduto);

                    printf("Produto alterado com sucesso!\n");
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;

            case 4:
                printf("Digite o ID para excluir: ");
                scanf("%d", &id);
                posicao = -1;

                for(i = 0; i < total; i++) {
                    if(listaProduto[i].idProduto == id) {
                        posicao = i;
                        break;
                    }
                }

                if(posicao != -1) {
                    for(i = posicao; i < total - 1; i++) {
                        listaProduto[i] = listaProduto[i + 1];
                    }
                    total--;
                    printf("Produto removido com sucesso!\n");
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;

            case 5:
                if(total == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    printf("Lista de produtos:\n");
                    for(i = 0; i < total; i++) {
                        printf("Posicao %d -> ID: %d | Nome: %s\n",
                               i+1,
                               listaProduto[i].idProduto,
                               listaProduto[i].nomeProduto);
                    }
                }
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}