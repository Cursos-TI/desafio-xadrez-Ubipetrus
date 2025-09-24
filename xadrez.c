
 #include <stdio.h>

// ===============================
// Funções Recursivas
// ===============================

// Movimento da Torre (para cima)
void moverTorre(int casas) {
    if (casas <= 0) return; // Caso base
    printf("Cima\n");
    moverTorre(casas - 1); // Chamada recursiva
}

// Movimento da Rainha (direita)
void moverRainha(int casas) {
    if (casas <= 0) return; // Caso base
    printf("Direita\n");
    moverRainha(casas - 1); // Chamada recursiva
}

// Movimento do Bispo (diagonal superior direita)
// Recursão + loops aninhados
void moverBispo(int casas) {
    if (casas <= 0) return; // Caso base

    // Loop externo: movimento vertical
    for (int i = 0; i < 1; i++) {
        printf("Cima\n");

        // Loop interno: movimento horizontal
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // Chamada recursiva
}

// ===============================
// Movimento do Cavalo com loops complexos
// ===============================

void moverCavalo() {
    int movimentosCima = 2;     // Duas casas para cima
    int movimentosDireita = 1;  // Uma casa para a direita

    printf("Movimento do Cavalo:\n");

    // Dois loops aninhados, simulando múltiplas variáveis
    for (int i = 0, j = 0; i < movimentosCima || j < movimentosDireita; ) {
        if (i < movimentosCima) {
            printf("Cima\n");
            i++;
            continue; // volta para o loop, priorizando o movimento "Cima"
        }

        if (j < movimentosDireita) {
            printf("Direita\n");
            j++;
        } else {
            break; // encerra o loop quando terminou o "L"
        }
    }
}

// ===============================
// Função principal
// ===============================
int main() {
    // Torre: 3 casas para cima
    printf("Movimento da Torre:\n");
    moverTorre(3);

    // Linha em branco
    printf("\n");

    // Rainha: 3 casas para direita
    printf("Movimento da Rainha:\n");
    moverRainha(3);

    // Linha em branco
    printf("\n");

    // Bispo: 3 casas em diagonal
    printf("Movimento do Bispo:\n");
    moverBispo(3);

    // Linha em branco
    printf("\n");

    // Cavalo
    moverCavalo();

    return 0;
}
