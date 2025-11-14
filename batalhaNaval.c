#include <stdio.h>

#define TAM 10        // tamanho do tabuleiro (10x10)
#define NAVIO 3       // tamanho de cada navio

int main() {

    // ==============================
    // 1. CRIAR TABULEIRO 10x10
    // ==============================
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==============================
    // 2. DEFINIÇÃO DAS COORDENADAS
    // ==============================

    // Navio Horizontal (3 posições)
    int linhaH = 2;   // linha inicial
    int colunaH = 4;  // coluna inicial

    // Navio Vertical (3 posições)
    int linhaV = 5;   // linha inicial
    int colunaV = 1;  // coluna inicial

    // ==============================
    // 3. VALIDAÇÃO DOS NAVIOS
    // ==============================

    // Verificar se o navio horizontal cabe no tabuleiro
    if (colunaH + NAVIO > TAM) {
        printf("ERRO: Navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }

    // Verificar se o navio vertical cabe no tabuleiro
    if (linhaV + NAVIO > TAM) {
        printf("ERRO: Navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }

    // Verificar sobreposição
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] == 3 ||
            tabuleiro[linhaV + i][colunaV] == 3) {
            printf("ERRO: Os navios estao se sobrepondo!\n");
            return 1;
        }
    }

    // ==============================
    // 4. POSICIONAR OS NAVIOS
    // ==============================

    // Posiciona navio horizontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Posiciona navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // ==============================
    // 5. EXIBIR O TABULEIRO
    // ==============================
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
