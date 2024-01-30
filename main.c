#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Funcao para impressao de matriz
void imprimeMatriz(int area, int mat[area][area], int andar) { 
    printf("\nDisposicao das mesas no andar %d: \n", andar);
    for(int i = 0; i < area; i++) {
        for(int j = 0; j < area; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Funcao para verificar se a area e o tamanho das mesas eh impar
int verificaImpar(int num1, int num2) {
    if(num1 % 2 != 0 && num2 % 2 != 0) return 1;
    else return 0;
}

// Funcao para contar a quantidade de mesas que cabem em um andar
int contaMesas(int area, int andar[area][area], int mesasTam, int espaco) {
    int mesas, countLin, countCol, central;
    countLin = countCol = 0;
    mesas = 0;
  
    if(area - (espaco + mesasTam) <= 1 && verificaImpar(area, mesasTam)) { // Verifica condicao para centralizar quando for somente uma mesa
        mesas = 1;
        central = area / 2;
        for(int i = 0; i < area; i++) {
            countCol = 0;
            for(int j = 0; j < area; j++) {
                if( i >= central - 1 && j >= central - 1 
                    && (area - countCol) >= mesasTam 
                    && (area - countLin) >= mesasTam) {
                    andar[i][j] = 1;
                }
                else andar[i][j] = 0;
                countCol++;
            }
            countLin++;
        }
    }
    else {
        for(int i = 0 ; i < area; i++) { // preenche o andar conforme o tamanho da sala, mesa e espacamento
            countCol = 0;
            if(countLin >= espaco + mesasTam && (area - i) >= mesasTam) { // reseta o contador de linhas para que possa imprimir 1 dnv
                countLin = 0;
            }
            for(int j = 0; j < area; j++) {
                if(countCol >= espaco + mesasTam && (area - j) >= mesasTam) { // reseta o contador de colunas para que possa imprimir 1 dnv
                    countCol = 0;
                }
                if(countCol < mesasTam && countLin < mesasTam) { // insere 1 se os contadores sao menores que o tamanho da mesa
                    andar[i][j] = 1;
                    mesas++;
                }
                else { // insere 0 se passar do tamanho da mesa
                    andar[i][j] = 0;
                }
                countCol++;
            }
            countLin++;
        }
        mesas /= mesasTam * mesasTam; // insere a quantidade de mesas que a sala comporta
    }
    return mesas;
}

int main(void) {

    int andares, i, j, mesasTam, areaAndar, esp, numPredios, mesasPredio;

    printf("Insira a quantidade de predios que vc quer verificar: ");
    scanf("%d", &numPredios);
    int predios[numPredios];

    for(j = 0; j < numPredios; j++) { // Laco para iteracao dos predios
        mesasPredio = 0;
        printf("Insira a quantidade de andares do predio %d: ", j + 1);
        scanf("%d", &andares);
        int predio[andares];
        
        for(i = 0; i < andares; i++) { // Laco para iteracao dos andares de cada predio
            printf("\nInsira a area(m²) do andar %d, a area ocupada pelas mesas e o espacamento entre elas: ", i + 1);
            scanf("%d %d %d", &areaAndar, &mesasTam, &esp);
            
            areaAndar = (int) sqrt(areaAndar); // passa o tamanho dos lados do andar
            mesasTam = (int) sqrt(mesasTam); // passa o tamanho dos lados da mesa
            
            int andar[areaAndar][areaAndar];
            predio[i] = contaMesas(areaAndar, andar, mesasTam, esp);
            imprimeMatriz(areaAndar, andar, i + 1);
        }
        
        printf("\nTOTAL DE MESAS EM CADA ANDAR: \n");
        for(i = 0; i < andares; i++) {
            printf("O andar %d comporta %d mesas\n", i+1, predio[i]);
            mesasPredio += predio[i];
        }
        printf("\n");
        predios[j] = mesasPredio;
    }
    
    printf("TOTAL DE MESAS EM CADA PREDIO: \n");
    for(i = 0; i < numPredios; i++) {
        printf("O predio %d comporta no total %d mesas\n", i + 1, predios[i]);
    }
}
