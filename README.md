# Batalha Naval com Habilidades Especiais

Execute através do JOGO.exe
Um jogo simples de batalha naval em C onde você posiciona navios no tabuleiro e pode usar habilidades especiais.

# Como Funciona

# 1. Posicionamento dos Navios

4 navios no total, cada um ocupa 3 casas
- Navio 1: Horizontal (escolha linha e colunas inicial/final)
- Navio 2: Vertical (escolha coluna e linhas inicial/final)
- Navio 3: Diagonal (escolha coordenadas inicial/final)
- Navio 4: Diagonal (escolha coordenadas inicial/final)
# 2. Habilidades Especiais

Após posicionar os navios, você pode usar uma habilidade:

- Cone: Desenha um triângulo 5x5
- Cruz: Desenha uma cruz 5x5
- Octaedro: Desenha um losango 5x5

# Regras

- Tabuleiro é 10x10 (linhas 1-10, colunas 1-10)
- Navios não podem se sobrepor
- Navios devem ter exatamente 3 casas de tamanho
- Navios diagonais devem formar uma diagonal perfeita
- Habilidades podem sair parcialmente do tabuleiro (só a parte dentro será desenhada)

# Representação no Tabuleiro

0 = Água (vazio)
3 = Navio
7 = Habilidade especial