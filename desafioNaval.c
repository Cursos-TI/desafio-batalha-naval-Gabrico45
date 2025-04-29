#include <stdio.h>
#include <stdlib.h>

#define LINHA 10 
#define COLUNA 10
#define TAM_HAB 5 // Tamanho da matriz da habilidade (5x5)

// Função para exibir o tabuleiro |  Lembrando que tive que alterar a agua de zero para '~' e navio virou 'N' tudo isso pra poder adicionar os poderes. 
void exibirTabuleiro(int tabuleiro[LINHA][COLUNA]) {
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
            else
                printf("? ");
        }
        printf("\n");
    }
}

// Função para aplicar habilidade
void aplicarHabilidade(int tabuleiro[LINHA][COLUNA], int origem_linha, int origem_coluna, char tipo) {
    int habilidade[TAM_HAB][TAM_HAB] = {0};
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            switch (tipo) {
                case 'c': // Cone
                    if (i >= j - centro && i >= centro - j && i <= centro)
                        habilidade[i][j] = 1;
                    break;
                case 'r': // Cruz
                    if (i == centro || j == centro)
                        habilidade[i][j] = 1;
                    break;
                case 'o': // Octaedro
                    if (abs(i - centro) + abs(j - centro) <= centro)
                        habilidade[i][j] = 1;
                    break;
            }
        }
    }
// Aqui eu pego cada célula da matriz de habilidade e calculo onde ela cai no tabuleiro, centralizada em (origem_linha, origem_coluna). | Verifica se está dentro dos limites do tabuleiro (para não acessar posições inválidas).
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origem_linha + i - centro;
            int colunaTab = origem_coluna + j - centro;

            if (linhaTab >= 0 && linhaTab < LINHA && colunaTab >= 0 && colunaTab < COLUNA) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[LINHA][COLUNA] = {0};
    int naV, naH;
    char direcao;

    printf("--- BATALHA NAVAL ---\n");
    printf("Escolha a posição do navio: 'h' para horizontal, 'v' para vertical, 'd' para diagonal direita ou 'e' para diagonal esquerda: ");
    scanf(" %c", &direcao);

    while (direcao != 'h' && direcao != 'v' && direcao != 'd' && direcao != 'e') {
        printf("Direção inválida. Digite 'h', 'v', 'd' ou 'e': ");
        scanf(" %c", &direcao);
    }

    if (direcao == 'v') {
        printf("Digite a linha do navio vertical (0 a %d): ", LINHA - 3);
        scanf("%d", &naV);
        while (naV < 0 || naV > LINHA - 3) {
            printf("Linha inválida. Digite novamente (0 a %d): ", LINHA - 3);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio vertical (0 a %d): ", COLUNA - 1);
        scanf("%d", &naH);
        while (naH < 0 || naH >= COLUNA) {
            printf("Coluna inválida. Digite novamente (0 a %d): ", COLUNA - 1);
            scanf("%d", &naH);
        }

        for (int i = 0; i < 3; i++)
            tabuleiro[naV + i][naH] = 3;
    } 
    else if (direcao == 'h') {
        printf("Digite a linha do navio horizontal (0 a %d): ", LINHA - 1);
        scanf("%d", &naV);
        while (naV < 0 || naV >= LINHA) {
            printf("Linha inválida. Digite novamente (0 a %d): ", LINHA - 1);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio horizontal (0 a %d): ", COLUNA - 3);
        scanf("%d", &naH);
        while (naH < 0 || naH > COLUNA - 3) {
            printf("Coluna inválida. Digite novamente (0 a %d): ", COLUNA - 3);
            scanf("%d", &naH);
        }

        for (int i = 0; i < 3; i++)
            tabuleiro[naV][naH + i] = 3;
    } 
    else if (direcao == 'd') {
        printf("Digite a linha do navio diagonal direita (0 a %d): ", LINHA - 3);
        scanf("%d", &naV);
        while (naV < 0 || naV > LINHA - 3) {
            printf("Linha inválida. Digite novamente (0 a %d): ", LINHA - 3);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio diagonal direita (0 a %d): ", COLUNA - 3);
        scanf("%d", &naH);
        while (naH < 0 || naH > COLUNA - 3) {
            printf("Coluna inválida. Digite novamente (0 a %d): ", COLUNA - 3);
            scanf("%d", &naH);
        }

        for (int i = 0; i < 3; i++)
            tabuleiro[naV + i][naH + i] = 3;
    } 
    else if (direcao == 'e') {
        printf("Digite a linha do navio diagonal esquerda (0 a %d): ", LINHA - 3);
        scanf("%d", &naV);
        while (naV < 0 || naV > LINHA - 3) {
            printf("Linha inválida. Digite novamente (0 a %d): ", LINHA - 3);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio diagonal esquerda (2 a %d): ", COLUNA - 1);
        scanf("%d", &naH);
        while (naH < 2 || naH > COLUNA - 1) {
            printf("Coluna inválida. Digite novamente (2 a %d): ", COLUNA - 1);
            scanf("%d", &naH);
        }

        for (int i = 0; i < 3; i++)
            tabuleiro[naV + i][naH - i] = 3;
    }

    // Exibir tabuleiro após navio
    exibirTabuleiro(tabuleiro);

    // Aplicar habilidade
    char tipoHab;
    int origem_linha, origem_coluna;

    printf("\nDigite o tipo de habilidade: 'c' para cone, 'r' para cruz, 'o' para octaedro: ");
    scanf(" %c", &tipoHab);
    while (tipoHab != 'c' && tipoHab != 'r' && tipoHab != 'o') {
        printf("Tipo inválido. Digite novamente ('c', 'r', 'o'): ");
        scanf(" %c", &tipoHab);
    }

    printf("Digite a linha de origem da habilidade (0 a %d): ", LINHA - 1);
    scanf("%d", &origem_linha);
    printf("Digite a coluna de origem da habilidade (0 a %d): ", COLUNA - 1);
    scanf("%d", &origem_coluna);

    aplicarHabilidade(tabuleiro, origem_linha, origem_coluna, tipoHab);

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
