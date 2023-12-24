#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int notasA[3] = {1, 4, 5};
    int notasB[3] = {2, 5, 6};
    int notasC[3] = {3, 1, 4};
    int mat[3][3];


    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(row == 0) {
                mat[row][col] = notasA[col];
            }
            else if(row == 1){
                mat[row][col] = notasB[col];
            }
            else {
                mat[row][col] = notasC[col];
            }
        }
    }

    for(int row = 0; row < 3; row++) {
        char alunos[] = {'A', 'B', 'C'};
        printf("Aluno %c: ", alunos[row]);
        for(int col = 0; col < 3; col++) {
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }

}