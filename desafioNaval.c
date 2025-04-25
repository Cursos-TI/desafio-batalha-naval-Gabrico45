#include <stdio.h>

#define linha 10 
#define coluna 10

int main ()
{
    int tabuleiro [linha][coluna] = {0};

    int naV;
    int naH;
    char direcao;

    printf("--- BATALHA NAVAL ---\n");
    printf("Escola a posição do navio: 'h' para horizontal, 'v' para vertical, 'd' para diagonal direita ou 'e' para diagonal esquerda: : ");
    scanf(" %c", &direcao); // espaço antes do %c para ignorar enter pendente

    // codigo para identificar erro de digito.
    while (direcao != 'h' && direcao != 'v' && direcao != 'd' && direcao != 'e')
    {
        printf("Direção inválida. Digite 'h' para horizontal, 'v' para vertical, 'd' para diagonal direita ou 'e' para diagonal esquerda: \n");
        scanf(" %c", &direcao);
    }

    //direcao para vertical 
    if (direcao == 'v')
    {
        printf("Digite a linha do navio vertical (0 a %d): ", linha - 3);
        scanf("%d", &naV);

        //esses codigos em while são para identificar algum erro e repitir até que o usuario escolha o numero ou digito correto.
        while (naV < 0 || naV > linha - 3)
        {
            printf("Linha Inválida. Digite novamente (0 a %d): \n", linha - 3);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio vertical (0 a %d): ", coluna - 1);
        scanf("%d", &naH);

        while (naH < 0 || naH >= coluna)
        {
            printf("Coluna inválida. Digite novamente (0 a %d): \n", coluna - 1);
            scanf("%d", &naH);
        }

        printf("\n--- CORDENADAS ---\n");
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[naV + i][naH] = 3;
            printf("Coordenada do Navio Vertical: (%d, %d)\n", naV + i, naH);
        }
    }
    
    //direcao horizontal.
    else if (direcao == 'h')
    {
        printf("Digite a linha do navio horizontal (0 a %d): \n", linha - 1);
        scanf("%d", &naV);

        while (naV < 0 || naV >= linha)
        {
            printf("Linha inválida. Digite novamente (0 a %d): \n", linha - 1);
            scanf("%d", &naV);
        }

        printf("Digite a Coluna do navio horizontal (0 a %d): ", coluna - 3);
        scanf("%d", &naH);

        while (naH < 0 || naH > coluna - 3)
        {
            printf("Coluna inválida. Digite novamente (0 a %d): \n", coluna - 3);
            scanf("%d", &naH);
        }

        printf("\n--- CORDENADAS ---\n");
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[naV][naH + i] = 3;
            printf("Coordenada do navio Horizontal: (%d, %d)\n", naV, naH + i);
        }
    }
    
    else if (direcao == 'd') // diagonal direita "\"
    {
        printf("Digite a linha do navio diagonal direita (0 a %d): ", linha - 3);
        scanf("%d", &naV);

        while (naV < 0 || naV > linha - 3)
        {
            printf("Linha inválida. Digite novamente (0 a %d): ", linha - 3);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio diagonal direita (0 a %d): ", coluna - 3);
        scanf("%d", &naH);

        while (naH < 0 || naH > coluna - 3)
        {
            printf("Coluna inválida. Digite novamente (0 a %d): ", coluna - 3);
            scanf("%d", &naH);
        }

        printf("\n--- CORDENADAS ---\n");
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[naV + i][naH + i] = 3;
            printf("Coordenada do navio Diagonal Direita: (%d, %d)\n", naV + i, naH + i);
        }
    }
    
    else if (direcao == 'e') // diagonal esquerda "/"
    {
        printf("Digite a linha do navio diagonal esquerda (0 a %d): ", linha - 3);
        scanf("%d", &naV);

        while (naV < 0 || naV > linha - 3)
        {
            printf("Linha inválida. Digite novamente (0 a %d): ", linha - 3);
            scanf("%d", &naV);
        }

        printf("Digite a coluna do navio diagonal esquerda (2 a %d): ", coluna - 1);
        scanf("%d", &naH);

        while (naH < 2 || naH > coluna - 1)
        {
            printf("Coluna inválida. Digite novamente (2 a %d): ", coluna - 1);
            scanf("%d", &naH);
        }

        printf("\n--- CORDENADAS ---\n");
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[naV + i][naH - i] = 3;
            printf("Coordenada do navio Diagonal Esquerda: (%d, %d)\n", naV + i, naH - i);
        }
    }

    // Exibição do tabuleiro
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    } 
}
