#include <stdio.h>

// Protótipos das funções que serão usadas no Nível Mestre
void moverTorreRecursivo(int passos);
void moverRainhaRecursivo(int passos);
void moverBispoRecursivo(int passos);

// Constantes para definir o número de movimentos de cada peça
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

// Função principal onde o programa executa
int main() {
    printf("==============================================\n");
    printf("     Desafio de Xadrez - MateCheck\n");
    printf("==============================================\n\n");

    printf("----------------------------------------------\n");
    printf("               NIVEL NOVATO\n");
    printf("----------------------------------------------\n");

    // Movimentação da Torre com loop 'while'
    printf("\n--> Movimentando a Torre (5 casas para a direita):\n");
    int contador_torre = 0; // Variável de controle do loop
    while (contador_torre < MOV_TORRE) {
        printf("Direita\n");
        contador_torre++; // Incrementa para evitar loop infinito
    }

    // Movimentação da Rainha com loop 'do-while'
    printf("\n--> Movimentando a Rainha (8 casas para a esquerda):\n");
    int contador_rainha = 0;
    do {
        printf("Esquerda\n");
        contador_rainha++;
    } while (contador_rainha < MOV_RAINHA); // Condição é checada no final

    // Movimentação do Bispo com loop 'for'
    printf("\n--> Movimentando o Bispo (5 casas na diagonal superior direita):\n");
    for (int i = 0; i < MOV_BISPO; i++) {
        // A diagonal é simulada com um movimento para Cima e um para Direita
        printf("Cima + Direita (passo %d)\n", i + 1);
    }

    printf("\n\n----------------------------------------------\n");
    printf("             NIVEL AVENTUREIRO\n");
    printf("----------------------------------------------\n");

    // Movimentação do Cavalo em 'L' com loops aninhados
    printf("\n--> Movimentando o Cavalo em L (2x Baixo, 1x Esquerda):\n");
    // O loop externo roda uma vez para executar a sequência do movimento 'L'
    for (int mov_l = 0; mov_l < 1; mov_l++) {
        // Loop aninhado (while) para os 2 passos verticais
        int passos_baixo = 0;
        while(passos_baixo < 2) {
            printf("Baixo\n");
            passos_baixo++;
        }
        // Loop aninhado (for) para o passo horizontal
        for (int passos_esquerda = 0; passos_esquerda < 1; passos_esquerda++) {
            printf("Esquerda\n");
        }
    }

    printf("\n\n----------------------------------------------\n");
    printf("               NIVEL MESTRE\n");
    printf("----------------------------------------------\n");

    // Movimentação das peças usando funções recursivas
    printf("\n--> Movendo a Torre com Funcao Recursiva:\n");
    moverTorreRecursivo(MOV_TORRE);

    printf("\n--> Movendo a Rainha com Funcao Recursiva:\n");
    moverRainhaRecursivo(MOV_RAINHA);

    printf("\n--> Movendo o Bispo com Funcao Recursiva e Loop Aninhado:\n");
    moverBispoRecursivo(MOV_BISPO);

    // Movimentação do Cavalo com um loop 'for' avançado
    printf("\n--> Movendo o Cavalo em L (Cima, Direita) com loop avancado:\n");
    // Este loop usa múltiplas variáveis e condições para controlar o movimento
    for (int passo_cima = 0, passo_direita = 0; passo_cima < 2 || passo_direita < 1; ) {
        if (passo_cima < 2) {
            passo_cima++;
            // Demonstração do 'continue': pula o resto do código nesta iteração
            if (passo_cima == 2) {
                printf("Cima (passo 2) -> (usando continue para pular a impressão do passo)\n");
                continue; 
            }
            printf("Cima (passo %d)\n", passo_cima);
        } else if (passo_direita < 1) {
            passo_direita++;
            printf("Direita (passo %d)\n", passo_direita);
        }

        // Demonstração do 'break': uma condição de segurança para sair do loop
        if (passo_cima > 2 && passo_direita > 1) {
            printf("Erro inesperado, saindo do loop com break!\n");
            break; 
        }
    }

    printf("\n\n==============================================\n");
    printf("          Desafio Concluido!\n");
    printf("==============================================\n");

    return 0; // Indica que o programa terminou com sucesso
}


//----------------------------------------------
//   Implementação das Funções Recursivas
//----------------------------------------------

// Move a Torre para a direita usando recursão
void moverTorreRecursivo(int passos) {
    // Caso base: condição de parada para evitar recursão infinita
    if (passos <= 0) {
        return;
    }
    printf("Direita\n");
    // Chamada recursiva: a função chama a si mesma com um passo a menos
    moverTorreRecursivo(passos - 1);
}

// Move a Rainha para a esquerda usando recursão
void moverRainhaRecursivo(int passos) {
    // Caso base
    if (passos <= 0) {
        return;
    }
    printf("Esquerda\n");
    // Chamada recursiva
    moverRainhaRecursivo(passos - 1);
}

// Move o Bispo na diagonal usando recursão e um loop interno
void moverBispoRecursivo(int passos) {
    // Caso base
    if (passos <= 0) {
        return;
    }
    
    // Loop interno para cumprir o requisito de 'loop aninhado' do desafio
    for(int i = 0; i < 1; i++) {
        printf("Cima + Direita (recursivo, passo %d)\n", MOV_BISPO - passos + 1);
    }
    
    // Chamada recursiva
    moverBispoRecursivo(passos - 1);
}