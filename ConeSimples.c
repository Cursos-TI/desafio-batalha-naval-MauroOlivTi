#include <stdio.h>
#include "habilidades.h"

// Define o tamanho do cone e o valor que representa o desenho
#define LIN_MATRIZCONE 5 // Altura do cone (5 linhas)
#define COL_MATRIZCONE 5 // Largura do cone (5 colunas)
#define TINTA 7          // Número que representa o desenho (7)

// Desenha um cone no tabuleiro principal, começando na posição escolhida
void desenhar_cone(int tabuleiro[10][10], int linhahabilidade, int colunahabilidade)
{
    // Calcula o centro do cone e onde ele começa a "abrir"
    int centro = (COL_MATRIZCONE - 1) / 2;
    int metade = LIN_MATRIZCONE / 2;
    int lateraldireita = centro;
    int lateralesquerda = centro;

    // Para cada linha do cone
    for (int linha = 0; linha < LIN_MATRIZCONE; linha++)
    {
        // Para cada coluna da linha atual
        for (int coluna = 0; coluna < COL_MATRIZCONE; coluna++)
        {
            // Calcula a posição real no tabuleiro
            int linhafinal = linhahabilidade + linha;
            int colunafinal = colunahabilidade + coluna;

            // Só desenha se estiver dentro do cone e dentro do tabuleiro
            if (coluna >= lateralesquerda && coluna <= lateraldireita && linhafinal < 10 && colunafinal < 10)
            {
                tabuleiro[linhafinal][colunafinal] = TINTA;
            }
        }
        // O cone vai abrindo a cada linha
        lateraldireita++;
        lateralesquerda--;
    }
}
