#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
 char nome[30];
 char cor[30];
 int tropas;
} Territorio;

void troca(int idxA, int idxD, Territorio* t){
    if(t[idxD].tropas == 0){
            strcpy(t[idxD].cor, t[idxA].cor);
        }
}

void mapa(int n, Territorio* t){
    printf("\n       MAPA DO MUNDO -> ESTADO ATUAL:\n");

    for(int i=0; i<n; i++){
        printf("\n%d: ", i+1);
        printf("%s ", t[i].nome);
        printf("(Exército %s, ", t[i].cor);
        printf("Tropas: %d)", t[i].tropas);
    }
}

void atacar(int A, int D, Territorio* t){
    int idxA = A - 1;
    int idxD = D - 1;

    int atacante = rand() % 6+1;
    int defensor = rand() % 6+1;

    printf("\nO Atacante %s rolou o dado e tirou: %d\n", t[idxA].nome, atacante);
    printf("O Defensor %s rolou o dado e tirou: %d\n", t[idxD].nome, defensor);

    if(atacante>defensor){
        t[idxD].tropas--;
        printf("O Defensor perde 1 tropa\n");
        troca(idxA, idxD, t);
    } else{
        t[idxA].tropas--;
        printf("O Atacante perde 1 tropa\n");
    }
}

int main(){
    srand(time(NULL));
    int n, opcaoA, opcaoD;

    printf("Insira o número de Territórios:\n");
    scanf("%d", &n);

    Territorio *t = (Territorio*) calloc(n, sizeof(Territorio));

    for(int i=0; i<n; i++){
        printf("\nCADASTRANDO TERRITÓRIO %d\n\n", i+1);

        printf("Nome do Território: ");
        scanf("%s", t[i].nome);
        printf("Cor do Exército: ");
        scanf("%s", t[i].cor);
        printf("Número de Tropas: ");
        scanf("%d", &t[i].tropas);
    }

    do{

        mapa(n, t);

        printf("\n\n       FASE DE ATAQUE:\n\n");
    
        printf("Escolha um território ATACANTE entre (1 e %d) ou 0 para sair: ", n);
        scanf("%d", &opcaoA);

        if(opcaoA==0){
            break;
        }

        printf("Escolha um território DEFENSOR entre (1 e %d): ", n);
        scanf("%d", &opcaoD);

        atacar(opcaoA, opcaoD, t);

    }while(opcaoA!=0);

    free(t);
    return 0;
}