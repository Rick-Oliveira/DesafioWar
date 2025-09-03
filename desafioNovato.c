#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-- Constantes GLOBAIS

#define MAX_STRINGS 50


//-- Criando STRUCT
struct territorio{
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//-- Funcao Principal Main
int main(){
    struct territorio biblioteca[MAX_STRINGS];
    int totalTerritorio = 0;

    // -- Laço principal do menu
    do{
         // Exibe o menu de cadastro
        printf("\n======================================\n");
        printf("  WAR ESTRUTURADO - CADASTRO INICIAL  ");
        printf("\n======================================\n");
        printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n\n");
        for ( totalTerritorio = 0; totalTerritorio <= 4; totalTerritorio++ ){

            printf("--- Cadastrando territorio %d ---\n", totalTerritorio + 1);
            printf("Nome do territorio: ");
            fgets(biblioteca[totalTerritorio].nome, MAX_STRINGS, stdin);

            printf("Cor do exercito (ex: Azul, Verde): ");
            fgets(biblioteca[totalTerritorio].cor, MAX_STRINGS, stdin);

            biblioteca[totalTerritorio].nome[strcspn(biblioteca[totalTerritorio].nome, "\n")];
            biblioteca[totalTerritorio].cor[strcspn(biblioteca[totalTerritorio].cor, "\n")];

            printf("Numero de tropas: ");
            scanf("%d", &biblioteca[totalTerritorio].tropas);
            printf("\n");
            limparBufferEntrada(); // Limpa  o 'n' deixado pelo scanf.


        }; 

        //LISTAGEM DE TERRITORIOS:

         printf("\n========================================\n");
         printf("     MAPA DO MUNDO - ESTADO ATUAL");
         printf("\n========================================\n");

         for (totalTerritorio = 0; totalTerritorio <= 4; totalTerritorio++) {
            printf("\n");
            printf("TERRITORIO %d:\n", totalTerritorio + 1);
            printf("- Nome: %s", biblioteca[totalTerritorio].nome);
            printf("- Dominado por: Exercito %s", biblioteca[totalTerritorio].cor);
            printf("- Tropas: %d\n", biblioteca[totalTerritorio].tropas);
            printf("\n");
         }; 

        printf("\nCadastro inicial feito com sucesso!\n");
    
    } while (totalTerritorio<=4); // Condição pra o programa seja executado!

    return 0; // Fim do programa
}