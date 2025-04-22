#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    // Declaração da matriz
    int Tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // As variáveis das coordenadas
    int VertLinha;
    int VertColuna;
    int HorzLinha;
    int HorzColuna;

    // Sistema simples para entrada de comando
    printf("\n=== ENTRADA Batalha Naval ===\n");
    printf("Digite a linha do navio vertical: ");
    scanf("%d", &VertLinha);

    printf("Digite a coluna do navio vertical: ");
    scanf("%d", &VertColuna);

    printf("Digite a linha do navio horizontal: ");
    scanf("%d", &HorzLinha);

    printf("Digite a coluna do navio horizontal: ");
    scanf("%d", &HorzColuna);

    // Posicionamento dos navios
    printf("\n=== COORDENADAS ===\n");
    for (int i = 0; i < 3; i++) { // Aqui, 3 significa o comprimento do navio
        Tabuleiro[VertLinha + i][VertColuna] = 3; // Basicamente, ao colocar as coordenadas desejadas, o sistema muda o valor de três posições (partindo da selecionada) para 3, representando a parte de um navio. 
        printf("Coordenada do Navio Vertical: (%d, %d)\n", VertLinha + i, VertColuna); // "+ i" muda a linha onde está o ponto a alterar
    }

    for (int i = 0; i < 3; i++) {
        Tabuleiro[HorzLinha][HorzColuna + i] = 3; // Mesma coisa, mas agora o "+ i" muda a coluna
        printf("Coordenada do Navio Horizontal: (%d, %d)\n", HorzLinha, HorzColuna + i);
    }

    // Exibição do tabuleiro
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < 10; i++) { // 10 é o tamanho do tabuleiro
        for (int j = 0; j < 10; j++) {
            printf("%d ", Tabuleiro[i][j]); // Para cada linha, imprima o valor de cada coluna
        }
        printf("\n");
    }


    return 0;
}
