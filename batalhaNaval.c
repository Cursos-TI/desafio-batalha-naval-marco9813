#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3
#define EFEITO_CONE 5
#define EFEITO_CRUZ 5
#define EFEITO_OCTAEDRO 5


int main() {

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[LINHAS][COLUNAS];

    // Aqui eu criei uma matriz de batalha naval só com 0s
    for (int j = 0; j < 10; j++){
        for(int k = 0; k < 10; k++){
            tabuleiro[j][k] = AGUA;
        }
    }

        // Aqui criei a matriz cone e inicializei
    int cone[7][7] ={
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    // defini a largura e altura e os pontos de origem
    int larguraHab = 7;
    int alturaHab = 7;
    int origemConeLinha = 5;
    int origemConeColuna = 3;
    int centroPadraoLinhaCone = alturaHab / 2;
    int centroPadraoColunaCone = larguraHab / 2;

    for(int i = 0; i < alturaHab; i++){ // aqui é a lógica do cone aonde ele vai sobrepor os 0s e não os navios
        for(int j = 0; j < larguraHab; j++){
            if(cone[i][j] == 1){
                int linhaTabuleiro = origemConeLinha + (i - centroPadraoLinhaCone);
                int colunaTabuleiro = origemConeColuna + (j - centroPadraoColunaCone);
                if(linhaTabuleiro >= 0 && linhaTabuleiro < LINHAS &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < COLUNAS){
                        if(tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA){
                            tabuleiro[linhaTabuleiro][colunaTabuleiro] = EFEITO_CONE;
                        }
                    }
            }
        }
    }

        // aqui criei a matriz da cruz
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    // defini sua altura e largura e ponto de origem
    int larguraHabCruz = 5;
    int alturaHabCruz = 5;
    int origemCruzLinha = 7;
    int origemCruzColuna = 6;
    int centroPadraoLinhaCruz = alturaHabCruz / 2;
    int centroPadraoColunaCruz = larguraHabCruz / 2;

    for(int i = 0; i < alturaHabCruz; i++){ // implimentei a lógica da Cruz, e vai sobrepor 0s e não navios de acordo com a posição que eu defini
        for(int j = 0; j < larguraHabCruz; j++){
            if(cruz[i][j] == 1){
                int linhaTabuleiro = origemCruzLinha + (i - centroPadraoLinhaCruz);
                int colunaTabuleiro = origemCruzColuna + (j - centroPadraoColunaCruz);
                if(linhaTabuleiro >= 0 && linhaTabuleiro < LINHAS &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < COLUNAS){
                        if(tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA){
                            tabuleiro[linhaTabuleiro][colunaTabuleiro] = EFEITO_CRUZ;
                        }
                    }
            }
        }
    }
    // criei a matriz do octaedro 
    int octaedro[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    // defini sua altura, largura e ponto de origem
    int larguraHabOct = 4;
    int alturaHabOct = 4;
    int origemOctLinha = 4;
    int origemOctColuna = 9;
    int centroPadraoLinhaOct = alturaHabOct / 2;
    int centroPadraoColunaOct = larguraHabOct / 2;

     for(int i = 0; i < alturaHabOct; i++){ // implimentei a lógica e ela vai sobrepor os 0s e não os navios de acordo com a posição que eu defini
        for(int j = 0; j < larguraHabOct; j++){
            if(octaedro[i][j] == 1){
                int linhaTabuleiro = origemOctLinha + (i - centroPadraoLinhaOct);
                int colunaTabuleiro = origemOctColuna + (j - centroPadraoColunaOct);
                if(linhaTabuleiro >= 0 && linhaTabuleiro < LINHAS &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < COLUNAS){
                        if(tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA){
                            tabuleiro[linhaTabuleiro][colunaTabuleiro] = EFEITO_OCTAEDRO;
                        }
                    }
            }
        }
    }

    // Aqui eu defini as posições dos navios na horizontal
    for(int h = 0; h < 3; h++){
        tabuleiro[5][h + 1] = NAVIO;
    }

    // Aqui eu defini as posições dos navios na Vertical
    for(int v = 6; v < 9; v++){
        tabuleiro[v + 1][0] = NAVIO;
    }

    // Aqui eu defini as posições dos navios na Diagonal da Esquerda para Direita
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){ // aqui o loop vai rodar a matriz e colocar os navios na diagonal linha igual a coluna
            tabuleiro[0][0] = NAVIO;
            tabuleiro[1][1] = NAVIO;
            tabuleiro[2][2] = NAVIO;
            
        }
    }

    // aqui eu defini as posições dos navios na Diagonal da Direita para a Esquerda
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){ // aqui o loop vai rodar a madriz e colocar os navios na diagonal a linha eu comecei com 0 e coluna 9, depois eu fui almentando a linha e diminuindo a coluna
            tabuleiro[0][9] = NAVIO;
            tabuleiro[1][8] = NAVIO;
            tabuleiro[2][7] = NAVIO;
        }
    }

    printf("Jogo Batalha Naval \n");
    printf("  ");

    // Aqui eu criei um alfabeto que vai de A até J
    for (int i = 0; i < 10; i++){
        printf("%c ", linha[i]);
    }

    for(int j = 0; j < 10; j++){
        printf(" \n"); // Aqui ele vai pular a linha para não colidir com o alfabeto
        printf("%2d", j + 1); // Aqui é a numeração que fica no lado esquerdo da matriz que vai de 1 até 10
        for(int k = 0; k < 10; k++){
            printf(" %d", tabuleiro[j][k]); // Aqui imprimi todo tabuleiro da batalha naval com os navios definido
   }
    
    }

    
    return 0;
}
