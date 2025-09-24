#include <stdio.h>

/*
    Desafio: Movimentando as Peças do Xadrez
    ----------------------------------------
    - Torre: mover 5 casas para a direita (usando for)
    - Bispo: mover 5 casas na diagonal (cima e direita) (usando while)
    - Rainha: mover 8 casas para a esquerda (usando do-while)
*/

int main() {
    // Quantidade de casas que cada peça vai se mover
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // ========================
    // Movimento da TORRE (for)
    // ========================
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita (%d)\n", i);
    }

    printf("\n");

    // ==========================
    // Movimento do BISPO (while)
    // ==========================
    printf("Movimento do Bispo:\n");
    int j = 1;
    while (j <= casasBispo) {
        printf("Cima, Direita (%d)\n", j);
        j++;
    }

    printf("\n");

    // ===============================
    // Movimento da RAINHA (do-while)
    // ===============================
    printf("Movimento da Rainha:\n");
    int k = 1;
    do {
        printf("Esquerda (%d)\n", k);
        k++;
    } while (k <= casasRainha);

        // ===============================
    // Movimento do Cavalo
    // ===============================
    printf("\nMovimento do Cavalo:\n");

    // O cavalo se move 2 casas para baixo e 1 casa para a esquerda
    int movimentosBaixo = 2;
    int movimentosEsquerda = 1;

    // Loop externo (for): controla o movimento para baixo
    for (int i = 0; i < movimentosBaixo; i++) {
        printf("Baixo\n");
    }

    // Loop interno (while): controla o movimento para esquerda
    int j = 0;
    while (j < movimentosEsquerda) {
        printf("Esquerda\n");
        j++;
    }


    return 0;
}
// O que esse código faz
Torre: usa um for para andar 5 vezes para a direita.

Bispo: usa um while para andar 5 vezes na diagonal (cima + direita).




Rainha: usa um do-while para andar 8 vezes para a esquerda.
