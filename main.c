#include <stdio.h>
#include <math.h>


void imprimeMatriz(int area, int mat[area][area]) {
    printf("Disposicao das mesas nesse andar: \n");
    for(int i = 0; i < area; i++) {
        for(int j = 0; j < area; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int contaMesas(int area, int sala[area][area], int mesasTam, int espaco) {
    int mesas, countLin, countCol;
    countLin = countCol = 0;
    mesas = 0;
  
    for(int i = 0 ; i < area; i++) {
        countCol = 0;
        if(countLin >= espaco + mesasTam && (area - i) >= mesasTam) { // reseta o contador de linhas para que possa imprimir 1 dnv
            countLin = 0;
        }
        for(int j = 0; j < area; j++) {
            if(countCol >= espaco + mesasTam && (area - j) >= mesasTam) { // reseta o contador de colunas para que possa imprimir 1 dnv
                countCol = 0;
            }
            if(countCol < mesasTam && countLin < mesasTam) { // insere 1 se os contadores sao menores que o tamanho da mesa
                sala[i][j] = 1;
                mesas++;
            }
            else { // insere 0 se passar do tamanho da mesa
                sala[i][j] = 0;
            }
            countCol++;
        }
        countLin++;
    }
    
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
        areaAndar = (int) sqrt(areaAndar); // passa o tamanho dos lados da sala
        mesasTam = (int) sqrt(mesasTam); // passa o tamanho dos lados da mesa
        int andar[areaAndar][areaAndar];
        predio[i] = contaMesas(areaAndar, andar, mesasTam, esp);
        imprimeMatriz(areaAndar, andar);
    }
    for(i = 0; i < andares; i++) {
        printf("O andar %d comporta %d mesas\n", i+1, predio[i]);
    }
}
