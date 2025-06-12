// Jogo de batalha naval simples - posiciona 2 navios no tabuleiro
#include <stdio.h> // Para usar printf e scanf
#include <stdlib.h> // Para usar a função abs()

int main()
{ inicio:; // Se os navios se tocarem, volta aqui e recomeça tudo
    // As letras que aparecem em cima do tabuleiro
    char letras[] = "A B C D E F G H I J";

    // O tabuleiro do jogo - começa vazio
    int tabuleiro[10][10] = {0};

    // Os dois navios do jogo
    int navio1[3] = {3, 3, 3}; // Vai na horizontal
    int navio2[3] = {3, 3, 3}; // Vai na vertical

    // Onde o usuário quer colocar os navios
    int linhanavio1, colunainicialnavio1, colunafinalnavio1,colunanavio2,linhainicialnavio2,linhafinalnavio2, linhanavio1x10;
    // Pede pro usuário colocar o primeiro navio até dar certo
    do
    {
        // Fala oi pro usuário
        printf("***Bem vindo a Batalha naval, tabuleiro 10x10***\n\n");
        printf("**A seguir o programa pedira para colocar seus navios no tabuleiro, todos os valores precisam ser de 1 a 10**\n");
        printf("\nO primeiro navio deve ir na horizontal, digite a linha desse navio: ");

        // Pergunta onde colocar o primeiro navio
        scanf("%d", &linhanavio1);

        printf("Digite a coluna inicial do navio, ele tem 3 casas de tamanho: ");
        scanf("%d", &colunainicialnavio1);
        printf("Digite a coluna final do navio: ");
        scanf("%d", &colunafinalnavio1);

        // Vê se o navio tá dentro do tabuleiro
        if (linhanavio1 > 10 || colunainicialnavio1 > 10 || colunafinalnavio1 > 10 || linhanavio1 < 1 || colunainicialnavio1 < 1 || colunafinalnavio1 < 1)
        {
            printf("\nO seu navio esta fora do tabuleiro, tente novamente.\n\n");
            continue; // Tenta de novo
        }

        // Vê se o navio tem o tamanho certo (3 casas)
        if (abs(colunafinalnavio1 - colunainicialnavio1) != 2)
        {
            printf("\nSeu navio nao tem 3 casas de tamanho, tente novamente.\n\n");
            continue; // Tenta de novo
        }

        // Deu tudo certo, pode sair do loop
        break;
    } while (1);

    // Agora pede o segundo navio
    do
    {
        printf("\n**A seguir o programa pedira para colocar o segundo navio no tabuleiro**\n");
        printf("\nEsse navio deve ir na vertical, digite a coluna desse navio: ");

        // Pergunta onde colocar o segundo navio
        scanf("%d", &colunanavio2);

        printf("Digite a linha inicial do navio, ele tem 3 casas de tamanho: ");
        scanf("%d", &linhainicialnavio2);
        printf("Digite a linha final do navio: ");
        scanf("%d", &linhafinalnavio2);

        // Vê se o segundo navio tá dentro do tabuleiro
        if (colunanavio2 > 10 || linhainicialnavio2 > 10 || linhafinalnavio2 > 10 || colunanavio2 < 1 || linhainicialnavio2 < 1 || linhafinalnavio2 < 1)
        {
            printf("\nO seu navio esta fora do tabuleiro, tente novamente.\n\n");
            continue; // Tenta de novo
        }

        // Vê se o segundo navio tem o tamanho certo
        if (abs(linhafinalnavio2 - linhainicialnavio2) != 2)
        {
            printf("\nSeu navio nao tem 3 casas de tamanho, tente novamente.\n\n");
            continue; // Tenta de novo
        }

        // Segundo navio também deu certo
        break;
    } while (1);

    // Ajusta os números (usuário digita 1-10, mas computador usa 0-9)
    colunanavio2 -=1 ;
    linhainicialnavio2 -=1;
    linhafinalnavio2 -= 1;
    linhanavio1 -= 1;
    colunafinalnavio1 -= 1;
    colunainicialnavio1 -= 1;

    // Cria números especiais pra cada posição dos navios
    linhanavio1x10 = linhanavio1 * 10;
    int vetorconferencianavio1[]={linhanavio1x10+colunainicialnavio1, linhanavio1x10+colunafinalnavio1, linhanavio1x10 +(colunainicialnavio1 + colunafinalnavio1)/2};

    int vetorconferencianavio2[] = {linhainicialnavio2*10 + colunanavio2, linhafinalnavio2*10 + colunanavio2, (linhainicialnavio2 + linhafinalnavio2)*5 + colunanavio2};

    // Vê se os navios se tocam
    for(int i = 0; i<=2; i++){
        for(int j = 0; j<=2; j++){
            if(vetorconferencianavio1[i] == vetorconferencianavio2[j]){
                // Opa! Os navios se tocaram
                printf("\n\nVoce sobrepos os navios, comece novamente.\n\n");
                goto inicio; // Volta pro começo
            }
        }
    }


    // Agora bota os navios no tabuleiro

    // Bota o primeiro navio
    if(colunainicialnavio1<colunafinalnavio1){
        // Se digitou da esquerda pra direita
        for (int tabuleirocontadorx = colunainicialnavio1, contadornavio1 = 0; tabuleirocontadorx <= colunafinalnavio1; tabuleirocontadorx++)
        {
            tabuleiro[linhanavio1][tabuleirocontadorx] = navio1[contadornavio1++];
        }
    }
    else {
        // Se digitou da direita pra esquerda
        for (int tabuleirocontadorx = colunafinalnavio1, contadornavio1 = 0; tabuleirocontadorx <= colunainicialnavio1; tabuleirocontadorx++)
        {
            tabuleiro[linhanavio1][tabuleirocontadorx] = navio1[contadornavio1++];
        }
    }
    // Bota o segundo navio
    if(linhainicialnavio2<linhafinalnavio2){
        // Se digitou de cima pra baixo
        for (int tabuleirocontadory = linhainicialnavio2, contadornavio2 = 0; tabuleirocontadory <= linhafinalnavio2; tabuleirocontadory++)
        {
            tabuleiro[tabuleirocontadory][colunanavio2] = navio2[contadornavio2++];
        }
    }
    else{
        // Se digitou de baixo pra cima
        for (int tabuleirocontadory = linhafinalnavio2, contadornavio2 = 0; tabuleirocontadory <= linhainicialnavio2; tabuleirocontadory++)
        {
            tabuleiro[tabuleirocontadory][colunanavio2] = navio2[contadornavio2++];
        }
    }

    // Mostra o tabuleiro pronto
    printf("\n");
    printf("    %s\n", letras); // As letras em cima

    // Mostra cada linha
    for (int linha = 0; linha <= 9; linha++)
    {
        printf("%2d  ", linha + 1); // Número da linha

        // Mostra cada coluna
        for (int coluna = 0; coluna <= 9; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]); // 0 = vazio, 3 = navio
        }
        printf("\n");
    }

    return 0; // Acabou
}