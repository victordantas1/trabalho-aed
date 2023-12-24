#include <stdio.h>

int contPrateleiras(int lin, int col, int esp) {
    int prateleiras, countEsp, i, j;
    int mat[lin][col];
    countEsp = 0;
    prateleiras = 1;
    for(j = 0; j < col; j++) {
        if(countEsp > esp) {
            countEsp = 0;
            prateleiras++;
        }
        for(i = 0; i < lin; i++) {
            if(countEsp == 0) {
                mat[i][j] = 1;
            }
            else {
                mat[i][j] = 0;
            }
        }
        countEsp++;
    }
    printf("Disposicao do armazem: \n");
    for(j = 0; j < lin; j++) {
        for(i = 0; i < col; i++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    return prateleiras;
}

int main(void) {
    int alt, larg, esp;

    alt = 100;
    larg = 100;
    esp = 2;

    int prateleiras = contPrateleiras(alt, larg, esp);

    printf("Para um armazem de %dX%d com espacamento de %d \nvoce pode colocar ate: %d prateleiras\n",alt, larg, esp, prateleiras);

}