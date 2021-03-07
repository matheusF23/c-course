#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Imprime cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativa = 1;
    float pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int ntentativas;

    switch (nivel)  {
        case 1:
            ntentativas = 20;
            break;
        case 2:
            ntentativas = 10;    
            break;
        default:
            ntentativas = 5;
            break;
    }

    for (int i = 1; i <= ntentativas; i++) {
        printf("\nTentativa %d\n", tentativa);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = chute == numerosecreto;
        int menor = chute < numerosecreto;

        if (acertou) {
            break;
        } else if (menor) {
            printf("Seu chute foi menor do que o número secreto!\n");
        } else {
            printf("Seu chute foi maior do que o número secreto!\n");
        }

        tentativa++;
        float pontosperdidos = (double)(chute - numerosecreto) / 2;
        pontos = pontos - abs(pontosperdidos);
    }

    printf("Fim de jogo!\n");

    if (acertou) {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas\n", tentativa);
        printf("Total de pontos: %.2f\n", pontos);
    } else {
        printf("Você perdeu. Tente de novo.");
    }
}
