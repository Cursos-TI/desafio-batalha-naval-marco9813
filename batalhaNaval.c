#include <stdio.h>



int main() {

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int tabuleiro[10][10];

    // Aqui eu criei uma matriz de batalha naval só com 0s
    for (int j = 0; j < 10; j++){
        for(int k = 0; k < 10; k++){
            tabuleiro[j][k] = 0;
        }
    }

    // Aqui eu defini as posições dos navios na horizontal
    for(int h = 2; h < 5; h++){
        tabuleiro[2][h + 1] = 3;
    }

    // Aqui eu defini as posições dos navios na Vertical
    for(int v = 4; v < 7; v++){
        tabuleiro[v + 1][1] = 3;
    }

    printf("Jogo Batalha Naval \n");
    printf("  ");

    // Aqui eu criei um alfabeto que vai de A até J
    for (int i = 0; i < 10; i++){
        printf("%c ", linha[i]);
    }

    for(int j = 0; j < 10; j++){
        printf(" \n"); // Aqui ele vai pular a linha para não colidir com o alfabeto
        printf("%d", j + 1); // Aqui é a numeração que fica no lado esquerdo da matriz que vai de 1 até 10
        for(int k = 0; k < 10; k++){
            printf(" %d", tabuleiro[j][k]); // Aqui imprimi todo tabuleiro da batalha naval com os navios definido
   }
    
    }

    
    return 0;
}
