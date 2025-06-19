#include <stdio.h>
#include "habilidades.h"

// Define o tamanho da cruz e o valor que representa o desenho
#define LIN_MATRIZCRUZ 5  // Altura da cruz (5 linhas)
#define COL_MATRIZCRUZ 5  // Largura da cruz (5 colunas)
#define TINTA 7           // Número que representa o desenho (7)

// Desenha uma cruz no tabuleiro principal, começando na posição escolhida
void desenhar_cruz(int tabuleiro[10][10], int linhahabilidade, int colunahabilidade)
{
    // Calcula o centro da cruz (linha e coluna do meio)
    int centro = (COL_MATRIZCRUZ - 1) / 2;
    int metade = LIN_MATRIZCRUZ / 2;

    // Para cada linha da cruz
    for (int linha = 0; linha < LIN_MATRIZCRUZ; linha++)
    {
        // Para cada coluna da linha atual
        for (int coluna = 0; coluna < COL_MATRIZCRUZ; coluna++)
        {
            int linhafinal = linhahabilidade + linha;
            int colunafinal = colunahabilidade + coluna;

            // Só desenha se estiver dentro do tabuleiro
            if(linhafinal < 10 && colunafinal < 10){
                // Desenha a linha vertical da cruz
                if (coluna == centro)
                {
                    tabuleiro[linhafinal][colunafinal] = TINTA;
                }
                // Desenha a linha horizontal da cruz
                if (linha == metade)
                {
                    tabuleiro[linhafinal][colunafinal] = TINTA;
                }
            }
        }
    }
}

