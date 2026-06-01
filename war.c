#include <stdio.h>
#include <string.h>

#define Trr_Max 5

typedef struct{
 char nome[30];
 char cor[30];
 int tropas;
} Territorio;

int main(){

    Territorio t[Trr_Max];

    for(int i=0; i<Trr_Max; i++){
        printf("\nCADASTRANDO TERRITÓRIO %d\n\n", i+1);

        printf("Nome do Território: ");
        scanf("%s", t[i].nome);
        printf("Cor do Exército: ");
        scanf("%s", t[i].cor);
        printf("Número de Tropas: ");
        scanf("%d", &t[i].tropas);
    }

    printf("\n    MAPA DO MUNDO -> ESTADO ATUAL:\n");

    for(int i=0; i<Trr_Max; i++){
        printf("\nTERRITÓRIO %d:\n", i+1);
        printf("%s\n", t[i].nome);
        printf("%s\n", t[i].cor);
        printf("%d Tropas\n", t[i].tropas);
    }

    return 0;
}