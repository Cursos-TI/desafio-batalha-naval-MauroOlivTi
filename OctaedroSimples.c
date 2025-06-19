#include <stdio.h>
#include "habilidades.h"

// Define o tamanho do octaedro e o valor que representa o desenho
#define LIN_MATRIZOCT 5  // Altura do octaedro (5 linhas)
#define COL_MATRIZOCT 5  // Largura do octaedro (5 colunas)
#define TINTA 7          // Número que representa o desenho (7)

// Desenha um octaedro no tabuleiro principal, começando na posição escolhida
void desenhar_octaedro(int tabuleiro[10][10], int linhahabilidade, int colunahabilidade){
    // Calcula o centro do octaedro e onde ele começa a abrir/fechar
    int centro = (COL_MATRIZOCT - 1) / 2;
    int metade = LIN_MATRIZOCT / 2;
    int lateraldireita = centro;
    int lateralesquerda = centro;

    // Para cada linha do octaedro
    for (int linha = 0; linha < LIN_MATRIZOCT; linha++) {
        // Para cada coluna da linha atual
        for (int coluna = 0; coluna < COL_MATRIZOCT; coluna++) {
            int linhafinal = linhahabilidade + linha;
            int colunafinal = colunahabilidade + coluna;

            // Só desenha se estiver dentro do octaedro e do tabuleiro
            if (coluna >= lateralesquerda && coluna <= lateraldireita && colunafinal < 10 && linhafinal < 10) {
                tabuleiro[linhafinal][colunafinal] = TINTA;
            }
        }
        // O octaedro abre até a metade, depois fecha
        if(linha < metade ) {
            lateraldireita++;
            lateralesquerda--;
        } else {
            lateraldireita--;
            lateralesquerda++;
        }
    }
}