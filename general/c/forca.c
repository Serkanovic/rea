#include <stdio.h>
#include <string.h>
#include "forca.h"

char palavra[20];
char chutes[26];
int tentativas = 0;

void chuta(){
    char chute;
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;

}

int jachutou(char letra){
    int achou = 0;
    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void palavraForca(){
    for(int i = 0; i < strlen(palavra); i++) {
        int achou = jachutou(palavra[i]);

        if (achou) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");

        }

    }
    printf("\n");
}

void palavraEscolhida(){
    sprintf(palavra,"atomo");
}

int acertou(){
    for(int i = 0; i < strlen(palavra); i++){
        if(!jachutou(palavra[i])) {
            return 0;
        }
    }

    return 1;
}

int enforcou(){
    int erros = 0;
    for(int i =0; i < tentativas;i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavra); j++){

            if (chutes[i] == palavra[j]){
                existe = 1;
                break;
            }
        }

        if(!existe) erros ++;
    }
    return erros >=5;

}

int main(){

    palavraEscolhida();
    //printf("%s",palavra);


    do {

        palavraForca();
        chuta();


    } while (!acertou() && !enforcou());

    if (acertou() == 1) {
    printf("%s", palavra);

    }

    return 0;
}
