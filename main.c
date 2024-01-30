#include <stdio.h>
#include <math.h>


void imprimeMatriz(int col, int *mat[]) { // teoricamente eh pra imprimir a matriz
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int contaMesas(int area, int mesasTam, int esp) {
    int mesas, countLin, countCol;
    countLin = countCol = 0;
    mesas = 0;
    area = (int) sqrt(area); // passa o tamanho dos lados da sala
    mesasTam = (int) sqrt(mesasTam); // passa o tamanho dos lados da mesa
    int mat[area][area];

    for(int i = 0 ; i < area; i++) {
        countCol = 0;
        if(countLin >= esp + mesasTam) { // reseta o contador de linhas para que possa imprimir 1 dnv
            countLin = 0;
        }
        for(int j = 0; j < area; j++) {
            if(countCol >= esp + mesasTam) { // reseta o contador de colunas para que possa imprimir 1 dnv
                countCol = 0;
            }
            if(countCol < mesasTam && countLin < mesasTam) { // insere 1 se os contadores sao menores que o tamanho da mesa
                mat[i][j] = 1;
                mesas++;
            }
            else { // insere 0 se passar do tamanho da mesa
                mat[i][j] = 0;
            }
            countCol++;
        }
        countLin++;
    }

    imprimeMatriz(area, mat);
    
    mesas /= mesasTam * mesasTam; // insere a quantidade de mesas que a sala comporta
    return mesas;
}


int main(void) {

    int andares, i, mesasTam, areaAndar, esp;

    printf("Insira a quantidade de andares do seu predio: ");
    scanf("%d", &andares);

    int predio[andares];

    for(i = 0; i < andares; i++) {
        printf("Insira a area(m²) do andar %d a area ocupada pelas mesas e o espacamento entre elas: ", i + 1);
        scanf("%d %d %d", &areaAndar, &mesasTam, &esp);
        predio[i] = contaMesas(areaAndar, mesasTam, esp);
    }
    for(i = 0; i < andares; i++) {
        printf("O andar %d comporta %d mesas\n", i+1, predio[i]);
    }
}