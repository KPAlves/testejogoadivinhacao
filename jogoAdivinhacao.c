#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define NUMBER_ATTEMPT 5

int main() {

    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int numUser;
    int win;
    int level;
    int numtry;
    
    double score = 1000;
    
    srand(time(0));
    int numSecret = rand() % 100;
    
    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &level);

    switch(level) {
        case 1:    
            numtry = 20;
            break;

        case 2:
            numtry = 15;
            break;
        default:
            numtry = 6;
            break;
    }

    for(int i = 1; i <= numtry; i++) {

        printf("Tentativa %d de %d\n", i, numtry);
        
        printf("Chute um numero: ");
        scanf("%d", &numUser);

        if(numUser < 0) {
            printf("Nao e permitido chutar numeros negativos!\n");
            i--;
            continue;
        }

        win = numUser == numSecret;
    
        if(win) {
            break;
        } else if (numUser > numSecret) {
            printf("\nSeu chute foi maior que o numero secreto!!!\n\n");
        } else {
            printf("\nSeu chute foi menor que o numero secreto!!!\n\n");
        }

        double lossscore = abs(numUser - numSecret) / 2.0;
        score = score - lossscore;
    }
            
    printf("Fim do jogo!\n\n");
    
    if (win) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nVoce ganhou! Parabens !!!\n");
        printf("Total de pontos: %.2f\n\n", score);
    }
    else {
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");
        printf("\nVoce perdeu! Tente novamente!\n\n");
    }
}