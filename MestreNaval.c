// Jogo de batalha naval simples - posiciona 4 navios no tabuleiro e permite usar habilidades especiais
#include <stdio.h>  // Para usar printf e scanf
#include <stdlib.h> // Para usar a função abs()
#include "habilidades.h" // Para usar as funções de habilidades (cone, cruz, octaedro)

#define LINHA 10
#define COLUNA 10

// Função para checar se 3 coordenadas estão dentro do tabuleiro (1 a 10)
int foradotabuleiro(int cord1, int cord2, int cord3)
{
    // Se qualquer coordenada for maior que 10 ou menor que 1, está fora
    if (cord1 > 10 || cord2 > 10 || cord3 > 10 || cord1 < 1 || cord2 < 1 || cord3 < 1)
    {
        return 1; // Fora do tabuleiro
    }
    else
    {
        return 0; // Dentro do tabuleiro
    }
}

// Função para checar se 4 coordenadas estão dentro do tabuleiro (usada para navios diagonais)
int foradotabuleirodiagonal(int cord1, int cord2, int cord3, int cord4)
{
    // Checa se todas as 4 coordenadas estão entre 1 e 10
    if (cord1 > 10 || cord2 > 10 || cord3 > 10 || cord4 > 10 || cord1 < 1 || cord2 < 1 || cord3 < 1 || cord4 < 1)
    {
        return 1; // Fora do tabuleiro
    }
    else
    {
        return 0; // Dentro do tabuleiro
    }
}

// Função para checar se o navio diagonal está realmente na diagonal (diferença de 2 nas linhas e colunas)
int conferirnaodiagonal(int linhafinal, int linhainicial, int colunafinal, int colunainicial)
{
    // Para ser diagonal, a diferença entre linhas e colunas deve ser exatamente 2
    if (!(abs(linhafinal - linhainicial) == 2 && abs(colunafinal - colunainicial) == 2))
    {
        return 1; // Não está na diagonal
    }
    return 0; // Está na diagonal
}

int main()
{
    
inicio:; // Se houver sobreposição de navios, volta aqui e recomeça tudo

    char letras[] = "A B C D E F G H I J"; // Letras para mostrar as colunas do tabuleiro

    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10, começa vazio (tudo 0)

    // Quatro navios, cada um ocupa 3 casas (representados pelo número 3)
    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical
    int navio3[3] = {3, 3, 3}; // Navio diagonal 1
    int navio4[3] = {3, 3, 3}; // Navio diagonal 2

    // Variáveis para guardar as posições dos navios
    int linhanavio1, colunainicialnavio1, colunafinalnavio1, colunanavio2, linhainicialnavio2, linhafinalnavio2, linhanavio1x10;

    // Pede ao usuário para posicionar o primeiro navio (horizontal)
    do
    {
        printf("***Bem vindo a Batalha naval, tabuleiro 10x10***\n\n");
        printf("**A seguir o programa pedira para colocar seus navios no tabuleiro, todos os valores precisam ser de 1 a 10**\n");
        printf("\nO primeiro navio deve ir na horizontal, digite a linha desse navio: ");
        scanf("%d", &linhanavio1);

        printf("Digite a coluna inicial do navio, ele tem 3 casas de tamanho: ");
        scanf("%d", &colunainicialnavio1);
        printf("Digite a coluna final do navio: ");
        scanf("%d", &colunafinalnavio1);

        // Checa se todas as coordenadas estão dentro do tabuleiro (1 a 10)
        if (foradotabuleiro(linhanavio1, colunainicialnavio1, colunafinalnavio1))
        {
            printf("\nO seu navio esta fora do tabuleiro, tente novamente.\n\n");
            continue; // Volta e pergunta novamente
        }

        // Checa se o navio tem exatamente 3 casas de tamanho
        if (abs(colunafinalnavio1 - colunainicialnavio1) != 2)
        {
            printf("\nSeu navio nao tem 3 casas de tamanho, tente novamente.\n\n");
            continue; // Volta e pergunta novamente
        }

        break; // Se chegou aqui, está tudo certo - sai do loop
    } while (1);

    // Pede ao usuário para posicionar o segundo navio (vertical)
    do
    {
        printf("\n**A seguir o programa pedira para colocar o segundo navio no tabuleiro**\n");
        printf("\nEsse navio deve ir na vertical, digite a coluna desse navio: ");
        scanf("%d", &colunanavio2);

        printf("Digite a linha inicial do navio, ele tem 3 casas de tamanho: ");
        scanf("%d", &linhainicialnavio2);
        printf("Digite a linha final do navio: ");
        scanf("%d", &linhafinalnavio2);

        // Checa se todas as coordenadas estão dentro do tabuleiro
        if (foradotabuleiro(linhainicialnavio2, linhafinalnavio2, colunanavio2))
        {
            printf("\nO seu navio esta fora do tabuleiro, tente novamente.\n\n");
            continue;
        }

        // Checa se o navio tem exatamente 3 casas de tamanho
        if (abs(linhafinalnavio2 - linhainicialnavio2) != 2)
        {
            printf("\nSeu navio nao tem 3 casas de tamanho, tente novamente.\n\n");
            continue;
        }

        break; // Se chegou aqui, está tudo certo
    } while (1);

    // Variáveis para os navios diagonais
    int linhainicialnaviodiagonal1, colunainicialnaviodiagonal1, linhafinalnaviodiagonal1, colunafinalnaviodiagonal1, linhainicialnaviodiagonal2, colunainicialnaviodiagonal2, linhafinalnaviodiagonal2, colunafinalnaviodiagonal2;

    // Pede ao usuário para posicionar o terceiro navio (diagonal)
    do
    {
        printf("\nAgora vamos colocar o terceiro navio, esse vai na diagonal\n");
        printf("Digite a linha inicial do seu navio: ");
        scanf("%d", &linhainicialnaviodiagonal1);
        printf("Agora digite a coluna inicial do seu navio, formando a coordenada dele: ");
        scanf("%d", &colunainicialnaviodiagonal1);
        printf("Coloque a linha final do seu navio, lembre que o navio ocupa 3 casas: ");
        scanf("%d", &linhafinalnaviodiagonal1);
        printf("Coloque a coluna final do seu navio: ");
        scanf("%d", &colunafinalnaviodiagonal1);

        // Checa se todas as 4 coordenadas estão dentro do tabuleiro
        if (foradotabuleirodiagonal(linhainicialnaviodiagonal1, linhafinalnaviodiagonal1, colunainicialnaviodiagonal1, colunafinalnaviodiagonal1))
        {
            printf("Seu navio esta fora do tabuleiro\n");
            continue;
        }

        // Checa se o navio está realmente posicionado na diagonal
        if (conferirnaodiagonal(linhafinalnaviodiagonal1, linhainicialnaviodiagonal1, colunafinalnaviodiagonal1, colunainicialnaviodiagonal1))
        {
            printf("Seu navio nao esta na diagonal\n");
            continue;
        }
        break; // Se chegou aqui, está tudo certo
    } while (1);

    // Pede ao usuário para posicionar o quarto navio (diagonal)
    do
    {
        printf("\nAgora vamos colocar o quarto navio, esse tambem vai na diagonal\n");
        printf("Digite a linha inicial do seu navio: ");
        scanf("%d", &linhainicialnaviodiagonal2);
        printf("Agora digite a coluna inicial do seu navio, formando a coordenada dele: ");
        scanf("%d", &colunainicialnaviodiagonal2);
        printf("Coloque a linha final do seu navio, lembre que o navio ocupa 3 casas: ");
        scanf("%d", &linhafinalnaviodiagonal2);
        printf("Coloque a coluna final do seu navio: ");
        scanf("%d", &colunafinalnaviodiagonal2);

        // Checa se todas as coordenadas estão dentro do tabuleiro
        if (foradotabuleirodiagonal(linhainicialnaviodiagonal2, linhafinalnaviodiagonal2, colunainicialnaviodiagonal2, colunafinalnaviodiagonal2))
        {
            printf("Seu navio esta fora do tabuleiro\n");
            continue;
        }

        // Checa se está realmente na diagonal
        if (conferirnaodiagonal(linhafinalnaviodiagonal2, linhainicialnaviodiagonal2, colunafinalnaviodiagonal2, colunainicialnaviodiagonal2))
        {
            printf("Seu navio nao esta na diagonal\n");
            continue;
        }
        break; // Se chegou aqui, está tudo certo
    } while (1);

    // Ajusta os índices das coordenadas do usuário (1-10) para índices do C (0-9)
    linhainicialnaviodiagonal2--;
    colunainicialnaviodiagonal2--;
    linhafinalnaviodiagonal2--;
    colunafinalnaviodiagonal2--;
    linhainicialnaviodiagonal1--;
    linhafinalnaviodiagonal1--;
    colunainicialnaviodiagonal1--;
    colunafinalnaviodiagonal1--;
    colunanavio2--;
    linhainicialnavio2--;
    linhafinalnavio2--;
    linhanavio1--;
    colunafinalnavio1--;
    colunainicialnavio1--;

    // Calcula as posições ocupadas pelos navios para verificar se há sobreposição
    linhanavio1x10 = linhanavio1 * 10; // Multiplica por 10 para criar um ID único para cada posição
    int vetorconferencianavio1[3] = {linhanavio1x10 + colunainicialnavio1, linhanavio1x10 + colunafinalnavio1, linhanavio1x10 + (colunainicialnavio1 + colunafinalnavio1) / 2};

    int vetorconferencianavio2[3] = {linhainicialnavio2 * 10 + colunanavio2, linhafinalnavio2 * 10 + colunanavio2, (linhainicialnavio2 + linhafinalnavio2) * 5 + colunanavio2};

    // Calcula as posições médias dos navios diagonais
    int linhamedianaviodiagonal1x5 = (linhainicialnaviodiagonal1 + linhafinalnaviodiagonal1) / 2;
    int colunamedianaviodiagonal1x5 = (colunainicialnaviodiagonal1 + colunafinalnaviodiagonal1) / 2;
    int linhamedianaviodiagonal2x5 = (linhainicialnaviodiagonal2 + linhafinalnaviodiagonal2) / 2;
    int colunamedianaviodiagonal2x5 = (colunainicialnaviodiagonal2 + colunafinalnaviodiagonal2) / 2;

    int vetorconferencianavio1diagonal[3] = {linhainicialnaviodiagonal1 * 10 + colunainicialnaviodiagonal1, linhafinalnaviodiagonal1 * 10 + colunafinalnaviodiagonal1, linhamedianaviodiagonal1x5 * 10 + colunamedianaviodiagonal1x5};

    int vetorconferencianavio2diagonal[3] = {linhainicialnaviodiagonal2 * 10 + colunainicialnaviodiagonal2, linhafinalnaviodiagonal2 * 10 + colunafinalnaviodiagonal2, linhamedianaviodiagonal2x5 * 10 + colunamedianaviodiagonal2x5};

    // Checa se algum navio está sobreposto a outro comparando as posições
    for (int indice1 = 0; indice1 < 3; indice1++)
    {
        for (int indice2 = 0; indice2 < 3; indice2++)
        {
            // Compara todas as combinações possíveis de posições entre os navios
            if (vetorconferencianavio1[indice1] == vetorconferencianavio2[indice2] ||
                vetorconferencianavio1[indice1] == vetorconferencianavio1diagonal[indice2] ||
                vetorconferencianavio1diagonal[indice1] == vetorconferencianavio2[indice2] ||
                vetorconferencianavio1[indice1] == vetorconferencianavio2diagonal[indice2] ||
                vetorconferencianavio2[indice1] == vetorconferencianavio2diagonal[indice2] ||
                vetorconferencianavio1diagonal[indice1] == vetorconferencianavio2diagonal[indice2])
            {
                printf("\n\nOs navios foram posicionados um em cima do outro, coloque-os novamente\n\n");
                goto inicio; // Se há sobreposição, recomeça tudo do início
            }
        }
    }

    // Posiciona o primeiro navio (horizontal) no tabuleiro
    if (colunainicialnavio1 < colunafinalnavio1)
    {
        // Navio vai da esquerda para a direita
        for (int tabuleirocontadorx = colunainicialnavio1, contadornavio1 = 0; tabuleirocontadorx <= colunafinalnavio1; tabuleirocontadorx++)
        {
            tabuleiro[linhanavio1][tabuleirocontadorx] = navio1[contadornavio1++];
        }
    }
    else
    {
        // Navio vai da direita para a esquerda
        for (int tabuleirocontadorx = colunafinalnavio1, contadornavio1 = 0; tabuleirocontadorx <= colunainicialnavio1; tabuleirocontadorx++)
        {
            tabuleiro[linhanavio1][tabuleirocontadorx] = navio1[contadornavio1++];
        }
    }

    // Posiciona o segundo navio (vertical) no tabuleiro
    if (linhainicialnavio2 < linhafinalnavio2)
    {
        // Navio vai de cima para baixo
        for (int tabuleirocontadory = linhainicialnavio2, contadornavio2 = 0; tabuleirocontadory <= linhafinalnavio2; tabuleirocontadory++)
        {
            tabuleiro[tabuleirocontadory][colunanavio2] = navio2[contadornavio2++];
        }
    }
    else
    {
        // Navio vai de baixo para cima
        for (int tabuleirocontadory = linhafinalnavio2, contadornavio2 = 0; tabuleirocontadory <= linhainicialnavio2; tabuleirocontadory++)
        {
            tabuleiro[tabuleirocontadory][colunanavio2] = navio2[contadornavio2++];
        }
    }

    // Posiciona o terceiro navio (diagonal) no tabuleiro
    int linhamedianaviodiagonal1 = (linhainicialnaviodiagonal1 + linhafinalnaviodiagonal1) / 2;
    int colunamedianaviodiagonal1 = (colunainicialnaviodiagonal1 + colunafinalnaviodiagonal1) / 2;
    // Cria vetores com as 3 posições do navio diagonal (início, meio, fim)
    int vetordiagonallinha1[3] = {linhainicialnaviodiagonal1, linhamedianaviodiagonal1, linhafinalnaviodiagonal1};
    int vetordiagonalcoluna1[3] = {colunainicialnaviodiagonal1, colunamedianaviodiagonal1, colunafinalnaviodiagonal1};
    // Coloca o navio nas 3 posições calculadas
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[vetordiagonallinha1[i]][vetordiagonalcoluna1[i]] = navio3[i];
    }

    // Posiciona o quarto navio (diagonal) no tabuleiro
    int linhamedianaviodiagonal2 = (linhainicialnaviodiagonal2 + linhafinalnaviodiagonal2) / 2;
    int colunamedianaviodiagonal2 = (colunainicialnaviodiagonal2 + colunafinalnaviodiagonal2) / 2;
    // Cria vetores com as 3 posições do segundo navio diagonal
    int vetordiagonallinha2[3] = {linhainicialnaviodiagonal2, linhamedianaviodiagonal2, linhafinalnaviodiagonal2};
    int vetordiagonalcoluna2[3] = {colunainicialnaviodiagonal2, colunamedianaviodiagonal2, colunafinalnaviodiagonal2};
    // Coloca o navio nas posições calculadas
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[vetordiagonallinha2[i]][vetordiagonalcoluna2[i]] = navio4[i];
    }

    // Mostra o tabuleiro completo com todos os navios posicionados
    printf("\n");
    printf("    %s\n", letras); // Mostra as letras das colunas (A B C D...)

    for (int linha = 0; linha <= 9; linha++)
    {
        printf("%2d  ", linha + 1); // Mostra o número da linha (1, 2, 3...)
        for (int coluna = 0; coluna <= 9; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]); // Mostra cada célula (0 = água, 3 = navio)
        }
        printf("\n");
    }

    // Variáveis para o menu de habilidades especiais
    int habilidade;
    int linhahabilidade, colunahabilidade;
final:;
    // Menu de habilidades especiais
    do
    {
        printf("\n*********Habilidades Especiais*********\n");
        printf("1 - Cone\n");
        printf("2 - Cruz\n");
        printf("3 - Octaedro\n");
        printf("Escolha uma habilidade: ");
        scanf("%d", &habilidade);
        printf("Digite qual a linha inicial da habilidade: ");
        scanf("%d", &linhahabilidade);
        printf("Digite qual a coluna inicial da habilidade: ");
        scanf("%d", &colunahabilidade);

//estabelecer limites para linha habilidade e coluna habilidade para nao sairem do tabuleiro
        // Chama a habilidade escolhida pelo usuário
        switch (habilidade)
        {
        case 1: // Desenha um cone no tabuleiro
            desenhar_cone(tabuleiro, linhahabilidade-1,colunahabilidade-1);
            

            break;

        case 2: // Desenha uma cruz no tabuleiro
            desenhar_cruz(tabuleiro, linhahabilidade-1,colunahabilidade-1);
            break;

        case 3: // Desenha um octaedro no tabuleiro
            desenhar_octaedro(tabuleiro, linhahabilidade-1,colunahabilidade-1);
            break;

        default: // Opção inválida

            printf("\nVoce selecionou uma habilidade que nao existe, tente novamente.\n");
            continue; // Volta para o menu de habilidades
        }
        break; // Sai do loop após usar uma habilidade válida
    } while (1);

    // Mostra o tabuleiro final com a habilidade aplicada
    for (int linha = 0; linha <= 9; linha++)
    {
        printf("%2d  ", linha + 1); // Mostra o número da linha
        for (int coluna = 0; coluna <= 9; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]); // Mostra cada célula (0 = água, 3 = navio, 7 = habilidade)
        }
        printf("\n");
    }

    return 0; // Fim do programa
}

