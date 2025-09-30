#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n--- Tabuleiro ---\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado (sem sair do tabuleiro ou sobrepor)
int podePosicionar(int tabuleiro[TAM][TAM], int x, int y, int dx, int dy) {
    for (int i = 0; i < 3; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM) return 0; // fora do tabuleiro
        if (tabuleiro[nx][ny] != 0) return 0; // já ocupado
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int x, int y, int dx, int dy) {
    for (int i = 0; i < 3; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        tabuleiro[nx][ny] = NAVIO;
    }
}

// Função genérica para aplicar habilidades no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[7][7], int tamHab, int origemX, int origemY) {
    int centro = tamHab / 2;

    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            if (habilidade[i][j] == 1) {
                int nx = origemX + (i - centro);
                int ny = origemY + (j - centro);

                if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
                    if (tabuleiro[nx][ny] == 0) {
                        tabuleiro[nx][ny] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Criar matriz em formato de cone (7x7)
void criarCone(int cone[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cone[i][j] = 0;
        }
    }

    for (int i = 0; i < 7; i++) {
        int inicio = 3 - i;
        int fim = 3 + i;
        if (inicio < 0) inicio = 0;
        if (fim >= 7) fim = 6;

        for (int j = inicio; j <= fim; j++) {
            cone[i][j] = 1;
        }
    }
}

// Criar matriz em formato de cruz (7x7)
void criarCruz(int cruz[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cruz[i][j] = 0;
        }
    }
    for (int i = 0; i < 7; i++) {
        cruz[3][i] = 1; // linha central
        cruz[i][3] = 1; // coluna central
    }
}

// Criar matriz em formato de octaedro (7x7)
void criarOctaedro(int oct[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            oct[i][j] = 0;
        }
    }
    for (int i = 0; i < 7; i++) {
        int inicio = 3 - i;
        int fim = 3 + i;
        if (inicio < 0) inicio = -inicio; // espelhamento
        if (fim >= 7) fim = 6 - (i - 3);

        for (int j = inicio; j <= fim; j++) {
            oct[i][j] = 1;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    if (podePosicionar(tabuleiro, 0, 0, 0, 1)) // horizontal
        posicionarNavio(tabuleiro, 0, 0, 0, 1);

    if (podePosicionar(tabuleiro, 2, 2, 1, 0)) // vertical
        posicionarNavio(tabuleiro, 2, 2, 1, 0);

    if (podePosicionar(tabuleiro, 5, 0, 1, 1)) // diagonal principal
        posicionarNavio(tabuleiro, 5, 0, 1, 1);

    if (podePosicionar(tabuleiro, 0, 9, 1, -1)) // diagonal secundária
        posicionarNavio(tabuleiro, 0, 9, 1, -1);

    // Criar habilidades
    int cone[7][7], cruz[7][7], oct[7][7];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    // Aplicar habilidades
    aplicarHabilidade(tabuleiro, cone, 7, 4, 4);  // cone no centro
    aplicarHabilidade(tabuleiro, cruz, 7, 7, 7);  // cruz no canto inferior
    aplicarHabilidade(tabuleiro, oct, 7, 2, 7);   // octaedro na lateral

    // Exibir resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}
