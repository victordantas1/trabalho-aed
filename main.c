#include <stdio.h>
#include <math.h>

int contaMesas(int area, int mesasTam, int esp) {
    int mesas, countLin, countCol, countMesas;
    countLin = countCol = 0;
    mesas = 0;
    area = (int) sqrt(area);
    mesasTam = (int) sqrt(mesasTam);
    int mat[area][area];

    for(int i = 0 ; i < area; i++) {
        countCol = 0;
        if(countLin >= esp + mesasTam) {
            countLin = 0;
        }
        for(int j = 0; j < area; j++) {
            if (countCol >= esp + mesasTam) {
                countCol = 0;
            }
            if (countCol < mesasTam && countLin < mesasTam) {
                mat[i][j] = 1;
                mesas++;
            } else {
                mat[i][j] = 0;
            }
            countCol++;
        }
        countLin++;
    }
    for(int i = 0; i < area; i++) {
        for(int j = 0; j < area; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    mesas /= mesasTam * mesasTam;
    return mesas;
}

int contaMesasV2(int area, int mesasTam, int esp) {
    int mesas, countLin, countCol;
    countLin = countCol = 0;
    mesas = 0;
    area = (int) sqrt(area);
    mesasTam = (int) sqrt(mesasTam);
    int mat[area][area];

    for(int i = area - 1; i >= 0; i--) {
        countCol = 0;
        if(countLin >= esp + mesasTam) {
            countLin = 0;
        }
        for(int j = area - 1; j >= 0; j--) {
            if (countCol >= esp + mesasTam) {
                countCol = 0;
            }
            if (countCol < mesasTam && countLin < mesasTam
                && j >= mesasTam && i >= mesasTam) {
                mat[i][j] = 1;
                mesas++;
            } else {
                mat[i][j] = 0;
            }
            countCol++;
        }
        countLin++;
    }
    for(int i = 0; i < area; i++) {
        for(int j = 0; j < area; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    mesas /= mesasTam * mesasTam;
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
        predio[i] = contaMesasV2(areaAndar, mesasTam, esp);
    }
    printf("%d", predio[0]);
}