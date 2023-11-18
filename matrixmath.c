#include <stdio.h>
#include <stdlib.h>

typedef struct matrixDef{
    int m,n;
    float **A;
} MD;

void create_matrix(MD* a,int rowSize,int colSize){
    a->m = rowSize;
    a->n = colSize;
    a->A = (float**) malloc(sizeof(float*)*(a->m));
    for(int i=0;i<(a->m);i++){
        a->A[i] = (float*) malloc(sizeof(float)*(a->n));
    }
}

void assign_value(MD *a){
    float count = 1;
    for(int i=0;i<(a->m);i++){
        for (int j=0;j<(a->n);j++){
            a->A[i][j] = count;
            count += 1;
        }
    }
}

void print(MD *a){
    for(int i=0;i<(a->m);i++){
        for (int j=0;j<(a->n);j++){
            printf("%0.2f ",a->A[i][j]);
        }
        printf("\n");
    }
}

void multiply(MD *P,MD *A,MD *B){
    for(int i=0;i<(A->m);i++){
        for(int j=0;j<(B->n);j++){
            int count = 0;
            float res=0;
            while(count < B->n){
                res += A->A[i][count] * B->A[count][j];
                count += 1;
            }
            P->A[i][j] = res; 
        }
    }
}

void memfree(MD *a){
    for(int i=0;i<(a->m);i++){
        free(a->A[i]);
    }
    free(a->A);
}
