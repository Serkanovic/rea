#include <stdio.h>
#include <stdlib.h>

//#define NUM_TENTATIVAS 3

int main(){
    printf("Jogo de adivinhacao\n");
    int escolhido = 55;
    int valor;
    int tentativas = 1;
    double pontos = 1000;

    while(1){
        printf("Tentativa %d\n", tentativas);
        printf("Digite um valor: ");
        scanf("%d",&valor);
        printf("Valor inserido: %d\n",valor);

        if (valor < 0) {
            printf("Utilize um valor adequado.\n\n");
            continue;
        }

        if(valor == escolhido){
            printf("Valor correto.\n\n");
            break;
        }
        else{
            if(valor > escolhido){
                printf("Tente um valor menor\n\n");
            }
            else{
                printf("Tente um valor maior\n\n");
            }
            tentativas++;

            double pontosperdidos = abs(valor - escolhido) / 2.0;
            pontos = pontos - pontosperdidos;
        }
    }
    printf("Jogo encerrado.\nTentativas: %d\n", tentativas);
    printf("Pontuacao final: %.2lf\n", pontos);
}
